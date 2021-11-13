//https://www.acmicpc.net/problem/14939

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

char map[10][10];
char tmp[10][10];

//눌렀을 때 바뀌는 것
int nextX[5] = {0, 1, -1, 0, 0};
int nextY[5] = {0, 0, 0, 1, -1};
void toggleSwitch(int num);

bool isAllOff() {
	for(int i=9; i>=0; i--) {
		for(int j=9; j>=0; j--) {
			if(tmp[i][j] == 'O') {
				return false;
			}
		}
	}
	return true;
}

int main(void) {
	//입력
	for(int i=0; i<10; i++) {
		for(int j=0; j<10; j++) {
			scanf(" %c", &map[i][j]);
		}
	}
	
	//풀이
	int res = 100;
	//2^10만큼(맨 위의 가능한 갯수만큼) 반복
	int state = 1<<10;
	for(int i=0; i<state; i++) {
		//초기화
		int cnt = 0;
		memcpy(tmp, map, sizeof(map));
		
		//맨위 다 돌리기
		for(int j=0; j<10; j++) {
			if(i & (1<<j)) {
				toggleSwitch(j);
				cnt ++;
			}
		}
		// 맨위 다 돌린다음에, 
		for(int x=1; x<10; x++) {
			for(int y=0; y<10; y++) {
				if(tmp[x-1][y] == 'O') {
					toggleSwitch((x*10) + y);
					cnt ++;
				}
			}
		}
		
		if(isAllOff()) {
			if(cnt < res) res = cnt;
		}
	}
	
	//출력
	printf("%d\n", res);
	return 0;
}

void toggleSwitch(int num) {
	int x=num/10, y=num%10;
	for(int i=0; i<5; i++) {
		int toggleX = x+nextX[i], toggleY = y+nextY[i];
		if(toggleX >= 0 && toggleX < 10 && toggleY >= 0 && toggleY < 10) {
			if(tmp[toggleX][toggleY] == '#') tmp[toggleX][toggleY] = 'O';
			else if(tmp[toggleX][toggleY] == 'O') tmp[toggleX][toggleY] = '#';
		}
	}
}