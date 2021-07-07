//https://www.acmicpc.net/problem/7562

/*
중간에 배열 꼭 초기화 해주기 !!!!!
그래도 이정도 문제는 금방 푸는구나!!
*/

#include <stdio.h>
#include <stdbool.h>
#include <queue>
#include <algorithm>
using namespace std;

bool visited[300][300];
int cnt[300][300];

int nextX[] = {-1, -2, -2, -1, 1, 2, 2, 1};
int nextY[] = {2, 1, -1, -2, -2, -1, 1, 2};
bool check(int x, int y, int l) {
	return (0<=x && x<l) && (0<=y && y<l) && (visited[x][y] == 0);
}

int main(void) {
	int reps;
	scanf("%d", &reps);
	for(int r = 0; r < reps; r++) {
		//초기화
		for(int i=0; i<300; i++) {
			for(int j=0; j<300; j++) {
				visited[i][j] = 0;
				cnt[i][j] = 0;
			}
		}
		
		//입력
		int l, startX, startY, endX, endY;
		scanf("%d %d %d %d %d", &l, &startX, &startY, &endX, &endY);
		
		//풀이		
		queue<pair<int,int>> q;
		q.push(make_pair(startX, startY));
		visited[startX][startY] = 1;
		cnt[startX][startY] = 0;
		while(!q.empty()) {
			int currX=q.front().first, currY=q.front().second;
			q.pop();
			for(int i=0; i<8; i++) {
				if(check(currX + nextX[i], currY + nextY[i], l)) {
					q.push(make_pair(currX + nextX[i], currY + nextY[i]));
					visited[currX + nextX[i]][currY + nextY[i]] = 1;
					cnt[currX + nextX[i]][currY + nextY[i]] = cnt[currX][currY] + 1;	
				}
			}
		}
		
		//출력
		printf("%d\n", cnt[endX][endY]);
	}
	return 0;
}