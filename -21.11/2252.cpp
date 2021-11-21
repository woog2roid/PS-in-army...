//https://www.acmicpc.net/problem/2252

#include <stdio.h>
#include <stdbool.h>
#include <queue>
#include <vector>
using namespace std;

vector<int> fromTo[32001];
int degree[32001];

int ans[32000];

int main(void) {
	//입력
	int N, M;
	scanf("%d %d", &N, &M);
	for(int i=0; i<M; i++) {
		int from, to;	
		scanf("%d %d", &from, &to);
		//printf("%d %d\n", from ,to);
		fromTo[from].push_back(to);
		degree[to]++;
		//printf("to::: %d\n", to);
	}
	
	//풀이
	//일단 차수가 0인거 넣고
	queue<int> q;
	for(int i=1; i<=N; i++) {
		if(degree[i] == 0) {
			q.push(i);
		}
	}
	
	for(int cnt=0; cnt<N; cnt++) {
		int curr = q.front();
		q.pop();
		ans[cnt] = curr;
		//printf("cnt: %d curr:%d\n", cnt, curr);
		
		for(int i=0; i<fromTo[curr].size(); i++) {
			degree[fromTo[curr][i]]--;
			if(degree[fromTo[curr][i]] == 0) {
				q.push(fromTo[curr][i]);
			}
		}
	}
	
	//출력
	for(int i=0; i<N; i++) {
		printf("%d ", ans[i]);
	}
	printf("\n");
	return 0;
}