//https://www.acmicpc.net/problem/1644

#include <stdio.h>
#include <stdbool.h>
#include <math.h>

int sosu[4000000];
int filter[4000000];
int main(void) {
	//입력
	int N;
	scanf("%d", &N);
	
	//에라토스테네스의 체에서 "체"의 역할을 할 소수들 찾기
	int n = sqrt(N);
	filter[0] = 2;
	int filterIndex = 0;
	for(int i=2; i<=n; i++) {
		bool isSosu = true;
		for(int j=0; filter[j] < i && filter[j] != 0; j++) {
			if(i % filter[j] == 0) {
				isSosu = false;
				break;
			}
		}
		if(isSosu) {
			filter[filterIndex] = i;
			filterIndex++;
		}
	}
	//체로 거르기
	int sosuIndex = 0;
	for(int i=2; i<=N; i++) {
		bool isSosu = true;
		for(int j=0; j<filterIndex; j++) {
			if(i == filter[j]) {
				break;
			}
			if(i % filter[j] == 0) {
				isSosu = false;
				break;
			}
		}
		if(isSosu) {
			sosu[sosuIndex] = i;
			sosuIndex++;
		}
	}
	
	/*
	//체크
	for(int i=0; i<filterIndex; i++) {
		printf("%d ", filter[i]);
	}
	printf("\n");
	for(int i=0; i<sosuIndex; i++) {
		printf("%d ", sosu[i]);
	}
	printf("\n");
	*/
	
	//풀이
	int res = 0;
	int left = 0, right = 0;
	while(left <= right && right < sosuIndex) {
		int sum = 0;
		for(int i=left; i<=right; i++) {
			sum += sosu[i];
		}
		if(sum > N) left++;
		if(sum < N) right++;
		if(sum == N) {
			res++;
			right++;
		}
	}
	
	//출력
	printf("%d\n", res);
	return 0;
}