#!/usr/bin/python3
import sys


class Log:
    """ holds important attributes for loging """

    def __init__(self):
        """ init """
        empty_cache = {}
        li = [200, 301, 400, 401, 403, 404, 405, 500]
        for l in li:
            empty_cache[str(l)] = 0
        self.empty_cache = empty_cache.copy()
        self.id = 1
        self.cache = empty_cache.copy()
        self.size = 0
        self.i = 0

    def do_stuff(self):
        """ do stuff """
        i = 0
        for line in sys.stdin:
            ls = line.split(' ')
            if len(ls) != 9:
                '''self.size += eval(ls[8].strip('\n'))
                self.i += 1'''
                continue
            code = ls[-2]
            '''print("code: [{}]".format(code))
            print("cachecode1: [{}]".format(self.cache[code]))'''
            '''if self.cache.get(code) is None:
                self.cache.update({code: 1})
            else:'''
            if code in self.cache.keys():
                self.cache[code] += 1
            '''self.cache[code] += 1'''
            '''self.cache['cool'] += 2'''
            '''print("cachecode2: [{}]".format(self.cache[code]))
            print("--------")'''
            self.size += int(ls[-1].strip('\n'))
            self.i += 1
            if self.i == 10:
                self.i = 0
                self.print_dat()
                '''self.cache = self.empty_cache.copy()'''

    def print_dat(self):
        """ Prints dat cache """
        print("File size: {:d}".format(self.size))
        for k in sorted(self.cache.keys()):
            if self.cache[k] != 0:
                print("{}: {}".format(k, self.cache[k]))
        '''self.cache = self.empty_cache.copy()'''


log = Log()
try:
    log.do_stuff()
    log.print_dat()
except KeyboardInterrupt:
    log.print_dat()
    raise
