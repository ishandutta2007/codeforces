#include <iostream>
#include <stdio.h>
#include <queue>
using namespace std;

const int MAX_N = 1006;

int a[MAX_N];

int main () {
	int n,m;
	while (scanf("%d %d",&n,&m) != EOF) {
		priority_queue<int> pq;
		priority_queue<int,vector<int>,greater<int> >pq2;
		for (int i=1;m>=i;i++) {
			scanf("%d",&a[i]);
			pq.push(a[i]);
			pq2.push(a[i]);
		}
		int tmp=n;
		int _=0,__=0;
		while (tmp--) {
			_ += pq.top();
			int t=pq.top();
			pq.pop();
			t--;
			if (t) pq.push(t);
		}
		tmp=n;
		while (tmp--) {
			__+= pq2.top();
			int t=pq2.top();
			pq2.pop();
			t--;
			if (t) pq2.push(t);
		}
		printf("%d %d\n",_,__);
	}
}