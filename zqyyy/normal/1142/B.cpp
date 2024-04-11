#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read(){
	int f=1,r=0;char c=getchar();
	while(!isdigit(c))f^=c=='-',c=getchar();
	while(isdigit(c))r=(r<<1)+(r<<3)+(c^48),c=getchar();
	return f?r:-r;
}
const int N=2e5+7;
int n,m,Q,a[N],pos[N],p[N],lst[N];
int lg[N],st[N][18];
inline int query(int l,int r){
	int k=lg[r-l+1];
	return min(st[l][k],st[r-(1<<k)+1][k]);
}
int main(){
	n=read(),m=read(),Q=read();
	for(int i=1;i<=n;i++)pos[p[i]=read()]=i;
	for(int i=1;i<=m;i++)a[i]=read(),st[i][0]=m+1;
	for(int i=2;i<=m;i++)lg[i]=lg[i>>1]+1;
	for(int i=1;i<=m;i++)st[i][0]=m+1;
	for(int i=m;i;i--){
		int x=lst[p[pos[a[i]]%n+1]];
		st[i][0]=x,lst[a[i]]=i;
	}
	for(int j=1;j<=lg[n];j++)
		for(int i=1;i<=m;i++)
			st[i][j]=st[st[i][j-1]][j-1];
	for(int i=1;i<=m;i++){
		int x=i;
		for(int j=lg[n];~j;j--)
			if((n-1)>>j&1)x=st[x][j];
		st[i][0]=x;
		if(!st[i][0])st[i][0]=m+1;
	}
	for(int j=1;j<=lg[m];j++)
		for(int i=1;i+(1<<j)-1<=m;i++)
			st[i][j]=min(st[i][j-1],st[i+(1<<j-1)][j-1]);
	while(Q--){
		int l=read(),r=read();
		printf("%d",query(l,r)<=r);
	}
	return 0;
}