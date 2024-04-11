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

int block[13];
int blockbet[13];

int fix(int x)
{
	while(x>12) x-=12;
	while(x<=0) x+=12;
	return x;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
	int h,m,s,a,b; cin>>h>>m>>s>>a>>b;
	//where is hour hand
	if(m==0&&s==0) 
	{
		block[h]=1;
	}
	else
	{
		blockbet[h]=1;
	}
	//where is minute hand
	if(s==0&&m%5==0)
	{
		block[fix(m/5)]=1;
	}
	else
	{
		blockbet[fix(m/5)]=1;
	}
	//where is second
	if(s%5==0)
	{
		block[fix(s/5)]=1;
	}
	else
	{
		blockbet[fix(s/5)]=1;
	}
	//a, a + 1, ...
	bool pos=1;
	for(int i=a;i!=b;i=fix(i+1))
	{
		int u = i; int v = fix(i+1);
		//can i get from u to v?
		if(block[u]||block[v])
		{
			pos=0;
			break;
		}
		if(blockbet[u])
		{
			pos=0;
			break;
		}
	}
	if(pos)
	{
		cout<<"YES\n";
		return 0;
	}
	swap(a,b);
	pos=1;
	for(int i=a;i!=b;i=fix(i+1))
	{
		int u = i; int v = fix(i+1);
		//can i get from u to v?
		if(block[u]||block[v])
		{
			pos=0;
			break;
		}
		if(blockbet[u])
		{
			pos=0;
			break;
		}
	}
	if(pos) cout<<"YES\n";
	else cout<<"NO\n";
}