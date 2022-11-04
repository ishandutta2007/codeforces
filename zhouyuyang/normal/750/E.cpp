#include<iostream>
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
using namespace std;
const int inf=1e9;
char s[200005];
int n,q,x,y,ans;
struct orz{
	int a[5][5];
	orz operator + (const orz b)const{
		orz c;
		for (int i=0;i<5;i++)
			for (int j=0;j<5;j++){
				c.a[i][j]=inf;
				for (int k=0;k<5;k++) c.a[i][j]=min(c.a[i][j],a[i][k]+b.a[k][j]);
			}
		return c;
	}
}e[800005];
void build(int l,int r,int x){
	if (l==r){
		for (int i=0;i<5;i++)
			for (int j=0;j<5;j++)
				e[x].a[i][j]=((i==j)?0:inf);
		if (s[l]=='2') e[x].a[0][0]=1,e[x].a[0][1]=0;
		else if (s[l]=='0') e[x].a[1][1]=1,e[x].a[1][2]=0;
		else if (s[l]=='1') e[x].a[2][2]=1,e[x].a[2][3]=0;
		else if (s[l]=='7') e[x].a[3][3]=1,e[x].a[3][4]=0;
		else if (s[l]=='6') e[x].a[3][3]=1,e[x].a[4][4]=1;
		return;
	}
	int m=(l+r)/2;
	build(l,m,x*2);
	build(m+1,r,x*2+1);
	e[x]=e[x*2]+e[x*2+1];
}
orz ask(int l,int r,int p,int q,int x){
	if (l==p&&r==q) return e[x];
	int m=(l+r)/2;
	if (q<=m) return ask(l,m,p,q,x*2);
	if (p>m) return ask(m+1,r,p,q,x*2+1);
	else return ask(l,m,p,m,x*2)+ask(m+1,r,m+1,q,x*2+1);
}
int main(){
	scanf("%d%d%s",&n,&q,s+1);
	build(1,n,1);
	for (int i=1;i<=q;i++){
		scanf("%d%d",&x,&y);
		ans=ask(1,n,x,y,1).a[0][4];
		if (ans==inf) printf("-1\n");
		else printf("%d\n",ans);
	}
	return 0;
}