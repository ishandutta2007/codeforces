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
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
typedef set<int>::iterator sit;
typedef map<int,int>::iterator mit;
typedef vector<int>::iterator vit;

int cnt[2][1025];
int cur;

void upd(int x)
{
	int pre = cur;
	cur^=1;
	int par = 0;
	for(int i = 0; i < 1024; i++) cnt[cur][i]=0;
	for(int i = 0; i < 1024; i++)
	{
		if(cnt[pre][i]==0) continue;
		int v = cnt[pre][i];
		if(v&1)
		{
			if(!par)
			{
				cnt[cur][(i^x)]+=(v+1)/2;
				cnt[cur][i]+=(v-1)/2;
			}
			else
			{
				cnt[cur][(i^x)]+=(v-1)/2;
				cnt[cur][i]+=(v+1)/2;
			}
			par^=1;
		}
		else
		{
			cnt[cur][(i^x)]+=v/2;
			cnt[cur][i]+=v/2;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin>>n;
	int k, x; cin>>k>>x;
	cur=0;
	for(int i =0;i<n;i++)
	{
		int z; cin>>z;
		cnt[cur][z]++;
	}
	for(int i = 0; i < k; i++) upd(x);
	for(int i = 1023; i >= 0; i--)
	{
		if(cnt[cur][i]>0)
		{
			cout<<i<<' ';
			break;
		}
	}
	for(int i = 0; i <= 1023; i++)
	{
		if(cnt[cur][i]>0)
		{
			cout<<i;
			break;
		}
	}
}