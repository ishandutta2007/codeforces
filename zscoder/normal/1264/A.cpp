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

int a[555555];
void solve()
{
	int n; cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	int id = n/2-1;
	while(id>=0&&a[id]==a[id+1])
	{
		id--;
	}
	if(id<0)
	{
		cout<<0<<' '<<0<<' '<<0<<'\n'; return ;
	}
	int cnt=0;
	for(int i=0;i<=id;i++)
	{
		if(a[i]==a[0])
		{
			cnt++;
		}
		else break;
	}
	int cnt2=cnt+1;
	for(int i=cnt*2+1;i<=id;i++)
	{
		if(a[i]==a[i-1])
		{
			cnt2++;
		}
		else break;
	}
	int cnt3=0;
	for(int i=cnt+cnt2;i<=id;i++)
	{
		cnt3++;
	}
	if(cnt<=0||cnt2<=0||cnt3<=0||cnt>=cnt2||cnt>=cnt3) cout<<0<<' '<<0<<' '<<0<<'\n';
	else cout<<cnt<<' '<<cnt2<<' '<<cnt3<<'\n';
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t; cin>>t;
	while(t--) solve();
}