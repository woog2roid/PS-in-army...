//https://www.acmicpc.net/problem/11286

#include <stdio.h>
#include <queue>
#include <utility>

using namespace std;

priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

int abs(int num) {
	if(num > 0) return num;
	else return num * -1;
};

int main(void) {
	//입력
	int N;
	scanf("%d", &N);
	for(int i=0; i<N; i++) {
		int input;
		scanf("%d", &input);
		
		if(input == 0) {
			if(pq.size() == 0) {
				printf("0\n");
			}
			else {
				printf("%d\n", pq.top().second);
				pq.pop();
			}
		}
		else {
			pq.push(make_pair(abs(input), input));
		}
	}
}