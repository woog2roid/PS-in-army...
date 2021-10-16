//https://www.acmicpc.net/problem/2661

/*
문자열을 비교하는 것을 c의 한계 때문에 직접 갯수를 세가면서 짰다.
범위를 잘 못 생각해서 시간 좀 버린문제....
*/
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int N;
int res[80];

void solve(int depth);
bool check(int depth);

int main(void) {
	//입력
	scanf("%d", &N);
	
	//풀이 및 출력
	res[0] = 1;
	solve(1);
}

void solve(int depth) {
	//종료
	if(depth == N) {
		for(int i=0; i<N; i++) {
			printf("%d", res[i]);
		}
		printf("\n");
		exit(0); //프로그램 강제종료
	}
	
	//풀이
	for(int i=1; i<=3; i++) {
		res[depth] = i;
		if(check(depth + 1)) {
			res[depth] = i;
			solve(depth + 1);
		}
	}
}

bool check(int depth) {
	for(int len=1; len<=depth/2; len++) {//길이 정하고
		for(int idx=0; idx+ 2*len -1 < depth; idx++) {//위치 잡고
			bool promising = false;
			for(int i=idx; i<idx+len; i++) {//문자열 겹치냐?
				if(res[i] != res[len + i]) {
					promising = true;
					break;
				}
			}
			if(promising == false) {
				return false;
			}
		}
	}
	return true;
}