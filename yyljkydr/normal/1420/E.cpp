#include<bits/stdc++.h>
using namespace std;

const int N=87;

int f[N][N][N*(N-1)/2+1];

int n,a[N],s[N],t;

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	int now=0;
	for(int i=1;i<=n;i++)
	{
		if(!a[i])
			now++;
		else
			s[++t]=now,now=0;
	}
	s[++t]=now;
	for(int i=1;i<=t;i++)
		s[i]+=s[i-1];
	for(int i=0;i<=t;i++)
		for(int j=0;j<=s[t];j++)
			for(int k=0;k<=n*(n-1)/2;k++)
				f[i][j][k]=1e9;
	f[0][0][0]=0;
	for(int i=0;i<t;i++)
		for(int j=0;j<=s[t];j++)
			for(int k=0;k<=n*(n-1)/2;k++)
				if(f[i][j][k]!=1e9)
					for(int nj=j;nj<=s[t];nj++)
						if(k+abs(nj-s[i+1])<=n*(n-1)/2)
							f[i+1][nj][k+abs(nj-s[i+1])]=min(f[i+1][nj][k+abs(nj-s[i+1])],f[i][j][k]+(nj-j)*(nj-j));
	int ans=1e9;
	for(int k=0;k<=n*(n-1)/2;k++)
	{
		ans=min(ans,f[t][s[t]][k]);
		printf("%d%c",(s[t]*s[t]-ans)/2," \n"[k==n*(n-1)/2]);
	}
}