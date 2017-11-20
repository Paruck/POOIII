#include "DCLL.h"



void DCLL::insertWepon(Item * nuevo)
{
	if (!head)
	{
		head = nuevo;
		head->next = nuevo;
		head->prev = nuevo;
	}
	else
	{
		head->next->prev = nuevo;
		nuevo->next = head->next;
		nuevo->prev = head;
		head->next = nuevo;
		head = head -> next;
	}
}

void DCLL::insertStr(std::string name)
{
	Item *it = new Item(name);
	insertWepon(it);
}

void DCLL::remove()
{
	head->prev->next = head->next;
	head->next->prev = head->prev;
	Item *temp = head;
	head = head->next;
	delete temp;
}

void DCLL::print()
{
	Item* it = head;
	std::cout << "Head: \n" << head->name.c_str();
	do
	{
		char *prefijo = (it == head) ? "\t" : "\t";
		std::cout << prefijo << it->name.c_str() << "\n";
		it = it->next;
	} while (it != head);
}

DCLL::DCLL():head(NULL)
{
}


DCLL::~DCLL()
{
}

