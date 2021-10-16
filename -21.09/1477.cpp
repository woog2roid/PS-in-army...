//https://www.acmicpc.net/problem/1477
//읽어보기: https://www.acmicpc.net/board/view/35663

#include <stdio.h>
#include <algorithm>
#include <limits.h>
using namespace std;

int map[100 + 2]; //처음과 끝도 포함해서
int main(void) {
	//입력
	int N, M, L;
	scanf("%d %d %d", &N, &M, &L);
	for(int i=1; i<=N; i++) {
		scanf("%d", &map[i]);
	}
	sort(map, map + N + 1);
	map[N + 1] = L;
	
	//풀이
	int res = INT_MAX;
	int left = 0, right = L;
	while(left <= right) {
		int cnt = 0;
		int mid = (left + right) / 2;
		for(int i=1; i<=N+1; i++) {
			if(map[i] - map[i - 1] > mid) {
				//휴게소를 몇개 놓는지 계산중...
				cnt += (map[i] - map[i-1])/mid;
				if((map[i] - map[i-1])%mid == 0) cnt--;
			}
		}
		
		if(cnt <= M) { //휴게소를 너무 조금 놨는데? --> 휴게소가 없는 구간의 길이를 줄이자
			right = mid - 1;
			if(res > mid) res = mid;
		}
		else if(cnt > M){ //휴게소를 너무 많이 놨네? --> 휴게소가 없는 구간의 길이를 늘린다.
			left = mid + 1;
		}
	}
	
	//출력
	printf("%d\n", res);
	return 0;
}