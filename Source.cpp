#include <iostream>
#include <queue>
#include <functional>
#include <cstring>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <vector>


using namespace std;

#pragma warning(disable:4996)£»

#define MAX 100001
#define totalFarm 101

int node[totalFarm];
int trnode[MAX];
int matrix[totalFarm][totalFarm];
bool isAdd[totalFarm];

int main() {
	int N = 0;
	while (scanf("%d", &N) != EOF) {

		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				scanf("%d", &matrix[i][j]);
			}
		}



		for (int i = 2; i <= N; i++) {
			node[i] = MAX;
		}
		node[1] = 0;
		for (int i = 1; i <= N; i++) {
			isAdd[i] = false;
		}

		for (int i = 1; i <= N; i++) {
			trnode[node[i]] = i;
		}
		int trueNumber = 1;

		int minmum = 0;
		int u = 1;
		isAdd[u] = true;
		while (trueNumber != N) {



			for (int i = 1; i <= N; i++) {
				if (isAdd[i] == true)
					continue;
				if (node[i] > matrix[u][i]) {
					node[i] = matrix[u][i];
					trnode[node[i]] = i;
				}
			}

			int minn = MAX;
			for (int i = 1; i <= N; i++) {
				if (isAdd[i] == true)
					continue;
				if (node[i] < minn) {
					minn = node[i];
					u = i;
				}
			}
			isAdd[u] = true;
			minmum = minmum + minn;

			trueNumber++;


		}
		printf("%d\n", minmum);

	}

	return 0;

}
