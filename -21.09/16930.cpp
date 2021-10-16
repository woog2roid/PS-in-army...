//https://www.acmicpc.net/problem/16930

#include <stdio.h>
#include <queue>
#include <stdbool.h>
#include <limits.h>
using namespace std;

int N, M, K;
char map[1001][1001];//index:1-1000
int ans[1001][1001][4];//0:미방문, 1~:숫자세기 + 방향
int startX, startY, endX, endY;

int dirX[] = {-1, 1, 0, 0};
int dirY[] = {0, 0, 1, -1};

typedef struct {
	int x;
	int y;
	int step;
	int dir;
} info;

bool check(int x, int y, int d);

int main(void) {
	//입력
	scanf("%d %d %d", &N, &M, &K);
	for(int i=1; i<=N; i++) {
		for(int j=1; j<=M; j++) {
			scanf(" %c", &map[i][j]);
			//char형 체크했음
		}
	}
	scanf("%d %d %d %d", &startX, &startY, &endX, &endY);

	//풀이
	//3차원 배열로 정답 배열을 만든다.
	//마지막 차원은 방향이 되며, 4방향에서 오는 것은 모두 다르게, (중복처리를 하지 않는다.)
	
	//queue에 초기값 1개 넣기
	queue<info> q;
	info t;
	t.x=startX, t.y=startY, t.step=0, t.dir=-1;
	q.push(t);
	
	while(!q.empty()) {
		info tmp = q.front();
		int currX=tmp.x, currY=tmp.y, currStep=tmp.step, currDir=tmp.dir;
		q.pop();
		for(int i=0; i<4; i++) {
			int nextX = currX + dirX[i];
			int nextY = currY + dirY[i];
			if(check(nextX, nextY, i)) {
				//next 초기화 및 푸시
				info next;
				next.x = nextX, next.y = nextY;
				next.dir = i;
				if(currDir == next.dir)	next.step = currStep + 1;
				else next.step = 0;
				q.push(next);
				
				//ans[][][]에 다음 값 넣을 때, +1을 하지 않는 기준 정하기	
				if(currDir == next.dir && next.step <= K) {
					ans[nextX][nextY][i] = ans[currX][currY][currDir];
				} else {
					ans[nextX][nextY][i] = ans[currX][currY][currDir] + 1;
				}
				//추가로, 다른 방향에서 더 빠르게 온 방법이 있나 확인해보기...?
				for(int j=0; j<4; j++) {
					if(j != currDir && ans[currX][currY][j] != 0) {
						if(ans[nextX][nextY][i] > ans[currX][currY][j] + 1)
							ans[nextX][nextY][i] = ans[currX][currY][j] + 1;
					}
				}
			}
		}
	}

	/*
	//체크
	printf("\n");
	for(int i=1; i<=N; i++) {
		for(int j=1; j<=M; j++) {
			int min = INT_MAX;
			for(int dir=0; dir<4; dir++) {
				if(min > ans[i][j][dir] && ans[i][j][dir] != 0 )
					min = ans[i][j][dir];
			}
			if(min == INT_MAX) printf("- ");
			else printf("%d ", min);
		}
		printf("\n");
	}
	*/

	//출력
	int res = INT_MAX;
	for(int i=0; i<4; i++) {
		if(res > ans[endX][endY][i] && ans[endX][endY][i] != 0)
			res = ans[endX][endY][i];
	}
	if(res == INT_MAX) {
		printf("-1\n");
		return 0;
	} else {
		printf("%d\n", res);
		return 0;
	}
}

bool check (int x, int y, int d) {
	return ((1<=x && x<=N) && (1<=y && y<=M) && (map[x][y] == '.') && (ans[x][y][d] == 0));
}