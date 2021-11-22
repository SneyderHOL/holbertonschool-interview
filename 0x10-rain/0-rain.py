#!/usr/bin/python3
"""Rain module"""


def rain(walls):
    """Calculate how much water will be retained after it rains"""
    if not walls:
        return 0
    if len(walls) < 3:
        return 0
    rain_water_retain = 0
    for key in range(1, len(walls) - 1):
        right_wall = max(walls[key + 1:])
        left_wall = max(walls[:key])
        minimum = min(left_wall, right_wall)
        if walls[key] < minimum:
            rain_water_retain += minimum - walls[key]
    return rain_water_retain
