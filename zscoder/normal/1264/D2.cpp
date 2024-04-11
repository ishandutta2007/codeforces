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
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef long double ld; 
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
	if(a<0) return 0;
	if(b<0) return 0;
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

int dp[2222][2222];
int pref[1000111][3];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	string s; cin>>s;
	int n = s.length();
	init(1000111);
	for(int i=0;i<2011;i++)
	{
		for(int j=0;j<2011;j++)
		{
			dp[i][j]=choose(i,j);
			if(j>0) dp[i][j]=add(dp[i][j],dp[i][j-1]);
		}
	}
	int a[3]={0,0,0};
	for(int i=0;i<n;i++)
	{
		if(s[i]=='(') a[0]++;
		else if(s[i]==')') a[1]++;
		else a[2]++;
		for(int j=0;j<3;j++) pref[i][j]=a[j];
	}
	int ans=0;
	int P[2] = {0,0};
	for(int j=0;j<n;j++)
	{
		P[0]=add(P[0],MOD-choose(a[2]-1,j-a[1]));
		P[1]=add(P[1],MOD-choose(a[2],j-a[1]));
		if(s[j]==')') continue;
	
		int b[3] = {0,0,0};
		if(j>0) 
		{
			for(int k=0;k<3;k++) b[k]=pref[j-1][k];
		}
		int c[3];
		for(int k=0;k<3;k++) c[k]=a[k]-pref[j][k];
		ans=add(ans,pow2[c[2]+b[2]]);
		/*
		for(int x=0;x<=b[2];x++)
		{
			if(x+b[0]-c[1]>=0) cerr<<b[2]<<' '<<x<<' '<<c[2]<<' '<<x+b[0]-c[1]<<'\n';
			for(int z=0;z<=x+b[0]-c[1];z++)
			{
				ans=add(ans,MOD-mult(choose(b[2],x),choose(c[2],z)));
			}
		}
		*/
		
		if(b[2]+c[2]==a[2])
		{
			ans=add(ans,P[1]);
		}
		else 
		{
			assert(a[2]==b[2]+c[2]+1);
			ans=add(ans,P[0]);
		}
		
		//for(int z=0;z<=j-1-a[1];z++) ans=add(ans,MOD-choose(b[2]+c[2],z));
		//for(int z=max(0,c[2]-b[0]+c[1]);z<=b[2]+c[2];z++) ans=add(ans,MOD-choose(b[2]+c[2],z));
	}
cout<<ans<<'\n';
}