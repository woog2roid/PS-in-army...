//https://www.acmicpc.net/problem/2467

#include <stdio.h>
#include <limits.h>

int arr[100000];

int abs(int num) {
	if(num > 0) return num;
	else return num * -1;
};

int main(void) {
	//입력
	int N;
	scanf("%d", &N);
	for(int i=0; i<N; i++) {
		scanf("%d", &arr[i]);
	}
	
	//풀이
	int min = INT_MAX;
	int left = 0, right = N-1;
	int ansLeft, ansRight;
	while(left < right) {
		int tmp = arr[left] + arr[right];
		if(tmp == 0) {
			ansLeft = left;
			ansRight = right;
			break;
		}
		if(abs(min) > abs(tmp)) {
			min = tmp;
			ansLeft = left;
			ansRight = right;
		}
		
		if(tmp > 0) right--;
		if(tmp < 0) left++;
	}
		
	//출력
	printf("%d %d", arr[ansLeft], arr[ansRight]);
}