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

	treeNode<N>* reset(treeNode<N>* x){
		delete x;
		treeNode<N>* px = new treeNode<N>;
		return px;
	}
};

template<typename T>
class bsTree{
private:
	treeNode<T>* temp;
	treeNode<T>* root; 			// root and current nodes of the tree
	T counter; 					//keep track of current length of tree

	void init()
	{
		root = nullptr; 
		temp = nullptr; 
	}

public:
	bsTree()
	{
		init();
	}

	~bsTree()
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
		delete temp;
	}

	treeNode<T>* getRoot() const;
	void inorderTreeWalk(treeNode<T>* subNode);
	void preOrderTreeWalk(treeNode<T>* subNode);
	void postOrderTreeWalk(treeNode<T>* subNode);
	treeNode<T>* minimum(treeNode<T>* subNode);
	treeNode<T>* maximum(treeNode<T>* subNode);
	treeNode<T>* find(treeNode<T>* subNode, const T& elem);
	void insert(treeNode<T>* inNode);
	treeNode<T>* treeSuccessor(treeNode<T>* subNode);
	void transplant(treeNode<T>* u, treeNode<T>* v);
	void remove(treeNode<T>* z);
};

template<typename T>
treeNode<T>* bsTree<T>::getRoot()	const
{
	return this->root;
}
template<typename T>
void bsTree<T>::inorderTreeWalk(treeNode<T>* subNode)
{
	if(subNode != nullptr){
		inorderTreeWalk(subNode->left);
		OUTL(subNode->value << " ");
		inorderTreeWalk(subNode->right);
	}
}

template<typename T>
void bsTree<T>::preOrderTreeWalk(treeNode<T>* subNode){
	if(subNode != nullptr){
		OUTL(subNode->value << " ");
		preOrderTreeWalk(subNode->left);
		preOrderTreeWalk(subNode->right);
	}
}

template<typename T>
void bsTree<T>::postOrderTreeWalk(treeNode<T>* subNode){
	if(subNode != nullptr){
		postOrderTreeWalk(subNode->left);
		postOrderTreeWalk(subNode->right);
		OUTL(subNode->value << " ");
	}
}

template<typename T>
treeNode<T>* bsTree<T>::minimum(treeNode<T>* subNode){
	while(subNode->left != nullptr){
		subNode = subNode->left;
	}
	OUT ("minimum is "<< subNode->value);
	return subNode;
}

template<typename T>
treeNode<T>* bsTree<T>::maximum(treeNode<T>* subNode){
	while(subNode->right!=nullptr){
		subNode = subNode->right;
	}
	OUT("maximum is " << subNode->value);
	return subNode;
}

/*Search for a key: O(h)*/
template<typename T>
treeNode<T>* bsTree<T>::find(treeNode<T>* subNode, const T& elem)
{
	while(subNode != nullptr && elem != subNode->value)
	{
		if(elem < (subNode->value))
		{
			subNode = subNode->left;
		}
		else
		{
			subNode = subNode->right;
		}
	}
	return subNode;
}

/*O(h) time on a tree of height h*/
template<typename T>
inline void bsTree<T>::insert(treeNode<T>* inNode){
	temp = nullptr;
	treeNode<T>* x = root;
	while( x!= nullptr){
		temp = x;
		if((inNode->value) < (x->value)){
			x = x->left;
		}
		else{
			x = x->right;
		}
	}
	// inNode->value = temp;
	if(temp == nullptr){
		root = inNode; 					//Tree was empty
	}
	else if ((inNode->value) < (temp->value)){
		temp->left = inNode;
	}
	else{
		temp->right = inNode;
	}
	OUT("inserted " << inNode->value << " into tree");
}

template<typename T>
treeNode<T>* bsTree<T>::treeSuccessor(treeNode<T>* subNode){
	if(subNode->right!=nullptr){		
		OUT("Successor is: " << (minimum(subNode->right))->value);
		return minimum(subNode->right);
	}
	temp = subNode;
	while(temp!=nullptr && subNode == temp->right){
		subNode = temp;
	}
	OUT("Successor: " << temp->value);
	return temp;
}

template<typename T>
void bsTree<T>::transplant(treeNode<T>* u, treeNode<T>* v)
{
	if(u == nullptr){
		root = v;
	}
	else if(u==u->left){
		u->left = v;
	}
	else{
		u->right = v;
	}
	if(v!=nullptr){
		v = u;
	}
}

template<typename T>
void bsTree<T>::remove(treeNode<T>* z)
{
	if(z->left==nullptr){
		transplant(z, z->right);
	}
	else if(z->right==nullptr){
		transplant(z, z->left);
	}
	else{
		temp = treeSuccessor(z);
		if(temp != z){
			transplant(temp, temp->right);
			temp->right = z->right;
			temp->right = temp;
		}
		transplant(z, temp);
		temp->left = z->left;
		temp->left = temp;
	}
	OUT("removed: " << z->value);
}

int main(void){
	bsTree<int>* bSearch = new bsTree<int>;
	int elem;
	treeNode<int>* tNode = new treeNode<int>;
	while(true){
		OUT("Input keys to insert (type \"-0\" to break):");
		std::cin>> tNode->value;
		if(tNode->value == -0){
			break;
		}
		bSearch->insert(tNode);
		tNode = tNode->reset(new treeNode<int>);
	}

	OUT("\ninorderTreeWalk");
	bSearch->inorderTreeWalk(bSearch->getRoot());
	std::cout << std::endl;

	bSearch->minimum(bSearch->getRoot());
	bSearch->maximum(bSearch->getRoot());
	auto suc = bSearch->treeSuccessor(bSearch->getRoot());

	auto f = 6;
	auto res = bSearch->find(bSearch->getRoot(), 6);
	OUT("\nSearch for " << 6 << " returned " << res->value);

	/*test remove*/
	treeNode<int>* tempNode = new treeNode<int>;
	for(;;){
		OUT("Input keys to insert (type \"-0\" to break):");
		std::cin>> tempNode->value;
		if(tempNode->value == -0){
			break;
		}
		bSearch->insert(tempNode);
		tempNode = tempNode->reset(new treeNode<int>);
	}
	OUT("Printing members of tempNode");
	bSearch->inorderTreeWalk(tempNode);
	bSearch->remove(tempNode);	
	OUT("\nPrinting members of root node after removing tempNode");
	bSearch->inorderTreeWalk(bSearch->getRoot());

	delete tempNode;

	return EXIT_SUCCESS;
}