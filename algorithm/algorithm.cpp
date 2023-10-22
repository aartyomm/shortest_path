#include"algorithm.h"
#include"consts.h"
#include<vector>
#include<algorithm>

void dijkstra(int start, int(&mas)[SIZE][SIZE], int n, int(&dist)[SIZE]) {
	std::vector<int> was(SIZE, 0);
	dist[start] = 0;
	for (int it = 0; it < n; it++) { //���������� �� ������ �������
		int start = -1;
		for (int i = 0; i < n; i++) //���� ��� ������ ��������� �������
			if (was[i] == 0)
				if (start == -1 || dist[i] < dist[start]) //�������� �� ������� �������. ���� ��� ������ � src, �� ������� ���� ��, ������� �����
					start = i;
		was[start] = 1;
		for (int j = 0; j < n; j++) {
			int fin = j; //���������� �������� �������
			int c = mas[start][j]; //���������� �� ������� ������� �� ������������
			if (c && dist[start] + c < dist[fin]) //���� �� ������������ ������� ���� ���� � ������ ����� ������� ��������, ��� ������, �� ����������� ����� ��������
				dist[fin] = dist[start] + c;
		}
	}
}

void bellmanford(int start, int(&mas)[SIZE][SIZE], int n, int(&dist_bf)[SIZE]) {
	dist_bf[start] = 0;
	for (int k = 1; k < n; k++) //���� �� 1 �����, �� 2, �� 3...
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				if (dist_bf[i] < INF && mas[i][j] != 0)
					dist_bf[j] = std::min(dist_bf[j], dist_bf[i] + mas[i][j]);
}