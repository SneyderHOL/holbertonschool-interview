#!/usr/bin/python3
"""Lockboxes task for project 0x00-lockboxes"""


def canUnlockAll(boxes):
    '''method to determine if all boxes can be opened'''
    if boxes is None:
        return False
    boxes_open = [False]*len(boxes)
    boxes_open[0] = True
    open_box(boxes[0], boxes, boxes_open)
    if False in boxes_open:
        return False
    return True


def open_box(box, boxes, boxes_open):
    '''method to open boxes'''
    if len(box) == 0:
        return
    for key in box:
        if key >= len(boxes_open):
            continue
        if boxes_open[key] is False:
            boxes_open[key] = True
            open_box(boxes[key], boxes, boxes_open)
