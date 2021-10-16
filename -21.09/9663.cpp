//https://www.acmicpc.net/problem/9663

/*
이렇게 짜면 되겠지? 싶었던 N퀸...
사실 유명한 문제라 여러번 남의 코드를 봐왔기에 한번에 풀어버렸다...
백트래킹 공부의 시작...

그래도 포인트가 있다면,
1. N퀸 특성상 가로줄 하나에 퀸 하나니까 1차원 배열로도 풀린다
2. 스택에 넣기전에 유망성검사를 해야한다(backtracking의 기본)
3. 배열 하나로 돌려막지만, 결국 검사할때 범위 제한을 걸어서 굳이 초기화 안함
(한번 씨게 데여서 신경쓰였다 ^^....)
*/

#include <stdio.h>
#include <stdbool.h>

int map[15];//하나의 가로줄에 여러개가 어차피 못들어간다는 점에서 하나로 하였음
int cnt;
int N;

void solve(int depth);

int main(void) {
	//입력
	scanf("%d", &N);
	
	//풀이
	for(int i=0; i<N; i++) {
		//첫줄 N개가 탐색할 그래프의 루트가 된다.
		map[0] = i;
		solve(1);
	}
	
	//출력
	printf("%d\n", cnt);
	return 0;
}

void solve(int depth) {
	if(depth == N)	{ //종료조건
		cnt++;
		//map을 정리하지 않은 이유는, 어차피 검사할 때, depth아래로만 보니까.
		return;
	}
	
	for(int i=0; i<N; i++) {//스택에 넣기전에 넣을 수 있는지
		bool promising = true;
		for(int d=0; d<depth; d++) {
			if(map[d] == i ||//직선으로 내릴 때
			   map[d] + d == i + depth ||//대각선1
			   map[d] - d == i -depth) {//대각선2
				promising = false;
				break;
			}
		}
		//유망한 노드라면,
		if(promising) {
			map[depth] = i;
			solve(depth + 1);
		}
	}
}