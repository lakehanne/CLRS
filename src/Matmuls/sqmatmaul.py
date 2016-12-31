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

def gen_matrix(n):
	return np.random.randint(1,5, size=(n,n))

def sqmatmul(n):
	A = gen_matrix(n)
	B = gen_matrix(n)

	C = np.zeros([n,n], dtype=np.int)
	for i in xrange(0, n):
		for j in xrange(0,n):
			C[i][j] = 0
			for k in xrange(0,n):
				C[i][j] = C[i][j] + (A[i][k]*B[k][j])

	return A,B, C

A, B, C = sqmatmul(4)

print 'A: \n', A
print 'B: \n', B
print 'C: \n', C

