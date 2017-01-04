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
*
* Rudimentary Binary Tree
* Code based on treatment in Chapter 12 of CLRS
*/

#include <iostream>

#define OUT(__o__) std::cout << __o__ << std::endl;
#define OUTL(__o__) std::cout << __o__ << " ";

template<typename N>
struct treeNode{
	treeNode<N>* left; 			//left node of the tree
	treeNode<N>* right;         //right node of tree 
	N value; 					//value of this node

	//default node constructor
	treeNode()
	:left(nullptr), right(nullptr)
	{ }
	//copy constructor
	treeNode(const N& value)
	: value(value), left(nullptr), right(nullptr)
	{}
};

template<typename T>
class binSearch{
private:
	treeNode<T>* y;
	T counter; 					//keep track of current length of tree

	void init()
	{
		root = new treeNode<T>;
		y = new treeNode<T>;
	}

public:

	treeNode<T>* root; 			// root and current nodes of the tree
	binSearch()
	{
		init();
	}

	~binSearch()
	{
		eraseAll();
	}

	//delete all nodes one after the other
	inline void eraseAll(){
		if(root->left != nullptr){
			delete root->left;
		}
		else if(root->right != nullptr){
			delete root->right;
		}
		else if(root != nullptr){
			delete root;
		}
		delete y;
	}

	T minimum(treeNode<T>* subNode);
	T maximum(treeNode<T>* subNode);
	T find(treeNode<T>* subNode, const T& elem);
	void treeSuccessor(treeNode<T>* subNode);
	void insert(treeNode<T>* inNode);
	void inorderTreeWalk(treeNode<T>* subNode);
	void postOrderTreeWalk(treeNode<T>* subNode);
	void preOrderTreeWalk(treeNode<T>* subNode);
};

template<typename T>
void binSearch<T>::inorderTreeWalk(treeNode<T>* subNode)
{
	if(subNode != nullptr){
		inorderTreeWalk(subNode->left);
		OUTL(subNode->value << " ");
		inorderTreeWalk(subNode->right);
	}
}

template<typename T>
void binSearch<T>::postOrderTreeWalk(treeNode<T>* subNode){
	if(subNode != nullptr){
		postOrderTreeWalk(subNode->left);
		postOrderTreeWalk(subNode->right);
		OUTL(subNode->value << " ");
	}
}

template<typename T>
void binSearch<T>::preOrderTreeWalk(treeNode<T>* subNode){
	if(subNode != nullptr){
		OUTL(subNode->value << " ");
		preOrderTreeWalk(subNode->left);
		preOrderTreeWalk(subNode->right);
	}
}

template<typename T>
T binSearch<T>::find(treeNode<T>* subNode, const T& elem){
	while(subNode != nullptr || elem != subNode->value){
	if(elem < subNode->value){
		subNode = subNode->left;
	}
	else
		subNode = subNode->right;
	}
	return subNode->value;
}

template<typename T>
T binSearch<T>::minimum(treeNode<T>* subNode){
	while(subNode->left != nullptr){
		subNode = subNode->left;
	}
	OUT ("minimum is "<< subNode->value);
	return subNode->value;
}

template<typename T>
T binSearch<T>::maximum(treeNode<T>* subNode){
	while(subNode->right!=nullptr){
		subNode = subNode->right;
	}
	OUT("maximum is " << subNode->value);
	return subNode->value;
}

template<typename T>
inline void binSearch<T>::insert(treeNode<T>* inNode){
	y = nullptr;
	treeNode<T>* x = root;
	while( x!= nullptr){
		y = x;
		if((inNode->value) < (x->value)){
			x = x->left;
		}
		else{
			x = x->right;
		}
	}
	// inNode->value = y;
	if(y == nullptr){
		root = inNode; 					//Tree was empty
	}
	else if ((inNode->value) < (y->value)){
		y->left = inNode;
	}
	else{
		y->right = inNode;
	}
	OUT("inserted " << inNode->value << " into tree");
}

template<typename T>
void binSearch<T>::treeSuccessor(treeNode<T>* subNode){
	if(subNode->right!=nullptr){
		return minimum(subNode->right);
	}
	y = subNode;
}


int main(void){
	binSearch<int>* bSearch = new binSearch<int>;
	int elem;
	for(;;){
		treeNode<int>* tNode = new treeNode<int>;
		OUT("Input keys to insert (type -6545 to break):");
		std::cin>> elem; //tNode->value;
		tNode->value = elem;
		if(elem == -6545){
			delete tNode;
			break;
		}
		bSearch->insert(tNode);
		// delete tNode;
	}

	OUT("\ninorderTreeWalk");
	bSearch->inorderTreeWalk(bSearch->root);
	std::cout << std::endl;

	OUT("\npostOrderTreeWalk");
	bSearch->postOrderTreeWalk(bSearch->root);
	std::cout << std::endl;

	OUT("\npreOrderTreeWalk");
	bSearch->preOrderTreeWalk(bSearch->root);
	std::cout << std::endl;

	// bSearch->eraseAll();s
}