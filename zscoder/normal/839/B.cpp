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
typedef vector<ll> vi;
typedef long double ld; 
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds;
typedef set<ll>::iterator sit;
typedef map<ll,ll>::iterator mit;

int a[1111];
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n,k; cin>>n>>k;
	int x = 2*n;
	int y = n;
	int cnt[4]={};
	for(int i=0;i<k;i++)
	{
		cin>>a[i];
		while(y>0&&a[i]>=4)
		{
			a[i]-=4;
			y--;
		}
		if(a[i]>0)
		{
			while(a[i]>=2&&x>0)
			{
				x--;
				a[i]-=2;
			}
			cnt[a[i]]++;
		}
	}
	while(y>0&&cnt[3]>0)
	{
		cnt[3]--; y--;
	}
	while(cnt[3]>0)
	{
		cnt[3]--;
		cnt[2]++; cnt[1]++;
	}
	while(x>0&&cnt[2]>0)
	{
		x--; cnt[2]--;
	}
	while(y>0&&cnt[2]>0&&cnt[1]>0)
	{
		cnt[2]--; cnt[1]--; y--;
	}
	if(cnt[2]>0) //x = 0
	{
		if(cnt[2]<=y)
		{
			int max1 = (y - cnt[2])*2 + cnt[2];
			if(cnt[1]<=max1)
			{
				cout<<"YES\n";
				return 0;
			}
			else
			{
				cout<<"NO\n";
				return 0;
			}
		}
		else
		{
			if(y>=(cnt[2]-y)*2+cnt[1])
			{
				cout<<"YES\n";
				return 0;
			}
			else
			{
				cout<<"NO\n";
				return 0;
			}
		}
	}
	//cnt[2] = 0
	if(cnt[1]<=x+2*y) cout<<"YES\n";
	else cout<<"NO\n";
}