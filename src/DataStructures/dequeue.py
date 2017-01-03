#!/usr/bin/env python
"""
10.1-5
Whereas a stack allows insertion and deletion of elements at only one end, and a
queue allows insertion at one end and deletion at the other end, a deque (double-ended queue) allows insertion and deletion at both ends. Write four O.1/-time
procedures to insert elements into and delete elements from both ends of a deque
implemented by an array.
"""

class dequeue:

    def __init__(self, length):
        self.N = 0
        self.head = 0
        self.tail = length-1
        self.queue = [0]*length
        self.length = length

    def putBegin(self, elem):
        self.queue[self.head] = elem
        self.N += 1
        self.head = (self.head+1)%self.length

    def putEnd(self, elem):
        self.queue[self.tail] = elem
        self.N += 1
        self.tail = (self.tail-1)%self.length

    def popBegin(self):
        self.N -= 1
        self.head = (self.head-1)%self.length
        v = self.queue[self.head]
        return v

    def popEnd(self):
        self.N -= 1
        self.tail = (self.tail+1)%self.length
        v = self.queue[self.tail]
        return v

    def out(self):
        print self.head,self.tail,self.N
        print self.queue

testqueue = dequeue(10)
testqueue.putBegin(2)
testqueue.putBegin(3)
testqueue.putBegin(4)
testqueue.putEnd(5)
testqueue.putEnd(6)
testqueue.putEnd(6)
testqueue.out()
print testqueue.popEnd()
print testqueue.popBegin()