#include <bits/stdc++.h>
using namespace std;

const int MAXN=10011;
map<string, int> mp, cnt, vis;
string nam[MAXN], s;
int n, m;

int main() {
	scanf("%d", &n);
	for(int i=1;i<=n;++i) {
		cin >> nam[i];
		int l=nam[i].length();
		vis.clear();
		for(int j=0;j<l;++j) {
			for(int k=0;j+k<=l;++k) {
				mp[nam[i].substr(j, k)]=i;
				vis[nam[i].substr(j, k)]=1;
			}
		}
		for(map<string, int>::iterator mit=vis.begin();mit!=vis.end();++mit) {
			++cnt[mit->first];
		}
	}
	scanf("%d", &m);
	for(int i=1;i<=m;++i) {
		cin >> s;
		if(cnt[s]==0) {
			puts("0 -");
		} else {
			printf("%d ", cnt[s]);
			cout << nam[mp[s]] << endl;
		}
	}
	return 0;
}