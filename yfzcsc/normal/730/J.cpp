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

int n,a[100],b[100],mx[10001][101],q[101][10001],qe[101];
bool ap[10001][101];

int main()
{
	int as=0,bs=0;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d",a+i),as+=a[i];
	for(int i=0;i<n;i++)
		scanf("%d",b+i),bs+=b[i];
	bs-=as;
	memset(mx,0x7f,sizeof(mx));
	mx[0][0]=0;
	q[0][0]=0,qe[0]=1;
	for(int i=0;i<n;i++)
	{
		for(int j=n-1;j>=0;j--)
			for(int k=0;k<qe[j];k++)
			{
				if(q[j][k]+b[i]>bs)continue;
				repl(mx[q[j][k]+b[i]][j+1],mx[q[j][k]][j]+a[i]);
				if(!ap[q[j][k]+b[i]][j+1])
				{
					ap[q[j][k]+b[i]][j+1]=1;
					q[j+1][qe[j+1]++]=q[j][k]+b[i];
				}
			}
	}
	for(int i=n;i>=0;i--)
	{
		if(qe[i])
		{
			int y=0x7fffffff;
			for(int j=0;j<=bs;j++)
				repl(y,mx[j][i]);
			printf("%d %d\n",n-i,y);
			return 0;
		}
	}
}