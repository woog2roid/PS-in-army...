//https://www.acmicpc.net/problem/1904

#include <stdio.h>

int dp[1000001];
int main(void) {
	//입력
	int N;
	scanf("%d", &N);
	
	//풀이
	dp[1] = 1, dp[2] = 2;
	for(int i=3; i<=N; i++) {
		dp[i] = (dp[i-2] + dp[i-1])%15746;
	}
	
	//출력
	printf("%d\n", dp[N]);
	return 0;
}