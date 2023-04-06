#include <iostream>
#include <ctime>
#include "sensor.h"
#include "object.h"
#include "windows.h"

using namespace std;

int main()
{
	srand(time(NULL));
	setlocale(LC_ALL, "Russian");

	int size = 16;
	object* objects = new object[size];

	for (int i = 0; i < size; i++)
	{
		objects[i].set(rand() % 101, rand() % 101, (rand() % 101 - 50) / 10.0, (rand() % 101 - 50) / 10.0, 0, 100, 100, 0);
	}

	sensor datchik1(20, 20, 20);
	sensor datchik2(20, 20, 10);
	sensor datchik3(50, 50, 25);
	sensor datchik4(35, 20, 20);

	while (true)
	{
		for (int i = 0; i < size; i++) objects[i].update();

		Sleep(1000);

		if (datchik1.cheak(objects, size)) cout << "������ 1 ������������ " << datchik1.count(objects, size) << " ��������\n";
		else cout << "������ 1 �� ������������ ��������\n";
		if (datchik2.cheak(objects, size)) cout << "������ 2 ������������ " << datchik2.count(objects, size) << " ��������\n";
		else cout << "������ 2 �� ������������ ��������\n";
		if (datchik3.cheak(objects, size)) cout << "������ 3 ������������ " << datchik3.count(objects, size) << " ��������\n";
		else cout << "������ 3 �� ������������ ��������\n";
		if (datchik4.cheak(objects, size)) cout << "������ 4 ������������ " << datchik4.count(objects, size) << " ��������\n";
		else cout << "������ 4 �� ������������ ��������\n";
		cout << "\n";
	}

	return 0;
}
