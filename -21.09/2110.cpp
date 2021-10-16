//https://www.acmicpc.net/problem/2110

#include <stdio.h>
#include <stdbool.h>
#include <algorithm>


using namespace std;

int main(void) {
	//입력
	int n, c;
	int map[200000];
	scanf("%d %d", &n, &c);
	for(int i=0; i<n; i++) {
		scanf("%d", &map[i]);
	}
	
	/*
	풀이
	공유기 간의 간격을 기준으로 이진탐색을
	시도해본다.
	참고:: https://m.blog.naver.com/vjhh0712v/221683269377
	*/
	sort(map, map+n);
	int min = 1, max = map[n - 1] - map[0];
	int ans = -1;
	while(min <= max) {
		int mid = (min + max) / 2; 
		int currIndex = 0;
		int currX = map[currIndex];
		int cnt = 1;
		while(true) { //계속 반복하며 공유기 두다가,
			if(currX + mid > map[n - 1]) break; //더 이상 mid간격으로 둘 곳이 없으면 탈출
			for(int i = currIndex + 1; i < n; i++) {
				if(currX + mid <= map[i]) {
					currIndex = i;
					currX = map[currIndex];
					cnt++;
					break;
				}
			}
		}
		
		if (cnt >= c) {//간격이 너무 좁은 경우 --> min을 키우자
			//추가로 간격이 좁은경우도 정답이 될수 있으므로, (일단 들어는 가니까)
			//ans를 교체할 수 있도록 한다. 
			//+ cnt==c이더라도 예제와 같이 2,3이 나올 수 있으므로, 더 탐색을 해야한다.
			min = mid + 1;
			if(ans < mid) ans = mid;
		}
		else if (cnt < c) {//간격이 너무 넓은 경우 --> max를 줄이자
			max = mid - 1;
		}
	}
	
	//출력
	printf("%d\n", ans);
	return 0;
}