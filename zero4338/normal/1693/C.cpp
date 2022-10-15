#include<bits/stdc++.h>
using namespace std;
int read()
{
	int ret=0;bool f=0;char c=getchar();
	while(c>'9'||c<'0')f|=(c=='-'),c=getchar();
	while(c>='0'&&c<='9')ret=(ret<<3)+(ret<<1)+(c^48),c=getchar();
	return f?-ret:ret;
}
const int maxn=2e5+50;
int n,m;
vector<int>e[maxn];
void add(int x,int y){e[x].push_back(y);}
vector<int>p[maxn];
int f[maxn],deg[maxn];
int main()
{
	n=read();m=read();
	for(int i=1;i<=m;i++){int u=read(),v=read();add(v,u);deg[u]++;}
	memset(f,0x3f,sizeof f);p[0].push_back(n);
	f[n]=0;
	for(int i=0;i<=m+10;i++)
	{
		for(int &j:p[i])
		{
			if(f[j]!=i)continue;
			for(int &k:e[j])
			{
				deg[k]--;
				if(deg[k]+i+1<f[k]){f[k]=deg[k]+i+1;p[f[k]].push_back(k);}
			}
		}
	}
	printf("%d\n",f[1]);

}