#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAX_N = 306;
const int MAGIC = 9;
const int INF = 1e9 + 7;

int val[MAX_N],cost[MAX_N];
int dp[(1<<MAGIC)];
int mask[MAX_N];
int prime[MAGIC];

int main() {
	int n;
	while (scanf("%d",&n) != EOF) {
		int _gcd=0;
		for (int i=1;n>=i;i++) {
			scanf("%d",&val[i]);
			if (!_gcd) _gcd=val[i];
			else _gcd = __gcd(val[i],_gcd);
		}
		for (int i=1;n>=i;i++) {
			scanf("%d",&cost[i]);
		}
		if (_gcd != 1) {
			puts("-1");
			continue;
		}
		int mn = INF;
		//we must select a[i]
		for (int i=1;n>=i;i++) {
			if (val[i] == 1) {
				mn = min(mn,cost[i]);
				continue;
			}
			fill(dp,dp+(1<<MAGIC),INF);
			//get the prime number first
			int t=sqrt(val[i]);
			int id=0;
			int tmp=val[i];
			for (int i=2;t>=i;i++) {
				if (tmp%i==0) {
					prime[id++]=i;
				}
				while (tmp%i==0) {
					tmp/=i;
				}
			}
			if(tmp != 1) prime[id++] = tmp;
			//dp[11.....11] = cost --> total id's 1s
			dp[(1<<id)-1] = cost[i];
			mask[i] = (1<<id)-1;
			//get all masks
			for (int j=1;n>=j;j++) {
				if(i==j) continue;
				int _=0;
				for (int k=0;id>k;k++) {
					if (val[j] % prime[k] == 0) {
						_ += (1<<k);
					}
				}
				mask[j] = _;
			}
			for (int j=(1<<id)-1;j>=1;j--) {
				if (dp[j] == INF) continue;
				for (int k=1;n>=k;k++) {
					int ala = (j&mask[k]);
					dp[ala] = min(dp[ala],dp[j] + cost[k]);
				}
			}
			mn = min(mn,dp[0]);
		}
		printf("%d\n",mn);
	}
}