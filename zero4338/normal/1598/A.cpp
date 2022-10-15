#include<iostream>
#include<cstdio>
using namespace std;
int read()
{
	int ret=0;char c=getchar();
	while(c>'9'||c<'0')c=getchar();
	while(c>='0'&&c<='9')ret=(ret<<3)+(ret<<1)+(c^48),c=getchar();
	return ret;
}
int T;
const int maxn=2000;
int n;
char s[3][maxn];
int id(int x,int y){return (x-1)*n+y;}
struct dsu
{
	int fa[maxn];
	void prework(){for(int i=1;i<=2*n;i++)fa[i]=i;}
	int get(int x){return x==fa[x]?x:fa[x]=get(fa[x]);}
	void merge(int x,int y){fa[get(x)]=get(y);}
	bool check(int x,int y){return get(x)==get(y);}
}S;
int main()
{
	T=read();
	while(T--)
	{
		n=read();S.prework();
		scanf("%s%s",s[1]+1,s[2]+1);
		for(int i=1;i<=2;i++)
			for(int j=1;j<=n;j++)
			{
				if(s[i][j]=='1')continue;
				for(int d1=-1;d1<=1;d1++)
					for(int d2=-1;d2<=1;d2++)
						if(i+d1>=1&&i+d1<=2&&j+d2<=n&&j+d2>=1&&s[i+d1][j+d2]=='0')S.merge(id(i,j),id(i+d1,j+d2));
			}
		printf("%s\n",S.check(id(1,1),id(2,n))?"YES":"NO");
	}
	return 0;
}