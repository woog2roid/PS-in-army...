//https://www.acmicpc.net/problem/1927

#include <stdio.h>
#include <queue>

using namespace std;

//내림차순 오름차순 바꾸는 법 알아두기: greater<int>를 넣어야함
//greater<int>를 넣기전에 vector<int>(컨테이너)도 같이 넣어줘야함
priority_queue<int, vector<int>, greater<int>> greaterPQ;

int main() {
	//입력
	int N;
	scanf("%d", &N);
	for(int i=0; i<N; i++) {
		int input;
		scanf("%d", &input);
		
		//풀이
		if(input == 0) {
			if(greaterPQ.size() != 0) {
				printf("%d\n", greaterPQ.top());
				greaterPQ.pop();
			} else {
				printf("0\n");
			}
		}
		else {
			greaterPQ.push(input);
		}
	}
}