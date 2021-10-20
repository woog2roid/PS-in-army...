//https://www.acmicpc.net/problem/17404

#define INT_MAX 987654321

#include <stdio.h>
#include <algorithm>
using namespace std;

int N;
int cost[1000][3];//RGB
int dp[1000][3];
//처음에 뭔색? 지금 어디? 지금 무슨색?

//앞뒤와 색이 달라야함, 1번은 n,2 n번은 n-1,1
int main(void) {
	//입력
	scanf("%d", &N);
	for(int i=0; i<N; i++) {
		scanf("%d %d %d", &cost[i][0], &cost[i][1], &cost[i][2]);
	}
	
	//풀이: 걍 처음 집 빨간색으로 칠했다 치자 ㅋㅋ
	dp[0][0] = cost[0][0], dp[0][1] = INT_MAX, dp[0][2] = INT_MAX; 
	for(int i=1; i<N; i++) {
		for(int color=0; color<3; color++) {
			dp[i][color] = min(dp[i-1][(color + 1)%3], dp[i-1][(color + 2)%3]) + cost[i][color];
		}
	}
	int ans = min(dp[N-1][1], dp[N-1][2]);
	/*
	//체크
	printf("%d", min(dp[N-1][1], dp[N-1][2]));
	*/
	
	//처음집 G, B에 대해서 두번 반복
	dp[0][1] = cost[0][1], dp[0][0] = INT_MAX, dp[0][2] = INT_MAX; 
	for(int i=1; i<N; i++) {
		for(int color=0; color<3; color++) {
			dp[i][color] = min(dp[i-1][(color + 1)%3], dp[i-1][(color + 2)%3]) + cost[i][color];
		}
	}
	ans = min(ans, min(dp[N-1][0], dp[N-1][2]));
	
	dp[0][2] = cost[0][2], dp[0][0] = INT_MAX, dp[0][1] = INT_MAX; 
	for(int i=1; i<N; i++) {
		for(int color=0; color<3; color++) {
			dp[i][color] = min(dp[i-1][(color + 1)%3], dp[i-1][(color + 2)%3]) + cost[i][color];
		}
	}
	ans = min(ans, min(dp[N-1][1], dp[N-1][0]));
	
	printf("%d\n", ans);
	return 0;
}