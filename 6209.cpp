//https://www.acmicpc.net/problem/6209

#include <stdio.h>
//#include <limits.h>
#include <algorithm>
using namespace std;

int d, n, m;
int arr[50001];

int main(void) {
	//입력
	scanf("%d %d %d", &d, &n, &m);
	for(int i=1; i<=n; i++) {
		scanf("%d", &arr[i]);
	}
	sort(arr, arr+n+1);
	
	//풀이
	int res = -1;
	int left=0, right=d;
	while(left <= right) {
		int mid = (left + right)/2;
		//여기서 mid는 "에이 이정도는 뛰어야지!"를 의미함
		int curr = 0;
		int cnt = 0;
		for(int i=curr+1; i<=n; i++) {
			if(arr[i] - arr[curr] < mid) { //이정도는 뛰어야지 보다 작으면,
				//어차피 나중에 없어질 돌이니까 cnt++
				cnt++;
			} else {//최솟값만큼, 혹은 그 이상 뛰었으면 그곳이 기준점.
				curr = i;
			}
		}
		
		if(cnt > m) {//너무 많이 건너뛰었는데? --> 너무 많은 돌을 없앴는데?
			//--> 거리를 좀 줄여야겠는데?
			right = mid - 1;
		} else {//너무 적게 뜀,,, 최소를 좀 늘리자.
			//혹은 딱 맞거나? ㅇㅇ --> 그러면 최적화해야지... --> 계속 돌리자.
			left = mid + 1;
			if(res < mid) res = mid;
		}
	}
		
	//출력
	printf("%d\n", res);
	return 0;
}