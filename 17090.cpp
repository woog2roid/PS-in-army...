//https://www.acmicpc.net/problem/17090

#include <stdio.h>
#include <stdbool.h>

int N, M;
char map[500][500];//최대 500자 + NULL
bool res[500][500];
bool visited[500][500];

bool DFS(int n, int m);

int main(void) {
	//입력
	scanf("%d %d ", &N, &M);
	for(int i=0; i<N; i++) {
		for(int j=0; j<M; j++) {
			scanf(" %c", &map[i][j]);
		}
	}
	/*
	//체크
	for(int i=0; i<N; i++) {
		for(int j=0; j<M; j++) {
			printf("%c ", map[i][j]);
		}
		printf("\n");
	}
	*/
	
	//풀이
	//재귀적(DFS)으로 쭉 탐색했다가 다시 돌아오면서 가능한지 체크하는게 좋을듯.
	for(int i=0; i<N; i++) {
		for(int j=0; j<M; j++) {
			if(visited[i][j] == 0) DFS(i, j);
		}
	}
	
	//출력
	/*
	//체크
	for(int i=0; i<N; i++) {
		for(int j=0; j<M; j++) {
			printf("%d ", res[i][j]);
		}
		printf("\n");
	}
	*/
	
	int ans = 0;
	for(int i=0; i<N; i++) {
		for(int j=0; j<M; j++) {
			if(res[i][j] == 1) ans++;
		}
	}
	printf("%d\n", ans);
	return 0;
}

bool DFS(int n, int m) {
	if(!((0<=n) && (n<N) && (0<=m) && (m<M))) {//안에 없으면, 끝내고
		return true;
	} else if(visited[n][m] == 1) { //안에 있으면, 메모이제이션 한거 확인
		return res[n][m];
	} else {
		visited[n][m] = 1;
		
		if(map[n][m] == 'U') {
			res[n][m] = DFS(n-1, m);
		} else if(map[n][m] == 'R') {
			res[n][m] = DFS(n, m+1);
		} else if(map[n][m] == 'D') {
			res[n][m] = DFS(n+1, m);
		} else if(map[n][m] == 'L') {
			res[n][m] = DFS(n, m-1);
		}

		return res[n][m];		
	}
}