#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
#define N 200005
int nxt[N],n,m;
long long ans;
struct node{
	char c;
	long long v;
	friend bool operator <=(node a,node b){
		return a.c==b.c&&a.v<=b.v;
	}
	friend bool operator ==(node a,node b){
		return a.c==b.c&&a.v==b.v;
	}
}a[N],b[N];
void pre(node *a,int &n){
	int x=n; n=1;
	for (int i=2;i<=x;i++)
		if (a[i].c==a[n].c) a[n].v+=a[i].v;
		else a[++n]=a[i];
}
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++)
		scanf("%I64d-%c",&a[i].v,&a[i].c);
	pre(a,n);
	for (int i=1;i<=m;i++)
		scanf("%I64d-%c",&b[i].v,&b[i].c);
	pre(b,m);
	if (m==1){
		for (int i=1;i<=n;i++)
			if (b[1]<=a[i])
				ans+=(a[i].v-b[1].v+1);
		printf("%I64d",ans);
		return 0;
	}
	if (m==2){
		for (int i=2;i<=n;i++)
			if (b[1]<=a[i-1]&&b[2]<=a[i]) ans++;
		printf("%I64d",ans);
		return 0;
	}
	for (int i=1,j=0;i<=m;)
		if (b[i]==b[j]||!j) nxt[++i]=++j;
		else j=nxt[j];
	for (int i=1,j=1;i<=n&&j<=m;){
		if (b[j+1]==a[i]) i++,j++;
		else if (!nxt[j]) j=1,i++;
		else j=nxt[j];
		if (j==m-1){
			if (b[1]<=a[i-j]&&b[j+1]<=a[i]) ans++;
			j=nxt[j];
		}
	}
	printf("%I64d",ans);
}