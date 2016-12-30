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

def gen_array(n):
	return np.random.randint(1,5, size=(n))

def exchange(A, idx1, idx2):
	A[idx1], A[idx2] = A[idx2], A[idx1]

def quicksort(A, p, r):
	if(p < r):
		q = partition(A,p,r)
		quicksort(A, p, q-1)
		quicksort(A, q+1, r)

def partition(A, p, r):
	x = A[r]
	i = p -1
	for j in xrange(p,r):
		if (A[j] <= x):
			i = i + 1
			exchange(A, i, j)
	exchange(A, i+1, r)
	return i + 1
	
#example
A = gen_array(5)
print '\ngiven array:\n', A

quicksort(A, 0, A.size-1)
print '\nsorted array:\n', A

#example 2
B = gen_array(10)
print '\ngiven array:\n', B

quicksort(B, 0, B.size-1)
print '\nsorted array:\n', B
