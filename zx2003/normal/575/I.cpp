#include<bits/stdc++.h>
using namespace std;
const int N=5005,Q=1e5+5;
int bi[N][N*2],nn,mm,i;
inline void add(int x,int y,int v){for(;x<=nn;x+=x&-x)for(int t=y;t<=mm;t+=t&-t)bi[x][t]+=v;}
inline int ask(int x,int y){int ans=0;for(;x;x-=x&-x)for(int t=y;t;t-=t&-t)ans+=bi[x][t];return ans;}
int n,q,o[Q],dir[Q],x[Q],y[Q],len[Q],ans[Q];
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n>>q;
	for(i=1;i<=q;++i){
		cin>>o[i];
		if(o[i]==1)cin>>dir[i]>>x[i]>>y[i]>>len[i];
			else cin>>x[i]>>y[i];
	}
//1
	nn=n;mm=n;memset(bi,0,sizeof bi);
	for(i=1;i<=q;++i){
		if(o[i]==1 && dir[i]==1)add(x[i],n-y[i]+2,1),add(x[i]+len[i]+1,n-y[i]+2,-1);
		if(o[i]==2)ans[i]-=ask(x[i],n-y[i]+1);
	}
	nn=n;mm=n*2;memset(bi,0,sizeof bi);
	for(i=1;i<=q;++i){
		if(o[i]==1 && dir[i]==1)add(x[i],n*2-x[i]-y[i]-len[i]+1,1),add(x[i]+len[i]+1,n*2-x[i]-y[i]-len[i]+1,-1);
		if(o[i]==2)ans[i]+=ask(x[i],n*2-x[i]-y[i]+1);
	}
//2
	nn=n;mm=n;memset(bi,0,sizeof bi);
	for(i=1;i<=q;++i){
		if(o[i]==1 && dir[i]==2)add(x[i],y[i]+1,1),add(x[i]+len[i]+1,y[i]+1,-1);
		if(o[i]==2)ans[i]-=ask(x[i],y[i]);
	}
	nn=n;mm=n*2;memset(bi,0,sizeof bi);
	for(i=1;i<=q;++i){
		if(o[i]==1 && dir[i]==2)add(x[i],n-x[i]+(y[i]-len[i]),1),add(x[i]+len[i]+1,n-x[i]+(y[i]-len[i]),-1);
		if(o[i]==2)ans[i]+=ask(x[i],n-x[i]+y[i]);
	}
//3
	nn=n;mm=n;memset(bi,0,sizeof bi);
	for(i=1;i<=q;++i){
		if(o[i]==1 && dir[i]==3)add(x[i]-len[i],n-y[i]+2,1),add(x[i]+1,n-y[i]+2,-1);
		if(o[i]==2)ans[i]-=ask(x[i],n-y[i]+1);
	}
	nn=n;mm=n*2;memset(bi,0,sizeof bi);
	for(i=1;i<=q;++i){
		if(o[i]==1 && dir[i]==3)add(n-x[i]+1,n+x[i]-(y[i]+len[i]),1),add(n-(x[i]-len[i]-1)+1,n+x[i]-(y[i]+len[i]),-1);
		if(o[i]==2)ans[i]+=ask(n-x[i]+1,n+x[i]-y[i]);
	}
//4	
	nn=n;mm=n;memset(bi,0,sizeof bi);
	for(i=1;i<=q;++i){
		if(o[i]==1 && dir[i]==4)add(x[i]-len[i],y[i]+1,1),add(x[i]+1,y[i]+1,-1);
		if(o[i]==2)ans[i]-=ask(x[i],y[i]);
	}
	nn=n;mm=n*2;memset(bi,0,sizeof bi);
	for(i=1;i<=q;++i){
		if(o[i]==1 && dir[i]==4)add(n-x[i]+1,x[i]-len[i]+y[i]-1,1),add(n-(x[i]-len[i]-1)+1,x[i]-len[i]+y[i]-1,-1);
		if(o[i]==2)ans[i]+=ask(n-x[i]+1,x[i]+y[i]-1);
	}

	for(i=1;i<=q;++i)if(o[i]==2)cout<<ans[i]<<'\n';
	return 0;
}