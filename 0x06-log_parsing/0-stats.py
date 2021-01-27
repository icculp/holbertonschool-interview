#!/usr/bin/python3
import sys
from signal import signal, SIGINT, SIG_IGN, getsignal
from _thread import start_new_thread

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
        print("INSIDE")
        i = 0
        try:
            print('inside try')
            sys.stdin.flush()
            for line in sys.stdin:
                print('----------------------')
                #print(line)
                #print('----------------------')
                #print_dat(cache, size)
                #print(line)
                ls = line.split(' ')
                code = ls[7]
                self.cache[code] += 1
                self.size += eval(ls[8].strip('\n'))
                self.i += 1
                if self.i == 10:
                    self.i = 0
                    self.print_dat()
                    self.cache = self.empty_cache.copy()
                #print(code)
            print('end of try')
        except KeyboardInterrupt:
            print('weeeeee')
            sys.stdin.flush()
            sys.stdout.flush()

    def print_dat(self):
        """ Prints dat cache """
        print("File size: {}".format(self.size))
        for k in sorted(self.cache.keys()):
            if self.cache[k] != 0:
                print("{}: {}".format(k, self.cache[k]))
        self.cache = self.empty_cache.copy()

log = Log()

def handler(signum, frame):
    """ handles ctrl-c signal """
    print('SIGINT or CTRL-C detected. Exiting gracefully')
    # restore the original signal handler as otherwise evil things will happen
    # in raw_input when CTRL+C is pressed, and our signal handler is not re-entrant
    signal(SIGINT, SIG_IGN)
    sys.stdout.flush()
    pass

if __name__ == '__main__':
    log = Log()
    #signal(SIGINT, SIG_IGN)
    while(1):
        #original_sigint = getsignal(SIGINT)
        #signal(SIGINT, SIG_IGN)
        #pid = os.fork()
        log.do_stuff()
        print('here?')
        #sys.stdin.flush()
        #sys.stdout.flush()
        #except KeyboardInterrupt:
            #sys.stdin.close
            #log.do_stuff()
        #    pass
