//https://www.acmicpc.net/problem/1932

#include <stdio.h>

int arr[125250]; //최대크기 500
int main(void) {
	//입력
	int n;
	scanf("%d", &n);
	for(int i=0; i<n; i++) {
		for(int j=0; j<=i; j++) {
			scanf("%d", &arr[((i+1)*i)/2 + j]);
		}
	}
	
	/*
	//체크
	for(int i=0; i<n*(n+1)/2; i++) {
		printf("%d ", arr[i]);
	}
	*/
	
}