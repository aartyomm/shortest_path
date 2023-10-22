#pragma once
#include"consts.h"

void dijkstra(int start, int(&mas)[SIZE][SIZE], int n, int(&dist)[SIZE]);

void bellmanford(int start, int(&mas)[SIZE][SIZE], int n, int(&dist_bf)[SIZE]);