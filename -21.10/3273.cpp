//https://www.acmicpc.net/problem/3273

#include <stdio.h>
#include <algorithm>
using namespace std;

int main(void) {
	//입력
	int n;
	scanf("%d", &n);
	int arr[1000000];
	for(int i=0; i<n; i++) {
		scanf("%d", &arr[i]);
	} 
	sort(arr, arr+n);
	int x;
	scanf("%d", &x);
	
	//풀이
	int cnt = 0;
	int left = 0, right = n-1;
	while(left < right) {
		int sum = arr[left] + arr[right];
		if(sum < x) {
			left++;
		}
		else if(sum > x) {
			right--;
		}
		else if(sum == x) {
			cnt++;
			left++;//그냥 임의로
		}
	}
	
	//출력
	printf("%d", cnt);
	return 0;
}