//https://www.acmicpc.net/problem/15654

#include <stdio.h>
#include <algorithm>
#include <stdbool.h>
using namespace std;

void backtracking(int depth);

int N, M;
int arr[8];
int res[8];

int main(void) {
	//입력
	scanf("%d %d", &N, &M);
	for(int i=0; i<N; i++) {
		scanf("%d", &arr[i]);
	}
	sort(arr, arr+N);
	
	//풀이
	backtracking(0);
}

void backtracking(int depth) {
	//출력 (종료조건)
	if(depth == M) {
		for(int i=0; i<M; i++) {
			printf("%d ", res[i]);
		}
		printf("\n");
		return;
	}
	
	for(int i=0; i<N; i++) {
		bool isPossible = true;
		for(int dup=0; dup<depth; dup++) {
			if(arr[i] == res[dup]) {
				isPossible = false;
				break;
			}
		}
		
		if(isPossible) {
			res[depth] = arr[i];
			backtracking(depth + 1);
		} else {
			continue;
		}
	}
}