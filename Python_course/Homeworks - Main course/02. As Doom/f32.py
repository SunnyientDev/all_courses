from enum import Enum

class C32(object):
    def __init__(self):
        self.state = 'A'

    def coast(self):
        return self.engine('c')

    def herd(self):
        return self.engine('h')

    def engine(self, connection):
        if self.state == 'A':
            if connection == 'c':
                self.state = 'B'
                return 0
            if connection == 'h':
                self.state = 'F'
                return 1

        if self.state == 'B':
            if connection == 'c':
                self.state = 'C'
                return 2

        if self.state == 'C':
            if connection == 'h':
                self.state = 'D'
                return 3

        if self.state == 'D':
            if connection == 'h':
                self.state = 'E'
                return 4
            if connection == 'c':
                self.state = 'F'
                return 5

        if self.state == 'E':
            if connection == 'h':
                self.state = 'F'
                return 6

        if self.state == 'F':
            if connection == 'c':
                self.state = 'G'
                return 7

        if self.state == 'G':
            if connection == 'c':
                self.state = 'C'
                return 8
            if connection == 'h':
                self.state = 'E'
                return 9