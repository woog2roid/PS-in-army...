//https://www.acmicpc.net/problem/1003

#include <stdio.h>

int dp0[41];
int dp1[41];
int main(void) {
	//풀이
	dp0[0] = 1;
	dp1[1] = 1;
	for(int i=2; i<41; i++) {
		dp0[i] = dp0[i-1] + dp0[i-2];
		dp1[i] = dp1[i-1] + dp1[i-2];
	}
	
	//출력
	int reps;
	scanf("%d", &reps);
	for(int i=0; i<reps; i++) {
		int num;
		scanf("%d", &num);
		printf("%d %d\n", dp0[num], dp1[num]);	
	}
}