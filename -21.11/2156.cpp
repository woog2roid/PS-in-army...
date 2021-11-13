//https://www.acmicpc.net/problem/2156
//시간을 보니까 N^2으로 풀릴듯~
#include <stdio.h>
#include <algorithm>
using namespace std;

int arr[10000];
int dp[10000];
int main(void) {
	//입력
	int n;
	scanf("%d", &n);
	for(int i=0; i<n; i++) {
		scanf("%d", &arr[i]);
	}
	
	//풀이
	dp[0] = arr[0];
	dp[1] = arr[0] + arr[1];
	dp[2] = max(dp[0]+arr[2], arr[1]+arr[2]);
	dp[2] = max(dp[2], dp[1]);
	for(int i=3; i<n; i++) {
		dp[i] = max(dp[i-2] + arr[i], dp[i-3] + arr[i-1] + arr[i]);
		dp[i] = max(dp[i], dp[i-1]);
	}
	
	/*
	//체크
	for(int i=0; i<n; i++) {
		printf("%d ", dp[i]);
	}
	printf("\n");
	*/
	
	//출력
	printf("%d\n", dp[n-1]);
	return 0;
}