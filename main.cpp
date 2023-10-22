#include"consts.h"
#include"tests.h"
#include<iostream>
#include<stdlib.h>

using namespace std;

int mas[SIZE][SIZE];

int main() {
	srand(time(NULL)); // Установить генератор случайных чисел


	//dijtest3132(mas, 0);
	//dijtest3132(mas, 1);
	//dijtest3132(2);
	//dijtest3132(3);

	bftest3132(mas, 0);
	//bftest3132(1);
	//bftest3132(2);
	//bftest3132(3);

	//dijtest33();
	//bftest33();

	//dijtest34(0);
	//dijtest34(1);

	//bftest34(0);
	//bftest34(1);

}