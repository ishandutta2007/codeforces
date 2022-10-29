#include <iostream>
#include <stdio.h>
#include <cstring>
#include <queue>
#include <cmath>
using namespace std;

const int MAX_N = 1e5 + 6;

int cnt1[MAX_N];
int cnt2[2*MAX_N];
int ans[MAX_N];

int main () {
	int n,m;
	while (scanf("%d %d",&n,&m) != EOF) {
		memset(cnt1,0,sizeof(cnt1));
		memset(cnt2,0,sizeof(cnt2));
		memset(ans,0,sizeof(ans));
		for (int i=1;n>=i;i++) {
			int t;
			scanf("%d",&t);
			cnt1[t]++;
		}
		for (int i=1;n>=i;i++) {
			int t;
			scanf("%d",&t);
			cnt2[m-t-1]++;
		}
		for (int i=0;m>i;i++) {
			//cout<<"cnt1["<<i<<"] = "<<cnt1[i]<<" , ~~~2 = "<<cnt2[i]<<endl;
			int tmp=min(cnt1[i],cnt2[i]);
			//cout<<"tmp = "<<tmp<<endl;
			ans[m-1]+= tmp;
			cnt1[i] -= tmp;
			cnt2[i] -= tmp;
			//cout<<"ans[m-1] = "<<ans[m-1]<<endl;
		}
		priority_queue<int> pq;
		for (int i=0;m>i;i++) {
			for (int j=0;cnt1[i]>j;j++) {
				pq.push(i);
			}
			while (cnt2[i]>0 && !pq.empty()) {
				cnt2[i]--;
				int t=pq.top();
				//cout<<"i = "<<i<<" , t = "<<t<<endl;
				pq.pop();
				ans[abs((m-i-1+t)%m)]++;
			}
		}
		for (int i=0;m>i;i++) {
			cnt2[m+i]=cnt2[i];
		}
		for (int i=m;2*m>i;i++) {
			while (cnt2[i]>0 && !pq.empty()) {
				cnt2[i]--;
				int t=pq.top();
				//cout<<"ii = "<<i<<" , t = "<<t<<endl;
				pq.pop();
				ans[abs((2*m-i+t-m-1))]++;
			}
		}
		bool check=false;
		for (int i=m-1;i>=0;i--) {
			while (ans[i]--) {
				if (check) printf(" ");
				check=true;
				printf("%d",i);
			}
		}
		puts("");
	}
}