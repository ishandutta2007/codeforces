#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<cmath>
using namespace std;
int n,ans,m;
struct node{int x,y;}a[200005],b[200005];
bool cmp(node a,node b){
	if (a.x!=b.x) return a.x<b.x;
	return a.y<b.y;
}
bool cmp1(node a,node b){
	if (a.y!=b.y) return a.y<b.y;
	return a.x<b.x;
} 
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d%d",&a[i].x,&a[i].y);
	scanf("%d",&m);
	for (int i=1;i<=m;i++) scanf("%d%d",&b[i].x,&b[i].y);
	sort(b+1,b+m+1,cmp);
	ans=0;
	for (int i=1;i<=n;i++)
		if (a[i].y<b[m].x) ans=max(ans,-a[i].y+b[m].x);
	sort(b+1,b+m+1,cmp1);
	for (int i=1;i<=n;i++)
		if (b[1].y<a[i].x) ans=max(ans,-b[1].y+a[i].x);
	printf("%d",ans);
}