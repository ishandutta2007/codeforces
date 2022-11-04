#include<bits/stdc++.h>
#define mo 1000000007
#define N 1000005
using namespace std;
int s0[N],s1[N];
int s2[N],s3[N];
int p[N];
long long ans;
void upd(int &x,int y){
	(x+=y)>=mo?x-=mo:233; 
}
int main(){
	int S=1e6-1,n;
	scanf("%d",&n);
	p[0]=1;
	for (int i=1;i<=n;i++){
		int x;
		scanf("%d",&x);
		upd(s0[x],1);
		upd(s1[x],x);
		upd(s2[x],1ll*x*x%mo);
		p[i]=p[i-1]*2%mo;
	}
	for (int x=1;x<=1e5;x*=10)
		for (int i=S;i>=0;i--)
			if (i/x%10){
				upd(s0[i-x],s0[i]);
				upd(s1[i-x],s1[i]);
				upd(s2[i-x],s2[i]);
			}
	for (int i=0;i<=S;i++){
		if (s0[i]-1>=0)
			upd(s3[i],1ll*s2[i]*p[s0[i]-1]%mo);
		if (s0[i]-2>=0)
			upd(s3[i],1ll*(1ll*s1[i]*s1[i]+mo-s2[i])%mo*p[s0[i]-2]%mo);
	}
	for (int x=1;x<=1e5;x*=10)
		for (int i=0;i<=S;i++)
			if (i/x%10<9)
				upd(s3[i],mo-s3[i+x]);
	for (int i=0;i<=S;i++)
		ans^=1ll*i*s3[i];
	printf("%lld",ans);
}