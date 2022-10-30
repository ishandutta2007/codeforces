#include <iostream>
#include <stdio.h>
#include <utility>
#include <vector>
#include <cstring>
#include <algorithm>
#include <bitset>
#include <queue>
using namespace std;

typedef pair<int,int> pii;
const int MAX_N = 1e6 + 6;
const int MAX_M = 106;
const int T = 100;

int a[MAX_N];
bool visit[MAX_N];
int val[MAX_N];
int cnt[MAX_M];
bitset<MAX_N> dp;
int dp2[2][MAX_N];
int dq[MAX_N];
int v[MAX_N];

int main () {
	int n,k;
	while (scanf("%d %d",&n,&k) != EOF) {
		for (int i=1;n>=i;i++) {
			scanf("%d",&a[i]);
		}
		int sz=0;
		int id=1;
		for (int i=1;n>=i;i++) {
			if (!visit[i]) {
				int tmp=0;
				int j=i;
				while (!visit[j]) {
					tmp++;
					visit[j]=true;
					j=a[j];
				}
				v[sz++] = tmp;
				if (tmp>T) val[id++]=tmp;
				else cnt[tmp]++;
			}
		}
		id--;
		dp[0]=1;
		for (int i=1;id>=i;i++) dp=(dp)|(dp<<val[i]);
		int _i=0;
		for (int i=1;T>=i;i++) {
			if (cnt[i] == 0) continue;
			memset(dq,-1,sizeof(dq));
			for (int j=0;n>=j;j++) {
				if (dp[j]) {
					dq[j%i]=j;
					continue;
				}
				else {
					if (dq[j%i]!=-1&& j-dq[j%i]<=cnt[i]*i) {
						dp[j]=1;
					}
				}
			}
		}
		
		bool check=dp[k];

		int mx=0,mn=0;
		if (check) mn=k;
		else mn=min(n,k+1);
		int tmp=k;
		mx=0;
		//round 1 --> 2
		for (int x=0;sz>x;x++) {
			int can=v[x]/2;
			if (tmp <= can) {
				mx += 2*tmp;
				tmp=0;
				break;
			}
			else {
				v[x] -= can*2;
				mx += 2*can;
				tmp -= can;
			}
		}
		for(int x=0;sz>x;x++) {
			if (tmp==0) break;
			if (v[x]) {
				tmp--;
				mx++;
			}
		}
		printf("%d %d\n",mn,mx);
	}
}