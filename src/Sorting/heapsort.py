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
		self.Aheapsize = A.size

	def exchange(self, idx1, idx2):
		self.A[idx1], self.A[idx2] = self.A[idx2], self.A[idx1]

	def parent(self, i):
		return int(np.floor(i/2))

	def left(self, i):
		return 2*i

	def right(self, i):
		return 2*i + 1

	def maxheapify(self, i):
		l = self.left(i)
		r = self.right(i)

		if ((l <= self.Aheapsize-1) and (self.A[l] > self.A[i])) :
			self.largest = l
		else:
			self.largest = i

		if (r <= self.Aheapsize-1) and (self.A[r] > self.A[self.largest]):
			self.largest = r

		if self.largest != i:
			# exchange
			self.exchange(i, self.largest)
			self.maxheapify(self.largest)
		
	def buildmaxheap(self):
		for i in xrange(int(np.floor(self.A.size/2)),0,-1):
			self.maxheapify(i)

	def heapsort(self):
		self.buildmaxheap()
		for i in xrange(self.A.size-1, 0, -1):
			self.exchange(1, i)
			self.Aheapsize -= 1
			self.maxheapify(1)
		return self.A

def main():		
	A = np.array([4,1,3,2,16,9,10,14,8,7], dtype=int)
	print '\ngiven array:\n', A

	heapsrt = MaxHeapify(A).heapsort()
	print('\nsorted array is')
	print(A)

if __name__ == "__main__":
    main()




