//https://www.acmicpc.net/problem/9184

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int cache[51][51][51];
int w(int a, int b, int c);

int main(void) {
	memset(cache, -1, sizeof(cache));
	cache[0][0][0] = 1;
	
	while(true) {
		//입력
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		//printf("%d%d%d", a,b,c);
		if(a == -1 && b == -1 && c == -1) return 0;
		
		//풀이
		printf("w(%d, %d, %d) = %d\n", a,b,c,w(a,b,c));
	}
}

int w(int a, int b, int c) {
	if(a <= 0 || b <= 0 || c <= 0) return 1;
	
	int ans;
	if(cache[a][b][c] != -1) {
		return cache[a][b][c];
	}
	else if(a > 20 || b > 20 || c > 20) {
		ans = w(20, 20, 20);
	}
	else if(a < b &&  b < c) {
		ans = w(a,b,c-1) + w(a,b-1,c-1) - w(a,b-1,c);
	}
	else {
		ans = w(a-1, b, c) + w(a-1, b-1, c) + w(a-1, b, c-1) - w(a-1, b-1, c-1);
	}
	
	cache[a][b][c] = ans;
	return ans;
}