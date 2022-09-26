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
typedef set<int>::iterator sit;
typedef map<int,int>::iterator mit;
typedef vector<int>::iterator vit;

int pref[100001];
int suff[100001];
const int INF = 10019312;
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	string a,b;
	cin>>a>>b;
	pref[0] = -1;
	int ptr = 0;
	for(int i = 1; i <= b.length(); i++)
	{
		char c = b[i-1];
		while(ptr<a.length())
		{
			if(c==a[ptr]) break;
			ptr++;
		}
		if(ptr>=a.length()) pref[i] = INF;
		else pref[i] = ptr;
		ptr++;
	}
	int n = b.length();
	ptr = int(a.length()) - 1;
	suff[n] = int(a.length());
	for(int i = n - 1; i >= 0; i--)
	{
		char c = b[i];
		while(ptr>=0)
		{
			if(c==a[ptr]) break;
			ptr--;
		}
		if(ptr<0) suff[i]=-INF;
		else suff[i]=ptr;
		ptr--;
	}
	ii bestsol = mp(0, n);
	int res = n;
	for(int i = 0; i <= n; i++)
	{
		//pref[i] find the largest suff[j]
		int lo = i; int hi = n;
		int ans = -1;
		while(lo<=hi)
		{
			int mid = (lo+hi)>>1;
			if(suff[mid]>pref[i])
			{
				ans=mid;
				hi = mid - 1;
			}
			else
			{
				lo = mid + 1;
			}
		}
		if(ans==-1) continue;
		if(ans-i<res)
		{
			res=ans-i;
			bestsol = mp(i,ans);
		}
	}
	string A;
	//cerr<<bestsol.fi<<' '<<bestsol.se<<'\n';
	//cerr<<pref[3]<<' '<<suff[8]<<'\n';
	A+=b.substr(0,bestsol.fi);
	if(bestsol.se<n) A+=b.substr(bestsol.se,n-bestsol.se);
	if(A.length()==0) cout<<'-';
	else cout<<A;
}