#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=200005;
int a[N],n,i,ch[10000000][2],xb;
ll solve(int l,int r,int d){
	if(d==-1)return 0;
	xb=0;memset(ch[0],0,8);int i,x=l,y=r,j,u,z,s,an=1<<30;
	static int b[N];memcpy(b+l,a+l,(r-l+1)<<2);
	for(i=l;i<=r;++i)a[b[i]>>d&1?y--:x++]=b[i];
	if(x==l || y==r)return solve(l,r,d-1);
	for(i=l;i<=y;++i)
		for(j=d,u=0;j>=0;--j){
			z=a[i]>>j&1;
			if(!ch[u][z])ch[u][z]=++xb,memset(ch[xb],0,8);
			u=ch[u][z];
		}
	for(i=x;i<=r;an=an>s?s:an,++i)
		for(s=0,j=d,u=0;j>=0;--j){
			z=a[i]>>j&1;
			if(ch[u][z])u=ch[u][z];else u=ch[u][z^1],s+=1<<j;
		}
	return an+solve(l,y,d-1)+solve(x,r,d-1);
}
int main(){
	cin.tie(0),cin.sync_with_stdio(0);
	cin>>n;for(i=1;i<=n;++i)cin>>a[i];
	cout<<solve(1,n,29)<<endl;
	return 0;
}