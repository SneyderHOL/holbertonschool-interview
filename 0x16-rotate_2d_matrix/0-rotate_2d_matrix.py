#!/usr/bin/python3
""" Rotation Module """


def rotate_2d_matrix(matrix):
    """Rotates a 2D Matrix 90 degrees clockwise"""
    matrix.reverse()
    matrix_copy = matrix.copy()

    for i in range(len(matrix)):
        matrix[i] = [row[i] for row in matrix_copy]
