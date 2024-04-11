#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#define SIZE 500005
#define BT 512*1024*2

using namespace std;
typedef long long int ll;
typedef pair <int,int> P;

struct segtree
{
	ll seg[BT],add[BT];
	int mum;
	
	void init(int n)
	{
		mum=1;
		while(mum<n) mum<<=1;
		for(int i=0;i<mum*2;i++) seg[i]=add[i]=0;
	}
	void update(int a,int b,int k,int l,int r,ll v)
	{
		if(b<=l||r<=a) return;
		if(a<=l&&r<=b) seg[k]+=v,add[k]+=v;
		else
		{
			update(a,b,k*2+1,l,(l+r)/2,v);
			update(a,b,k*2+2,(l+r)/2,r,v);
			seg[k]=min(seg[k*2+1],seg[k*2+2])+add[k];
		}
	}
	void update(int a,int b,ll v)
	{
		update(a,b,0,0,mum,v);
	}
	ll get()
	{
		return seg[0];
	}
}seg;
int A[SIZE];

int main()
{
	int pr=0;
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&A[i]);
		pr^=A[i];
	}pr%=2;
	sort(A,A+n);
	reverse(A,A+n);
	vector <P> vx;
	for(int i=0;i<n;i++) vx.push_back(P(A[i],i));
	sort(vx.begin(),vx.end());
	seg.init(n+2);
	int to=n-1;
	for(int i=0;i<n;i++)
	{
		seg.update(i,n,-A[i]);
		seg.update(i,i+1,(ll) i*(ll) (i+1));
		if(max(A[i]-1,0)<i) seg.update(max(A[i]-1,0),i,A[i]);
		while(to>=0&&A[to]<=i+1) to--;
		seg.update(i,i+1,(ll) (i+1)*(ll) max(0,to-i));
	}
	//printf("%lld\n",seg.get());
	vector <int> ans;
	if(pr==0&&seg.get()>=0) ans.push_back(0);
	for(int i=n-1;i>=0;i--)
	{
		int v=vx[i].second;
		if(A[v]==0) break;
		seg.update(v,n,1);
		if(A[v]<=v) seg.update(A[v]-1,v,-1);
		if(seg.get()>=0&&(n-i)%2==pr) ans.push_back(n-i);
	}
	if(ans.empty()) puts("-1");
	else
	{
		for(int i=0;i<ans.size();i++) printf("%d ",ans[i]);
		puts("");
	}
	return 0;
}