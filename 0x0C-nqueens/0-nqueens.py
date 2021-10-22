#!/usr/bin/python3
"""N queens puzzle module"""

import sys


def wrong_input(msg):
  """function that prints a message and exit"""
  print(msg)
  exit(1)

def nqueens(n):
  """function that find solutions for n queens puzzle"""
  matrix = create_matrix(n)
  # print(matrix)
  matrix[2][2] = 1
  occupate_column_and_row(matrix, 2, 2, n - 1)
  print(matrix)

def create_matrix(n):
  """function that creates and returns a matrix"""
  matrix = []
  for i in range(n):
    matrix.append([n] * n)
  return matrix

def occupate_column_and_row(matrix, row, col, limit):
  """function that blocks a column of a matrix"""
  if row > 0:
    aux = row - 1
    while aux >= 0:
      matrix[aux][col] = 0
      aux -= 1
  if row < limit:
    aux = row + 1
    while aux <= limit:
      matrix[aux][col] = 0
      aux += 1
  if col > 0:
    aux = col - 1
    while aux >= 0:
      matrix[row][aux] = 0
      aux -= 1
  if col < limit:
    aux = col + 1
    while aux <= limit:
      matrix[row][aux] = 0
      aux += 1

#print every possible solution to the problem
#One solution per line
#Format: see example

if __name__ == '__main__':
    if len(sys.argv) < 2:
      wrong_input('Usage: nqueens N')
    if not sys.argv[1].isnumeric():
      wrong_input('N must be a number')
    n = int(sys.argv[1])
    if n < 4:
      wrong_input('N must be at least 4')
    nqueens(n)
