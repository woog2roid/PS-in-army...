//https://www.acmicpc.net/problem/1929

#include <stdio.h>
#include <stdbool.h>
#include <math.h>

bool isSosu[1000001]; //1-1000000의 정수 필요

int main(void) {
	//입력
	int min, max;
	scanf("%d %d", &min, &max);
	for(int i=0; i<1000001; i++) isSosu[i] = 1;
	isSosu[0] = 0;
	isSosu[1] = 0;
	
	//에라토스테네스의 체 "제대로" 구현하기
	for(int i=2; i<=sqrt(max); i++) {
		if(isSosu[i] == 0) continue;//이미 소수가 아니라고 체크됨
		
		for(int j=i*2; j<=max; j += i) {
			isSosu[j] = 0;
		}
	}
	
	//출력
	for(int i=min; i<=max; i++) {
		if(isSosu[i] == 1) {
			printf("%d\n", i);
		}
	}
	return 0;
}