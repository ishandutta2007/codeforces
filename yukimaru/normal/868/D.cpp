/*************************************************************************
    > File Name: 868_D.cpp
    > Author: yuki
    > ################### 
    > Mail: ################### 
    > Created Time: Thu 05 Oct 2017 05:11:33 PM CST
 ************************************************************************/
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<vector>
#include<cstring>
#include<map>
#include<queue>
#include<stack>
#include<string>
#include<cstdlib>
#include<ctime>
#include<set>
#include<cmath>
using namespace std;
 /*MACRO*/
#define FORi(l,r) for(int i=(l);i<(r);i++)
#define FORj(l,r) for(int j=(l);j<(r);j++)
#define FORk(l,r) for(int k=(l);k<(r);k++)
#define MEMSET0(i) memset((i),0,sizeof((i)))
#define MEMSET1(i) memset((i),-1,sizeof((i)))

char s[205][505];
int f[105];

int max(int a, int b)
{
	if(a > b) return a;
	return b;
}

void work(int x)
{
	int k;
	for(k=1; k<=10; k++)
	{
		for(int i=0;i<(1<<k);i++)
		{
			char str[20]={0};
			int t=i;
			for(int j=k-1;j>=0;j--){
				str[j]=(t&1)+'0';
				t>>=1;
			}
			if(strstr(s[x],str)==NULL){
				f[x]=k-1;
				return;
			}
		}
	}
}

int main()
{
	int n;
	while(scanf("%d", &n) != EOF)
	{
		for(int i=1; i<=n; i++) scanf("%s", s[i]);
		int sk[105]={0};
		bool flag=0;
		for(int i=1; i<=n; i++)
		{
			for(int xx=1; xx<=10; xx++)
			{
				flag=1;
				for(int j=0; j<(1<<xx); j++)
				{
					char tmp[15]={0};
					int tt=j;
					for(int ll=xx-1; ll>=0; ll--)
					{
						tmp[ll]=(tt&1)+'0';
						tt=tt>>1;
					}
					if(strstr(s[i], tmp) == NULL) flag=0;
					if(flag == 0) break;
				}
				if(flag == 0)
				{
					sk[i]=xx-1;
					break;
				}
			}
		}
//		for(int i=1; i<=n; i++) printf("%d ", sk[i]); printf("\n");
		int m;
		scanf("%d", &m);
		int a[105]={0}, b[105]={0};
//		int f[105]={0};
		for(int i=1; i<=m; i++)
		{
			scanf("%d%d",&a[i],&b[i]);
			int j=0;
			for(int x=max(0,strlen(s[a[i]])-200);s[a[i]][x]!=0;x++){
				s[i+n][j]=s[a[i]][x];
				j++;
			}
			for(int x=0;s[b[i]][x]!=0&&x<200;x++){
				s[i+n][j]=s[b[i]][x];
				j++;
			}
			work(i+n);
			memset(s[i+n],0,sizeof(s[i+n]));
			j=0;
			for(int x=0;s[a[i]][x]!=0&&x<200;x++){
				s[i+n][j]=s[a[i]][x];
				j++;
			}
			for(int x=max(0,strlen(s[b[i]])-200);s[b[i]][x]!=0;x++){
				s[i+n][j]=s[b[i]][x];
				j++;
			}
			f[i+n]=max(f[i+n],f[a[i]]);
			f[i+n]=max(f[i+n],f[b[i]]);
			printf("%d\n",f[i+n]);
		}
	}
	return 0;
}