#!/usr/bin/python
import os,sys
import math
from pprint import pprint as P


class fountain:
    def __init__(self,x,y):
        self.x = x
        self.y = y
    def __str__(self):
        return "({0.x} {0.y})".format(self)

class flower(object):
    def __init__(self,id,x,y,d1,d2):
        self.id = id
        self.x = x
        self.y = y
        self.d1 = d1
        self.d2 = d2
    def __str__(self):
        return "({0.id} {0.x} {0.y}, {0.d1}, {0.d2})".format(self)

def distance(a,b):
    x = a.x - b.x
    y = a.y - b.y
    #return math.sqrt(x*x + y*y)
    return x*x + y*y

def distance2(a,bx,by):
    x = a.x - bx
    y = a.y - by
    #return math.sqrt(x*x + y*y)
    return x*x + y*y

def printl(list):
    for i in list:
        print(i)

def main():
    f1=None
    f2=None
    flowers = []
    fid=0
    #with open("input_file",'r') as fh:
    with sys.stdin as fh:
        flower_num, f1x, f1y, f2x, f2y = map(int, fh.readline().strip().split())
        f1 = fountain(f1x,f1y)
        f2 = fountain(f2x,f2y)
        for line in fh:
            x,y = map(int, line.strip().split())
            flowers.append(flower(fid,x,y,distance2(f1,x,y),distance2(f2,x,y)))
            fid+=1

    s1 = sorted(flowers, key=lambda x: x.d1, reverse = True)
    s2 = sorted(flowers, key=lambda x: x.d2, reverse = True)

    s1size = s1[0].d1
    s2size = 0
    result = s1size + s2size
    for i,item in enumerate(s1):
        if s2size <= item.d2:
            s2size = item.d2
        if i < len(s1)-1:
            s1size = s1[i+1].d1
        else:
            s1size = 0
        tmp = s1size + s2size
        print(str(tmp) + " " + str(s1size) + " " + str(s2size))
        if tmp < result:
            result = tmp
        print(str(result))
    print(str(result))
    return 0

if __name__ == "__main__":
    sys.exit(main())
