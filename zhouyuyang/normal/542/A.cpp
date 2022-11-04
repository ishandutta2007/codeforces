#include<bits/stdc++.h>
#define ll long long
using namespace std;
struct LZH{
	int l,r,id;
	LZH(int _l=0,int _r=0,int _id=0){
		l=_l; r=_r; id=_id;
	}
	bool operator <(const LZH &lzh)const{
		return l!=lzh.l?l<lzh.l:r<lzh.r;
	}
}a[200005];
vector<LZH> ad;
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++)
		scanf("%d%d",&a[i].l,&a[i].r),a[i].id=i;
	sort(a+1,a+n+1);
	ad.push_back(LZH(-2e9,-2e9,-1));
	for (int i=1;i<=n;i++)
		if (ad.back().r<a[i].r) ad.push_back(a[i]);
	n=ad.size();
	ll ans=0;
	int id1=-1,id2=-1;
	for (int i=1;i<=m;i++){
		int l,r,c,pos;
		scanf("%d%d%d",&l,&r,&c);
		pos=lower_bound(ad.begin(),ad.end(),LZH(l,-1,-1))-ad.begin()-1;
		if (!pos) pos++;
		for (;pos<n&&ad[pos].l<=r;pos++){
			ll val=1ll*c*(min(ad[pos].r,r)-max(ad[pos].l,l));
			if (val>ans) ans=val,id1=ad[pos].id,id2=i;
		}
	}
	if (!ans) puts("0");
	else printf("%I64d\n%d %d",ans,id1,id2);
}