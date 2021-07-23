//https://www.acmicpc.net/problem/1520
/*
DFS를 이용해야 된다고 생각이 들었음
BFS는 안되는 이유 --> 넓이우선탐색이라서 그런지 최단거리 위주로 카운팅할듯
DFS로 조금 돌아가더라도 목표지점까지 얼마나 가는지가 더 중요하니까 ㅇㅇ
*/
#include <stdio.h>
#include <stdbool.h>

int M, N;
int map[500][500];
int dp[500][500];
//-1이면 미탐색, dp[a][b]은 a,b에서 도착지점까지 가는 방법의 갯수 

int nextM[] = {1, -1, 0, 0};
int nextN[] = {0, 0, 1, -1};

bool check(int m, int n) {
	return (0 <= m && m < M) && (0 <= n && n < N);	
}
int DFS(int m, int n);

int main(void) {
	//입력
	scanf("%d %d", &M, &N);
	for(int i=0; i<M; i++) {
		for(int j=0; j<N; j++) {
			dp[i][j] = -1;
			scanf("%d", &map[i][j]);
		}
	}
	
	//풀이
	dp[M-1][N-1] = 1;
	for(int i=M-1; i>=0; i--) {
		for(int j=N-1; j>=0; j--) {
			if(dp[i][j] == -1) {
				DFS(i,j);
			}
		}	
	}
	
	/*
	//체크
	for(int i=0; i<M; i++) {
		for(int j=0; j<N; j++) {
			printf("%d ",dp[i][j]);
		}
		printf("\n");
	}
	*/
	
	//출력
	printf("%d\n", dp[0][0]);
	return 0;
}

int DFS(int m, int n) {
	//종료조건
	if(dp[m][n] != -1) { //어 나 여기 와봤는데?
		return dp[m][n];
	} 
	
	//일단 들어왔으면, visited처리
	dp[m][n] = 0;
		
	//DFS돌리기
	for(int i=0; i<4; i++) {
		int tmpM = m+nextM[i], tmpN=n+nextN[i];
		if(check(tmpM,tmpN) && map[m][n] > map[tmpM][tmpN]) {
			dp[m][n] += DFS(tmpM, tmpN);
		}
	}
	
	return dp[m][n];
}