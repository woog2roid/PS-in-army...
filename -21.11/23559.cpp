//https://www.acmicpc.net/problem/23559

#include <stdio.h>
#include <algorithm>
using namespace std;

int A[100000], B[100000];
pair<int, int> diff[100000]; //A-B, index

int main(void) {
	//입력
	int N, X;
	scanf("%d %d", &N, &X);
	for(int i=0; i<N; i++) {
		scanf("%d %d", &A[i], &B[i]);
		diff[i].first = (A[i] - B[i]) * -1;
		diff[i].second = i;
	}
	sort(diff, diff+N);
	
	//풀이
	int expensiveCnt = (X - 1000*N)/4000;
	int ans = 0;
	for(int i=0; i<N; i++) {
		int index = diff[i].second;
		if(i < expensiveCnt) {
			if(diff[i].first < 0) ans += A[index];
			else ans += B[index];
		}
		else {
			ans += B[index];
		}
	}
	
	//출력
	printf("%d\n", ans);
	return 0;
}