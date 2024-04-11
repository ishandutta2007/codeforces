#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
 
#define fi first
#define se second
#define mp make_pair
#define pb push_back
 
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<int> vi;
typedef unsigned long long ull;
typedef double ld; 
typedef tree<ii, null_type, less<ii>, rb_tree_tag, tree_order_statistics_node_update> pbds;

vector<int> fact;
vector<int> ifact;
vector<int> inv;
vector<int> pow2;
const int MOD = 998244353;
int add(int a, int b)
{
	a+=b;
	while(a>=MOD) a-=MOD;
	return a;
}
int mult(int a, int b)
{
	return (a*1LL*b)%MOD;
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
	
int L[2222222];
int R[2222222];
int c[2222222];
bool pos=1;
int curval=1;
void dfs(int u)
{
	if(u<0) return ;
	if(L[u]>=0) c[L[u]]=c[u]^1;
	if(R[u]>=0) c[R[u]]=c[u];
	if(L[u]<0)
	{
		if(c[u]!=curval%2)
		{
			curval++;
		}
	}
	dfs(L[u]); 
	//cerr<<u<<' '<<c[u]<<' '<<curval<<'\n';
	if(c[u]!=curval%2){pos=0;}
	curval++;
	dfs(R[u]);
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	init(1010101);
	int n; cin>>n;
	/*
	F[0]=0;
	F[1]=0;
	for(int i=2;i<=n;i++)
	{
		F[i]=ll(1e18);
		for(int j=0;j<=i-1;j++)
		{
			F[i]=min(F[i],F[j]+F[i-1-j]);
			//cerr<<F[j]+F[i-1-j]+i-1<<' ';
		}
		F[i]+=i-1;
		cerr<<F[i]<<'\n';
		vi vec;
		for(int j=0;j<=i-1;j++)
		{
			if(F[j]+F[i-1-j]+i-1==F[i]) vec.pb(j);
		}
		cerr<<"L R : "<<vec[0]<<' '<<vec.back()<<'\n';
	}
	*/
	int largest=1;
	while((1<<(largest+1))-1<=n) largest++;
	int n2=(1<<largest)-1;
	memset(L,-1,sizeof(L)); memset(R,-1,sizeof(R));
	for(int i=0;i<n2;i++)
	{
		if(2*i+1<n2) L[i]=2*i+1; 
		if(2*i+2<n2) R[i]=2*i+2;
	}
	int ans=0;
	for(c[0]=0;c[0]<2;c[0]++)
	{
		curval=1; pos=1;
		dfs(0);
		if(curval!=n+1) continue;
		if(pos) ans++;
	}
	cout<<ans<<'\n';
}