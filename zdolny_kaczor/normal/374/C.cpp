# include <cstdio>
# include <cstdlib>
# include <vector>
using namespace std;
int m, n;
int nr(int x, int y)
{
	return x*n+y;
}
int x(int coo)
{
	return coo/n;
}
int y(int coo)
{
	return coo%n;
}
char mapa[1001][1001];
vector <int> graf[1000000];
int dx[4]={1, 0, -1, 0};
int dy[4]={0, 1, 0, -1};
int order[1000000];
int onr [1000000];
int last;
void numerate(int x)
{
	if (onr[x]==-2)
	{
		printf("Poor Inna!\n");
		exit(0);
	}
	else if (onr[x]!=-1)
		return;
	onr[x]=-2;
	for (int i=0; i<graf[x].size(); ++i)
		numerate(graf[x][i]);
	onr[x]=last;
	order[last]=x;
	last++;
}
int res[1000000];
int main()
{
	scanf("%d%d", &m, &n);
	for (int i=0; i<m; ++i)
		scanf("%s", mapa[i]);
	for (int i=0; i<m; ++i)
		for (int k=0; k<n; ++k)
			for (int l=0; l<4; ++l)
			{
				int i2=i+dx[l];
				int k2=k+dy[l];
				if (i2>=0 && i2<m && k2>=0 && k2<n &&
					(
						(mapa[i][k]=='D' && mapa[i2][k2]=='I')
					||
						(mapa[i][k]=='I' && mapa[i2][k2]=='M')
					||
						(mapa[i][k]=='M' && mapa[i2][k2]=='A')
					||
						(mapa[i][k]=='A' && mapa[i2][k2]=='D')
					)
				)
					graf[nr(i, k)].push_back(nr(i2, k2));
			}
// 	for (int i=0; i<m*n; ++i)
// 	{
// 		printf("%d.", i);
// 		for (int k=0; k<graf[i].size(); ++k)
// 			printf("%d ", graf[i][k]);
// 		putchar(10);
// 	}
	for (int i=0; i<m*n; ++i)
		onr[i]=-1;
	for (int i=0; i<m*n; ++i)
		if (onr[i]==-1)
			numerate(i);
	for (int i=0; i<m*n; ++i)
	{
		int vnr=order[i];
// 		printf("in %d\n", vnr);
		int maxx=0;
		for (int k=0; k<graf[vnr].size(); ++k)
			if (res[graf[vnr][k]]>maxx)
				maxx=res[graf[vnr][k]];
		res[vnr]=maxx+1;
	}
	int maxx=0;
	for (int i=0; i<m; ++i)
		for (int k=0; k<n; ++k)
			if (mapa[i][k]=='D' && res[nr(i, k)]>maxx)
			{
				maxx=res[nr(i, k)];
			}
	if (maxx<4)
		printf("Poor Dima!\n");
	else
		printf("%d\n", maxx/4);
}