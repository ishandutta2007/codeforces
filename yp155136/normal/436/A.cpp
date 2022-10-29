#include <iostream>
#include <stdio.h>
#include <utility>
#include <algorithm>
#include <queue>
using namespace std;

typedef pair<int,int> pii;
const int MAX_N = 2e3 + 6;

pii _0[MAX_N];
pii _1[MAX_N];

int main () {
	int n,x;
	while (scanf("%d %d",&n,&x) != EOF) {
		int a=0,b=0;
		for (int i=1;n>=i;i++) {
			int c,d,e;
			scanf("%d %d %d",&c,&d,&e);
			if (c==0) {
				_0[a++] = make_pair(d,e);
			}
			else if (c==1) {
				_1[b++] = make_pair(d,e);
			}
		}
		sort(_0,_0+a);
		sort(_1,_1+b);
		int mx=0;
		priority_queue<int> pq1,pq2;
		int cnt=0;
		//start from _0
		int ala=x;
		int _i=0,_j=0;
		for (;a>_i&& x>=_0[_i].first;_i++) pq1.push(_0[_i].second);
		for (;b>_j&& x>=_1[_j].first;_j++) pq2.push(_1[_j].second);
		while (!pq1.empty()) {
			int tmp=pq1.top();
			pq1.pop();
			x += tmp;
			cnt++;
			for (;a>_i&& x>=_0[_i].first;_i++) pq1.push(_0[_i].second);
			for (;b>_j&& x>=_1[_j].first;_j++) pq2.push(_1[_j].second);
			if (pq2.empty()) break;
			else {
				tmp=pq2.top();
				cnt++;
				x+=tmp;
				pq2.pop();
			}
			for (;a>_i&& x>=_0[_i].first;_i++) pq1.push(_0[_i].second);
			for (;b>_j&& x>=_1[_j].first;_j++) pq2.push(_1[_j].second);
		}
		mx = max(mx,cnt);
		x=ala;
		while (!pq1.empty()) pq1.pop();
		while (!pq2.empty()) pq2.pop();
		cnt=0;
		//start from _0
		_i=0,_j=0;
		for (;a>_i&& x>=_0[_i].first;_i++) pq1.push(_0[_i].second);
		for (;b>_j&& x>=_1[_j].first;_j++) pq2.push(_1[_j].second);
		while (!pq2.empty()) {
			int tmp=pq2.top();
			pq2.pop();
			x += tmp;
			cnt++;
			for (;a>_i&& x>=_0[_i].first;_i++) pq1.push(_0[_i].second);
			for (;b>_j&& x>=_1[_j].first;_j++) pq2.push(_1[_j].second);
			if (pq1.empty()) break;
			else {
				tmp=pq1.top();
				cnt++;
				x+=tmp;
				pq1.pop();
			}
			for (;a>_i&& x>=_0[_i].first;_i++) pq1.push(_0[_i].second);
			for (;b>_j&& x>=_1[_j].first;_j++) pq2.push(_1[_j].second);
		}
		mx = max(mx,cnt);
		printf("%d\n",mx);
	}
}