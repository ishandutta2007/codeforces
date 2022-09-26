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
typedef long double ld; 
typedef tree<ii, null_type, less<ii>, rb_tree_tag, tree_order_statistics_node_update> pbds;

struct node
{
	int ans;
	int maxr,maxl;
	int l,r;
};
string s; 
node t[1000011];
node emp;

node combine(node a, node b)
{
	if(a.ans==-1) return b;
	if(b.ans==-1) return a;
	node c;
	c.l=a.l;c.r=b.r;
	int alen=a.r-a.l+1; int blen=b.r-b.l+1;
	c.maxr=b.maxr;c.maxl=a.maxl;
	if(b.maxr==blen)
	{
		if(s[a.r]!=s[b.l])
		{
			c.maxr=b.maxr+a.maxr;
		}
	}
	if(a.maxl==alen)
	{
		if(s[a.r]!=s[b.l])
		{
			c.maxl=b.maxl+a.maxl;
		}
	}
	c.ans=max(a.ans,b.ans);
	if(s[a.r]!=s[b.l]) c.ans=max(c.ans,a.maxr+b.maxl);
	return c;
}

void build(int n) {  // build the tree
  for (int i = n - 1; i > 0; --i) 
  {
	  t[i] = combine(t[i<<1], t[i<<1|1]);
  }
}


node query(int n, int l, int r) {
  node resl, resr; resl=emp; resr=emp;
  for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
    if (l&1) resl = combine(resl, t[l++]);
    if (r&1) resr = combine(t[--r], resr);
  }
  return combine(resl, resr);
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	emp.ans=-1;
	cin>>s;
	s+=s;
	int n=int(s.length())/2;
	int ans=0;
	for(int id=2*n;id<4*n;id++)
	{
		t[id].ans=t[id].maxr=t[id].maxl=1;
		t[id].l=id-2*n; t[id].r=id-2*n;
	}
	build(2*n);
	for(int i=0;i<n;i++)
	{
		ans=max(ans,query(2*n,i,i+n).ans);
	}
	cout<<ans<<'\n';
}