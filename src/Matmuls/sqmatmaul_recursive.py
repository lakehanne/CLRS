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

"""
This algorithm uses the algorithm described in Section 4.2
of CLRS. pg 77. In the big order of things, this stakes theta(n^3)
because of the 8 recurrence of aqmatrix mults
"""
import numpy as np

def partition_matrix(A):
	n = A.shape[1]
	A11 = A[0:int(np.floor(n/2)),0:int(np.floor(n/2))]
	A12 = A[0:int(np.floor(n/2)),int(np.floor(n/2)):n]
	A21 = A[int(np.floor(n/2)):n,0:int(np.floor(n/2))]
	A22 = A[int(np.floor(n/2)):n,int(np.floor(n/2)):n]
	return A11, A12, A21, A22

def gen_matrix(n):
	return np.random.randint(1,5, size=(n,n))

def sqmatmul_recursive(A, B):
	assert(A.shape == B.shape), "error, A and B nust be equal in dimensions"
	n = A.shape[1]
	C = np.zeros([n,n], dtype=np.int)
	if n == 1:
		C[0][0] = A[0][0]*B[0][0]
	else:
		A11, A12, A21, A22 = partition_matrix(A)
		B11, B12, B21, B22 = partition_matrix(B)
		"""
		all recursive call take 8T(n/2) running time since each 
		recursive call multiplies two n/2 x n/2 matrices.
		the four matrix additions below each contribute theta(n^2/4)
		~= theta(n^2) time. Total time spent is thus theta(n^2)
		"""
		C11 = sqmatmul_recursive(A11,B11) + sqmatmul_recursive(A12,B21)
		C12 = sqmatmul_recursive(A11,B12) + sqmatmul_recursive(A12,B22)
		C21 = sqmatmul_recursive(A21,B11) + sqmatmul_recursive(A22,B21)
		C22 = sqmatmul_recursive(A21,B12) + sqmatmul_recursive(A22,B22)

		#join the arrays into C
		"""
		The indexing operations below each cause a theta(1) time per entry

		"""
		Cvert1 = np.vstack((C11, C21))
		Cvert2 = np.vstack((C12,C22))
		C      = np.hstack((Cvert1, Cvert2))
		
		"""	
		so the total time for the recursive case is the sum of the partitioning 
		time, the time for all the recursive calls, and the time to add the
		matrices resulting from the recursive calls
		T(n) = theta(1) + 8T(n/2) + theta(n^2)

		Therefore, the recurrence for running the square matrix multiply 
		recursive algorithm is

		T(n) = theta(1) if n = 1
		T(n) = 8T(n/2) + theta(n^2) if n > 1
		"""

	return C


n = 4
A = gen_matrix(n)
B = gen_matrix(n)

C = sqmatmul_recursive(A, B)


print 'A: \n', A
print 'B: \n', B

print 'C: \n', C

#check if algorithm does what we expect
print np.array_equal(A*B, C)