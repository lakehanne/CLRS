#!/usr/bin/env python
"""
/*  
*  Copyright December 2016
*  Author: Olalekan P. Ogunmolu
*
* Licensed under the Apache License, Version 2.0 (the "License");
*  you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
*      http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* 
* See the License for the specific language governing permissions and
* limitations under the License.
* 
*/
"""

import numpy as np
import sys

def merge(A, p, q, r):
	n1 = q - p +1
	n2 = r - q
	#initialize the left and right subarrays
	L = np.zeros([n1 + 1])
	R = np.zeros([n2 + 1])
	for i in range (0, n1):
		L[i] = A[p+i-1]
	for j in range (0, n2):
		R[j] = A[q+j]
	# //allocate sentinels
	R[n2] = np.inf
	L[n1] = np.inf
	i, j = 0,0
	for k in range(p, r):
		if L[i] < R[j]:
			A[k] = L[i]
			i = i +1
		else:
			A[k] = R[j]
			j = j+1

def mergesort(A, p, r):
	q = int((p+r)/2)
	mergesort(A, p, q)
	mergesort(A, q + 1, r)
	merge(A, p, q, r)

#test
n = 3
A = np.random.randint(1, 10, size=n)
print 'input array: ', A
p, r = 0, len(A)-1
# print p, r
mergesort(A, p, r)
print 'output array: ', A

#test with strings and chars
B = np.random.bytes(n)
print 'input array of bytes: ', B
p, r = 0, len(B)-1
mergesort(B, p, r)
print 'output array of bytes: ', B
 
#test with negative arrays ints
A = np.random.randint(1, 10, size=n)
A *= -1
print 'input -ve array: ', A
p, r = 0, len(A)-1
mergesort(A, p, r)
print 'output -ve array: ', A

# # test with floating point numbers
# A = 5 * np.random.random_sample((n, 1)) - 5
# print 'input array: ', A
# p, r = 0, len(A)-1
# mergesort(A, p, r)
# print 'output array: ', A
