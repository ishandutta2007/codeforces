#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

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

const int C = 2500;
const int N = 301001;
int a[333333];
short ans[N/C+3][N];
int dp[333333];

struct Fenwick
{
	vector<ll> t;
    Fenwick(int n)
    {
        t.assign(n+1,0);
    }
    void reset(int n)
    {
		t.assign(n+1, 0);
	}
    void update(int p, ll v)
    {
        for (; p < (int)t.size(); p += (p&(-p))) t[p] += v;
    }
    ll query(int r) //finds [1, r] sum
    {                     
        ll sum = 0;
        for (; r; r -= (r&(-r))) sum += t[r];
        return sum;
    }
    ll query(int l, int r) //finds [l, r] sum
    {
		if(l == 0) return query(r);
		return query(r) - query(l-1);
	}
};
Fenwick fen(1);
void prepblock(int l, int r)
{
	fen.reset(N);
	pbds T;
	for(int i=l;i<=r;i++)
	{
		int lo=0;
		int hi=a[i];
		int res=300111;
		while(lo<=hi)
		{
			int mid=(lo+hi)>>1;
			int cnt = mid+fen.query(mid+1); //<= mid de
			if(cnt>=a[i])
			{
				//enough
				res=mid;
				hi=mid-1;
			}
			else lo=mid+1;
		}
		dp[i]=res;
		//cerr<<i<<' '<<dp[i]<<'\n';
		//T.insert(dp[i]);	
		fen.update(dp[i]+1,1);
		ans[l/C][dp[i]]++; //if i start from >= dp[i] i sure win this guy
	}
	for(int i=1;i<N;i++) ans[l/C][i]+=ans[l/C][i-1]; //if i use 1 what can i do
	//cerr<<"BL ANS: "<<ans[l/C][0]<<'\n';
}

int query(int l, int r)
{
	int res=0;
	int rem=l%C;
	if(rem>0) rem=C-rem;
	while(l<=r&&rem>0)
	{
		if(res>=a[l]&&a[l]>=0) res++;
		l++; rem--;
	}
	if(l<r) assert(l%C==0);
	int bl=l/C;
	while(l+C-1<=r)
	{
		res+=ans[bl][res]; l+=C; bl++;
	}
	while(l<=r)
	{
		if(res>=a[l]&&a[l]>=0) res++;
		l++;
	}
	return res;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n,q; cin>>n>>q;
	//n=900;q=1;
	for(int i=0;i<n;i++) 
	{
		cin>>a[i]; 
		//a[i]=1;
		a[i]=(i+1)-a[i];
		//cerr<<i<<' '<<a[i]<<'\n';
	}
	for(int i=0;i<n;i+=C)
	{
		int l=i; int r=min(n-1,i+C-1);
		prepblock(l,r);
	}
	for(int i=0;i<q;i++)
	{
		int l,r; cin>>l>>r;
		r=n-1-r;
		cout<<query(l,r)<<'\n';
	}
}