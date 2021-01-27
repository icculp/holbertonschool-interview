#!/usr/bin/python3
import sys
from signal import signal, SIGINT



def print_dat(cache, size, empty_cache):
    """ Prints dat cache """
    print("File size: {}".format(size))
    for k in sorted(cache.keys()):
        if cache[k] != 0:
            print("{}: {}".format(k, cache[k]))
    cache = empty_cache.copy()


def handler(signal_received, frame):
    ''' Handle signal '''
    #print('SIGINT or CTRL-C detected. Exiting gracefully')
    #print(frame)
    print_dat(cache, size)

signal(SIGINT, handler)
i = 0
size = 0
def do_stuff(size):
    """ does the stuff """
    empty_cache = {}
    li = [200, 301, 400, 401, 403, 404, 405, 500]
    for l in li:
        empty_cache[str(l)] = 0
    cache = empty_cache.copy()
    i = 0
    for line in sys.stdin:
        #print('----------------------')
        #print(line)
        #print('----------------------')
        #print_dat(cache, size)
        #print(line)
        ls = line.split(' ')
        code = ls[7]
        cache[code] += 1
        size += eval(ls[8].strip('\n'))
        i += 1
        if i == 10:
            i = 0
            print_dat(cache, size, empty_cache)
            cache = empty_cache.copy()
        #print(code)
def handler(signal_received, frame):
    # Handle any cleanup here
    print('SIGINT or CTRL-C detected. Exiting gracefully')
    print(frame)
    print_dat(cache, size)
signal(SIGINT, handler)

do_stuff(size)
