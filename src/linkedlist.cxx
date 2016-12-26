#include <iostream>
#include <memory>

struct node{
	int x;
	std::shared_ptr<node> next;
};

int main(void)
{
	std::shared_ptr<node> root(new node);
	
	root->next = 0;
	root->x = 5;
	std::shared_ptr<node> conductor(root);

	if(conductor!=0)
	{
		while(conductor->next != 0)
		{
			std::cout << "conductor " << conductor->x << std::endl;
			conductor = conductor->next;
		}
	}
	conductor->next.reset(new node);
	conductor = conductor->next;
	conductor->next = 0;
	conductor->x = 42;
			std::cout << "conductor " << conductor->x << std::endl;
}