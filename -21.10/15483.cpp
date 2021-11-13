
//https://www.acmicpc.net/problem/15483

#include <stdio.h>
#include <algorithm>
using namespace std;

//NULL문자 포함
char str1[1000 + 1];
char str2[1000 + 1];
//DP TABLE
int dp[1001][1001];

int main(void) {
	//입력
	scanf("%s", &str1);
	scanf("%s", &str2);
	int length1, length2;
	for(length1=0; str1[length1] != 0; length1++) ;
	for(length2=0; str2[length2] != 0; length2++) ;
	//printf("%s\n%s", str1, str2);
	//printf("%d %d", length1, length2);
	
	//풀이
	for(int i=0; i<=length1; i++) dp[i][0] = i;
	for(int i=0; i<=length2; i++) dp[0][i] = i;
	
	for(int i=0; i<length1; i++) {
		for(int j=0; j<length2; j++) {
			if(str1[i] == str2[j]) { //글자가 같으면,
				//printf("%c %c!\n", str1[i], str2[j]);
				dp[i + 1][j + 1] = dp[i][j];
			}
			else if(str1[i] != str2[j]) { //글자가 다르면,
				dp[i + 1][j + 1] = min(dp[i][j + 1], min(dp[i + 1][j], dp[i][j])) + 1;
			}
		}
	}
	
	//테스트
	/*
	printf("TEST\n");
	for(int i=1; i<=length1; i++) {
		for(int j=1; j<=length2; j++) {
			printf("%d ", dp[i][j]);
		}
		printf("\n");
	}
	*/
	
	//출력
	printf("%d\n", dp[length1][length2]);
	return 0;
}