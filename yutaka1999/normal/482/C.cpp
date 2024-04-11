#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#define SIZE 55
#define MX 25
#define BT (1<<20)

using namespace std;
typedef long double ld;
typedef long long int ll;

char str[SIZE][MX];
int cnt[BT];
ll mat[BT];
ld C[SIZE][SIZE];
ld per[BT];

void make()
{
	for(int i=0;i<SIZE;i++)
	{
		C[i][0]=C[i][i]=1.0;
		for(int j=1;j<i;j++)
		{
			C[i][j]=C[i-1][j-1]*C[i-1][j]/(C[i-1][j-1]+C[i-1][j]);
		}
	}
}
int main()
{
	make();
	int n;
	scanf("%d",&n);
	if(n==1)
	{
		puts("0");
		return 0;
	}
	for(int i=0;i<n;i++)
	{
		scanf("%s",&str[i]);
	}
	int m=strlen(str[0]);
	ld ret=0.0;
	for(int i=0;i<n;i++)
	{
		mat[0]=0;
		cnt[0]=0;
		for(int j=0;j<m;j++)
		{
			mat[1<<j]=0;
			cnt[1<<j]=1;
			for(int k=0;k<n;k++)
			{
				if(str[i][j]==str[k][j])
				{
					mat[1<<j]|=1LL<<k;
				}
			}
		}
		for(int S=1;S<1<<m;S++)
		{
			int T=S&(S-1);
			if(T>0)
			{
				mat[S]=mat[T]&mat[S-T];
				cnt[S]=cnt[T]+1;
			}
			if(mat[S]==(1LL<<i))
			{
				ret+=C[m][cnt[S]]*cnt[S];
				if(S!=(1<<m)-1) ret-=C[m][cnt[S]]*(cnt[S]+1);
			}
		}
	}
	printf("%.10f\n",(double) (ret/(ld) n));
	return 0;
}