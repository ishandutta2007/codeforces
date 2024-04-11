#include <iostream>
#include <stdio.h>
#include <queue>
using namespace std;

const int MAX_N = 3e5 + 6;

int a[MAX_N];

int main () {
	int n,k;
	while (scanf("%d %d",&n,&k) != EOF) {
		for (int i=1;n>=i;i++) {
			scanf("%d",&a[i]);
		}
		if(k==0) {
			int mx=0;
			int tmp=0;
			for (int i=1;n>=i;i++) {
				if (a[i]) {
					tmp++;
					mx = max(mx,tmp);
				}
				else {
					tmp=0;
				}
			}
			printf("%d\n",mx);
			for (int i=1;n>=i;i++) {
				if (i!=1) printf(" ");
				printf("%d",a[i]);
			}
			puts("");
			continue;
		}
		deque<int> dq;
		int L=1;
		int ans=0;
		int ans2=1;
		a[n+1]=0;
		for (int i=1;n+1>=i;i++) {
			if (a[i]==1) {
				ans = max(ans,i-1-L+1);
			}
			else if (dq.size() < k) dq.push_back(i);
			else {
				if (ans < i-1-L+1) {
					ans = max(ans,i-1-L+1);
					ans2=dq.front();
				}
				L = dq.front()+1;
				dq.pop_front();
				dq.push_back(i);
			}
		}
		for (int i=ans2;n>=i&&k>0;i++) {
			if (!a[i]) {
				a[i]=1;
				k--;
			}
		}
		int mx=0,tmp=0;
		for (int i=1;n>=i;i++) {
			if (a[i]) {
				tmp++;
				mx = max(mx,tmp);
			}
			else {
				tmp=0;
			}
		}
		printf("%d\n",mx);
		for (int i=1;n>=i;i++) {
			if (i!=1) printf(" ");
			printf("%d",a[i]);
		}
		puts("");
	}
}