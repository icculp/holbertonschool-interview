#!/usr/bin/python3
import sys
'''from signal import signal, SIGINT'''


class Log:
    """ holds important attributes for loging """

    def __init__(self):
        """ init """
        empty_cache = {}
        li = [200, 301, 400, 401, 403, 404, 405, 500]
        for l in li:
            empty_cache[str(l)] = 0
        self.empty_cache = empty_cache
        self.id = 1
        self.cache = empty_cache.copy()
        self.size = 0
        self.i = 0

    def do_stuff(self):
        """ do stuff """
        i = 0
        for line in sys.stdin:
            ls = line.split(' ')
            code = ls[7]
            self.cache[code] += 1
            self.size += eval(ls[8].strip('\n'))
            self.i += 1
            if self.i == 10:
                self.i = 0
                self.print_dat()
                self.cache = self.empty_cache.copy()

    def print_dat(self):
        """ Prints dat cache """
        print("File size: {}".format(self.size))
        for k in sorted(self.cache.keys()):
            if self.cache[k] != 0:
                print("{}: {}".format(k, self.cache[k]))
        self.cache = self.empty_cache.copy()


def handler(signum, frame):
    """ handles ctrl-c signal """
    log.print_dat()
    exit()


if __name__ == '__main__':
    log = Log()
    signal(SIGINT, handler)
    while(1):
        log.do_stuff()
