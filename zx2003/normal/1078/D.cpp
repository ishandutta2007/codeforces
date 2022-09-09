#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>P;
const int N=3e5+5;
int lo[N];
int n,r[N],lb[N],rb[N],i,j,k;
struct ST{
	P f[20][N];
	function<P(P,P)>uni;
	void ini(int*a){
		for(int i=1;i<=n*3;++i)f[0][i]={a[i],i};
		for(int i=1;(1<<i)<=n*3;++i)for(int j=1;j+(1<<i)-1<=n*3;++j)f[i][j]=uni(f[i-1][j],f[i-1][j+(1<<i-1)]);
	}
	inline P ask(int x,int y){
		int l=lo[y-x+1];
		return uni(f[l][x],f[l][y-(1<<l)+1]);
	}
}ss[2];
int anc[2][20][N];
inline int calc(int x,int y){
	int x1,y1,step=0,x2,y2;
	x1=ss[0].ask(x,y).second;y1=ss[1].ask(x,y).second;
	for(int i=19;i>=0;--i){
		x2=anc[0][i][x1];y2=anc[1][i][y1];
		if(rb[y2]-lb[x2]+1>=n || (lb[x2]<x && ss[1].ask(lb[x2],x-1).first>y) || 
			(y<rb[y2] && ss[0].ask(y+1,rb[y2]).first<x))continue;
		step+=1<<i;x1=x2;y1=y2;
	}
	x1=lb[x1];y1=rb[y1];++step;
	return y1-x1+1>=n?step:calc(x1,y1)+step;
}
int main(){
	for(i=2;i<N;++i)lo[i]=lo[i>>1]+1;
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n;for(i=1;i<=n;++i)cin>>r[i],r[i+n]=r[i+n*2]=r[i];
	for(i=1;i<=n*3;++i)lb[i]=max(1,i-r[i]),rb[i]=min(n*3,i+r[i]);
	ss[0].uni=[&](P a,P b){return min(a,b);};ss[1].uni=[&](P a,P b){return max(a,b);};
	ss[0].ini(lb);ss[1].ini(rb);
	for(i=1;i<=n*3;++i)anc[0][0][i]=ss[0].ask(lb[i],rb[i]).second,anc[1][0][i]=ss[1].ask(lb[i],rb[i]).second;
	for(k=0;k<2;++k)for(i=1;i<20;++i)for(j=1;j<=n*3;++j)anc[k][i][j]=anc[k][i-1][anc[k][i-1][j]];
	for(i=n+1;i<=n*2;++i)cout<<(n==1?0:calc(i,i))<<' ';cout<<endl;
	return 0;
}