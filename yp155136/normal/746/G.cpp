#include <iostream>
#include <stdio.h>
using namespace std;

const int MAX_N = 2e5 + 6;

int cnt[MAX_N];
int mx[MAX_N];
int mn[MAX_N];
int a[MAX_N];
int st[MAX_N];
int L[MAX_N],R[MAX_N];
int sufL[MAX_N],sufR[MAX_N];

int main () {
	int n,t,k;
	while (scanf("%d %d %d",&n,&t,&k) != EOF) {
		for (int i=1;t>=i;i++) {
			scanf("%d",&cnt[i]);
			if (i==1) {
				mx[i]=mn[i]=cnt[i];
				L[i] =R[i]=cnt[i];
			}
			else {
				mx[i] = mx[i-1]-1+cnt[i];
				R[i] = cnt[i]-1;
				if (cnt[i] > cnt[i-1]) {
					mn[i] = mn[i-1] - cnt[i-1] + cnt[i];
					L[i] = cnt[i]-cnt[i-1];
				}
				else {
					mn[i] = mn[i-1];
					L[i] = 0;
				}
			}
		}
		sufL[t+1]=sufR[t+1]=0;
		for (int i=t;i>=1;i--) {
			sufL[i] = sufL[i+1] + L[i];
			sufR[i] = sufR[i+1] + R[i];
		}
		if (mn[t]<=k && k<=mx[t]) {
			int id=2;
			int now=cnt[1];
			for (int i=1;t>=i;i++) {
				//cout<<"i = "<<i<<endl;
				st[i]=id;
				if (i==1) {
					int tmp=cnt[i];
					while (tmp--) {
						a[id++]=1;
					}
					continue;
				}
				else if (i==t) {
					int need=k-now;
					int tmp1=cnt[i];
					while (need>0 && tmp1>0) {
						a[id++] = st[i-1];
						tmp1--;
						need--;
					}
					if (tmp1>0) {
						int tmp2=cnt[i-1];
						int tmp3=st[i-1];
						while (tmp1>0 && tmp2>0) {
							a[id++]=tmp3++;
							tmp1--;
							tmp2--;
						}
					}
					continue;
				}
				int tmp=now+L[i]; //try to see use the minimum way
				if (sufL[i+1]<=k-tmp && k-tmp<=sufR[i+1]) {
					//cout<<"in here1\n";
					//we can use the minimum
					int tmp1=cnt[i];
					int tmp2=cnt[i-1];
					int tmp3=st[i-1];
					while (tmp1>0 && tmp2>0) {
						a[id++]=tmp3++;
						tmp1--;
						tmp2--;
					}
					if (tmp1) {
						while (tmp1--) {
							a[id++] = st[i-1];
						}
					}
					now += L[i];
					continue;
				}
				tmp=now+R[i];
				if (sufL[i+1]<=k-tmp && k-tmp<=sufR[i+1]) {
					//cout<<"in here2\n";
					//we can use the maximum way
					int temp=cnt[i];
					while (temp--) {
						a[id++] = st[i-1];
					}
					now += R[i];
					continue;
				}
				tmp=k-now-sufL[i];
				if(tmp>=0) {
					int need=tmp;
					int tmp1=cnt[i];
					while (need>0 && tmp1>0) {
						a[id++] = st[i-1];
						tmp1--;
						need--;
					}
					if (tmp1>0) {
						int tmp2=cnt[i-1];
						int tmp3=st[i-1];
						while (tmp1>0 && tmp2>0) {
							a[id++]=tmp3++;
							tmp1--;
							tmp2--;
						}
					}
					continue;
				}
			}
			printf("%d\n",n);
			for (int i=2;n>=i;i++) {
				printf("%d %d\n",a[i],i);
			}
		}
		else {
			puts("-1");
		}
	}
}