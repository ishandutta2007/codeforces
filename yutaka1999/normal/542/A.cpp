#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#define INF 1000000000
#define SIZE 200005
#define BT 256*1024*2

using namespace std;
typedef long long int ll;
typedef pair <int,int> P;

struct segtree
{
	P seg[BT];
	int mum;
	
	void init(int n)
	{
		mum=1;
		while(mum<n) mum<<=1;
		for(int i=0;i<mum*2;i++) seg[i]=P(-1,-1);
	}
	void add(int k,P x)
	{
		k+=mum-1;
		seg[k]=max(seg[k],x);
		while(k>0)
		{
			k=(k-1)/2;
			seg[k]=max(seg[k*2+1],seg[k*2+2]);
		}
	}
	P get(int a,int b,int k,int l,int r)
	{
		if(b<=l||r<=a) return P(-1,-1);
		if(a<=l&&r<=b) return seg[k];
		else
		{
			P vl=get(a,b,k*2+1,l,(l+r)/2);
			P vr=get(a,b,k*2+2,(l+r)/2,r);
			return max(vl,vr);
		}
	}
	P get(int a,int b)
	{
		return get(a,b,0,0,mum);
	}
};
segtree seg;
int left[SIZE],right[SIZE];
P back[SIZE],nxt[SIZE];

int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	vector <int> vl,vr;
	for(int i=0;i<n;i++)
	{
		scanf("%d %d",&left[i],&right[i]);
		vl.push_back(left[i]);
		vr.push_back(right[i]);
	}
	sort(vl.begin(),vl.end());
	vl.erase(unique(vl.begin(),vl.end()),vl.end());
	sort(vr.begin(),vr.end());
	vr.erase(unique(vr.begin(),vr.end()),vr.end());
	for(int i=0;i<vl.size();i++) nxt[i]=P(-1,-1);
	for(int i=0;i<vr.size();i++) back[i]=P(INF,-1);
	for(int i=0;i<n;i++)
	{
		int L=lower_bound(vl.begin(),vl.end(),left[i])-vl.begin();
		int R=lower_bound(vr.begin(),vr.end(),right[i])-vr.begin();
		nxt[L]=max(nxt[L],P(right[i],i));
		back[R]=min(back[R],P(left[i],i));
	}
	for(int i=0;i+1<vl.size();i++) nxt[i+1]=max(nxt[i+1],nxt[i]);
	for(int i=((int) vr.size())-2;i>=0;i--) back[i]=min(back[i],back[i+1]);
	seg.init(vl.size()+2);
	for(int i=0;i<vl.size();i++) seg.add(i,P(nxt[i].first-vl[i],nxt[i].second));
	ll ret=0;
	int S=-1,T=-1;
	for(int i=0;i<m;i++)
	{
		int A,B,C;
		scanf("%d %d %d",&A,&B,&C);
		P mx=P(0,-1);
		//Ro
		int pos=lower_bound(nxt,nxt+vl.size(),P(B,-1))-nxt;
		if(pos<vl.size()) mx=max(mx,P(B-max(vl[pos],A),nxt[pos].second));
		//S
		int start=lower_bound(vl.begin(),vl.end(),A)-vl.begin();
		if(start<pos) mx=max(mx,seg.get(start,pos));
		//Lo
		pos=upper_bound(back,back+vr.size(),P(A+1,-1))-back-1;
		if(pos>=0) mx=max(mx,P(min(vr[pos],B)-A,back[pos].second));
		if(ret<(ll) mx.first*(ll) C)
		{
			ret=(ll) mx.first*(ll) C;
			S=mx.second;
			T=i;
		}
	}
	printf("%lld\n",ret);
	if(ret>0) printf("%d %d\n",S+1,T+1);
	return 0;
}