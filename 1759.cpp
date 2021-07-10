//https://www.acmicpc.net/problem/1759

/*
얘도 어려움 없이 풀었음... BFS, DFS, 구현문제를 노가다식으로 익숙해지도록 많이 푼게 구현에 큰 도움이 된 듯.
*/


#include <stdio.h>
#include <stdbool.h>
#include <algorithm>
using namespace std;

int L, C;	
char arr[15];
char res[15];
char aeiou[5] = {'a', 'e', 'i', 'o', 'u'};

void solve(int depth, int idx); //idx는 여태까지 쓴 것중 제일 큰 알파벳

int main(void) {
	//입력
	scanf("%d %d", &L, &C);
	for(int i=0; i<C; i++) {
		scanf(" %c", &arr[i]);
	}
	/* //입력확인
	for(int i=0; i<C; i++) {
		printf("%c", arr[i]);
	}
	printf("!!!!!\n");
	*/
	sort(arr, arr+C);//사전식 출력을 위해
	
	//풀이 & 출력 동시에
	for(int i=0; i<C - L + 1; i++) {
		//범위에 주의! 어차피 첫줄이라 그냥 이렇게 했음,,,
		res[0] =arr[i];
		solve(1, i);
	}
}

void solve(int depth, int idx) {
	if(depth == L) { //종료
		//모음, 자음 갯수 검사
		int cnt = 0;
		for(int i=0; i<L; i++) {
			for(int j=0; j<5; j++){
				if(res[i] == aeiou[j]) {
					cnt++;
				}	
			}
		}
		if(cnt >= 1 && L - cnt >=2) {
			//조건 충족하면 출력
			for(int i=0; i<L; i++) {
				printf("%c", res[i]);
			}
			printf("\n");	
		}		
	}

	for(int i=idx + 1; i<C; i++) {
		if(C - i >= L - depth) {
			res[depth] = arr[i];
			solve(depth + 1, i);
		}
	}
}