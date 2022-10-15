#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
int read()
{
	int ret=0;bool f=0;char c=getchar();
	while(c>'9'||c<'0')f|=(c=='-'),c=getchar();
	while(c>='0'&&c<='9')ret=(ret<<3)+(ret<<1)+(c^48),c=getchar();
	return f?-ret:ret;
}
const int maxn=2e5+5;
int q,d;
class segment
{
	#define L(u) u<<1
	#define R(u) u<<1|1
	private:
	bool in[maxn];
	struct node
	{
		int sum0;ll sum1,sum2;
		int atag;
	}t[maxn<<2];
	void _add(int u,int x)
	{
		t[u].sum2+=(ll)t[u].sum0*x*x+2*t[u].sum1*x;
		t[u].sum1+=(ll)x*t[u].sum0;
		t[u].atag+=x;
	}
	void update(int u)
	{
		t[u].sum0=t[L(u)].sum0+t[R(u)].sum0;
		t[u].sum1=t[L(u)].sum1+t[R(u)].sum1;
		t[u].sum2=t[L(u)].sum2+t[R(u)].sum2;
	}
	void pushdown(int u)
	{
		if(t[u].atag)
		{
			_add(L(u),t[u].atag);
			_add(R(u),t[u].atag);
			t[u].atag=0;
		}
	}
	int query0(int nl,int nr,int u=1,int l=1,int r=2e5)
	{
		if(l>=nl&&r<=nr)return t[u].sum0;
		pushdown(u);
		int mid=(l+r)>>1,ret=0;
		if(mid>=nl)ret+=query0(nl,nr,L(u),l,mid);
		if(mid+1<=nr)ret+=query0(nl,nr,R(u),mid+1,r);
		return ret;
	}
	void set(int p,int x,int u=1,int l=1,int r=2e5)
	{
		if(l==r)
		{
			t[u].sum0=x>0;
			t[u].sum1=x;
			t[u].sum2=(ll)x*x;
			return;
		}
		pushdown(u);
		int mid=(l+r)>>1;
		if(mid>=p)set(p,x,L(u),l,mid);
		else set(p,x,R(u),mid+1,r);
		update(u);
	}
	void add(int nl,int nr,int x,int u=1,int l=1,int r=2e5)
	{
		if(l>=nl&&r<=nr){_add(u,x);return;}
		pushdown(u);
		int mid=(l+r)>>1;
		if(mid>=nl)add(nl,nr,x,L(u),l,mid);
		if(mid+1<=nr)add(nl,nr,x,R(u),mid+1,r);
		update(u);
	}
	public:
	void flip(int p)
	{
		if(!in[p])
		{
			add(max(1,p-d),p,1);
			set(p,query0(p,min((int)2e5,p+d))+1);
		}
		else
		{
			add(max(1,p-d),p,-1);
			set(p,0);	
		}
		in[p]^=1;
	}
	ll query(){return t[1].sum0+(t[1].sum2-3*t[1].sum1)/2;}
	#undef L
	#undef R
}tr;
int main()
{
	q=read();d=read();
	while(q--)
	{
		tr.flip(read());
		printf("%lld\n",tr.query());
	}
	return 0;
}