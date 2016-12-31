"""
This algorithm has a worst case running time of O(|_3n/2_|). Section 9.1 in CLRS

We are maintaining both the minimum and maximum elements seen thus far.
Rather than processing each element of the input by comparing it against 
the current minimum and maximum, at a cost of 2 comparisons per element.

We process elements in pairs. We compare pairs of elements from the input 
first with each other, and then we compare the smaller with the current 
minimum and the larger to the current maximum, at a cost of 3 comparisons 
for every 2 elements
"""
import numpy as np

def gen_array(n):
	return np.random.randint(1,n, size=n)

def minandmax(A):
	n = len(A)
	#initialize min and max
	mini, maxi = 0,0
	if (n%2 == 1): #array is odd
		mini = maxi = A[0]
		i = 0
		for j in xrange(1, n):
			if (mini > A[j]):
				tempmin = A[j]
				if mini > tempmin:
					mini = tempmin
			else:
				tempmax = A[j]
				if maxi < tempmax:
					maxi = tempmax
			i = i + 1
	else:			 #even
		if(A[0]<A[1]):
			mini, maxi = A[0], A[1]
		else:
			mini, maxi = A[1], A[0]			
		i = 0
		for j in xrange(1, n):
			if (A[i] > A[j]):
				tempmin = A[j]
				if mini > tempmin:
					mini = tempmin
			else:
				tempmax = A[j]
				if maxi < tempmax:
					maxi = tempmax
			i = i + 1
	return mini, maxi

A =  gen_array(11)
print '\nGiven array: \n', A

mini, maxi = minandmax(A)
print '\nmin: ', mini, '| max: ', maxi


