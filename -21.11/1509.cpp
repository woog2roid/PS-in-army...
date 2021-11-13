//https://www.acmicpc.net/problem/1509

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int min(int a, int b) {
	if(a <= b) return a;
	else return b;
}

char str[2500 + 1];//NULL
bool isPalindrome[2500][2500];
int dp[2500];

int main(void) {
	//입력
	int length;
	scanf("%s", str);
	for(length=0; str[length]!=0; length++) ;
	
	//풀이
	//테이블 초기화
	for(int i=0; i<2500; i++) {
		isPalindrome[i][i] = 1;
	}
	//boolean 테이플 만들기
	for(int gap=1; gap<length; gap++) {
		for(int start=0; start<length - gap; start++) {
			int end = start + gap;
			if(str[start] == str[end]) { //앞 뒤가 같다면,
				//검사하고 1 주자.
				if(start+1 < end-1) isPalindrome[start][end] = isPalindrome[start + 1][end - 1];
				else isPalindrome[start][end] = 1;
			}
		}
	}
	//dp 채우기
	dp[0] = 1;
	for(int i=0; i<=length; i++) {
		//기본값
		bool isTherePalindrome = false;
		dp[i] = dp[i-1] + 1;
		
		for(int start=0; start<i; start++) {
			if(isPalindrome[start][i]) {
				isTherePalindrome = true;
				if(start-1 >= 0)
					dp[i] = min(dp[i], dp[start - 1] + 1);
				if(start-1 == -1 )
					dp[i] = 1;
			}
			else continue;
		}
		if(isTherePalindrome == false) {
			dp[i] = dp[i-1] + 1;
		}
	}
	
	//출력
	/*
	for(int i=0; i<length; i++) {
		printf("%d\n", dp[i]);
	}
	*/
	printf("%d\n", dp[length-1]);
	return 0;
}