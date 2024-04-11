#include<cstdio>
#include<algorithm>

using namespace std;

const double INF=1e15;

double x,y;

struct MAT
{
	double num[3][3];
	MAT(){for(int i=0;i<3;i++)for(int j=0;j<3;j++)num[i][j]=-INF;}
	double* operator[](int x){return num[x];}
};
MAT operator*(MAT a,MAT b)
{
	MAT c;
	for(int i=0;i<3;i++)for(int j=0;j<3;j++)for(int k=0;k<3;k++)c[i][j]=max(c[i][j],a[i][k]+b[k][j]);
	return c;
}

MAT C;
struct SegmentTree
{
	struct nd
	{
		int l,r;MAT D;
	}t[800000];
	void build(int l,int r,int k=1)
	{
		t[k].l=l,t[k].r=r;if(l==r)return;
		int mid=(l+r)>>1;build(l,mid,k<<1),build(mid+1,r,k<<1|1);
	}
	void update(int pos,double val,int k=1)
	{
		if(t[k].l==t[k].r)
		{
			t[k].D[0][0]=0,t[k].D[1][1]=val/(x+y),t[k].D[2][2]=val/y;return;
		}
		int mid=(t[k].l+t[k].r)>>1;if(pos<=mid)update(pos,val,k<<1);else update(pos,val,k<<1|1);
		t[k].D=t[k<<1].D*C*t[k<<1|1].D;
	}
	MAT query(int l,int r,int k=1)
	{
		if(l<=t[k].l&&t[k].r<=r)return t[k].D;
		int mid=(t[k].l+t[k].r)>>1;
		if(r<=mid)return query(l,r,k<<1);
		if(l>mid)return query(l,r,k<<1|1);
		return query(l,r,k<<1)*C*query(l,r,k<<1|1);
	}
}T;



int main()
{
	C[0][0]=C[0][1]=C[0][2]=C[1][0]=C[2][0]=C[1][1]=0,C[1][2]=C[2][1]=C[2][2]=-INF;
	int n=0,q=0;scanf("%d%d%lf%lf",&n,&q,&x,&y);if(x>y)swap(x,y);T.build(1,n);
	for(int i=1;i<=n;i++){double b=0;scanf("%lf",&b);T.update(i,b);}
	while(q--)
	{
		int op=0;scanf("%d",&op);
		if(op==1)
		{
			int pos=0;double v=0;scanf("%d%lf",&pos,&v);T.update(pos,v);
		}
		else
		{
			int l=0,r=0;scanf("%d%d",&l,&r);
			MAT M=T.query(l,r);double ans=-INF;for(int i=0;i<3;i++)for(int j=0;j<3;j++)ans=max(ans,M[i][j]);
			printf("%.10lf\n",ans);
		}
	}
}