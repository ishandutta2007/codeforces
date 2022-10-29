#include <iostream>
#include <stdio.h>
#include <queue>
using namespace std;

const int MAX_N = 106;

int a[MAX_N];

int main () {
	int n;
	while (scanf("%d",&n) != EOF) {
		int A=0,B=0;
		priority_queue<int> pq;
		for (int i=1;n>=i;i++) {
			int s;
			scanf("%d",&s);
			for (int j=1;s>=j;j++) {
				scanf("%d",&a[j]);
			}
			if (s%2 == 1) pq.push(a[s/2+1]);
			int tmp=s/2;
			for (int i=1;tmp;i++,tmp--) {
				A += a[i];
			}
			tmp = s/2;
			for (int i=s;tmp;i--,tmp--) {
				B += a[i];
			}
		}
		int cnt=0;
		while (!pq.empty()) {
			if (cnt%2==0) A += pq.top();
			else B += pq.top();
			pq.pop();
			cnt++;
		}
		printf("%d %d\n",A,B);
	}
}