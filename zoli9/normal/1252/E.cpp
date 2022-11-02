#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=a; i<(b); ++i)
#define trav(a,x) for(auto& a : x)
#define all(x) x.begin, x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;

#define TESTING

#ifdef TESTING
#define TO
#else
#define TO if(0)
#endif

int best[100009];
int job[100009];
vector<ll> v;
int n, k;


int main(){
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	cin>>n>>k;
	for(int i=1; i<=n; i++)
	{
		cin>>job[i];
	}
	for(int i=1; i<=n; i++)
	{
		ll x;
		cin>>x;
		if(best[job[i]]==0) best[job[i]]=x;
		else
		{
			if(x>best[job[i]])
			{
				v.push_back(best[job[i]]);
				best[job[i]]=x;
			}
			else
			{
				v.push_back(x);
			}
		}
	}
	ll nojob=0;
	for(int i=1; i<=k; i++)
	{
		if(best[i]==0) nojob++;
	}
	sort(v.begin(), v.end());
	ll ans=0;
	for(int i=0; i<nojob; i++)
	{
		ans+=v[i];
	}
	cout<<ans<<endl;

	return 0;
}