#!/usr/bin/env python


import numpy as np

def selection_sort(A):
 	n = A.size
 	for i in xrange(0, n-1):
 		mini = i
 		for j in xrange(0, n):
 			if (A[j] < A[mini]):
 				mini = j
 		temp = A[i]
 		A[i] = A[mini]
 		A[mini] = temp

n = 10
A = np.random.randint(1,10, size=n)
print 'given matrix: \n', A

selection_sort(A)

print '\n\n resulting selection sorted matrix: ', A