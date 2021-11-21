//https://www.acmicpc.net/problem/23561

#include <stdio.h>
#include <algorithm>
using namespace std;

int arr[300000];
int main(void) {
	//입력
	int N;
	scanf("%d", &N);
	for(int i=0; i<3*N; i++) {
		scanf("%d", &arr[i]);
	}
	sort(arr, arr+3*N);
	
	//풀이
	int min=arr[N], max=arr[2*N-1];
	printf("%d\n", max-min);
	return 0;
}