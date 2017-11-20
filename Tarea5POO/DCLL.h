#pragma once
#include <string>
#include <iostream>

class Item
{
public:
	Item *next;
	Item *prev;
	std::string name;
	Item(std::string n)
	{
		name = n;
	}
};



class DCLL
{
public:

	void insertWepon(Item* nuevo);
	void insertStr(std::string);

	inline void prev(){ head = head->prev;	}
	inline void next(){ head = head->next;	}
	inline Item* getHead() { return head; }

	void print();
	void remove();
	DCLL();
	~DCLL();

private:
	Item *head;
};

