#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
 
#define fi first
#define se second
#define mp make_pair
#define pb push_back
 
typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef unsigned long long ull;
typedef long double ld; 
typedef tree<ii, null_type, less<ii>, rb_tree_tag, tree_order_statistics_node_update> pbds;

ll ans[1234567];

void update(int l, int r, ll v)
{
	if(l>r) return ;
	ans[l]+=v; ans[r+1]-=v;
}

void go()
{
	for(int i=1;i<=1234565;i++) ans[i]+=ans[i-1];
}

const int LG = 20;
const ll INF = ll(1e18);
ll st[LG][1111111];	
	
ll query(int l, int r)
{
	int k = 31 - __builtin_clz(r-l);
	if(l==r) k=0;
	return max(st[k][l], st[k][r - (1<<k) + 1]);
}

int main()
{
	int n,w; scanf("%d %d",&n,&w);
	for(int i=0;i<n;i++)
	{
		int l; scanf("%d",&l);
		vi v(l);
		for(int j=0;j<l;j++)
		{
			scanf("%d",&v[j]);
		}
		for(ll j = 0; j < LG; j++)
		{
			for(int i=0;i<l;i++)
			{
				st[j][i] = -INF;
				if(i + (1<<j) - 1 < l)
				{
					if(j == 0) st[j][i] = v[i];
					else st[j][i] = max(st[j-1][i], st[j-1][i + (1<<(j-1))]);
				}
			}
		}
		if(w-l<=l)
		{
			for(int j=0;j<w;j++)
			{
				int al=max(0,j-(w-l));
				int ar=min(j,l-1);
				ll val = query(al,ar);
				if(!(j>=w-l&&j<=l-1)) val=max(val,0LL);
				//cerr<<"V: "<<i<<' '<<j<<' '<<val<<'\n';
				update(j,j,val);
			}
		}
		else
		{
			for(int j=0;j<l;j++)
			{
				int al=max(0,j-(w-l));
				int ar=min(j,l-1);
				ll val = query(al,ar);
				if(!(j>=w-l&&j<=l-1)) val=max(val,0LL);
				//cerr<<"V: "<<i<<' '<<j<<' '<<val<<'\n';
				update(j,j,val);
			}
			for(int j=w-l;j<w;j++)
			{
				int al=max(0,j-(w-l));
				int ar=min(j,l-1);
				ll val = query(al,ar);
				if(!(j>=w-l&&j<=l-1)) val=max(val,0LL);
				//cerr<<"V: "<<i<<' '<<j<<' '<<val<<'\n';
				update(j,j,val);
			}
			update(l,w-l-1,max(0LL,query(0,l-1)));
		}
		for(ll j = 0; j < LG; j++)
		{
			for(int i=0;i<l;i++)
			{
				st[j][i] = -INF;
			}
		}
	}
	go();
	for(int i=0;i<w;i++)
	{
		printf("%lld", ans[i]);
		if(i+1<w) printf(" ");
	}
	printf("\n");
}