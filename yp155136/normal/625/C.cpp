#include <iostream>
#include <stdio.h>
#include <queue>
using namespace std;

const int MAX_N = 506;

int ans[MAX_N][MAX_N];

int main () {
	int n,k;
	while (scanf("%d %d",&n,&k) != EOF) {
		priority_queue<int> pq;
		priority_queue<int,vector<int>,greater<int> > pq2;
		for (int i=1;n*n>=i;i++) {
			pq.push(i);
			pq2.push(i);
		}
		int __=0;
		for (int i=1;n>=i;i++) {
			for (int j=1;n>=j;j++) {
				if (j<k) {
					ans[i][j] = pq2.top();
					pq2.pop();
				}
				else {
					for (int _=n;_>=k;_--) {
						ans[i][_]=pq.top();
						pq.pop();
					}
					__ += ans[i][k];
					break;
				}
			}
		}
		printf("%d\n",__);
		for (int i=1;n>=i;i++) {
			for (int j=1;n>=j;j++) {
				if (j!=1) printf(" ");
				printf("%d",ans[i][j]);
			}
			puts("");
		}
	}
}