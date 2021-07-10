//https://www.acmicpc.net/problem/15651

#include <stdio.h>

int N, M;
int res[7];

void solve(int depth);

int main(void) {
	//입력
	scanf("%d %d", &N, &M);
	
	//풀이 및 출력
	for(int i=1; i<=N; i++) {
		res[0] = i;
		solve(1);
	}
	return 0;
}

void solve(int depth) {
	if(depth == M) {
		for(int i=0; i<M; i++) {
			printf("%d ", res[i]);
		}
		printf("\n");
		return;
	}
	
	for(int i=1; i<=N; i++) {
		res[depth] =i;
		solve(depth + 1);
	}
}