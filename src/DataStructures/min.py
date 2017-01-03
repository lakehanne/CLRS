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
	return np.random.randint(1,n, size=n)

def minimum(A):
	n = len(A)
	mini = A[0]

	for j in xrange(1, n):
		if mini > A[j]:
			mini = A[j]
	return mini

def maximum(A):
	n = len(A)
	maxi = A[0]

	for j in xrange(1, n):
		if maxi < A[j]:
			maxi = A[j]
	return maxi


A =  gen_array(10)
print '\nGiven array: \n', A

mini = minimum(A)
maxi = maximum(A)
print '\nmin: ', mini, '| max: ', maxi