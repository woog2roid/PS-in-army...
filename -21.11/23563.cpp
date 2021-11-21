//https://www.acmicpc.net/problem/23563

#include <stdio.h>
#include <string.h>
#include <deque>
#include <algorithm>
using namespace std;

char map[500][500];
int cnt[500][500];

int dirH[4] = {-1, 1, 0, 0};
int dirW[4] = {0, 0, 1, -1};

bool isOnWall(int currH, int currW, int nextH, int nextW);
bool isOK(int h, int w);

int H, W;
int main(void) {
	//입력
	pair<int, int> start, end;
	scanf("%d %d", &H, &W);
	for(int i=0; i<H; i++) {
		for(int j=0; j<W; j++) {
			scanf(" %c", &map[i][j]);	
			if(map[i][j] == 'S') {
				start.first = i;
				start.second = j;
			}
			if(map[i][j] == 'E') {
				end.first = i;
				end.second = j;
			}
		}
	}
	memset(cnt, -1, sizeof(cnt));
	
	//풀이
	deque<pair<int, int>> dq;
	dq.push_back(make_pair(start.first, start.second));
	cnt[start.first][start.second] = 0;
	
	while(!dq.empty()) {
		int currH = dq.front().first, currW = dq.front().second;
		dq.pop_front();
		
		//출력
		if(currH == end.first && currW == end.second) {
			/*
			//체크
			for(int i=0; i<H; i++) {
				for(int j=0; j<W; j++) {
					printf("%d ", cnt[i][j]);	
				}
				printf("\n");
			}
			*/
			
			printf("%d\n", cnt[currH][currW]);
			return 0;
		}
		
		for(int i=0; i<4; i++) {
			int nextH = currH + dirH[i], nextW = currW + dirW[i];
			if(isOnWall(currH, currW, nextH, nextW)) {
				if(isOK(nextH, nextW) && (cnt[nextH][nextW] > cnt[currH][currW] || cnt[nextH][nextW] == -1)) {
					dq.push_front(make_pair(nextH, nextW));
					cnt[nextH][nextW] = cnt[currH][currW];
				}	
			} else {
				if(isOK(nextH, nextW) && (cnt[nextH][nextW] > cnt[currH][currW] + 1|| cnt[nextH][nextW] == -1)) {
					dq.push_back(make_pair(nextH, nextW));
					cnt[nextH][nextW] = cnt[currH][currW] + 1;
				}	
			}
		}
	}
}

bool isOnWall(int currH, int currW, int nextH, int nextW) {
	bool promising1 = false, promising2 = false;
	for(int i=0; i<4; i++) {
		if(map[currH + dirH[i]][currW + dirW[i]] == '#') {
			promising1 = true;
			break;
		}
	}
	for(int i=0; i<4; i++) {
		if(map[nextH + dirH[i]][nextW + dirW[i]] == '#') {
			promising2 = true;
			break;
		}
	}
	
	return promising1 & promising2;
}

bool isOK(int h, int w) {
	return (0<=h && h<H) && (0<=w && w<W) && (map[h][w]!='#');
}