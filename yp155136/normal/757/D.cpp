#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;

typedef long long LL;
const int MAX_N = 77;
const int MAX_P = 20;
const LL mod=1e9+7;

int dp[MAX_N][(1<<MAX_P)+6];
char c[MAX_N];
int a[MAX_N];

int mul(int a,int b) {
	LL x=a;
	return (x*b)%mod;
}

int add(int a,int b) {
	int ret=a+b;
	if (ret>=mod) ret-=mod;
	return ret;
}

int mns(int a,int b) {
	int ret=a-b;
	if (ret<0) ret+=mod;
	return ret;
}

int bnry(int L,int R) {
	int ret=0;
	int id=1;
	for (int x=R;x>=L;x--) {
		if(id>31 && a[x]==1) return 21;
		ret += id*a[x];
		id*=2;
		if (id>31) id=31;
	}
	return ret;
}

int main () {
	int n;
	while (scanf("%d",&n) != EOF) {
		getchar();
		scanf("%s",c);
		for (int i=1;n>=i;i++) {
			a[i] = c[i-1]-'0';
		}
		dp[0][0] = 1;
		int _0=0;
		for (int i=1;n>=i;i++) {
			//cout<<"i = "<<i<<endl;
			dp[i][0] = 1;
			for (int k=0;;k++) {
				if (i-k<=0) break;
				int tmp=bnry(i-k,i);
				if (tmp>20) break;
				else if (tmp==0) {
					continue;
				}
				else {
					for (int j=0;(1<<MAX_P)>j;j++) {
						dp[i][(j|(1<<(tmp-1)))]=add(dp[i][(j|(1<<(tmp-1)))],dp[i-k-1][j]);
						//cout<<"update "<<(1<<(tmp-1))<<" from dp["<<i-k-1<<"]["<<j<<"] = "<<dp[i-k-1][j]<<endl;
					}
				}
			}
		}
//		cout<<"\n------------------------------------\n\n";
//		for (int i=1;n>=i;i++) {
//			for(int j=0;(1<<MAX_P)>j;j++) {
//				cout<<"dp["<<i<<"]["<<j<<"] = "<<dp[i][j]<<endl;
//			}
//		}
		//cout<<"\n------------------------------------\n\n";
		int ans=0;
		for (int i=1;n>=i;i++) {
			for (int j=0;(1<<MAX_P)>j;j*=2) {
				j++;
//				if (j<17) cout<<"dp["<<i<<"]["<<j<<"] = "<<dp[i][j]<<endl;
				ans = add(dp[i][j],ans);
			}
		}
		printf("%d\n",ans);
	}
}