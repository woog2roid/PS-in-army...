//https://www.acmicpc.net/problem/12015
//https://www.acmicpc.net/problem/14003

#include <stdio.h>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;

int arr[1000000];
int index[1000000];
vector<int> v;
int main(void) {
	//입력
	int N;
	scanf("%d", &N);
	for(int i=0; i<N; i++) {
		scanf("%d", &arr[i]);
	}
	
	//풀이
	//초기화
	int cnt=0;
	v.push_back(arr[0]);
	index[0] = cnt;
	cnt++;
	//반복문
	for(int i=1; i<N; i++) {
		if(v[v.size() - 1] < arr[i]) {
			v.push_back(arr[i]);
			index[i] = cnt;
			cnt++;
		}
		else {
			vector<int>::iterator low = lower_bound(v.begin(), v.end(), arr[i]);
			*low = arr[i];
			int idx = low-v.begin();
			index[i] = idx;
		}
	}
	
	//출력
	printf("%d\n", cnt);
	cnt--;
	stack<int> s;
	//for(int i=0; i<N; i++) printf("%d ", index[i]);
	for(int i=N-1; i>=0; i--) {
		if(index[i] == cnt) {
			s.push(i);
			cnt--;
		}
	}
	while(!s.empty()) {
		printf("%d ", arr[s.top()]);
		s.pop();
	}
	return 0;
}