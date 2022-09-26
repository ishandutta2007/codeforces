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

int square(int x1, int y1)
{
	x1=abs(x1);
	y1=abs(y1);
	x1&=1;
	y1&=1;
	if(x1&&y1) return 3;
	else if(x1&&!y1) return 1;
	else if(!x1&&y1) return 2;
	else return 0;
}

int color(int x1, int y1, int x2, int y2)
{
	/*
	int res = 0;
	x2--; y2--;
	int r1,r2;
	ll tot = x2 - x1 + 1;
	ll ans = (tot-1)/2 + square(x2,y1);
	r1=ans%4;
	ans = (tot-1)/2+square(x2,y1+1);
	r2=ans%4;
	ll rows = y2 - y1 + 1;
	ll tmp = ((rows-1)/2)*ll(r1+r2);
	tmp%=4;
	tmp+=r1;
	tmp%=4;
	return tmp;
	*/
	return square(x2,y2);
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n;	cin>>n;
	cout<<"YES\n";
	for(int i = 0; i < n; i++)
	{
		int x1,y1,x2,y2;
		cin>>x1>>y1>>x2>>y2;
		cout<<color(x1,y1,x2,y2)+1<<'\n';
	}
}