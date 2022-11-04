#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
#define ll long long
#define N 1000005
using namespace std;
int a,b,L,R,le,ri,ans,ans1,vis[256],ch[256];
int main(){
	scanf("%d%d%d%d",&a,&b,&L,&R);
	for (int i=1;i<=10;i++){
		int l=(i-1)*(a+b)+1,r=i*(a+b);
		memset(vis,0,sizeof(vis));
		for (int j=max(1,l-a);j<l;j++)
			vis[ch[j]]=1;
		int k=l;
		for (int j=97;j<=97+26-1&&k<l+a;j++)
			if (!vis[j]) ch[k++]=j;
		for (int j=l+a;j<=r;j++)
			ch[j]=ch[min(l+a-1,r-a+1)];
	}
	int p=(L-1)/(a+b)+1,q=(L-1)%(a+b)+1;
	int x=(R-1)/(a+b)+1,y=(R-1)%(a+b)+1;
	le=q; ri=min(8,x-p)*(a+b)+y;
	memset(vis,0,sizeof(vis));
	for (int i=le;i<=ri;i++)
		vis[ch[i]]=1;
	for (int i=97;i<=97+26-1;i++)
		if (vis[i]) ans1++;
	for (int i=1;i<=10;i++){
		int l=(i-1)*(a+b)+1,r=i*(a+b);
		memset(vis,0,sizeof(vis));
		for (int j=max(1,l-a);j<l;j++)
			vis[ch[j]]=1;
		int k=l;
		for (int j=97;j<=97+26-1&&k<l+a;j++)
			if (!vis[j]) ch[k++]=j;
		for (int j=l+a;j<=r;j++)
			ch[j]=ch[l+a-1];
	}
	memset(vis,0,sizeof(vis));
	for (int i=le;i<=ri;i++)
		vis[ch[i]]=1;
	for (int i=97;i<=97+26-1;i++)
		if (vis[i]) ans++;
	printf("%d\n",min(ans,ans1));
}