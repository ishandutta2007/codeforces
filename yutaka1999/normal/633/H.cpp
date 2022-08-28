#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#define SIZE 30005
#define BT 512*128*2
#define SQR 200

using namespace std;
typedef long long int ll;
typedef pair <int,int> P;
typedef pair <P,int> PP;

ll MOD;
ll fib[SIZE];
void make()
{
	fib[0]=0;
	fib[1]=1;
	for(int i=2;i<SIZE;i++)
	{
		fib[i]=fib[i-1]+fib[i-2];
		if(fib[i]>=MOD) fib[i]-=MOD;
	}
}
ll get(int i)
{
	if(i==-1) return 1;
	return fib[i];
}
struct Q
{
	ll a,b;//ai*F(i+1)AAAai*F(i+2)AB
	int cnt;//
	Q(ll a=0,ll b=0,int cnt=0):a(a),b(b),cnt(cnt){}
};
Q merge(Q l,Q r)
{
	Q ret;
	ret.a=l.a+r.a*get(l.cnt-1)+r.b*get(l.cnt);
	ret.b=l.b+r.a*get(l.cnt)+r.b*get(l.cnt+1);
	ret.a%=MOD;
	ret.b%=MOD;
	ret.cnt=l.cnt+r.cnt;
	return ret;
}
struct segtree
{
	Q seg[BT];
	int mum;
	
	void init(int n)
	{
		mum=1;
		while(mum<n) mum<<=1;
		for(int i=0;i<mum*2;i++) seg[i]=Q();
	}
	void flip(int k,int v)
	{
		v%=MOD;
		k+=mum-1;
		if(seg[k].cnt==0)
		{
			seg[k].a=seg[k].b=v;
			seg[k].cnt=1;
		}
		else
		{
			seg[k].a=seg[k].b=0;
			seg[k].cnt=0;
		}
		while(k>0)
		{
			k=(k-1)/2;
			seg[k]=merge(seg[k*2+1],seg[k*2+2]);
		}
	}
	ll get()
	{
		return seg[0].a;
	}
};
segtree seg;
int left[SIZE],right[SIZE];
vector <int> vx;
int A[SIZE],cnt[SIZE];
ll ans[SIZE];
PP pos[SIZE];

int main()
{
	int n;
	scanf("%d %lld",&n,&MOD);
	make();
	for(int i=0;i<n;i++)
	{
		scanf("%d",&A[i]);
		vx.push_back(A[i]);
	}
	sort(vx.begin(),vx.end());
	vx.erase(unique(vx.begin(),vx.end()),vx.end());
	for(int i=0;i<n;i++) A[i]=lower_bound(vx.begin(),vx.end(),A[i])-vx.begin();
	int q;
	scanf("%d",&q);
	for(int i=0;i<q;i++)
	{
		scanf("%d %d",&left[i],&right[i]);left[i]--;right[i]--;
		pos[i]=PP(P(left[i]/SQR,right[i]),i);
	}
	sort(pos,pos+q);
	seg.init(vx.size()+2);
	int l=0,r=0;
	for(int i=0;i<q;i++)
	{
		int v=pos[i].second;
		while(r<=right[v])
		{
			if(cnt[A[r]]==0) seg.flip(A[r],vx[A[r]]);
			cnt[A[r]]++;
			r++;
		}
		while(right[v]<r-1)
		{
			r--;
			if(cnt[A[r]]==1) seg.flip(A[r],vx[A[r]]);
			cnt[A[r]]--;
		}
		while(l<left[v])
		{
			if(cnt[A[l]]==1) seg.flip(A[l],vx[A[l]]);
			cnt[A[l]]--;
			l++;
		}
		while(left[v]<l)
		{
			l--;
			if(cnt[A[l]]==0) seg.flip(A[l],vx[A[l]]);
			cnt[A[l]]++;
		}
		ans[v]=seg.get();
	}
	for(int i=0;i<q;i++) printf("%lld\n",ans[i]);
	return 0;
}