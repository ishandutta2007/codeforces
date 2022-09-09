#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>pii;
const int N=3e3+5;
int n,m,a,b,g,x,y,z,i,j,h[N][N],hh[N][N];
pii q[N];int t,w;
inline void clea(){
	t=1;w=0;
}
inline void ins(pii v){
	for(;t<=w && q[w]>=v;--w);
	q[++w]=v;
}
inline int ask(int l){
	for(;q[t].second<l;++t);
	return q[t].first;
}
long long ans;
int main(){
	scanf("%d%d%d%d%d%d%d%d",&n,&m,&a,&b,&g,&x,&y,&z);
	for(i=0;i<n;++i)for(j=0;j<m;++j)h[i][j]=g,g=(1ll*g*x+y)%z;
	for(i=0;i<n;++i){
		clea();
		for(j=0;j<m;++j){
			ins(pii(h[i][j],j));
			if(j>=b-1)hh[i][j-b+1]=ask(j-b+1);
		}
	}
	for(j=0;j<=m-b;++j){
		clea();
		for(i=0;i<n;++i){
			ins(pii(hh[i][j],i));
			if(i>=a-1)ans+=ask(i-a+1);
		}
	}
	cout<<ans<<endl;
	return 0;
}