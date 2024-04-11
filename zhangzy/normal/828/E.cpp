#include<cstdio>
#include<iostream>
#include<string>
#include<cstring>
#define xxx 100100
using namespace std;
int n,l;
char s[xxx<<1];

struct BIT{
	int c[xxx];
	int siz;
	void add(int x,int v){
		for (int i=x;i<=siz;i+=(i&(-i)))
			c[i]+=v;
	}
	int que(int x){
		int t=0;
		for (int i=x;i>0;i-=(i&(-i)))
			t+=c[i];
		return t;
	}
	int qj(int x,int y){
		if (x>y) return 0;
		return que(y)-que(x-1);
	}
}bit[11][11][4];

int cg(char c)
{
	if (c=='A') return 1;
	if (c=='T') return 2;
	if (c=='G') return 3;
	return 0;
}

char ss[233];

int main()
{
	scanf("%s",s+1);
	l=strlen(s+1);
	for (int i=1;i<=10;i++)
	{
		for (int j=0;j<i;j++)
			for (int k=0;k<4;k++)
				bit[i][j][k].siz=l/i+1;
		for (int j=1;j<=l;j++)
			bit[i][j%i][cg(s[j])].add((j-1)/i+1,1);
	}
		
	scanf("%d",&n);
	int t,a,b,d,ans;
	for (int ttt=0;ttt<n;ttt++)
	{
		scanf("%d",&t);
		if (t==1)
		{
			scanf("%d",&a);
			scanf("%s",ss);
			for (int i=1;i<=10;i++)
			{
				bit[i][a%i][cg(s[a])].add((a-1)/i+1,-1);
				bit[i][a%i][cg(ss[0])].add((a-1)/i+1,1);
			}
			s[a]=ss[0];
		}
		else
		{
			scanf("%d%d",&a,&b);
			scanf("%s",ss);
			d=strlen(ss);
			ans=0;
			for (int i=0;i<d;i++)
			{
				if (a+i>b) break;
				//printf(" %d %d %d : %d\n",i,(a+i-1)/d+1,(b-(i+a-1)%d-1)/d+1,bit[d][(i+a)%d][cg(ss[i])].qj((a+i-1)/d+1,(b-(i+a-1)%d-1)/d+1));
				ans+=bit[d][(i+a)%d][cg(ss[i])].qj((a+i-1)/d+1,(b-(i+a-1)%d-1)/d+1);
			}
			printf("%d\n",ans);
		}
	}
}