//https://www.acmicpc.net/problem/1562
//아직 못풀었음
#define MOD 1000000000
#include <cstdio>

//자릿수, 마지막 수, 상태
long long int dp[100][10][1<<10];

int main(void) {
	//입력
	int N;
	scanf("%d", &N);
	
	//풀이:상태가 꼭 다 차있지 않아도, "계단수"만 만족하면 갯수로 센다.
	//초기화
	for(int i=1; i<10; i++) {
		dp[0][i][1<<i] = 1;
	}
	//BOTTOM-UP
	for(int length=1; length<N; length++) {
		for(int last=0; last<10; last++) {
			for(int state=0; state < (1<<10); state++) {
				if(last == 0)
					dp[length][last][state | (1<<last)] += (dp[length-1][last+1][state] % MOD);
				else if(last == 9)
					dp[length][last][state | (1<<last)] += (dp[length-1][last-1][state] % MOD);
				else{
					dp[length][last][state | (1<<last)] += (dp[length-1][last-1][state] % MOD);
					dp[length][last][state | (1<<last)] += (dp[length-1][last+1][state] % MOD);
				}
			}
		}
	}
	
	//출력
	long long int res = 0;
	for(int i=0; i<10; i++) {
		res += (dp[N - 1][i][(1<<10) - 1] % MOD);
		//printf("%d번째: %d\n", i, dp[N-1][i][(1<<10) -1]);
	}
	printf("%lld\n", res%MOD);
	return 0;
}