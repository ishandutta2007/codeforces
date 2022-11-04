#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<cmath>
#define ll long long
using namespace std; 
int T,n;
ll A,B,C,a,b,c,M,MA,ans,v,p[100],q[100];
void cal(int s,ll now){
	if (now>M) return;
	if (s>n){
		if (now<a) return;
		b=now,c=v/a/b;
		if (a*b+a*c+b*c<ans)
			ans=a*b+a*c+b*c,A=a,B=b,C=c;
		return;
	}
	if (q[s]) q[s]--,cal(s,now*p[s]),q[s]++;
	cal(s+1,now);
}
void dfs(int s,ll now){
	if (now>MA) return;
	if (s>n){
		if (a=now,v/a+2*a*sqrt(v/a)<ans)
			M=sqrt(v/a+1e-8),cal(1,1);
		return;
	}
	if (q[s]) q[s]--,dfs(s,now*p[s]),q[s]++;
	dfs(s+1,now);
}
int main(){
	scanf("%d",&T);
	while (T--){
		scanf("%d",&n);
		v=1;
		for (ll i=1;i<=n;i++){
			scanf("%I64d%I64d",&p[i],&q[i]);
			for (ll j=1;j<=q[i];j++) v=v*p[i];
		}
		ans=5e18; A=0; MA=pow(v,1./3)+1e-9; dfs(1,1);
		printf("%I64d %I64d %I64d %I64d\n",2*ans,A,B,C);
	}
}