//https://www.acmicpc.net/problem/2629

#include <stdio.h>
#include <stdbool.h>

int arr[30];
int chk[7];
bool visited[31][40001];
bool res[40001];

void solve(int cnt, int weight);
int diff(int a, int b) {
	return a-b>=0 ? a-b : b-a;
}

int c, w;
int main(void) {
	//입력
	scanf("%d", &c);
	for(int i=0; i<c; i++) {
		scanf("%d", &arr[i]);
	}
	scanf("%d", &w);
	for(int i=0; i<w; i++) {
		scanf("%d", &chk[i]);
	}
	
	//풀이
	solve(0, 0);
	
	//출력
	for(int i=0; i<w; i++) {
		if(res[chk[i]]) printf("Y ");
		else printf("N ");
	}
	printf("\n");
	return 0;
}
			  
void solve(int cnt, int weight) {
	if(cnt > c) return;
	if(visited[cnt][weight] == true) return;
	
	visited[cnt][weight] = true;
	res[weight] = true;
	
	solve(cnt + 1, weight + arr[cnt]);
	solve(cnt + 1, weight);
	solve(cnt + 1, diff(weight, arr[cnt]));
}