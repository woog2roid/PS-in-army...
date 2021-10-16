//https://www.acmicpc.net/problem/14889

#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

int N;
int map[20][20];
int ans = INT_MAX;
int team[10];

bool isIn(int idx);
void solve(int depth);

int main(void) {
	//입력
	scanf("%d", &N);
	for(int i=0; i<N; i++) {
		for(int j=0; j<N; j++) {
			scanf("%d", &map[i][j]);
		}
	}
	
	/*풀이:
		N/2명만 다 다르게 고르면 된다. 나머지는 나머지팀에 넣기!
		--> 총 경우의 수에서, 절반만 세자.. 0번 정해놓고 나머지 오름차순 (이건 프로그래밍적이 아닌 수학적인 방법아닌가?)
	*/
	team[0] = 0;
	solve(1);
	
	//출력
	printf("%d\n", ans);
	return 0;
}

void solve(int depth) {
	if(depth == N/2) {
		/*
		//체크
		for(int i=0; i<depth; i++) {
			printf("%d", team[i]);
		}
		printf("\n");
		*/
		
		int team1 = 0, team2 = 0;
		//시간 초과 뜬다면 for문 최적화할것!
		for(int i=0; i<N; i++) {
			for(int j=i; j<N; j++) {
				if(isIn(i) == true && isIn(j) == true){
					team1 += (map[i][j] + map[j][i]);
				}
				else if(isIn(i) == false && isIn(j) == false) {
					team2 += (map[i][j] + map[j][i]);
				}
			}
		}
		int res = team1 - team2;
		if(res < 0) res *= -1;
		
		if(res < ans) ans = res;
		return;
	}
	
	//시간 초과 뜬다면 for문 최적화할것!
	for(int i=team[depth - 1] + 1; i<N; i++) {
		team[depth] = i;
		solve(depth + 1);
	}
	return;
}

bool isIn(int idx) {
	for(int i=0; i<N/2; i++) {
		if(team[i] == idx) return true;
	}
	return false;
}