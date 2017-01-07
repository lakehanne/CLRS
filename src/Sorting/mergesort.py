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
	L = A[p:q+1]
	R = A[q+1:r+1]
	i = j = 0
	print 'L: ', L, 'R: ', R
	for k in range(p, r):
		if L[i] <= R[j]:
			A[k] = L[i]
			i += 1
		else:
			A[k] = R[j]
			j += 1

def mergesort(A, p, r):
	if p < r:
		q = (p+r)/2
		mergesort(A, p, q)
		mergesort(A, q + 1, r)
		merge(A, p, q, r)

#test
n = 5
A = np.random.randint(1, 10, size=n)
print 'input array: ', A
p, r = 0, len(A)
# print p, r
mergesort(A, p, r)
print 'output array: ', A
 
#test with negative arrays ints
A = np.random.randint(1, 10, size=n)
A *= -1
print 'input -ve array: ', A
p, r = 0, len(A)
mergesort(A, p, r)
print 'output -ve array: ', A

# # test with floating point numbers
# A = 5 * np.random.random_sample((n, 1)) - 5
# print 'input array: ', A
# p, r = 0, len(A)-1
# mergesort(A, p, r)
# print 'output array: ', A
