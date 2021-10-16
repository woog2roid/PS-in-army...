//https://www.acmicpc.net/problem/2805

#include <stdio.h>

int main(void) {
	//입력
	long long n, m;
	long long map[1000000];
	long long min = 0, max = 0;
	scanf("%lld %lld", &n, &m);
	for(int i=0; i<n; i++) {
		scanf("%lld", &map[i]);
		if(max < map[i]) max = map[i];
	}
	
	//풀이
	long long res = -1;
	while(min <= max) {
		long long sum = 0;
		long long mid = (min + max)/2;
		for(int i=0; i<n; i++) {
			if(map[i] - mid > 0) sum += map[i] - mid;
		}
		if(m == sum) {
			res = mid;
			break;
		}
		else if(m > sum) { //너무 조금 자른 경우 --> 높이를 낮춘다
			max = mid - 1;
		}
		else if(m < sum) { //너무 많이 자른 경우 --> 높이를 높인다
			min = mid + 1;
			if(res < mid) { //이전 높이보다 지금 높이가 높으면 res를 바꾼다--> 남는 나무가 적다는 뜻
				res = mid;
			}
		}
	}
	
	//출력
	printf("%lld\n", res);
	return 0;
}