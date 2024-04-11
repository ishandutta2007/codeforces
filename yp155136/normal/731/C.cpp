#include <iostream>
#include <stdio.h>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX_N = 2e5 + 6;
const int INF = 1e9+7;

struct DisjointSet {
	int p[MAX_N];
	void init(int n) {
		for (int x=0;n>=x;x++) p[x]=x;
	}
	int Find(int x) {
		return x==p[x]?x:p[x]=Find(p[x]);
	}
	void Union(int x,int y) {
		p[Find(x)] = Find(y);
	}
} djs;

int a[MAX_N];
vector<int> v[MAX_N];

int main () {
	int n,m,k;
	while (scanf("%d %d %d",&n,&m,&k) != EOF) {
		for (int x=0;n>=x;x++) {
			v[x].clear();
		}
		djs.init(n);
		for (int x=1;n>=x;x++) scanf("%d",&a[x]);
		for (int x=0;m>x;x++) {
			int i,j;
			scanf("%d %d",&i,&j);
			djs.Union(i,j);
		}
		for (int x=1;n>=x;x++) {
			v[djs.Find(x)].push_back(a[x]);
		}
		int ans=0;
		for (int x=1;n>=x;x++) {
			if (!v[x].empty()) {
//				cout<<"x = "<<x<<endl;
				sort(v[x].begin(),v[x].end());
				int cnt=0,tmp=-1,mx=-1,sz=v[x].size();
				v[x].push_back(INF);
				for (auto i=v[x].begin();i!=v[x].end();i++) {
//					cout<<"i = "<<*i<<endl;
					if (*i != tmp) {
						mx = max(mx,cnt);
						tmp=*i;
						cnt=1;
					}
					else cnt++;
				}
//				cout<<"mx = "<<mx<<endl;
				ans += (sz-mx);
			}
		}
		printf("%d\n",ans);
	}
}