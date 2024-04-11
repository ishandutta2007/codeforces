#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

const long long INF=1e15;

struct nd
{
	int l,r;long long val,dat;
	nd(int _l=0,int _r=0,long long _val=0):l(_l),r(_r),val(_val),dat(0){}
};
bool lcmp(nd A,nd B){return A.l<B.l;}
bool rcmp(nd A,nd B){return A.r<B.r;}

int n,q;
long long a[600000][3],val[600000][3],f[600000];

void Solve(int l,int r,vector<nd> X)
{
	if(l==r||X.size()==0)return;
	
	int mid=(l+r)>>1;vector<nd> L,R,M;
	for(int i=0;i<X.size();i++){if(X[i].r<=mid)L.push_back(X[i]);else if(X[i].l>mid)R.push_back(X[i]);else M.push_back(X[i]);}
	
	Solve(l,mid,L);
	
	//printf("Solve: %d %d\n",l,r);
	//for(int i=0;i<=n;i++)printf("%lld ",val[i][1]);puts("");
	sort(M.begin(),M.end(),lcmp);
	long long a=INF,b=INF;
	for(int i=l,j=-1;i<=mid;i++)
	{
		while(j+1<M.size()&&M[j+1].l<=i)
		{
			j++;a=min(M[j].val,a);
		}
		val[i][1]=min(val[i][1],b);//printf("%lld %lld\n",a,b);
		b=min(b,a+min(val[i][0],val[i][1]));
	}
	//for(int i=0;i<=n;i++)printf("%lld ",val[i][1]);puts("");
	a=INF;
	for(int i=M.size()-1,p=mid;i>=0;i--)
	{
		while(p>=M[i].l)
		{
			a=min(a,min(val[p][0],val[p][1]));p--;
		}
		M[i].dat=a;
	}
	//for(int i=0;i<M.size();i++)printf("%d %d %lld %lld\n",M[i].l,M[i].r,M[i].val,M[i].dat);
	sort(M.begin(),M.end(),rcmp);
	
	a=INF;
	for(int i=mid+1;i<=r;i++)f[i]=INF;
	for(int i=r,j=M.size();i>mid;i--)
	{
		while(j-1>=0&&M[j-1].r>=i)
		{
			j--;a=min(a,M[j].dat+M[j].val);f[i]=min(f[i],M[j].val);
		}
		val[i][1]=min(val[i][1],a);
		if(i<r)f[i]=min(f[i],f[i+1]);
	}
	
	a=INF;
	for(int i=mid+1;i<=r;i++)
	{
		val[i][1]=min(val[i][1],a+f[i]);
		a=min(a,min(val[i][0],val[i][1]));
	}
	
	//for(int i=0;i<=n;i++)printf("%lld ",val[i][1]);puts("");
	
	Solve(mid+1,r,R);
}

int main()
{
	scanf("%d%d",&n,&q);
	for(int j=0;j<3;j++)for(int i=1;i<=n;i++)scanf("%lld",&a[i][j]),a[i][j]+=a[i-1][j];
	
	for(int i=0;i<=n;i++)for(int j=0;j<3;j++)val[i][j]=INF;
	for(int i=1;i<=n;i++)
	{
		val[i][2]=-(a[i][1]+a[n][2]-a[i-1][2]);
		val[i-1][0]=-(a[i][0]-a[i-1][1]);
	}
	
	//for(int j=0;j<3;j++){for(int i=0;i<=n;i++)printf("%lld ",val[i][j]);puts("");}
	vector<nd> X;
	for(int i=1,l=0,r=0,v=0;i<=q;i++)
	{
		scanf("%d%d%d",&l,&r,&v);X.push_back(nd(l-1,r,v));
	}
	
	Solve(0,n,X);
	long long ans=INF;
	//for(int i=0;i<=n;i++)printf("%lld ",val[i][1]);puts("");
	for(int i=0;i<=n;i++)ans=min(ans,val[i][1]+val[i][2]);
	printf("%lld",-ans);
}