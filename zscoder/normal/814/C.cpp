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
typedef vector<ll> vi;
typedef long double ld; 
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
typedef set<int>::iterator sit;
typedef map<int,int>::iterator mit;
typedef vector<int>::iterator vit;

int ans[1501][27];
int minchange[15001];
int cnt[1501];

int sum(int l, int r)
{
	if(l==0) return cnt[r];
	else return cnt[r]-cnt[l-1];
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin>>n;
	string s; cin>>s;
	int q; cin>>q;
	for(int z=0;z<26;z++)
	{
		for(int i=0;i<n;i++)
		{
			if(s[i]!='a'+z) cnt[i]=1;
			else cnt[i]=0;
			if(i>0) cnt[i]+=cnt[i-1];
		}
		minchange[0]=0;
		for(int i=1;i<=n;i++)
		{
			minchange[i]=1000000;
			for(int j=0;j+i-1<n;j++)
			{
				//[j, j + i -1]
				minchange[i]=min(minchange[i],sum(j,j+i-1));
			}
		}
		for(int i=n-1;i>=0;i--)
		{
			minchange[i]=min(minchange[i],minchange[i+1]);
		}
		minchange[n+1]=n+1;
		for(int i=0;i<=n;i++)
		{
			for(int j=minchange[i];j<minchange[i+1];j++)
			{
				ans[j][z]=i;
			}
		}
	}
	for(int i=0;i<q;i++)
	{
		int color; char c;
		cin>>color>>c;
		cout<<ans[color][c-'a']<<'\n';
	}
}