//https://www.acmicpc.net/problem/12852

#include <stdio.h>
#include <stack>

using namespace std;

int dp[1000000];
int before[1000000];

int main(void) {
	//입력
	int num;
	scanf("%d", &num);
	
	//풀이(TOP-DOWN 다이내믹 프로그래밍)
	for(int i=0; i<num; i++) dp[i] = -1;
	dp[num] = 0;
	for(int i=num; i>=1; i--) {
		if(i % 3 == 0) {
			if(dp[i / 3] == -1 || dp[i / 3] > dp[i] + 1) {
				dp[i / 3] = dp[i] + 1;
				before[i / 3] = i;
			}
		}
		if(i % 2 == 0) {
			if(dp[i / 2] == -1 || dp[i / 2] > dp[i] + 1) {
				dp[i / 2] = dp[i] + 1;
				before[i / 2] = i;
			}
		}
		if(true) {
			if(dp[i - 1] == -1 || dp[i - 1] > dp[i] + 1) {
				dp[i - 1] = dp[i] + 1;
				before[i - 1] = i;
			}
		}
	}
	
	/*
	//테스트
	printf("array:");
	for(int i=num; i>=1; i--) {
		printf("%d ", dp[i]);
	}
	printf("\n");
	*/
	
	//출력
	int res = dp[1];
	printf("%d\n", res);
	
	stack<int> s;
	s.push(1);
	while(true) {
		int tmp = before[s.top()];
		if(tmp == 0) break;
		if(tmp == num) {
			s.push(num);
			break;
		}
		s.push(before[s.top()]);
	}
	while(!s.empty()) {
		printf("%d ", s.top());
		s.pop();
	}
}