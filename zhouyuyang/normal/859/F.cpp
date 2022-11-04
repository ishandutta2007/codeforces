#include<bits/stdc++.h>
#define ll long long
#define sz 524288
#define N 400005
using namespace std;
int n;
ll M,w[N],D[N],S[N],DS[N],IT[N*3];
void insert(int x,ll v){
	IT[x+=sz]=v;
	for (;x!=1;)
		x/=2,IT[x]=min(IT[x*2],IT[x*2+1]);
}
ll qmin(int l,int r){
	ll ans=8e18; l+=sz,r+=sz;
	for (;l<=r;l=(l+1)/2,r=(r-1)/2)
		ans=min(ans,min(IT[l],IT[r]));
	return ans;
}
int main(){
	scanf("%d%I64d",&n,&M);
	for (int i=1;i<n<<1;i++)
		scanf("%I64d",&w[i]),S[i]=S[i-1]+w[i];
	for (int i=1;i<=n;i++) D[i]=min(M,w[i*2-1]);
	int pv=0; DS[1]=D[1];
	insert(1,S[2]-D[1]);
	for (int i=2;i<=n;i++){
		for (;S[i*2-1]-S[pv]>=M;pv++);
		int t=(pv+1)/2;
		if (t!=0) D[i]=max(D[i],M-(DS[i-1]-DS[t-1]));
		ll tp=qmin(t,i-1);
		D[i]=max(D[i],(S[i*2-1]-DS[i-1])-tp);
		DS[i]=DS[i-1]+D[i];
		insert(i,S[i*2]-DS[i]);
	}
	printf("%I64d",DS[n]);
}