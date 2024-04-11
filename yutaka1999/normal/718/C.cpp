#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#define SIZE 100005
#define BT 1024*128*2
#define MOD 1000000007

using namespace std;
typedef long long int ll;

struct Mat
{
	ll A[2][2];
	Mat(){memset(A,0,sizeof(A));}
	Mat operator*(Mat l)
	{
		Mat ans;
		for(int i=0;i<2;i++)
		{
			for(int j=0;j<2;j++)
			{
				ans.A[i][j]=0;
				for(int k=0;k<2;k++) ans.A[i][j]+=A[i][k]*l.A[k][j]%MOD;
				if(ans.A[i][j]>=MOD) ans.A[i][j]-=MOD;
			}
		}
		return ans;
	}
	Mat operator+(Mat l)
	{
		Mat ans;
		for(int i=0;i<2;i++)
		{
			for(int j=0;j<2;j++)
			{
				ans.A[i][j]=A[i][j]+l.A[i][j];
				if(ans.A[i][j]>=MOD) ans.A[i][j]-=MOD;
			}
		}
		return ans;
	}
};
Mat org[100];
void make()
{
	org[0].A[0][0]=org[0].A[0][1]=org[0].A[1][0]=1;
	org[0].A[1][1]=0;
	for(int i=1;i<100;i++) org[i]=org[i-1]*org[i-1];
}
Mat gt(int x)
{
	Mat ans;
	ans.A[0][0]=ans.A[1][1]=1;
	ans.A[1][0]=ans.A[0][1]=0;
	for(int i=0;x>0;i++)
	{
		if(x%2==1) ans=ans*org[i];
		x/=2;
	}
	return ans;
}
Mat now;
struct segtree
{
	Mat seg[BT];
	Mat add[BT];
	int mum;
	
	void init(int n)
	{
		mum=1;
		while(mum<n) mum<<=1;
		for(int i=0;i<n;i++)
		{
			int to=i+mum-1;
			seg[to].A[0][0]=seg[to].A[1][1]=1;
			seg[to].A[0][1]=seg[to].A[1][0]=0;
		}
		for(int i=mum-2;i>=0;i--) seg[i]=seg[i*2+1]+seg[i*2+2];
		for(int i=0;i<mum*2;i++)
		{
			add[i].A[0][0]=add[i].A[1][1]=1;
			add[i].A[0][1]=add[i].A[1][0]=0;
		}
	}
	void update(int a,int b,int k,int l,int r)
	{
		if(b<=l||r<=a) return;
		if(a<=l&&r<=b)
		{
			seg[k]=seg[k]*now;
			add[k]=add[k]*now;
		}
		else
		{
			update(a,b,k*2+1,l,(l+r)/2);
			update(a,b,k*2+2,(l+r)/2,r);
			seg[k]=(seg[k*2+1]+seg[k*2+2])*add[k];
		}
	}
	void update(int a,int b)
	{
		update(a,b,0,0,mum);
	}
	Mat get(int a,int b,int k,int l,int r)
	{
		if(b<=l||r<=a) return Mat();
		if(a<=l&&r<=b) return seg[k];
		else
		{
			Mat vl=get(a,b,k*2+1,l,(l+r)/2);
			vl=vl+get(a,b,k*2+2,(l+r)/2,r);
			return vl*add[k];
		}
	}
	ll get(int a,int b)
	{
		Mat ans=get(a,b,0,0,mum);
		return ans.A[0][0];
	}
};
segtree seg;

int main()
{
	make();
	int n,m;
	scanf("%d %d",&n,&m);
	seg.init(n+2);
	for(int i=0;i<n;i++)
	{
		int a;
		scanf("%d",&a);
		now=gt(a-1);
		seg.update(i,i+1);
	}
	for(int i=0;i<m;i++)
	{
		int tp;
		scanf("%d",&tp);
		if(tp==1)
		{
			int l,r,x;
			scanf("%d %d %d",&l,&r,&x);l--,r--;
			now=gt(x);
			seg.update(l,r+1);
		}
		else
		{
			int l,r;
			scanf("%d %d",&l,&r);l--,r--;
			printf("%lld\n",seg.get(l,r+1));
		}
	}
	return 0;
}