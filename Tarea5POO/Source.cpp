#include "DCLL.h"

int main(int argv, char** argc)
{
	DCLL *list = new DCLL();
		list->insertStr("Emilio");
		list->insertStr("Karla");
		list->insertStr("Dobby");
		list->insertStr("Babo");
		list->insertStr("Lupe");
		list->insertStr("Paty");
		list->insertStr("Robert");
		list->insertStr("Carlos");
	int i = 0;
	while (i < 9) {
		list->next();
		list->print();
		std::cout << "\n";
		++i;
	}
	system("pause");
	return 0;

}