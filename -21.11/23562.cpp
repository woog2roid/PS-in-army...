//https://www.acmicpc.net/problem/23562

#include <stdio.h>
#include <limits.h>

char map[20][20];
int solve(int startN, int startM, int endN, int endM);

int n, m, a, b;
int length, maxLength;
int main(void) {
	//입력
	scanf("%d %d %d %d", &n, &m, &a, &b);
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			scanf(" %c", &map[i][j]);
		}
	}
	
	//풀이 #은 Black, .은 White a는 W->B, b는 B->W
	if(n > m) maxLength = m/3;
	else maxLength = n/3;
	
	int min = INT_MAX;
	for(length=1; length<=maxLength; length++) {
		for(int i=0; i<n-length*3 + 1; i++) {
			for(int j=0; j<m-length*3 + 1; j++) {
				int tmp = solve(i, j, i+length*3, j+length*3);
				if(min > tmp) min = tmp;
			}
		}
	}
	
	//출력
	printf("%d\n", min);
	return 0;
}

int solve(int startN, int startM, int endN, int endM) {
	//printf("%d %d %d %d\n", startN, startM, endN, endM);
	int whiteToBlack=0, blackToWhite=0;
	//위의 대가리 세는중: ㅡ
	for(int i=startN; i<startN+length; i++) {
		for(int j=startM; j<endM; j++) {
			if(map[i][j] == '.') whiteToBlack++;
		}
	}
	//아래 대가리 세는중: ㅡ
	for(int i=startN+2*length; i<endN; i++) {
		for(int j=startM; j<endM; j++) {
			if(map[i][j] == '.') whiteToBlack++;
		}
	}
	//가운데 연결못 세는중: ㅣ
	for(int i=startN+1*length; i<startN+2*length; i++) {
		for(int j=startM; j<startM+length; j++) {
			if(map[i][j] == '.') whiteToBlack++;
		}
	}
	//ㅁ세는 중
	for(int i=startN+1*length; i<startN+2*length; i++) {
		for(int j=startM+length; j<endM; j++) {
			if(map[i][j] == '#') blackToWhite++;
		}
	}
	//나머지 검은색을 흰색으로
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			if(startN<=i && i<endN && startM<=j && j<endM) {
				continue;
			}
			if(map[i][j] == '#') blackToWhite++;
		}
	}
	//printf("%d %d\n", whiteToBlack, blackToWhite);
	
	return (whiteToBlack*a) + (blackToWhite*b);
}