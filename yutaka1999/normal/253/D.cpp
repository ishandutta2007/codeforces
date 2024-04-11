#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>

using namespace std;
typedef __int64 ll;

int rui[405][405];
int same[30];
char in[405][405];

int val(int a,int b,int c,int d)
{
	int ret=rui[c][d];
	if(b>0) ret-=rui[c][b-1];
	if(a>0) ret-=rui[a-1][d];
	if(a>0&&b>0) ret+=rui[a-1][b-1];
	return ret;
}
int toi(char c)
{
	return c-'a';
}
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int n,m,k;
	scanf("%d %d %d",&n,&m,&k);
	for(int i=0;i<n;i++)
	{
		scanf("\n");
		for(int j=0;j<m;j++)
		{
			char c;
			scanf("%c",&c);
			in[i][j]=c;
			if(i>0) rui[i][j]+=rui[i-1][j];
			if(j>0) rui[i][j]+=rui[i][j-1];
			if(i>0&&j>0) rui[i][j]-=rui[i-1][j-1];
			if(c=='a') rui[i][j]++;
		}
	}
	ll ret=0;
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			int s=m-1,e=m-1;
			memset(same,0,sizeof(same));
			while(s<=e&&s>=0)
			{
				if(in[i][s]==in[j][s])
				{
					while(s<e&&val(i,s,j,e)>k)
					{
						if(in[i][e]==in[j][e]) same[toi(in[i][e])]--;
						e--;
					}
					ret+=same[toi(in[i][s])]++;
				}s--;
			}
		}
	}
	printf("%I64d\n",ret);
	return 0;
}