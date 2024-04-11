#include<iostream>
#include<cstdio>
#include<queue>
#include<cmath>
using namespace std;
typedef double db;
typedef long long ll;
const int N=1005;
const db pi=acos(-1.0);
int n,i,j,in[N],u,d[N];
bool b[N][N];
ll x[N],y[N],r[N];
double ans;
inline ll sqr(ll x){
	return x*x;
}
queue<int> q;
int main(){
	scanf("%d",&n);
	for(i=1;i<=n;++i)cin>>x[i]>>y[i]>>r[i];
	for(i=1;i<=n;++i)
		for(j=1;j<=n;++j)
			if(i!=j && sqr(x[i]-x[j])+sqr(y[i]-y[j])<=r[i]*r[i] && r[j]<r[i]){
				b[i][j]=1;
				++in[j];
			}
	for(i=1;i<=n;++i)if(!in[i])q.push(i);
	while(!q.empty()){
		u=q.front();
		q.pop();
		if(d[u]>1 && !(d[u]&1))ans-=pi*r[u]*r[u];
			else ans+=pi*r[u]*r[u];
		for(i=1;i<=n;++i)
			if(b[u][i]){
				--in[i];
				if(!in[i]){
					q.push(i);
					d[i]=d[u]+1;
				}
			}
	}
	printf("%.10f\n",ans);
	return 0;
}