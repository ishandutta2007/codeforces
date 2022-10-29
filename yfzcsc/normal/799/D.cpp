#include<bits/stdc++.h>
#define maxn 100100
using namespace std;
typedef long long ll;
int A[maxn],B[maxn],a,b,h,w,n,ans;
int comp(ll a,ll b){return a>b;}
ll qpow(ll a,ll b){
	ll ans=1,tmp=a;
	for(;b;b>>=1,tmp*=tmp)
		if(b&1)ans*=tmp;
	return ans;
}
void dfs(int ptr,ll h,ll w,int an){
//	printf("[%lld,%lld,%d]",h,w,an);
	if(h>=a&&w>=b){ans=min(ans,an);return ;}
	if(ptr==n+1)return ;
	int ah=0,aw=0;
	ll _h=h,_w=w;
	while(_h<a)_h*=A[ptr],ah++;
	while(_w<b)_w*=A[ptr],aw++;
	if(ah<aw){
		for(int i=0;i<=ah&&i<=B[A[ptr]];++i)
			dfs(ptr+1,h*qpow(A[ptr],i),w*qpow(A[ptr],min(aw,B[A[ptr]]-i)),min(aw,B[A[ptr]]-i)+i+an);	
	} else {
		for(int i=0;i<=aw&&i<=B[A[ptr]];++i)
			dfs(ptr+1,h*qpow(A[ptr],min(ah,B[A[ptr]]-i)),w*qpow(A[ptr],i),min(ah,B[A[ptr]]-i)+i+an);
	}
	
}
int main(){
	scanf("%d%d%d%d%d",&a,&b,&h,&w,&n);
	for(int i=1;i<=n;++i)
		scanf("%d",&A[i]),B[A[i]]++;
	sort(A+1,A+n+1);
	n=unique(A+1,A+n+1)-A-1;
	reverse(A+1,A+n+1);
	ans=1<<30;
	dfs(1,h,w,0),dfs(1,w,h,0);
	if(ans==(1<<30))puts("-1");
	else printf("%d",ans);
}