//https://www.acmicpc.net/problem/2293

#include <stdio.h>
#include <algorithm>
using namespace std;

int arr[100];
int res[10001];

int main(void) {
	//입력
	int n, k;
	scanf("%d %d", &n, &k);
	for(int i=0; i<n; i++) {
		scanf("%d", &arr[i]);
	}
	sort(arr, arr+n);
	
	//풀이
	res[0] = 1;
	for(int i=0; i<n; i++) {
		for(int j=arr[i]; j<=k; j++) {
			res[j] += res[j - arr[i]];
		}
	}
	
	/*
	//체크	
	for(int i=1; i<=k; i++) {
		printf("%d ", res[i]);
	}
	printf("\n");
	*/
	
	//출력
	printf("%d\n", res[k]);
	return 0;
}

	//아래와 같이 짜면 중복이 일어나서, 동전별로 할 수 있도록 다시 짰다...
	/*
	for(int i=1; i<=k; i++) {
		for(int j=0; j<n; j++) {
			if(i - arr[j] >= 0) { // 더 뒤로 갈 곳이있다는 전제하에,
				res[i] += res[i - arr[j]];
			} 
		}
	}
	*/