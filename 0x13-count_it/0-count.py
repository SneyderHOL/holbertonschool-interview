#!/usr/bin/python3
"""Count it! module"""

import requests
import sys

REDDIT_URL = 'https://reddit.com/r/'
USER_AGENT = 'auxiliar-ua'
HEADERS = {"User-Agent": USER_AGENT}


def count_words(subreddit, word_list, after=None, kw_cont={}, reap_kw={}):
    """Queries the Reddit API, parses the title of all hot articles,
    and prints a sorted count of given keywords"""
    pagination = '/hot.json'
    if after:
        pagination += '?after=' + after
    response = requests.get(REDDIT_URL + subreddit + pagination,
                            headers=HEADERS)

    if response.status_code == 404:
        return

    if kw_cont == {}:
        keys = [word.lower() for word in word_list]
        for key in keys:
            kw_cont[key] = 0
            reap_kw[key] = keys.count(key)

    response_dict = response.json()
    data = response_dict['data']
    after = data['after']
    posts = data['children']

    for post in posts:
        data_in_post = post['data']
        title = data_in_post['title']
        words_in_title = title.split()
        for word in words_in_title:
            for key in kw_cont:
                if word.lower() == key.lower():
                    kw_cont[key] += 1

    if after:
        count_words(subreddit, word_list, after, kw_cont, reap_kw)
    else:
        for key, val in reap_kw.items():
            if val > 1:
                kw_cont[key] *= val

        sorted_abc = sorted(kw_cont.items(), key=lambda x: x[0])
        sorted_res = sorted(sorted_abc, key=lambda x: (-x[1], x[0]))
        for res in sorted_res:
            if res[1] > 0:
                print('{}: {}'.format(res[0], res[1]))
