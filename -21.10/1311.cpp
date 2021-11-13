//https://www.acmicpc.net/problem/1311

#define INT_MAX 200000

#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

int N;
int cost[20][20];//who, work
int dp[20][1<<20];

int dfs(int curr, int state);
	
int main(void) {
	//입력
	scanf("%d", &N);
	for(int who=0; who<N; who++) {
		for(int work=0; work<N; work++) {	
			scanf("%d", &cost[who][work]);
		}
	}
    memset(dp, -1, sizeof(dp));
	
	//풀이 --> 재귀를 이용한 브루트포스를 DP+비트마스크로 최적화
	//출력
	printf("%d\n", dfs(0,0));
	return 0;
}

int dfs(int curr, int state) {
	//종료조건: 범위를 넘어가거나, 이미 memo가 있거나
	if(state == ((1<<N) - 1) && curr == N) return 0;
	if(dp[curr][state] != -1)  return dp[curr][state];
	
	//dp 점화식
	dp[curr][state] = INT_MAX;
	for(int i=0; i<N; i++) {
		if((state & (1<<i)) == 0) {
			dp[curr][state] = min(dfs(curr + 1, (state | (1<<i))) + cost[curr][i], dp[curr][state]);
		}
	}
	return dp[curr][state];
}