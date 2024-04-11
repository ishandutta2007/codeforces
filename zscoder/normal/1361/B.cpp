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
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds;

vector<int> fact;
vector<int> ifact;
vector<int> inv;
vector<int> pow2;
const int MOD = (1e9 + 7);
int add(int a, int b)
{
	a+=b;
	while(a>=MOD) a-=MOD;
	return a;
}
void radd(int &a, int b)
{
	a=add(a,b); 
}
int mult(int a, int b)
{
	return (a*1LL*b)%MOD;
}
void rmult(int &a, int b)
{
	a=mult(a,b);
}
int modpow(int a, int b)
{
	int r=1;
	while(b)
	{
		if(b&1) r=mult(r,a);
		a=mult(a,a);
		b>>=1;
	}
	return r;
}
int choose(int a, int b)
{
	if(a<b) return 0;
	if(b==0) return 1;
	if(a==b) return 1;
	return mult(fact[a],mult(ifact[b],ifact[a-b]));
}
int inverse(int a)
{
	return modpow(a,MOD-2);
}
void init(int _n)
{
	fact.clear(); ifact.clear(); inv.clear(); pow2.clear();
	fact.resize(_n+1);
	ifact.resize(_n+1);
	inv.resize(_n+1);
	pow2.resize(_n+1);
	pow2[0]=1;
	ifact[0]=1;
	fact[0]=1;
	for(int i=1;i<=_n;i++)
	{
		pow2[i]=add(pow2[i-1],pow2[i-1]);
		fact[i]=mult(fact[i-1],i);
		//ifact[i]=mult(ifact[i-1],inv[i]);
	}
	ifact[_n] = inverse(fact[_n]);
	for(int i=_n-1;i>=1;i--)
	{
		ifact[i] = mult(ifact[i + 1], i + 1);
	}
	for(int i=1;i<=_n;i++)
	{
		inv[i] = mult(fact[i-1],ifact[i]);
	}
}

void normalize(deque<int> &v, int p)
{
	for(int i=0;i<v.size();i++)
	{
		while(v[i]<0)
		{
			v[i+1]--; v[i]+=p;
		}
	}
}

void solve()
{
	int n,p; cin>>n>>p;
	vi val(n); vi vec(n);
	for(int i=0;i<n;i++)
	{
		int x; cin>>x; vec.pb(x);
	}
	sort(vec.rbegin(),vec.rend());
	if(p==1)
	{
		if(n%2==0) cout<<0<<'\n';
		else cout<<1<<'\n';
		return ;
	}
	int ans=0; //additions to answer
	const int C = 40; //length of array
	deque<int> curnum(C,0); 
	int minflag=vec[0]-(C-1);
	for(int i=0;i<n;i++)
	{
		int val=vec[i];
		if(curnum.back()==0)
		{
			minflag=val-(C-1);
			curnum[val-minflag]=1;
		}
		else
		{
			if(val<minflag)
			{
				for(int j=0;j<C;j++)
				{
					if(curnum[j]!=0)
					{
						radd(ans,mult(curnum[j],modpow(p,j+minflag)));
					}
				}
				for(int j=i;j<n;j++)
				{
					radd(ans,MOD-modpow(p,vec[j]));
				}				
				for(int j=0;j<C;j++) curnum[j]=0;
				break;
			}
			else
			{
				curnum[val-minflag]--;
				normalize(curnum,p);
			}
		}
		int lasid=-1;
		for(int j=C-1;j>=0;j--)
		{
			if(curnum[j]!=0) 
			{
				lasid=j; break;
			}
		}
		if(lasid==-1) continue;
		for(int j=lasid+1;j<C;j++)
		{
			curnum.pop_back(); curnum.push_front(0); minflag--;
		}
	}
	for(int j=0;j<C;j++)
	{
		if(curnum[j]!=0)
		{
			radd(ans,mult(curnum[j],modpow(p,j+minflag)));
		}
	}
	cout<<ans<<'\n';
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t; cin>>t;
	while(t--) solve();
}