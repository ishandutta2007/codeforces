#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#define SIZE 500005
#define BT 512*1024*2
#define INF 1000000005

using namespace std;
typedef long long int ll;
typedef pair <int,int> P;
typedef pair <int,P> PP;

struct Q
{
	P mnA,mnB;
	int mn;
	PP opt1,opt2;
	P ml,mr;//ml : A , mr : B
	Q(int A=INF,int B=INF){mn=0,mnA=P(A,-1),mnB=P(B,-1),opt1=opt2=PP(INF*2,P(INF,INF)),ml=mr=P(INF,-1);}
};
Q merge(Q l,Q r)
{
	Q ret;
	ret.mn=min(l.mn,r.mn);
	ret.mnA=min(l.mnA,r.mnA);
	ret.mnB=min(l.mnB,r.mnB);
	ret.opt2=PP(ret.mnA.first+ret.mnB.first,P(ret.mnA.second,ret.mnB.second));
	if(ret.mn==l.mn) ret.ml=l.ml;
	else ret.ml=min(l.mnA,r.ml);
	if(ret.mn==r.mn) ret.mr=r.mr;
	else ret.mr=min(l.mr,r.mnB);
	ret.opt1=min(PP(l.mnA.first+r.mnB.first,P(l.mnA.second,r.mnB.second)),min(l.opt1,r.opt1));
	ret.opt1=min(ret.opt1,PP(l.mr.first+r.ml.first,P(r.ml.second,l.mr.second)));
	if(l.mn>ret.mn)
	{
		ret.opt1=min(ret.opt1,PP(l.mnB.first+r.ml.first,P(r.ml.second,l.mnB.second)));
		ret.opt1=min(ret.opt1,l.opt2);
	}
	if(r.mn>ret.mn)
	{
		ret.opt1=min(ret.opt1,PP(l.mr.first+r.mnA.first,P(r.mnA.second,l.mr.second)));
		ret.opt1=min(ret.opt1,r.opt2);
	}
	return ret;
}
struct segtree
{
	Q seg[BT];
	int add[BT];
	int mum;
	
	void init(int n)
	{
		mum=1;
		while(mum<n) mum<<=1;
		for(int i=0;i<mum*2;i++) seg[i]=Q(),add[i]=0;
	}
	void ins(int k,int A,int B)//mnlok
	{
		k+=mum-1;
		seg[k].mnA=P(A,k-mum+1);
		seg[k].mnB=seg[k].mr=P(B,k-mum+1);
		seg[k].opt1=seg[k].opt2=PP(A+B,P(k-mum+1,k-mum+1));
		while(k>0)
		{
			k=(k-1)/2;
			seg[k]=merge(seg[k*2+1],seg[k*2+2]);
			seg[k].mn+=add[k];
		}
	}
	void update(int a,int b,int k,int l,int r,int v)
	{
		if(b<=l||r<=a) return;
		if(a<=l&&r<=b)
		{
			add[k]+=v;
			seg[k].mn+=v;
		}
		else
		{
			update(a,b,k*2+1,l,(l+r)/2,v);
			update(a,b,k*2+2,(l+r)/2,r,v);
			seg[k]=merge(seg[k*2+1],seg[k*2+2]);
			seg[k].mn+=add[k];
		}
	}
	void update(int a,int b,int v)
	{
		update(a,b,0,0,mum,v);
	}
	void see()
	{
		for(int i=0;i<mum*2;i++)
		{
			if(i==2||i==5||i==6||i>=11) continue;
			printf("%d %d %d : %d %d %d\n",i,seg[i].mn,add[i],seg[i].opt1.first,seg[i].opt1.second.first,seg[i].opt1.second.second);
			printf("* %d %d : %d %d\n",seg[i].ml.first,seg[i].ml.second,seg[i].mr.first,seg[i].mr.second);
		}
	}
	P get()
	{
		//printf("%d : %d %d\n",seg[0].opt1.first,seg[0].opt1.second.first,seg[0].opt1.second.second);
		return seg[0].opt1.second;//]0opt10opt
	}
};
segtree seg;
int A[SIZE],B[SIZE];

int main()
{
	int n,k;
	scanf("%d %d",&n,&k);
	for(int i=0;i<n;i++) scanf("%d",&A[i]);
	for(int i=0;i<n;i++) scanf("%d",&B[i]);
	seg.init(n+2);
	for(int i=0;i<n;i++)
	{
		seg.ins(i,A[i],B[i]);
	}
	ll ret=0;
	for(int i=0;i<k;i++)
	{
		P p=seg.get();
		int a=p.first,b=p.second;
		//printf("%d %d\n",a,b);
		ret+=A[a]+B[b];
		A[a]=INF,B[b]=INF;
		seg.ins(a,A[a],B[a]);
		seg.ins(b,A[b],B[b]);
		seg.update(0,a+1,-1);
		seg.update(0,b+1,1);
		//seg.see();
	}
	printf("%lld\n",ret);
	return 0;
}