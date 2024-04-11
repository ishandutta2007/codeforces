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
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds;

struct node
{
	int a[10][10];
	char l,r;
	char lazy;
	node()
	{
		memset(a,0,sizeof(a));
		l=r='.'; lazy='$';
	}
	node(char c)
	{
		memset(a,0,sizeof(a));
		l=r=c; lazy='$';
	}
	node operator+(const node& nd) {
		node tmp;
		for(int i=0;i<10;i++)
		{
			for(int j=0;j<10;j++) tmp.a[i][j]=this->a[i][j]+nd.a[i][j];
		}
		if(this->r!='.'&&nd.l!='.') tmp.a[this->r-'a'][nd.l-'a']++;
		tmp.l=this->l;
		tmp.r=nd.r;
		tmp.lazy='$';
		return tmp;		
	}
};

string s;
node st[211111*4];

/*
void print(int id)
{
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			cerr<<st[id].a[i][j]<<' ';
		}
		cerr<<'\n';
	}
	cerr<<'\n';
}
*/

void combine(int id)
{
	st[id]=st[id*2]+st[id*2+1];
}

void build(int id, int l, int r)
{
	if(r-l<2)
	{
		st[id]=node(s[l]);
		return ;
	}
	int mid=(l+r)>>1;
	build(id*2,l,mid); build(id*2+1,mid,r);
	combine(id);
}

void push(int id, int l, int r)
{
	if(st[id].lazy!='$')
	{
		//cerr<<"LAZY "<<id<<" = "<<st[id].lazy<<'\n';
		char c = st[id].lazy;
		st[id]=node(c);
		st[id].a[c-'a'][c-'a']=r-l-1;
		if(r-l>=2)
		{
			st[id*2].lazy=st[id*2+1].lazy=c;
		}
		st[id].lazy='$';
	}
}

void update(int id, int l, int r, int ql, int qr, char c)
{
	push(id,l,r);
	if(ql>=r||l>=qr) return ;
	if(ql<=l&&r<=qr)
	{
		st[id].lazy=c;
		push(id,l,r); return ;
	}
	int mid=(l+r)>>1;
	update(id*2,l,mid,ql,qr,c); update(id*2+1,mid,r,ql,qr,c);
	combine(id);
	return ;
}

node query(int id, int l, int r, int ql, int qr)
{
	push(id,l,r);
	if(ql>=r||l>=qr) return node();
	if(ql<=l&&r<=qr)
	{
		return st[id];
	}
	int mid=(l+r)>>1;
	return query(id*2,l,mid,ql,qr)+query(id*2+1,mid,r,ql,qr);
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n,m,k; cin>>n>>m>>k;
	cin>>s;
	build(1,0,n);
	for(int z=0;z<m;z++)
	{
		int t; cin>>t;
		if(t==1)
		{
			int l,r; char c;
			cin>>l>>r>>c;
			l--; r--;
			update(1,0,n,l,r+1,c);
		}
		else
		{
			string t; cin>>t;
			node tmp = query(1,0,n,0,n);
			int ans=0;
			for(int i=0;i<t.length();i++)
			{
				for(int j=i;j<t.length();j++)
				{
					ans+=tmp.a[t[j]-'a'][t[i]-'a'];
				}
			}
			ans++;
			cout<<ans<<'\n';
		}
	}
}

//Template from https://github.com/zscoder/CompetitiveProgramming/blob/master/Data%20Structures%20Class%20Template.cpp.