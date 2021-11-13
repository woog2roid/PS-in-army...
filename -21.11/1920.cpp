//https://www.acmicpc.net/problem/1920

#include <stdio.h>
#include <algorithm>
using namespace std;

int arr[100000];
int main(void) {
	//입력
	int N;
	scanf("%d", &N);
	for(int i=0; i<N; i++) {
		scanf("%d", &arr[i]);
	}
	sort(arr, arr+N);
	
	//풀이
	int M;
	scanf("%d", &M);
	for(int i=0; i<M; i++) {
		int num;
		scanf("%d", &num);
		
		int left=0, right=N-1;
		bool isIn = false;
		while(left <= right) {
			int mid = (left + right)/2;
			if(arr[mid] > num) right = mid - 1;
			if(arr[mid] < num) left = mid + 1;
			if(arr[mid] == num) {
				isIn = true;
				break;
			}
		}
		if(isIn) printf("1\n");
		else printf("0\n");
	}
}