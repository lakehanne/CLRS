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

def merge(items, p, q, r):
    L = items[p:q+1]
    R = items[q+1:r+1]
    i = j = 0
    k = p
    while i < len(L) and j < len(R):
        if(L[i] < R[j]):
            items[k] = L[i]
            i += 1
        else:
            items[k] = R[j]
            j += 1
        k += 1
    if(j == len(R)):
        items[k:r+1] = L[i:]



def mergesort(items, p, r):
    if(p < r):
        q = (p+r)/2
        mergesort(items, p, q)
        mergesort(items, q+1, r)
        merge(items, p, q, r)


#test
A = np.random.randint(1, 10, size=5)
print 'input array: ', A
p, r = 0, len(A)-1
mergesort(A, p, r)
print 'output array: ', A

#test with negative arrays ints
A = np.random.randint(1, 10, size=5)
A *= -1
print '\ninput -ve array: ', A
p, r = 0, len(A)-1
mergesort(A, p, r)
print 'output -ve array: ', A

# # test with floating point numbers
# A = 5 * np.random.random_sample((n, 1)) - 5
# print 'input array: ', A
# p, r = 0, len(A)-1
# mergesort(A, p, r)
# print 'output array: ', A
