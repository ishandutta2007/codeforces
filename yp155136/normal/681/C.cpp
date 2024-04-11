#include <iostream>
#include <stdio.h>
#include <queue>
using namespace std;

typedef priority_queue<int, vector<int>, greater<int> > Heap;
const int MAX_N = 1e5 + 6;
const int MAX_M = 1e6 + 6;

int ans1[MAX_M];
int ans2[MAX_M];

int main () {
	int n;
	while (scanf("%d",&n) != EOF) {
		Heap heap;
		int cnt=0;
		for (int x=0;n>x;x++) {
			string i;
			int j;
			cin >> i;
			if (i=="removeMin") {
				if (heap.empty()) {
					ans1[cnt]=1;
					ans2[cnt++]=1;
					ans1[cnt++]=2;
					continue;
				}
				ans1[cnt++]=2;
				heap.pop();
				continue;
			}
			cin>>j;
			if (i=="insert") {
				heap.push(j);
				ans1[cnt]=1;
				ans2[cnt++]=j;
			}
			else if (i=="getMin") {
				while (!heap.empty() && heap.top() < j) {
					ans1[cnt++]=2;
					heap.pop();
				}
				if (heap.empty() || heap.top() > j) {
					heap.push(j);
					ans1[cnt]=1;
					ans2[cnt++]=j;
				}
				ans1[cnt]=3;
				ans2[cnt++]=j;
			}
		}
		printf("%d\n",cnt);
		for (int x=0;cnt>x;x++) {
			if (ans1[x]==2) {
				puts("removeMin");
				continue;
			}
			if (ans1[x]==1) {
				printf("insert ");
			}
			else {
				printf("getMin ");
			}
			printf("%d\n",ans2[x]);
		}
	}
}