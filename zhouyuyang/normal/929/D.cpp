#include<bits/stdc++.h>
#define N 300005
using namespace std;
int k[N],g[N],use[N];
int la[N],up[N],dn[N];
int n,S,T;
void GG(){
	puts("-1"); exit(0);
}
long long solve(int T){
	if (T==0||T==n+1) GG();
	if (use[T]) GG();
	use[T]=1;
	if (S==T) return 0;
	int tmp=(S<T?dn[T]:up[T]);
	return solve(tmp)+abs(T-tmp);
}
int main(){
	scanf("%d%d%d",&n,&S,&T);
	for (int i=1;i<n;i++)
		scanf("%d",&g[i]);
	for (int i=1;i<=n;i++)
		scanf("%d",&k[i]);
	dn[S]=S;
	for (int i=1;i<=n;i++){
		if (i>S) dn[i]=min(dn[i-1],la[g[i-1]]);
		la[k[i]]=i;
	}
	up[S]=S;
	for (int i=1;i<N;i++)
		la[i]=n+1;
	for (int i=n;i;i--){
		if (i<S) up[i]=max(up[i+1],la[g[i]]);
		la[k[i]]=i;
	}
	printf("%lld",solve(T));
}