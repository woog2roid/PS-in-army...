//https://www.acmicpc.net/problem/2667
/*
총평: 어렵진 않았지만, 오랜만에 구현이라 시간이 걸린문제
실수한 점들
1. continue를 break로 작성해서 오래걸림,
2. check함수 만들 때 조건 실수 했음
3. sort 범위 실수: sort(범위의 시작점, 범위의 끝점 + 1);

4!!! 이 문제가 오래걸린이유... 25자리라 int, 심지어 long long으로도 못 받는다..... 문자로 받았어야 함
*/
#include <stdio.h>
#include <algorithm>
#include <queue>
using namespace std;

int N;
int map[25][25];
bool visited[25][25];
int nextX[] = {0, 0, 1, -1};
int nextY[] = {1, -1, 0, 0};
bool check(int x, int y) {
	return (0 <= x && x < N) && (0 <= y && y < N) && map[x][y] == 1&& visited[x][y] == 0;
}

int main(void) {
	//입력
	scanf("%d", &N);
	char map2[25][26];
	for(int i = 0; i < N; i++) {
		scanf("%s", &map2[i]);
	}
	for(int i=0; i<N; i++) {
		for(int j=0; j<N; j++) {
			map[i][j] = map2[i][j] - 48;
		}
	}
	
	/*
	for(int i=0; i<N; i++) {
		for(int j=0; j<N; j++) {
			printf("%d", map[i][j]);
		}
		printf("\n");
	}
	*/

	//풀이:BFS
	int ans[625], ansCnt = 0, size = 1;
	for(int i=0; i<N; i++) {
		for(int j=0; j<N; j++) { //다 찾아볼건데,
			//printf("%d%d\n", i,j);
			if(visited[i][j] == 1|| map[i][j] == 0) continue;
			//이미 방문했거나, 집이 아니면 탈출
			
			queue<pair<int, int>> q;
			q.push(make_pair(i,j));
			visited[i][j] = 1;
			while(!q.empty()) {
				int currX = q.front().first;
				int currY = q.front().second;
				//printf("%d %d\n", currX, currY);
				q.pop();
				for(int k=0; k<4; k++) {
					if(check(currX + nextX[k], currY + nextY[k])) {
						q.push(make_pair(currX + nextX[k], currY + nextY[k]));
						visited[currX + nextX[k]][currY + nextY[k]] = 1;
						size++;
					}
				}	
			}
			ans[ansCnt] = size;
			ansCnt++;
			size = 1;
		}
	}
	
	/*
	//체크
	for(int i=0; i<N; i++) {
		for(int j=0; j<N; j++) {
			printf("%d", map[i][j]);
		}
		printf("\n");
	}
	*/
	
	//출력
	sort(ans, ans + ansCnt);
	printf("%d\n", ansCnt);
	for(int i=0; i<ansCnt; i++) {
		printf("%d\n", ans[i]);
	}
	return 0;
}