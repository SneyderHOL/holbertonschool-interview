#!/usr/bin/python3
""" Module change comes from within """


def makeChange(coins, total):
    """Determine the fewest number of coins needed to meet a given amount
      total"""
    if total <= 0:
        return 0
    coins.sort(reverse=True)
    coins_needed = 0
    idx = 0
    aux = 0
    number_of_coins = len(coins)
    while coins_needed < total and idx < number_of_coins:
        while coins[idx] <= total - coins_needed:
            coins_needed += coins[idx]
            aux = aux + 1
            if coins_needed == total:
                return aux
        idx += 1
    return -1
