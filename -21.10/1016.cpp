//https://www.acmicpc.net/problem/1016

#include <stdio.h>
#include <math.h>

int arr[1000001] = {0};

int main(void) {
	//입력
	long long int min, max;
	scanf("%lld %lld", &min, &max);

	//풀이
	long long int sqrtMax = sqrt(max);
	for(long long int i=2; i<=sqrtMax; i++) {
		long long int divisor = i*i;
		long long int reminder = (min % divisor);
		long long int start = min;
		if(reminder != 0) start = min - reminder + divisor;
		for(long long int num = start; num <= max; num += divisor) {
			arr[num-min] = 1;
		}
	}

	//출력
	int cnt = 0;
	for(int i=0; i<max-min+1; i++) {
		if(arr[i] == 0) cnt++;
	}
	printf("%d\n", cnt);
	return 0;
}