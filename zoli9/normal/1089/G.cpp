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

int test;
ll n;
int t[10];
ll sum=0;

int main(){
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	cin>>test;
	for(int tt=1; tt<=test; tt++)
	{
		cin>>n;
		sum=0;
		for(int i=0; i<7; i++)
		{
		    cin>>t[i];
			if(t[i]>0) sum++;
		}
		ll weeks=(n-1)/sum;
		ll need=n-weeks*sum;
		ll ans=7;
		for(int j=0; j<7; j++)
		{
			ll n2=need;
			ll i=0;
			while(n2>0 && i<7)
			{
				n2-=t[(i+j)%7];
				i++;
			}
			if(n2==0) ans=min(ans, i);
		}
		ans+=(weeks*7ll);
		cout<<ans<<endl;
	}

	return 0;
}