//https://www.acmicpc.net/problem/1590

#include <stdio.h>
#include <limits.h>

typedef struct {
	int start;
	int gap;
	int many;
} Bus;
Bus bus[100000]; 

int N, T;
int main(void) {
	//입력
	scanf("%d %d", &N, &T);
	for(int i=0; i<N; i++) {
		scanf("%d %d %d", &bus[i].start, &bus[i].gap, &bus[i].many);
	}
	
	//풀이
	int res = INT_MAX;
	for(int i=0; i<N; i++) {
		for(int j=0; j<bus[i].many; j++) {
			if(bus[i].start + (bus[i].gap * j) - T >= 0) {
				if(res > bus[i].start + (bus[i].gap * j) - T)
					res = bus[i].start + (bus[i].gap * j) - T;
				break;
			}	
		}
	}
	
	//출력
	if(res == INT_MAX)	printf("-1\n");
	else printf("%d\n", res);
	return 0;
}