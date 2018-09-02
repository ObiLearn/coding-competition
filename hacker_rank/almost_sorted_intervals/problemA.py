#!/usr/bin/python
import os,sys
import math
from pprint import pprint as P


def printl(list):
    for i in list:
        print(i)

def main():
    values = []
    with sys.stdin as fh:
        a, b, c = map(int, fh.readline().strip().split())
        for line in fh:
            x,y = map(int, line.strip().split())
            values.append((x, y))

    sorted_values = sorted(values, key=lambda x: x, reverse = True)

    print(str(result))
    return 0

if __name__ == "__main__":
    sys.exit(main())
