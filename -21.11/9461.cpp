//https://www.acmicpc.net/problem/9461
//1 1 1 2 2 3 4 5 7 9

#include <stdio.h>
long long int dp[101];

int main(void) {
	dp[1] = 1, dp[2]=1, dp[3]=1, dp[4]=2, dp[5]=2;
	for(int i=6; i<101; i++) {
		dp[i] = dp[i-5] + dp[i-1];
	}
	
	int T;
	scanf("%d", &T);
	for(int t=0; t<T; t++) {
		//입력
		int n;
		scanf("%d", &n);
		
		//출력
		printf("%lld\n", dp[n]);
	}
	return 0;
}