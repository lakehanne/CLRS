
import numpy as numpy

def inorder_tree_walk(X):
	if X.size != 0:
		inorder_tree_walk(X.left)
