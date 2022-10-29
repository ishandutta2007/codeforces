#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;

typedef long long LL;
const int MAX_N = 1e3 + 6;
const int MAX_P = 144;
const LL mod = 1e9 + 7;

LL dp[MAX_N];
int cnt[MAX_P];
int lim[MAX_P];

bool check(int _) {
	for (int i='a';'z'>=i;i++) {
		if (_ > lim[i] && cnt[i]) return false;
	}
	return true;
}

int main () {
	int n;
	while (scanf("%d",&n) != EOF){
		string s;
		cin >> s;
		s=" "+s;
		memset(dp,0,sizeof(dp));
		memset(cnt,0,sizeof(cnt));
		for (int i='a';'z'>=i;i++) {
			scanf("%d",&lim[i]);
		}
		if (n==1) {
			puts("1\n1\n1");
			continue;
		}
		dp[0]=1;
		dp[1]=1;
		for(int i=2;n>=i;i++) {
			memset(cnt,0,sizeof(cnt));
			int j=i-1;
			cnt[s[i]]++;
			while (check(i-j) && j>=0) {
				dp[i] += dp[j];
				dp[i] %= mod;
				cnt[s[j]]++;
				j--;
			}
		}
		printf("%I64d\n",dp[n]);
		int mx=-1;
		for (int i=1;n>=i;i++) {
			memset(cnt,0,sizeof(cnt));
			for (int j=i;n>=j;j++) {
				cnt[s[j]]=1;
				if (check(j-i+1)) mx=max(mx,j-i+1);
			}
		}
		printf("%d\n",mx);
		int ala=1;
		memset(cnt,0,sizeof(cnt));
		int _=0;
		for (int i=1;n>=i;i++) {
			cnt[s[i]]++;
			_++;
			if (!check(_)) {
				ala++;
				_=1;
				memset(cnt,0,sizeof(cnt));
				cnt[s[i]]=1;
			}
		}
		printf("%d\n",ala);
	}
}