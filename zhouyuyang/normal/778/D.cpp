#include <cstdio>

char c1[600000][60],c2[600000][60];
int u[120000],v[120000],x[120000],y[120000];
int i,j,m,n,w,z;

inline void getL(int x,int y,char c[][60]);

inline void getU(int x,int y,char c[][60])
{
	if (c[x+1][y]=='D')
		return;
	if (c[x+1][y]=='R')
		getU(x+1,y-1,c);
	if (c[x+1][y]=='U')
		getL(x+1,y,c);
	w++,u[w]=x,v[w]=y;
	c[x][y]=c[x][y+1]='U';
	c[x+1][y]=c[x+1][y+1]='D';
	return;
}

inline void getL(int x,int y,char c[][60])
{
	if (c[x][y+1]=='R')
		return;
	if (c[x][y+1]=='D')
		getL(x-1,y+1,c);
	if (c[x][y+1]=='L')
		getU(x,y+1,c);
	w++,u[w]=x,v[w]=y;
	c[x][y]=c[x+1][y]='L';
	c[x][y+1]=c[x+1][y+1]='R';
	return;
}

int main()
{
	scanf("%d%d\n",&n,&m);
	for (i=1;i<=n;i++)
		gets(c1[i]+1);
	for (i=1;i<=n;i++)
		gets(c2[i]+1);
	w=0;
	if (! (n&1))
		for (i=1;i<=n;i=i+2)
			for (j=1;j<=m;j++)
				getU(i,j,c1);
	else
		for (i=1;i<=n;i++)
			for (j=1;j<=m;j=j+2)
				getL(i,j,c1);
	for (i=1;i<=w;i++)
		z++,x[z]=u[i],y[z]=v[i];
	w=0;
	if (! (n&1))
		for (i=1;i<=n;i=i+2)
			for (j=1;j<=m;j++)
				getU(i,j,c2);
	else
		for (i=1;i<=n;i++)
			for (j=1;j<=m;j=j+2)
				getL(i,j,c2);
	for (i=w;i>0;i--)
		z++,x[z]=u[i],y[z]=v[i];
	printf("%d\n",z);
	for (i=1;i<=z;i++)
		printf("%d %d\n",x[i],y[i]);
	return 0;
}