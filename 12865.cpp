//https://www.acmicpc.net/problem/12865

#include <stdio.h>

int N, K;
int weight[101];
int value[101];
int res[100001][101];

int max(int a, int b) {
 	int res;
	if(a >= b) res = a;
	else res = b;
	return res;
}

int main(void) {
	//입력
	scanf("%d %d", &N, &K);
	for(int i=1; i<=N; i++) {
		scanf("%d %d", &weight[i], &value[i]);
	}
	
	//풀이
	for(int i=1; i<=N; i++) {
		for(int j=0; j<=K; j++) {
			if(j - weight[i] >= 0) {
				res[j][i] = max(res[j][i - 1], res[j-weight[i]][i-1] + value[i]);
			} else {
				res[j][i] = res[j][i - 1];
			}
		}
	}
	
	/*
	//체크
	for(int i=1; i<=K; i++) {
		printf("%d ", res[i][N]);
	}
	printf("\n");
	*/
	
	//출력
	printf("%d\n", res[K][N]);
	return 0;
}