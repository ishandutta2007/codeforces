#include <cstdio>
int f[50000];
bool b[50000];
char c[50000];
int i,j,m,n,s,fx,fy;
inline int getfather(int x){
	if (f[x]==x)return x;
	else return f[x]=getfather(f[x]);
}
int main(){
	scanf("%d%d",&n,&m);
	getchar();
	for (i=1;i<=n;i++)
	{
		gets(c+1);
		for (j=1;j<=m/4;j++)
			if (c[j]<=57)
				c[j]=c[j]-48;
			else
				c[j]=c[j]-55;
		for (j=1;j<=m;j++)
			if (f[j])
				f[m+j]=m+f[j],f[j]=0;
			else
				f[m+j]=0;
		for (j=1;j<=m;j++)
			b[j]=(c[(j-1)/4+1]>>(3-(j-1)%4))&1;
		for (j=1;j<=m;j++)
			if (b[j])
				s++,f[j]=j;
		for (j=1;j<=m;j++)
			if ((f[j]) && (f[m+j]))
			{
				fx=getfather(j);
				fy=getfather(m+j);
				if (fx!=fy)
					f[fy]=fx,s--;
			}
		for (j=1;j<m;j++)
			if ((f[j]) && (f[j+1]))
			{
				fx=getfather(j);
				fy=getfather(j+1);
				if (fx!=fy)
					f[fy]=fx,s--;
			}
		for (j=1;j<=2*m;j++)
			if (f[j])
				getfather(f[j]);
	}
	printf("%d",s);
	return 0;
}