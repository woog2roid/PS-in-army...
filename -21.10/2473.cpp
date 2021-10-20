//https://www.acmicpc.net/problem/2473

#include <stdio.h>
#include <algorithm>
#include <limits.h>
using namespace std;

long long int arr[5000];
int main(void) {
	//입력
	int N;
	scanf("%d", &N);
	for(int i=0; i<N; i++) {
		scanf("%lld", &arr[i]);
	}
	sort(arr, arr+N);
	
	//풀이
	long long int min = 3000000000;
	int minI, minLeft, minRight;
	for(int i=0; i<N-2; i++) {
		int left=i+1, right=N-1;
		while(left < right && right < N) {
			long long int sum = arr[i] + arr[left] + arr[right];
			if(sum == 0) {
				printf("%lld %lld %lld", arr[i], arr[left], arr[right]);
				return 0;
			}
			if(abs(sum) < min) {
				min = abs(sum);
				minI = i, minLeft = left, minRight = right;
			}
			
			if(sum < 0) left++;
			if(sum > 0) right--;
		}
	}
	
	//출력
	printf("%lld %lld %lld\n", arr[minI], arr[minLeft], arr[minRight]);
	//printf("%d %d %d", minI, minLeft, minRight);
	return 0;
}