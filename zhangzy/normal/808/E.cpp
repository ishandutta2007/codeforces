#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,m,pos;
struct P{
	int w,val;
}p[101000];
bool cmp(P p1,P p2){
	return (ll)p1.val*p2.w > (ll)p2.val*p1.w;
}
ll f[301000],ans;

int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++) scanf("%d%d",&p[i].w,&p[i].val);
	sort(p+1,p+n+1,cmp);
	for (int i=1;i<=n;i++){
		pos=min(pos+p[i].w,m);
		for (int j=min(m,pos+10);j>=max(p[i].w,pos-100);j--){
			f[j]=max(f[j],f[j-p[i].w]+p[i].val);
			ans=max(ans,f[j]);
		}
	}
	printf("%I64d",ans);
}