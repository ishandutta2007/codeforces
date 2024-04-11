#include<bits/stdc++.h>
#define xx first
#define yy second
#define maxn 100010
#define G(x) (lower_bound(lsh+1,lsh+tp+1,x)-lsh)
using namespace std;
typedef long double ldb;
typedef pair<ldb,ldb> par;
const ldb eps=1e-11;
par A[maxn];
int n,w,tr[maxn],tp,tp2;
long long ans;
ldb lsh[maxn];
ldb dcmp(ldb x){
	return fabs(x)<=eps?0:(x>0?1:-1);
}
void add(int x){
	for(;x<=tp;x+=x&-x)tr[x]++;
}
int qry(int x){
	int ans=0;
	for(;x;x-=x&-x)ans+=tr[x];
	return ans;
}
int main(){
	scanf("%d%d",&n,&w);
	for(int i=1,x,v;i<=n;++i){
		scanf("%d%d",&x,&v);
		A[i]=par(-(ldb)x/(ldb)(v-w),-(ldb)x/(ldb)(v+w));
		lsh[++tp]=A[i].second;
	}
	sort(A+1,A+n+1),sort(lsh+1,lsh+tp+1);
	for(int i=1;i<=tp;++i)
		if(!tp2||dcmp(lsh[tp2]-lsh[i]))
			lsh[++tp2]=lsh[i];
	tp=tp2;
	for(int i=1,j;i<=n;i=j){
		for(j=i;j<=n&&dcmp(A[i].first-A[j].first)==0;j++)
			ans+=qry(G(A[j].second)-1);
		for(j=i;j<=n&&dcmp(A[i].first-A[j].first)==0;j++)
			add(G(A[j].second));
	}
	printf("%lld",1ll*n*(n-1)/2-ans);
}