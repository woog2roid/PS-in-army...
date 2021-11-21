//https://www.acmicpc.net/problem/3665

#include <stdio.h>
#include <queue>
#include <vector>
using namespace std;
//n개의 정수 ti를 포함하고 있는 한 줄. (1 ≤ ti ≤ n) ti는 작년에 i등을 한 팀의 번호이다. 1등이 가장 성적이 높은 팀이다. 모든 ti는 서로 다르다.


int main(void) {
	int T;
	scanf("%d", &T);
	for(int t=0; t<T; t++) {
		//초기화
		int arr[500], ans[500];
		int degree[501] = {0}; 
		bool adjacent[501][501] = {0};
		
		//입력
		int n, m;
		scanf("%d", &n);
		for(int i=0; i<n; i++) {
			scanf("%d", &arr[i]);
		}
		//adjacent 만들기
		for(int i=0; i<n-1; i++) {
			for(int j=i+1; j<n; j++) {
				adjacent[arr[i]][arr[j]] = 1;
				degree[arr[j]]++;
			}
		}
		scanf("%d", &m);
		for(int i=0; i<m; i++) {
			int from, to;
			scanf("%d %d", &from, &to);
			if(adjacent[to][from]) {
				adjacent[to][from] = 0;
				adjacent[from][to] = 1;
				degree[from]--;
				degree[to]++;
			} else {
				adjacent[to][from] = 1;
				adjacent[from][to] = 0;
				degree[from]++;
				degree[to]--;
			}
		}
		
		/*
		//체크
		for(int i=0; i<n; i++) {
			printf("%d ", degree[i]);
		}
		printf("\n");
		for(int i=1; i<=n; i++) {
			for(int j=1; j<=n; j++){
				printf("%d ", adjacent[i][j]);
			}
			printf("\n");
		}
		*/
		
		//풀이
		queue<int> q;
		for(int i=1; i<=n; i++) {
			if(degree[i] == 0) {
				q.push(i);
			}
		}
		
		bool promising = true;
		for(int i=0; i<n; i++) {
			/*
			for(int j=0; j<n; j++) {
				printf("%d ", degree[j]);
			}
			printf("\n");
			*/
			
			if(q.size() > 1) {
				printf("?\n");
				promising = false;
				break;
			}
			if(q.empty()) {
				printf("IMPOSSIBLE\n");
				promising = false;
				break;
			}
			
			int curr = q.front();
			q.pop();
			ans[i] = curr;
			//printf("%d\n", curr);
			
			for(int j=1; j<=n; j++) {
				if(adjacent[curr][j] == 1) {
					//printf("!!\n");
					degree[j]--;
					if(degree[j] == 0) {
						q.push(j);
					}
				}
			}
		}
		
		//출력
		if(promising) {
			for(int i=0; i<n; i++) {
				printf("%d ", ans[i]);
			}
			printf("\n");
		}
	}
}