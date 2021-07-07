//https://www.acmicpc.net/problem/7569
/*
BFS나 이런 좌표 문제를 풀때 괜히 내가 x,y,z를 정하지 말고 문제에서 준대로 따라가자...
--> 괜히 헷갈리고 시간낭비가 너무 심하다...

+ check함수는 항상 조건 확인을 잘 할것!

// 그래도 한번에 풀어서 기분이 좋았던 문제
*/

#include <stdio.h>
#include <queue>
using namespace std;

int M, N, H;
int map[100][100][100];
int visited[100][100][100];
int cnt[100][100][100];

typedef struct {
	int x, y, z;
} pos;

int nextX[] = {0, 0, 0, 0, 1, -1};
int nextY[] = {1, -1, 0, 0, 0, 0};
int nextZ[] = {0, 0, 1, -1, 0, 0};
bool check(int x, int y, int z) {
	return (0 <= x && x <M) && (0 <=y && y < N ) && (0 <= z && z < H) &&
		(visited[x][y][z] == 0) && (map[x][y][z] == 0);
}

int main(void) {
	//입력
	scanf("%d%d%d", &M, &N, &H);
	for(int i=0; i<H; i++) {
		for(int j=0; j<N; j++) {
			for(int k=0; k<M; k++) {
				scanf("%d", &map[k][j][i]);
			}
		}
	}
	
	//풀이
	queue<pos> q;
	for(int i=0; i<M; i++) {
		for(int j=0; j<N; j++) {
			for(int k=0; k<H; k++) {
				if(map[i][j][k] == 1 && visited[i][j][k] == 0) {
					pos p;
					p.x = i, p.y=j, p.z=k;
					q.push(p);
					visited[i][j][k] = 1;
					cnt[i][j][k] = 0;
				}
			}
		}
	}
	while(!q.empty()) {
		int currX = q.front().x, currY = q.front().y,
		currZ = q.front().z;
		q.pop();
		for(int i=0; i<6; i++) {
			if(check(currX + nextX[i], currY + nextY[i], currZ + nextZ[i])) {
				pos p;
				p.x = currX + nextX[i], p.y = currY + nextY[i], p.z = currZ + nextZ[i];
				q.push(p);
				visited[p.x][p.y][p.z] = 1;
				cnt[p.x][p.y][p.z] = cnt[currX][currY][currZ] + 1;
			}
		}
	}
	
	//출력
	int max = -1;
	for(int i=0; i<M; i++) {
		for(int j=0; j<N; j++) {
			for(int k=0; k<H; k++) {
				if(visited[i][j][k] == 0 && map[i][j][k] == 0){
					printf("-1\n");
					return 0;
				}
				if(max < cnt[i][j][k]) {
					max = cnt[i][j][k];
				}
			}
		}
	}
	
	printf("%d\n", max);
	return 0;
}