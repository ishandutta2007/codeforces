#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define pa pair<ull,ull>
#define N 200005
using namespace std;
int n,m,l[N],r[N],cnt[N];
vector<int> L[N],R[N];
ull h1[N],h2[N],a[N],b[N];
map<pa,ll> F,G;
ll ans; 
ll calc(ll n){
	return n*(n+1)*(n+1)/2-n*(n+1)*(2*n+1)/6;
}
ull rnd(){
	ull tmp=1;
	for (int i=1;i<=30;i++)
		tmp=(tmp<<2)^rand();
	return tmp;
}
int main(){
	srand(time(NULL));
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++){
		scanf("%d%d",&l[i],&r[i]);
		L[l[i]].push_back(i);
		R[r[i]].push_back(i);
		a[i]=rnd(); b[i]=rnd();
		h1[l[i]]^=a[i]; h1[r[i]+1]^=a[i];
		h2[l[i]]^=b[i]; h2[r[i]+1]^=b[i];
		cnt[l[i]]++; cnt[r[i]+1]--;
	}
	for (int i=1;i<=m;i++)
		h1[i]^=h1[i-1],h2[i]^=h2[i-1];
	for (int i=1;i<=m;i++)
		h1[i]^=h1[i-1],h2[i]^=h2[i-1];
	G[pa(0,0)]=1; F[pa(0,0)]=0;
	ull s1=0,s2=0,t1=0,t2=0;
	for (int i=1;i<=m;i++){
		for (int j=0;j<L[i].size();j++)
			s1^=a[L[i][j]],s2^=b[L[i][j]];
		ans+=G[pa(s1^h1[i],s2^h2[i])]*i;
		ans-=F[pa(s1^h1[i],s2^h2[i])];
		for (int j=0;j<R[i].size();j++)
			t1^=a[R[i][j]],t2^=b[R[i][j]];
		F[pa(t1^h1[i],t2^h2[i])]+=i;
		G[pa(t1^h1[i],t2^h2[i])]++;
	}
	for (int i=1;i<=m;i++)
		cnt[i]+=cnt[i-1];
	for (int i=1,j;i<=m;)
		if (!cnt[i]){
			int j=i;
			for (;j+1<=m&&!cnt[j+1];j++);
			ans-=calc(j-i+1);
			i=j+1;
		}
		else i++;
	printf("%I64d",ans);
}