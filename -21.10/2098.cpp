//https://www.acmicpc.net/problem/2098

#define INT_MAX 987654321

#include <stdio.h>
#include <algorithm>
#include <string.h>
using namespace std;

int N;
int cost[16][16]; //from to
int dp[16][1<<16]; //어디어디를 방문했을 때, 나머지의 최솟값

int dfs(int curr, int state);

int main(void) {
	//입력
	scanf("%d", &N);
	for(int i=0; i<N; i++) {
		for(int j=0; j<N; j++) {
			scanf("%d", &cost[i][j]);	
		}
	}
	memset(dp, -1, sizeof(dp));
	
	//풀이
	printf("%d\n", dfs(0,1<<0));
	return 0;
}

int dfs(int curr, int state) {
	//printf("?%d %d\n", curr, state);
	//종료조건
	if(state == (1<<N)-1) {
		if(cost[curr][0] != 0) return cost[curr][0];
		else return INT_MAX;
	}
	if(dp[curr][state] != -1) {
		return dp[curr][state];
	}
	
	//풀이
	dp[curr][state] = INT_MAX;
	for(int i=0; i<N; i++) {
		//printf("%d\n", state & (1<<i));
		if(cost[curr][i] == 0) continue;
		if(state & (1<<i)) continue;
		dp[curr][state] = min(dp[curr][state], dfs(i, state | (1<<i)) + cost[curr][i]);
	}
	return dp[curr][state];
}