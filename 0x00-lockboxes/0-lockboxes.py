#!/usr/bin/python3
"""Lockboxes task for project 0x00-lockboxes"""


def canUnlockAll(boxes):
    '''method to determine if all boxes can be opened'''
    total_number = total_boxes(boxes)
    open_number = 0
    dataset = {0}
    size = len(boxes)
    for box_number in range(size):
        if box_number in dataset:
            open_number += box_number
            for key in boxes[box_number]:
                if key >= size:
                    continue
                dataset.add(key)
                open_box(boxes[key], dataset, size)
    if open_number != total_number:
        return False
    return True


def open_box(box, data, size):
    '''method to open boxes'''
    if len(box) == 0:
        return
    for key in box:
        if key >= size:
            continue
        if key not in data:
            data.add(key)


def total_boxes(boxes):
    '''method to calculate the sum of indexes'''
    counter = 0
    for index in range(len(boxes)):
        counter += index
    return counter
