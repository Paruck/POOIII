#include "Heap.h"

std::string StringEmergencia(int a)
{
	switch (a)
	{
	case 0:
		return "Raspon";
	case 1:
		return "Dolor de muela";
	case 2:
		return "Dolor de cabeza";
	case 3:
		return "Sangrado de nariz";
	case 4:
		return "Emergencia 1";
	case 5:
		return "Emergencia 2";
	case 6:
		return "Emergencia 3";
	case 7:
		return "Emergencia 4";
	case 8:
		return "Emergencia 5";
	case 9:
		return "Emergencia 6";
	case 10:
		return "Emergencia 7";
	case 11:
		return "Emergencia 8";
	case 12:
		return "Emergencia 9";
	case 13:
		return "Emergencia 10";
	case 14:
		return "Emergencia 11";
	case 15:
		return "Emergencia 12";
	case 16:
		return "Emergencia 13";
	case 17:
		return "Emergencia 14";
	case 18:
		return "Emergencia 15";
	case 19:
		return "Emergencia 16";
	case 20:
		return "Emergencia 17";
	case 21:
		return "Emergencia 18";
	case 22:
		return "Emergencia 19";
	case 23:
		return "Emergencia 20";
	case 24:
		return "Emergencia 21";
	case 25:
		return "Emergencia 22";
	case 26:
		return "Emergencia 23";
	case 27:
		return "Emergencia 24";
	case 28:
		return "Emergencia 25";
	case 29:
		return "Emergencia 26";
	case 30:
		return "Emergencia 27";
	case 31:
		return "Emergencia 28";
	case 32:
		return "Emergencia 29";
	case 33:
		return "Emergencia 30";
	case 34:
		return "Emergencia 31";
	case 35:
		return "Emergencia 32";
	case 36:
		return "Emergencia 33";
	case 37:
		return "Emergencia 34";
	case 38:
		return "Emergencia 35";
	case 39:
		return "Emergencia 36";
	case 40:
		return "Emergencia 37";
	case 41:
		return "Emergencia 38";
	case 42:
		return "Emergencia 39";
	case 43:
		return "Emergencia 40";
	case 44:
		return "Emergencia corazon roto :'(";
	case 45:
		return "Emergencia 41";
	case 46:
		return "Emergencia 42";
	case 47:
		return "Emergencia 43";
	case 48:
		return "Emergencia 44";
	case 49:
		return "Emergencia mal meme";
	case 50:
		return "Emergencia 45";
	case 51:
		return "Emergencia 46";
	case 52:
		return "Emergencia 47";
	case 53:
		return "Emergencia 48";
	case 54:
		return "Emergencia 49";
	case 55:
		return "Emergencia 50";
	case 56:
		return "Emergencia 51";
	case 57:
		return "Emergencia 52";
	case 58:
		return "Emergencia 53";
	case 59:
		return "Emergencia 54";
	case 60:
		return "Emergencia 55";
	case 61:
		return "Emergencia 56";
	case 62:
		return "Emergencia 57";
	case 63:
		return "Emergencia 58";
	case 64:
		return "Emergencia 59";
	case 65:
		return "Emergencia 60";
	case 66:
		return "Emergencia 61";
	case 67:
		return "Emergencia 62";
	case 68:
		return "Emergencia 63";
	case 69:
		return "Emergencia 64";
	case 70:
		return "Emergencia 65";
	case 71:
		return "Emergencia 66";
	case 72:
		return "Emergencia 67";
	case 73:
		return "Emergencia 68";
	case 74:
		return "Emergencia 69";
	case 75:
		return "Emergencia 70";
	case 76:
		return "Emergencia 71";
	case 77:
		return "Emergencia 72";
	case 78:
		return "Emergencia 73";
	case 79:
		return "Emergencia 74";
	case 80:
		return "Emergencia 75";
	case 81:
		return "Emergencia 76";
	case 82:
		return "Emergencia 77";
	case 83:
		return "Emergencia 78";
	case 84:
		return "Emergencia 79";
	case 85:
		return "Emergencia 80";
	case 86:
		return "Emergencia 81";
	case 87:
		return "Emergencia 82";
	case 88:
		return "Emergencia 83";
	case 89:
		return "Emergencia 84";
	case 90:
		return "Emergencia 85";
	case 91:
		return "Emergencia 86";
	case 92:
		return "Emergencia 87";
	case 93:
		return "Emergencia 88";
	case 94:
		return "Emergencia 89";
	case 95:
		return "Emergencia 90";
	case 96:
		return "Emergencia 91";
	case 97:
		return "Emergencia 92";
	case 98:
		return "Emergencia 93";
	case 99:
		return "Paro cardiaco.";
	}
	
}



int main()
{
	Heap heaperino(100);
	for (int i = 0; i < 100; ++i)
	{
		int r = rand() % 100;
		std::string paciente = StringEmergencia(r);
		std::cout << "Llego paciente num " << i << " emergencia: " << paciente << std::endl;
		heaperino.Queue(paciente,r);
	}
	system("pause");
	system("cls");
	for (int i = 0; i < 100; ++i)
	{
		std::cout << heaperino.Dequeue() << " atendido" << std::endl;
	}
	system("pause");
    return 0;
}

