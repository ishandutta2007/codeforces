#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=30005;
int d,m,n,lm,i,j,b[N],gen[25];
ll L,R;
struct atom{
	bitset<N>pr,sf,all;
	ll ans,l;
	void set(int v){
		if(v<=b[n])pr.set(n);if(v<=b[1])sf.set(1);
		for(int i=1;i<=n;++i)if(v<=b[i])all.set(i);
		ans=n==1 && v<=b[1];l=1;
	}
}a[65][65];
inline atom uni(const atom&a,const atom&b){
	static atom ret;
	ret.l=a.l+b.l;
	ret.pr=a.pr;if(a.l<n)ret.pr|=(a.all<<a.l&b.pr)>>a.l;
	ret.sf=b.sf;if(b.l<n)ret.sf|=(b.all>>1&a.sf)<<b.l;
	if(a.l+b.l<=n)ret.all=b.all>>a.l&a.all;else ret.all.reset();
	ret.ans=a.ans+b.ans+(a.sf<<1&b.pr).count();
	return ret;
}
inline ll calc(ll x){
	ll y=0,pr=0;
	static atom ans;bool fl=0;ans.ans=0;
	for(i=lm-1;i>=0;--i){
		for(j=0;y+a[i][(pr+gen[j])%m].l<=x;++j){
			if(!fl)ans=a[i][(pr+gen[j])%m],fl=1;else ans=uni(ans,a[i][(pr+gen[j])%m]);
			y+=a[i][(pr+gen[j])%m].l;
		}
		pr=(pr+gen[j])%m;
	}
	return ans.ans;
}
int main(){
	scanf("%d%d",&d,&m);for(i=0;i<d;++i)scanf("%d",gen+i);
	scanf("%d",&n);for(i=1;i<=n;++i)scanf("%d",b+i);scanf("%lld%lld",&L,&R);
	for(i=0;i<m;++i)a[0][i].set(i);
	for(lm=1;a[lm-1][0].l<=R/d;++lm)for(i=0;i<m;++i){
		a[lm][i]=a[lm-1][(i+gen[0])%m];
		for(j=1;j<d;++j)a[lm][i]=uni(a[lm][i],a[lm-1][(i+gen[j])%m]);
	}
	printf("%lld\n",calc(R)-calc(L+n-2));
	return 0;
}