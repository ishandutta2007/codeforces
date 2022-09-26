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

struct node
{
	int sum,mn,mx;
	node(){sum=mn=mx=0;}
};

node st[4001111];

void combine(int id)
{
	st[id].sum=st[id*2].sum+st[id*2+1].sum;
	st[id].mn=min(st[id*2].mn,st[id*2].sum+st[id*2+1].mn);
	st[id].mx=max(st[id*2].mx,st[id*2].sum+st[id*2+1].mx);
}

void update(int id, int l, int r, int pos, int v)
{
	if(pos>=r||pos<l) return ;
	if(r-l<2)
	{
		st[id].sum=v;
		st[id].mx=max(0,v);
		st[id].mn=min(0,v);
		return ;
	}
	int mid=(l+r)>>1;
	update(id*2,l,mid,pos,v); update(id*2+1,mid,r,pos,v);
	combine(id);
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin>>n;
	string s; cin>>s;
	int p=0;
	for(int i=0;i<n;i++)
	{
		p=max(p,0);
		if(s[i]=='L') p--;
		else if(s[i]=='R') p++;
		else if(s[i]=='(') update(1,0,n,p,1);
		else if(s[i]==')') update(1,0,n,p,-1);
		else update(1,0,n,p,0);
		if(st[1].sum!=0||st[1].mn<0)
		{
			cout<<-1<<' ';
		}
		else
		{
			cout<<st[1].mx<<' ';
		}
	}
}