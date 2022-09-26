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
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds;

const int N = 622222;

struct node
{
	int sum,ans; //minimum prefix sum
};

node st[4*N+11];

void build(int id, int l, int r)
{
	st[id].ans=st[id].sum=0;
	if(r-l<2)
	{
		return ;
	}
	int mid=(l+r)>>1;
	build(id*2,l,mid); build(id*2+1,mid,r);
}

void combine(int id)
{
	st[id].sum=st[id*2].sum+st[id*2+1].sum;
	st[id].ans=min(st[id*2].ans,st[id*2].sum+st[id*2+1].ans);
}

void update(int id, int l, int r, int pos, int v)
{
	if(pos>=r||pos<l) return ;
	if(r-l<2)
	{
		st[id].ans=st[id].sum=v;
		return ;
	}
	int mid=(l+r)>>1;
	update(id*2,l,mid,pos,v); update(id*2+1,mid,r,pos,v);
	combine(id);
}

ii query(int id, int l, int r, int ql, int qr)
{
	if(ql>=qr) return {0,0};
	if(ql>=r||l>=qr) return {int(1e9),0};
	if(ql<=l&&r<=qr) return {st[id].ans,st[id].sum};
	int mid=(l+r)>>1;
	ii L = query(id*2,l,mid,ql,qr);
	ii R = query(id*2+1,mid,r,ql,qr);
	return {min(L.fi,L.se+R.fi),L.se+R.se};
}

int a[333333];
int b[333333];
int pos[333333];
int res[333333];
int bad[333333];

void naive_check(int n)
{
	for(int i=0;i<n;i++)
	{
		b[i]/=2;
	}
	for(int i=0;i<n;i++)
	{
		bad[i]=0;
	}
	for(int i=0;i<n;i++)
	{
		set<int> S;
		for(int j=0;j<n;j++)
		{
			S.insert(a[j]);
			if(bad[j]) S.erase(prev(S.end()));
		}
		if(res[i]!=*(prev(S.end()))) 
		{
			cerr<<"FAIL "<<endl;
			cerr<<"GIVEN RESULT AT "<<i<<" = "<<res[i]<<'\n';
			cerr<<"EXPECTED RESULT AT "<<i<<" = "<<*(prev(S.end()))<<'\n';
			cout<<n<<'\n';
			for(int i=0;i<n;i++)
			{
				cout<<a[i]+1<<' ';
			}
			cout<<'\n';
			for(int i=0;i<n;i++)
			{
				cout<<b[i]+1<<' ';
			}
			cout<<'\n';
			exit(0);
		}
		bad[b[i]]=1;
	}
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	srand(1334);
	const bool DEBUG=0;
	for(int cc=1;;cc++)
	{
		int n; 
		if(!DEBUG)
		{
			cin>>n;
		}
		else n=rand()%55+1;
		vi p,q;
		for(int i=0;i<n;i++)
		{
			p.pb(i); q.pb(i);
		}
		random_shuffle(p.begin(),p.end());
		random_shuffle(q.begin(),q.end());
		for(int i=0;i<n;i++)
		{
			if(!DEBUG) 
			{
				cin>>a[i]; a[i]--;
			}
			else a[i]=p[i];
			pos[a[i]]=2*i;
		}
		for(int i=0;i<n;i++)
		{
			if(!DEBUG)
			{
				cin>>b[i]; b[i]--;
			}
			else b[i]=q[i];
			b[i]=2*b[i]+1;
		}
		build(1,0,2*n);
		int cur=-1;
		for(int i=0;i<n;i++) res[i]=0;
		for(int ans=n-1;ans>=0;ans--)
		{
			//current answer is ans
			update(1,0,2*n,pos[ans],1);
			ii tmp = query(1,0,2*n,0,pos[ans]);
			//cerr<<ans<<' '<<cur<<' '<<query(1,0,2*n,pos[ans],2*n).fi<<' '<<min(0,tmp.fi)<<' '<<tmp.se<<'\n';
			if(query(1,0,2*n,pos[ans],2*n).fi<=min(0,tmp.fi)-tmp.se)
			{
				continue;
			}
			cur++;
			res[cur]=ans;
			while(cur<n)
			{
				//bring b[cur] in
				update(1,0,2*n,b[cur],-1);
				//try to see if cur+1 works
				tmp = query(1,0,2*n,0,pos[ans]);
				if(query(1,0,2*n,pos[ans],2*n).fi<=min(0,tmp.fi)-tmp.se)
				{
					//update(1,0,2*n,b[cur],0);
					break;
				}
				else
				{
					cur++;
					res[cur]=ans;
				}
			}
		}
		if(DEBUG) naive_check(n);
		if(!DEBUG)
		{
			for(int i=0;i<n;i++)
			{
				cout<<res[i]+1;
				if(i+1<n) cout<<' ';
			}
			cout<<'\n';
			return 0;
		}
		else
		{
			cerr<<"Case #"<<cc<<" complete\n";
		}
	}
}