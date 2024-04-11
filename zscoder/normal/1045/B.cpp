#include <bits/stdc++.h>
using namespace std;
#define pb push_back
typedef vector<int> vi;
set<int> S;int n, m; vi vec;set<int> ans;int testcnt;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count()); cin>>n>>m;
	long long s=0;
	for(int i=0;i<n;i++)
	{
		int x; cin>>x; s+=x; S.insert(x); vec.pb(x);
	}
	s*=2; s%=m;
	random_shuffle(vec.begin(),vec.end());
	for(int i=0;i<n;i++) 
	{
		int v = (vec[0]+vec[i])%m; if((n*1LL*v)%m!=s) continue;
		ans.insert(v);
	}
	if(ans.empty()){cout<<0<<'\n'; return 0;}
	testcnt=int(4e6)/int(ans.size());
	vi T; for(int x:ans) T.pb(x);
	for(int x:T)
	{
		for(int i=0;i<testcnt;i++)
		{
			int lab = uniform_int_distribution<int>(0, n-1)(rng);
			int v = (x - vec[lab])%m;
			if(v<0) v+=m;
			if(S.find(v)==S.end()){ans.erase(x); break ;}
		}
	}
	cout<<ans.size()<<'\n';
	for(int x:ans) cout<<x<<' ';
	if(!ans.empty()) cout<<'\n';
}