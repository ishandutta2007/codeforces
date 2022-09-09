#include<bits/stdc++.h>
using namespace std;
typedef vector<int>V;
const int N=1e5+5;
int T,n,a[N],i;
V ans[999];int k;
bool b[N];
int getf(int n){int i=1;for(;i*(i+1)/2<=n;++i);return i-1;}
void solve(V a){
	static int pre[N],q[N],le[N];int w=0,n=a.size(),x,j;
	for(j=1;j<=n;++j){
		x=lower_bound(q+1,q+w+1,j,[&](int x,int y){return a[x-1]<a[y-1];})-q;
		pre[j]=q[x-1];q[x]=j;le[j]=x;w+=x==w+1;
	}
	if(w>getf(n)){
		memset(b,0,n);for(j=q[w];j;j=pre[j])b[j-1]=1;
		V na;++k;for(j=0;j<n;++j)if(!b[j])na.push_back(a[j]);else ans[k].push_back(a[j]);
		solve(na);
	}else{for(j=1;j<=n;++j)ans[le[j]+k].push_back(a[j-1]);k+=w;}
}
int main(){
	for(scanf("%d",&T);T--;){
		scanf("%d",&n);
		for(i=0;i<n;++i)scanf("%d",a+i);
		k=0;solve(V(a,a+n));
		printf("%d\n",k);
		for(i=1;i<=k;++i){printf("%d ",int(ans[i].size()));for(int x:ans[i])printf("%d ",x);puts("");ans[i].clear();}
	}
}