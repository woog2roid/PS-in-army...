//https://regularmember.tistory.com/142

#include <stdio.h>
#include <queue>
#include <vector>
#include <functional>
using namespace std;

int N;
int tmp;
int main(void) {	
	priority_queue<int> maxheap;
	priority_queue<int, vector<int>, greater<int>> minheap;
	
	scanf("%d", &N);
	for(int i=0; i<N; i++) {
		scanf("%d", &tmp);
		if(i == 0) {
			maxheap.push(tmp);
			printf("%d\n", maxheap.top());
			continue;
		}
		
		if(maxheap.size() == minheap.size() + 1) {
			minheap.push(tmp);
		}
		else {
			maxheap.push(tmp);
		}
		
		if(maxheap.top() > minheap.top()) {
			int maxTop = maxheap.top(), minTop = minheap.top();
			maxheap.pop();
			minheap.pop();
			minheap.push(maxTop);
			maxheap.push(minTop);
		}
		printf("%d\n", maxheap.top());
	}
	
	return 0;
}