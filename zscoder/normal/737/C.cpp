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

int n, s;
int a[200011];
const int INF = 300000;
int dp[200011][2];
int cnt[INF+1];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin>>n>>s;
	s--;
	int ans = 0;
	for(int i = 0; i < n; i++)
	{
		cin>>a[i];
		if(a[i]==0&&i!=s)
		{
			a[i] = INF;
		}
		if(i==s&&a[i]!=0)
		{
			a[i] = 0;
			ans++;
		}
		cnt[a[i]]++;
	}
	int extra = 0;
	int ptr = INF;
	for(int i = 0; i <= INF; i++)
	{
		if(cnt[i] > 1) extra+=(cnt[i]-1);
		if(cnt[i] == 0)
		{
			while(ptr>i)
			{
				if(cnt[ptr]>0)
				{
					cnt[ptr]--;
					cnt[i]++;
					ans++;
					break;
				}
				else
				{
					ptr--;
				}
			}
		}
	}
	cout<<ans;
	/*
	int ans2 = -1;
	int lo = 0; int hi = n - 1;
	while(lo<=hi)
	{
		int mid = (lo+hi)>>1;
		int quota = mid;
		int cur = 0;
		bool pos = true;
		for(int i = 0; i < n - mid; i++)
		{
			if(cnt[i]-cur<=1)
			{
				cur=cnt[i];
			}
			else
			{
				while(quota>0&&cnt[i]-cur>1)
				{
					quota--;
					cur++;
				}
				if(quota==0&&cnt[i]-cur>1)
				{
					pos=false;
					break;
				}
			}
		}
		if(!pos)
		{
			lo = mid + 1;
		}
		else
		{
			hi = mid - 1;
			ans2 = mid;
		}
	}
	cout<<ans+ans2;
	*/
	
}