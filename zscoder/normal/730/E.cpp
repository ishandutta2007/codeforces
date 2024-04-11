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

int a[101];
int d[101];
int score[101];
vector<ii> down;
vector<ii> up;
int n;

int rnk(int x)
{
	int cnt = 1;
	for(int i = 0; i < n; i++)
	{
		if(score[i]>score[x]) cnt++;
	}
	return cnt;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		cin>>a[i]>>d[i];
		a[i]*=1000; a[i]+=(n-1-i);
		d[i]*=1000;
		if(d[i]<0)
		{
			down.pb(mp(-a[i], i));
		}
		else
		{
			up.pb(mp(a[i],i));
		}
		score[i] = a[i];
	}
	sort(down.begin(),down.end());
	sort(up.begin(),up.end());
	int ans = 0;
	for(int i = 0; i < up.size(); i++)
	{
		int x = rnk(up[i].se);
		score[up[i].se] += d[up[i].se];
		int y = rnk(up[i].se);
		ans+=abs(x-y);
	}
	for(int i = 0; i < down.size(); i++)
	{
		int x = rnk(down[i].se);
		score[down[i].se] += d[down[i].se];
		int y = rnk(down[i].se);
		ans+=abs(x-y);
	}
	cout<<ans;
}