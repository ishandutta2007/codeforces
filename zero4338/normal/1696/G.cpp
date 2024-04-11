#include<bits/stdc++.h>
using namespace std;
int read()
{
	int ret=0;bool f=0;char c=getchar();
	while(c>'9'||c<'0')f|=(c=='-'),c=getchar();
	while(c>='0'&&c<='9')ret=(ret<<3)+(ret<<1)+(c^48),c=getchar();
	return f?-ret:ret;
}
const int maxn=2e5+5;
const double inf=1e18;
int n,q,x,y,b[maxn];
class matrix
{
	private:
	double v[3][3];
	public:
	matrix(){for(int i=0;i<3;i++)for(int j=0;j<3;j++)v[i][j]=-inf;}
	matrix(double _v)
	{
		for(int i=0;i<3;i++)for(int j=0;j<3;j++)v[i][j]=-inf;
		v[0][0]=0;v[0][1]=_v/(x+y);v[0][2]=_v/y;
		v[1][0]=0;v[1][1]=_v/(x+y);
		v[2][0]=0;
	}
	double*operator[](const int &i){return v[i];}
	matrix operator *(const matrix &rhs)
	{
		matrix ret;
		for(int i=0;i<3;i++)
			for(int j=0;j<3;j++)
				for(int k=0;k<3;k++)
					ret[i][j]=max(ret[i][j],v[i][k]+rhs.v[k][j]);
		return ret;
	}
	friend array<double,3> operator *(const array<double,3>&lhs,const matrix &rhs)
	{
		array<double,3>ret;ret.fill(-inf);
		for(int i=0;i<3;i++)
			for(int j=0;j<3;j++)
				ret[j]=max(ret[j],lhs[i]+rhs.v[i][j]);
		return ret;
	}
};
class segment
{
	#define L(u) u<<1
	#define R(u) u<<1|1
	private:
	struct node{matrix v;}t[maxn<<2];
	void update(int u){t[u].v=t[L(u)].v*t[R(u)].v;}
	public:
	void build(int u=1,int l=1,int r=n)
	{
		if(l==r){t[u].v=matrix(b[l]);return;}
		int mid=(l+r)>>1;
		build(L(u),l,mid);build(R(u),mid+1,r);
		update(u);
	}
	void query(int nl,int nr,array<double,3>&ret,int u=1,int l=1,int r=n)
	{
		if(l>=nl&&r<=nr){ret=ret*t[u].v;return;}
		int mid=(l+r)>>1;
		if(mid>=nl)query(nl,nr,ret,L(u),l,mid);
		if(mid+1<=nr)query(nl,nr,ret,R(u),mid+1,r);
	}
	void change(int p,int x,int u=1,int l=1,int r=n)
	{
		if(l==r){t[u].v=matrix(x);return;}
		int mid=(l+r)>>1;
		if(mid>=p)change(p,x,L(u),l,mid);
		else change(p,x,R(u),mid+1,r);
		update(u);
	}
	#undef L
	#undef R
}tr;
int main()
{
	n=read();q=read();x=read();y=read();
	if(x>y)swap(x,y);
	generate_n(b+1,n,read);
	tr.build();
	while(q--)
	{
		int opt=read();
		if(opt==1){int k=read(),v=read();tr.change(k,v);}
		else if(opt==2)
		{
			int l=read(),r=read();
			array<double,3>ret;ret.fill(-inf);
			ret[0]=0;
			tr.query(l,r,ret);
			printf("%.10lf\n",*max_element(ret.begin(),ret.end()));
		}
	}
	return 0;
}