#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<cstdlib>
#define ll long long
using namespace std;
ll x1,x2,x3,n,x,topa,topb,ans1,ans2,anum,bnum;
ll a[300005],b[300005];
char s[5];
int main(){
	scanf("%I64d%I64d%I64d%I64d",&x1,&x3,&x2,&n);
	for (ll i=1;i<=n;i++){
		scanf("%I64d%s",&x,&s);
		if (s[0]=='U') a[++topa]=x;
		else b[++topb]=x;
	}
	sort(a+1,a+topa+1);
	sort(b+1,b+topb+1);
	for (ll i=1;i<=topa;i++) a[i]+=a[i-1];
	for (ll i=1;i<=topb;i++) b[i]+=b[i-1];
	ans1=ans2=0;
	for (ll i=topa;i>=0;i--){
		anum=min(x1+x2,i);
		if (anum==x1+x2) bnum=min(topb,x3);
		else if (anum>=x1) bnum=min(topb,x1+x2-anum+x3);
		else bnum=min(topb,x2+x3);
		if (anum+bnum>ans1){
			ans1=anum+bnum;
			ans2=a[anum]+b[bnum];
		}
		else if (anum+bnum==ans1&&ans2>a[anum]+b[bnum]) ans2=a[anum]+b[bnum];
	}
	printf("%I64d %I64d",ans1,ans2);
}