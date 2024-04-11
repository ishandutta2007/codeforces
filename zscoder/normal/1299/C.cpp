#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
using namespace std;
using namespace __gnu_pbds;
 
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define fbo find_by_order
#define ook order_of_key
 
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<int> vi;
typedef long double ld; 
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

ll a[1001111];
ll F[1001111];

bool bad(int i, int j, int k)
{
	//(F[k]-F[i])/(k-i) <= (F[j]-F[i])/(j-i)
	return (F[k]-F[i])*1LL*(j-i)<=(F[j]-F[i])*1LL*(k-i);
}

int main()
{
	int n; scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%lld",a+i);
		F[i+1]=a[i]+F[i];
	}
	ii lastfrac = mp(0,1);
	vector<int> S;
	S.pb(0);
	for(int i=1;i<=n;i++)
	{
		while(S.size()>=2&&bad(S[int(S.size())-2],S[int(S.size())-1],i))
		{
			S.pop_back();
		}
		S.push_back(i);
	}
	for(int i=0;i+1<S.size();i++)
	{
		int l=S[i]; int r=S[i+1];
		//cerr<<l<<' '<<r<<'\n';
		ld grad = ld(F[r]-F[l])/ld(r-l);
		for(int j=l;j<r;j++)
		{
			printf("%.12Lf\n",grad);
		}
	}
}