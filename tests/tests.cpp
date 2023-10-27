#include"tests.h"
#include"generator.h"
#include"algorithm.h"

#include<iostream>
#include<algorithm>
#include<chrono>
#include<stdlib.h>
#include<time.h>

void dijtest3132(int(&mas)[SIZE][SIZE], int num) {
	int q = 1, r = 1000000;
	int dist[SIZE];
	for (int i = 0; i < SIZE; i++) {
		dist[i] = INF;
	}
	for (int n = num > 1 ? 1 + pow(10, num) : 1; n <= 10001; n += 100) {
		int m;
		switch (num)
		{
		case 0:
			m = n * n / 10;
			break;
		case 1:
			m = n * n;
			break;
		case 2:
			m = 100 * n;
			break;
		case 3:
			m = 1000 * n;
			break;
		default:
			m = 1;
			break;
		}
		int src = GetRandomNumber(0, n - 1);
		generate(mas, n, m, q, r);


		auto begin = std::chrono::steady_clock::now();
		dijkstra(src, mas, n, dist);
		auto end = std::chrono::steady_clock::now();
		auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
		std::cout << n << " " << elapsed.count() << " ms" << std::endl;
	}
}

void dijtest33(int(&mas)[SIZE][SIZE]) {
	int n = 10001;
	int q = 1, r = 1000000;
	int dist[SIZE];
	for (int i = 0; i < SIZE; i++) {
		dist[i] = INF;
	}
	for (int m = 0; m <= 10000000; m += 100000) {
		int src = GetRandomNumber(0, n - 1);
		generate(mas, n, m, q, r);

		auto begin = std::chrono::steady_clock::now();
		dijkstra(src, mas, n, dist);
		auto end = std::chrono::steady_clock::now();
		auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
		std::cout << m << " " << elapsed.count() << " ms" << std::endl;
	}
}

void dijtest34(int(&mas)[SIZE][SIZE], int num) {
	int n = 10001;
	int q = 1;
	int dist[SIZE];
	for (int i = 0; i < SIZE; i++) {
		dist[i] = INF;
	}
	for (int r = 1; r <= 200; r++) {
		int m;
		switch (num)
		{
		case 0:
			m = n * n;
			break;
		case 1:
			m = 1000 * n;
			break;
		default:
			m = 1;
			break;
		}
		int src = GetRandomNumber(0, n - 1);
		generate(mas, n, m, q, r);

		auto begin = std::chrono::steady_clock::now();
		dijkstra(src, mas, n, dist);
		auto end = std::chrono::steady_clock::now();
		auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
		std::cout << r << " " << elapsed.count() << " ms" << std::endl;
	}
}




void bftest3132(int(&mas)[SIZE][SIZE], int num) {
	int q = 1, r = 1000000;
	int dist_bf[SIZE];
	for (int i = 0; i < SIZE; i++) {
		dist_bf[i] = INF;
	}
	for (int n = num > 1 ? 1 + pow(10, num) : 1; n <= 10001; n += 500) {
		int m;
		switch (num)
		{
		case 0:
			m = n * n / 10;
			break;
		case 1:
			m = n * n;
			break;
		case 2:
			m = 100 * n;
			break;
		case 3:
			m = 1000 * n;
			break;
		default:
			m = 1;
			break;
		}
		int src = GetRandomNumber(0, n - 1);
		generate(mas, n, m, q, r);

		auto begin = std::chrono::steady_clock::now();
		bellmanford(src, mas, n, dist_bf);
		auto end = std::chrono::steady_clock::now();
		auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
		std::cout << n << " " << elapsed.count() << " ms" << std::endl;
	}
}

void bftest33(int(&mas)[SIZE][SIZE]) {
	int n = 10001;
	int q = 1, r = 1000000;
	int dist_bf[SIZE];
	for (int i = 0; i < SIZE; i++) {
		dist_bf[i] = INF;
	}
	for (int m = 0; m <= 10000000; m += 100000) {
		int src = GetRandomNumber(0, n - 1);
		generate(mas, n, m, q, r);

		auto begin = std::chrono::steady_clock::now();
		bellmanford(src, mas, n, dist_bf);
		auto end = std::chrono::steady_clock::now();
		auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
		std::cout << m << " " << elapsed.count() << " ms" << std::endl;
	}
}

void bftest34(int(&mas)[SIZE][SIZE], int num) {
	int n = 10001;
	int q = 1;
	int dist_bf[SIZE];
	for (int i = 0; i < SIZE; i++) {
		dist_bf[i] = INF;
	}
	for (int r = 1; r <= 200; r++) {
		int m;
		switch (num)
		{
		case 0:
			m = n * n;
			break;
		case 1:
			m = 1000 * n;
			break;
		default:
			m = 1;
			break;
		}
		int src = GetRandomNumber(0, n - 1);
		generate(mas, n, m, q, r);

		auto begin = std::chrono::steady_clock::now();
		bellmanford(src, mas, n, dist_bf);
		auto end = std::chrono::steady_clock::now();
		auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
		std::cout << r << " " << elapsed.count() << " ms" << std::endl;
	}
}