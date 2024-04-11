#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <cstring>
#include <map>
using namespace std;

typedef long long LL;
typedef pair<LL,LL> pii;
const int MAX_N = 1e5 + 6;
const int MAX_M = 1e6 + 6;
const LL mod = 1e9 + 7;
const LL P = 77773;

map<pii,int> mp;
LL per[MAX_M];
bool used[MAX_M];
vector<int> v[MAX_M];

LL hash1(vector<int> v) {
	LL p=P;
	LL ret=0;
	for (auto i:v) {
		ret += p*i;
		p*=P;
		p%=mod;
		ret%=mod;
	}
	return ret;
}

LL hash2(vector<int> v) {
	LL ret=0;
	for (auto i:v) {
		ret+=i;
	}
	return ret;
}

int main () {
	int n,m;
	while (scanf("%d %d",&n,&m) != EOF) {
		for (int i=0;m>=i;i++) {
			v[i].clear();
		}
		mp.clear();
		memset(used,0,sizeof(used));
		per[0]=per[1]=1;
		for (int i=2;MAX_M>i;i++) {
			per[i] = per[i-1]*i;
			per[i] %= mod;
		}
		for (int i=1;n>=i;i++) {
			int t;
			scanf("%d",&t);
			for (int x=0;t>x;x++) {
				int j;
				scanf("%d",&j);
				used[j]=1;
				v[j].push_back(i);
			}
		}
		int id=0;
		for (int i=1;m>=i;i++) {
			if (!used[i]) {
				id++;
				continue;
			}
			sort(v[i].begin(),v[i].end());
			mp[make_pair(hash1(v[i]),hash2(v[i]) )]++;
		}
		LL ans=1;
		for (auto iter=mp.begin();iter!=mp.end();iter++) {
			ans *= per[(*iter).second];
			ans%=mod;
		}
		printf("%I64d\n",(ans*per[id])%mod);
	}
}