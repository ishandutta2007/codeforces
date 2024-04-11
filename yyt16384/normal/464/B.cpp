#include <cstdio>
#include <cstring>
#ifdef _WIN32
#define LLFORMAT "%I64"
#else
#define LLFORMAT "%ll"
#endif
const long long INFLL=0x3f3f3f3f3f3f3f3fLL;
int a[8][3];
int b[8][3];
void init()
{
	for (int i=0;i<8;++i)
		for (int j=0;j<3;++j)
			scanf("%d",&a[i][j]);
}
inline long long dist(int x,int y)
{
	long long s=0;
	for (int i=0;i<3;++i)
		s+=(long long)(b[x][i]-b[y][i])*(b[x][i]-b[y][i]);
	return s;
}
int work()
{
	long long tmp;
	long long min=INFLL;
	int a[3];
	for (int i=1;i<8;++i)
		if ((tmp=dist(0,i))<min) min=tmp;
	if (min==0) return 0;
	int cnt=0;
	for (int i=1;i<8;++i)
		if (dist(0,i)==min)
		{
			if (cnt==3) return 0;
			a[cnt++]=i;
		}
	if (cnt<3) return 0;
	int c[3][3];
	for (int i=0;i<3;++i)
		for (int j=0;j<3;++j)
			c[i][j]=b[a[i]][j]-b[0][j];
	for (int i=0;i<3;++i)
		for (int j=i+1;j<3;++j)
		{
			long long s=0;
			for (int k=0;k<3;++k)
				s+=(long long)c[i][k]*c[j][k];
			if (s) return 0;
		}
	for (int i=0;i<3;++i)
		for (int j=i+1;j<3;++j)
		{
			int r[3];
			for (int k=0;k<3;++k)
				r[k]=b[0][k]+c[i][k]+c[j][k];
			int fl=1;
			for (int k=0;k<8;++k)
				if (memcmp(r,b[k],sizeof(r))==0)
				{
					fl=0;break;
				}
			if (fl) return 0;
		}
	int r[3];
	for (int k=0;k<3;++k)
		r[k]=b[0][k]+c[0][k]+c[1][k]+c[2][k];
	int fl=1;
	for (int k=0;k<8;++k)
		if (memcmp(r,b[k],sizeof(r))==0)
		{
			fl=0;break;
		}
	if (fl) return 0;
	printf("YES\n");
	for (int i=0;i<8;++i)
	{
		for (int j=0;j<3;++j)
			printf("%d ",b[i][j]);
		printf("\n");
	}
	return 1;
}
int search(int x)
{
	if (x==8) return work();
	const int d[6][3]={{0,1,2},{0,2,1},{1,0,2},{1,2,0},{2,0,1},{2,1,0}};
	for (int i=0;i<6;++i)
	{
		for (int j=0;j<3;++j)
			b[x][j]=a[x][d[i][j]];
		if (search(x+1)) return 1;
	}
	return 0;
}
void solve()
{
	for (int i=0;i<3;++i) b[0][i]=a[0][i];
	if (!search(1)) printf("NO\n");
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("B.in","r",stdin);
	freopen("B.out","w",stdout);
#endif
	init();
	solve();
#ifndef ONLINE_JUDGE
	fclose(stdin);fclose(stdout);
#endif
	return 0;
}