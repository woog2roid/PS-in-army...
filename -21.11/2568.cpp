//https://www.acmicpc.net/problem/2568

#include <stdio.h>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

pair<int,int> arr[100000];
int LISIndex[100000], LIS[100000];

int main(void) {
	//입력
	int N;
	scanf("%d", &N);
	for(int i=0; i<N; i++) {
		scanf("%d %d", &arr[i].first, &arr[i].second);
	}
	sort(arr, arr+N);
	
	//풀이
	vector<int> v;
	int cnt = 0;
	
	v.push_back(arr[0].second);
	LISIndex[0] = 0;
	cnt++;
	
	for(int i=1; i<N; i++) {
		if(arr[i].second > v[v.size()-1]) {
			v.push_back(arr[i].second);
			LISIndex[i] = v.size()-1;
			cnt++;
		}
		else {
			vector<int>::iterator ptr = lower_bound(v.begin(), v.end(), arr[i].second);
			*ptr = arr[i].second;
			LISIndex[i] = ptr - v.begin();
		}
	}
	
	//출력
	printf("%d\n", N - cnt);
	stack<int> s;
	cnt--;
	for(int i=N-1; i>=0; i--) {
		if(LISIndex[i] == cnt) {
			cnt--;
		}
		else if(LISIndex[i] != cnt) {
			s.push(i);
		}
	}
	while(!s.empty()) {
		printf("%d\n", arr[s.top()].first);
		s.pop();
	}
	
	return 0;
}