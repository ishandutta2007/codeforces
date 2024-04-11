#include<bits/stdc++.h>

typedef unsigned char uchar;
typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;

#define xx first
#define yy second

template<typename T> inline T max(T a,T b){return a>b?a:b;}
template<typename T> inline T min(T a,T b){return a<b?a:b;}
template<typename T> inline T abs(T a){return a>0?a:-a;}
template<typename T> inline void repr(T &a,T b){if(a<b)a=b;}
template<typename T> inline void repl(T &a,T b){if(a>b)a=b;}
#define mp(a,b) std::make_pair(a,b)

int n,x,y,a[3001],f[3001][3001],fa[3001][3001][2],a1[3000],a2[3000],m1,m2;

struct B
{
	int v,id;
	bool operator <(const B &x)const
	{
		return v>x.v;
	}
}b[3001];

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("o.txt","w",stdout);
	scanf("%d%d%d",&n,&x,&y);
	for(int i=1;i<=n;i++)
		scanf("%d",a+i),f[0][0]+=a[i];
	for(int i=1;i<=n;i++)
		scanf("%d",&b[i].v),b[i].v-=a[i],b[i].id=i;
	std::sort(b+1,b+n+1);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(f[i-1][j]-a[b[i].id]>f[i][j])f[i][j]=f[i-1][j]-a[b[i].id],fa[i][j][0]=i-1,fa[i][j][1]=j;
			if(j<=y)
			{
				if(f[i-1][j-1]+b[i].v>f[i][j])f[i][j]=f[i-1][j-1]+b[i].v,fa[i][j][0]=i-1,fa[i][j][1]=j-1;
			}
			else
			{
				if(f[i-1][j-1]>f[i][j])f[i][j]=f[i-1][j-1],fa[i][j][0]=i-1,fa[i][j][1]=j-1;
			}
		}
		f[i][0]=f[i-1][0]-a[b[i].id];
	}
	/*for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=2;j++)
			printf("%d ",f[i][j]); 
		printf("\n%d\n",b[i].id);
	}*/
	printf("%d\n",f[n][x+y]);
	for(int i=n,j=x+y;j;)
	{
		while(fa[i][j][1]==j)
		{
			i=fa[i][j][0];
		}
		if(j<=y)a2[m2++]=b[i].id;else a1[m1++]=b[i].id;
		i=fa[i][j][0];
		j--;
	}
	std::sort(a1,a1+m1);
	std::sort(a2,a2+m2);
	for(int i=0;i<m1;i++)
		printf("%d ",a1[i]);
	printf("\n");
	for(int i=0;i<m2;i++)
		printf("%d ",a2[i]);
	printf("\n");
}