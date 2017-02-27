#include <sys/types.h>
#include <iostream>
#include <cstdlib>
#include <string>
#include <unistd.h>

using namespace std;

void displayInterface ()
{
	cout << "****************************************\n";
	cout << "1 – Выполнить введенную команду\n";
	cout << "2 – Запустить на исполнение файл со сценарием\n";
	cout << "3 – Пометить все файлы как исполняемые\n";
	cout << "4 - Выход\n";
}

void runCommand ()
{
	fork();
	string command;
	cout << "Ваша команда:\n";
	cin >> command;	
	//cout << "Результат работы команды:\t";
	system (command.c_str());
}

void runShellcript ()
{
	fork();
	system("chmod +x script.sh");
	cout << "\n****************************************\nРезультат работы скрипта:\n";
	system("./script.sh");
}

void runLab2Command ()
{
	fork ();
	cout << "Все файлы в данной директории помечены как исполняемые\n";
	system ("chmod +x *.*");
}


int main()
{
	bool exit = false;
	int choice = 0;
   	system ("clear");
	while(!exit)
	{
   	  displayInterface();
	  cin >> choice;
		switch (choice)
		{
			case 1: runCommand(); break;
			case 2: runShellcript(); break;
			case 3: runLab2Command(); break;
			case 4: exit = true; break;
			default: cout << "Введите число от 1 до 4!\n"; 
		}
	}
	return 0;	
}


/*
CPP
g++ ./main.cpp
./a.out

SH
chmod +x script.sh
./script.sh
*/