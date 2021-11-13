//https://www.acmicpc.net/problem/1477
//고속도로를 더 짓고, 휴게소가 없는 구간의 길이의 최댓값의 최솟값
//이것보다 더 큰 공백이 없으면 안된다는 뜻
#include <stdio.h>
#include <stdbool.h>
#include <algorithm>
using namespace std;

int getResult(int leftRest, int maxGap);

int N, M, L;
int arr[50 + 2];
int main(void) {
	//입력
	scanf("%d %d %d", &N, &M, &L);
	for(int i=1; i<=N; i++) {
		scanf("%d", &arr[i]);
	}
	sort(arr+1, arr+N+1);
	arr[N+1] = L;
	/*
	for(int i=0; i<=N+1; i++) {
		printf("%d ", arr[i]);
	}
	*/

	//풀이
	//없는 구간의 최대 길이가 L일때, M개를 더 지을 수 있긴해?
	int left = 0, right = L;
	int mid;
	int res = 987654321;
	while(left <= right) {
		//printf("left: %d, right: %d\n", left, right);
		mid = (left + right)/2;
		int tmp = getResult(M, mid);
		if(tmp >= 0) {//딱 맞으면, 더 최적화 시키려고 해야함
			right = mid - 1;
			if(res > mid) res = mid;
		}
		if(tmp < 0) {//다 짓고도 자리가 또 남음. 최적화를 위해서 값을 올려라
			left = mid + 1;
		}
	}
	
	//출력
	printf("%d\n", res);
	return 0;
}

int getResult(int leftRest, int maxGap) {
	if(maxGap == 0) return -987654321;
	
	//rintf("!!!!!!!!!!!!!!!!!!!%d\n", maxGap);
	for(int i=1; i<=N+1; i++) {
		if(arr[i] - arr[i-1] > maxGap) {
			//공간 남는 곳에 휴게소 세우기
			int sum = ((arr[i] - arr[i-1])/maxGap);
			if(((arr[i] - arr[i-1]) % maxGap) == 0) {
				sum--;
			}
			leftRest -= sum;
			//printf("여기에 %d개 세울 수 있음 %d~%d\n", sum, arr[i-1], arr[i]);
		}
	}
	//printf("%d\n", leftRest);
	
	return leftRest;
}