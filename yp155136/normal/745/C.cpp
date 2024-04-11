#include <iostream>
#include <stdio.h>
#include <vector>
#include <cstring>
#include <algorithm>
#include <utility>
using namespace std;

#define int long long

typedef pair<int,int> pii;
typedef long long LL;
const int MAX_N = 1e3 + 6;
const int MAX_M =1e5 +6;

vector<int> edg[MAX_N];
bool king[MAX_N];
bool visit[MAX_N];
pii p[MAX_N];

int pt,eg;

void dfs(int id) {
	pt++;
	eg += edg[id].size();
	visit[id]=1;
	for (auto i:edg[id]) {
		if (!visit[i]) dfs(i);
	}
}

main () {
	int n,m,k;
	while (scanf("%I64d %I64d %I64d",&n,&m,&k) != EOF) {
		vector<int> ala;
		for (int i=0;n>=i;i++) {
			edg[i].clear();
		}
		memset(king,0,sizeof(king));
		for (int i=1;k>=i;i++) {
			int _;
			scanf("%I64d",&_);
			king[_]=1;
			ala.push_back(_);
		}
		for (int i=1;m>=i;i++) {
			int a,b;
			scanf("%I64d %I64d",&a,&b);
			edg[a].push_back(b);
			edg[b].push_back(a);
		}
		memset(visit,0,sizeof(visit));
		int totpt=0,toteg=0;
		for (auto i:ala) {
			pt=0;
			eg=0;
			dfs(i);
			eg/=2;
			totpt += pt;
			toteg += eg;
			p[i]  = make_pair(pt,eg);
		}
		//what left are clean edge & vertics
//		cout<<"totpt = "<<totpt<<" , toteg = "<<toteg<<endl;
		int ans = (n-totpt)*(n-totpt-1)/2 - (m-toteg);
		int mx=0;
//		cout<<"ans = "<<ans<<endl;
		for (auto i:ala) {
			int _pt=p[i].first,_eg=p[i].second;
			ans += (_pt*(_pt-1)/2 - _eg);
			//mx = max(mx,ans + (_pt*(_pt-1)/2 - _eg) + (n-totpt)*(_pt));
		}
		for (auto i:ala) {
			int _pt=p[i].first,_eg=p[i].second;
//			ans += (_pt*(_pt-1)/2 - _eg);
			mx = max(mx,ans + (n-totpt)*(_pt));
		}
		printf("%I64d\n",mx);
	}
}