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
		# self.largest = 0;
		self.A = A
		self.Aheapsize = A.size

	def exchange(self, idx1, idx2):
		temp = np.copy(self.A)
		temp[idx1] = self.A[idx2]
		temp[idx2] = self.A[idx1]
		self.A = temp
		return temp


	def parent(self, i):
		return int(np.floor(i/2))

	def left(self, i):
		return 2*i

	def right(self, i):
		return 2*i + 1

	def maxheapify(self, i):
		l = self.left(i)
		r = self.right(i)

		temp = np.copy(self.A)
		if ((l < self.Aheapsize) and (temp[l] > temp[i])) :
			self.largest = l
		else:
			self.largest = i

		if (r < self.Aheapsize) and (temp[r] > temp[self.largest]):
			self.largest = r

		# temp = self.exchange(i, self.largest)
		if self.largest != i:
			# exchange
			temp = self.exchange(i, self.largest)
			self.maxheapify(self.largest)
		# update temp
		self.A = temp 

		return temp

	def buildmaxheap(self):
		for i in xrange(int(np.floor(self.A.size/2)), 0, -1):
			temp = np.copy(self.A)
			temp = self.maxheapify(i)
			print(temp)
			self.A = temp
		return temp

	def heapsort(self):
		self.buildmaxheap()
		for i in xrange(self.A.size-1, 0, -1):
			temp = self.exchange(1, i)
			tempSize = self.Aheapsize - 1
			self.A = temp
			newTemp = self.maxheapify(1)

			self.A = newTemp

		return newTemp

def main():		
	A = np.array([4,1,3,2,16,9,10,14,8,7], dtype=int)
	heapsrt = MaxHeapify(A)
	B = heapsrt.heapsort()
	print('\nsorted array is\n')
	print(B)

if __name__ == "__main__":
    main()




