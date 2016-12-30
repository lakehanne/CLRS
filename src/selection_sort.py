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

def selection_sort(A):
 	n = A.size
 	for i in xrange(0, n-1):
 		mini = i
 		for j in xrange(0, n):
 			if (A[j] < A[mini]):
 				mini = j
 		temp = A[i]
 		A[i] = A[mini]
 		A[mini] = temp

n = 10
A = np.random.randint(1,10, size=n)
print 'given matrix: \n', A

selection_sort(A)

print '\n\n resulting selection sorted matrix: ', A