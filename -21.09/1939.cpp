//https://www.acmicpc.net/problem/1939

#include <stdio.h>
#include <vector>
#include <stdbool.h>
#include <algorithm>
#include <queue>
using namespace std;

int N,M;
bool visited[10001]; //섬이 0부터 시작하지 않음..
vector<pair<int, int>> map[10001];
int start, ends;

bool BFS(int w);

int main(void) {
	//입력
	int maxWeight = -1;
	scanf("%d %d", &N, &M);
	for(int i=0; i<M; i++) {
		//from to에 c(최대 무게)
		int from, to, c;
		scanf("%d %d %d", &from, &to, &c);
		map[from].push_back(make_pair(to, c));
		map[to].push_back(make_pair(from, c));
		if( maxWeight < c) maxWeight = c;
	}
	scanf("%d %d", &start, &ends);

	//풀이
	int left = 0, right = maxWeight;
	int res = -1;
	while( left <= right) {
		//초기화
		for(int i=0; i<10001; i++) visited[i] = 0;
		
		//이분탐색
		int mid = (left + right)/2;
		if(BFS(mid)) { //이정도는 충분히 들지, 무게 올리기
			left = mid + 1;
			if(res < mid) res = mid;
		}
		else { //다리 무너지는데...?
			right = mid - 1;
		}
		/*
		for(int i=0; i<N; i++) {
			printf("%d ", visited[i]);
		}
		printf("\n");
		*/
	}
	
	//출력
	printf("%d\n", res);
	return 0;
}

bool BFS(int w) {
	queue<int> q;
	q.push(start);
	visited[start] = 1;
	
	while(!q.empty()) {
		int curr = q.front();
		q.pop();
			
		for(int i=0; i<map[curr].size(); i++) {
			if(map[curr].at(i).second >= w && 
			   visited[map[curr].at(i).first] == 0) {
				q.push(map[curr].at(i).first);
				visited[map[curr].at(i).first] = 1;
			}
		}
	}
	
	if(visited[ends] == 1) return true;
	else return false;
}