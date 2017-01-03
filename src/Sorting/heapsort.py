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

class MaxHeapify:
	"""docstring for MAX-Heapify"""
	def __init__(self, A):
		self.A = A
		self.n = 0
		self.largest = 0

	def exchange(self, A, idx1, idx2):
		A[idx1], self.A[idx2] = A[idx2], self.A[idx1]
		return A

	def parent(self, i):
		return int((i-1)/2)

	def left(self, i):
		return 2*i+1

	def right(self, i):
		return 2*i+2

	def maxheapify(self, A, i):
		l = self.left(i)
		r = self.right(i)

		if ((l <= self.n-1) and (A[l] > A[i])) :
			self.largest = l
		else:
			self.largest = i

		if (r <= self.n-1) and (A[r] > A[self.largest]):
			self.largest = r

		if self.largest != i:
			# exchange
			A = self.exchange(A, i, self.largest)
			self.maxheapify(A, self.largest)
		
	def buildmaxheap(self, A):
		self.n = A.size
		for i in xrange(int(np.floor(self.n/2)),0,-1):
			self.maxheapify(A, i)

	def heapsort(self, A):
		self.buildmaxheap(A)
		for i in xrange(len(A)-1, 1, -1):
			A = self.exchange(A, 0, i)
			self.n -= 1
			self.maxheapify(A, 0)
		return A

def gen_array(n):
	return np.random.randint(1,5, size=(n))

def main():		
	A = gen_array(11)
	print '\ngiven array:\n', A

	heapsrt = MaxHeapify(A).heapsort(A)
	print('\nsorted array is')
	print(A)

if __name__ == "__main__":
    main()




