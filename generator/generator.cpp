#include"generator.h"
#include"consts.h"
#include<vector>
#include<stdlib.h>

int GetRandomNumber(int min, int max) {
	int num = min + rand() % (max - min + 1); // Получить случайное число - формула
	return num;
}

void generate(int(&mas)[SIZE][SIZE], int n, int m, int q, int r) {	//количество вершин, рёбер, мин, макс
	for (int i = 0; i < SIZE; i++) {	//очищаем массив, в котором будут лежать сгенерированные рёбра
		for (int j = 0; j < SIZE; j++) {
			mas[i][j] = 0;
		}
	}
	if (m == n * n) {
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				mas[i][j] = GetRandomNumber(q, r);
	}
	else {
		for (int i = 0; i < m; i++) {
			int a = GetRandomNumber(0, n - 1);
			int b = GetRandomNumber(0, n - 1);
			while (mas[a][b] != 0) {
				a = GetRandomNumber(0, n - 1);
				b = GetRandomNumber(0, n - 1);
			}
			int cost = GetRandomNumber(q, r);
			mas[a][b] = cost;
		}
	}
}