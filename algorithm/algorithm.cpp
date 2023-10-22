#include"algorithm.h"
#include"consts.h"
#include<vector>
#include<algorithm>

void dijkstra(int start, int(&mas)[SIZE][SIZE], int n, int(&dist)[SIZE]) {
	std::vector<int> was(SIZE, 0);
	dist[start] = 0;
	for (int it = 0; it < n; it++) { //проходимся по каждой вершине
		int start = -1;
		for (int i = 0; i < n; i++) //цикл для выбора следующей вершины
			if (was[i] == 0)
				if (start == -1 || dist[i] < dist[start]) //выбираем по очереди вершины. если они смежны с src, то первыми берём те, которые ближе
					start = i;
		was[start] = 1;
		for (int j = 0; j < n; j++) {
			int fin = j; //перебираем конечную вершину
			int c = mas[start][j]; //расстояние из текущей вершины до перебираемой
			if (c && dist[start] + c < dist[fin]) //если до перебираемой вершины есть путь и пройти через текущую выгоднее, чем сейчас, то присваиваем новое значение
				dist[fin] = dist[start] + c;
		}
	}
}

void bellmanford(int start, int(&mas)[SIZE][SIZE], int n, int(&dist_bf)[SIZE]) {
	dist_bf[start] = 0;
	for (int k = 1; k < n; k++) //путь до 1 ребра, до 2, до 3...
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				if (dist_bf[i] < INF && mas[i][j] != 0)
					dist_bf[j] = std::min(dist_bf[j], dist_bf[i] + mas[i][j]);
}