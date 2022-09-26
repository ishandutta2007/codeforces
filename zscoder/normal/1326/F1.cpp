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
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds;

int a[22][22];
ll ans[(1<<18)+10];
ll dl[15][(1<<7)+10];
ll dr[15][(1<<7)+10];
int rev[(1<<17)];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin>>n;
	for(int i=0;i<n;i++)
	{
		string s; cin>>s;
		for(int j=0;j<n;j++)
		{
			a[i][j]=s[j]-'0';
		}
	}
	for(int i=0;i<(1<<(n-1));i++)
	{
		for(int j=0;j<n-1;j++)
		{
			if(i&(1<<j)) rev[i]|=(1<<(n-2-j));
		}
	}
	int lsiz = n/2;
	for(int i=0;i<(1<<n);i+=2)
	{
		if(__builtin_popcount(i)!=lsiz) continue;
		vi L,R;
		for(int j=0;j<n;j++)
		{
			if(i&(1<<j)) L.pb(j);
			else R.pb(j);
		}
		/*
		for(int x:L)
		{
			cerr<<x<<' ';
		}
		cerr<<'\n';
		*/
		memset(dl,0,sizeof(dl));
		memset(dr,0,sizeof(dr));
		do
		{
			int bit=0;
			for(int i=0;i+1<L.size();i++)
			{
				if(a[L[i]][L[i+1]]) bit|=(1<<i);
			}
			dl[L.back()][bit]++;
		}while(next_permutation(L.begin(),L.end()));
		do
		{
			int bit=0;
			for(int i=0;i+1<R.size();i++)
			{
				if(a[R[i]][R[i+1]]) bit|=(1<<i);
			}
			dr[R.front()][bit]++;
		}while(next_permutation(R.begin(),R.end()));
		for(int x:L)
		{
			for(int i=0;i<(1<<(int(L.size())-1));i++)
			{
				if(dl[x][i]==0) continue;
				for(int y:R)
				{					
					for(int j=0;j<(1<<(int(R.size())-1));j++)
					{
						int b = (i|(j<<(int(L.size()))));
						if(a[x][y]) b|=(1<<(int(L.size())-1));
						ans[b]+=dl[x][i]*1LL*dr[y][j];
						if(n%2==1&&y==0) continue;
						ans[rev[b]]+=dl[x][i]*1LL*dr[y][j];
					}
				}
			}
		}
	}
	for(int i=0;i<(1<<(n-1));i++)
	{
		cout<<ans[i];
		if(i+1<(1<<(n-1))) cout<<' ';
	}
	cout<<'\n';
}