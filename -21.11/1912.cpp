//https://www.acmicpc.net/problem/1912

#include <stdio.h>
#include <algorithm>
using namespace std;

int arr[100000];
int dp[100000];

int main(void) {
	//입력
	int n;
	scanf("%d", &n);
	for(int i=0; i<n; i++) {
		scanf("%d", &arr[i]);
	}
	
	//풀이
	dp[0] = arr[0];
	for(int i=1; i<n; i++) {
		dp[i] = max(dp[i-1] + arr[i], arr[i]);
	}
	
	//출력
	int ans = -123457890;
	for(int i=0; i<n; i++) {
		if(ans < dp[i]) ans = dp[i];
	}
	printf("%d\n", ans);
	return 0;
}