#include<bits/stdc++.h>
#define mo 1000000007
#define N 2000005
using namespace std;
int mu[N],pri[N],P[N];
bool fl[N];
int ans[N];
int n,k,tot,Ans;
int power(int x,int y){
	int s=1;
	for (;y;y/=2,x=1ll*x*x%mo)
		if (y&1) s=1ll*s*x%mo;
	return s; 
}
int main(){
	scanf("%d%d",&n,&k);
	mu[1]=1;
	for (int i=2;i<=k;i++){
		if (!fl[i]) pri[++tot]=i,mu[i]=-1;
		for (int j=1;j<=tot&&i*pri[j]<=k;j++){
			fl[i*pri[j]]=1;
			if (i%pri[j]==0){
				mu[i*pri[j]]=0;
				break;
			}
			mu[i*pri[j]]=-mu[i];
		}
	}
	for (int i=1;i<=k;i++)
		P[i]=power(i,n);
	for (int i=1;i<=k;i++){
		if (!mu[i]) continue;
		for (int j=1;j<=k/i;j++){
			int tmp=P[j]-P[j-1];
			if (mu[i]==-1) tmp=-tmp;
			tmp=(tmp+mo)%mo;
			ans[j*i]=(ans[j*i]+tmp)%mo;
		}
	}
	for (int i=1;i<=k;i++){
		ans[i]=(ans[i]+ans[i-1])%mo;
		Ans=(Ans+(ans[i]^i))%mo;
	}
	printf("%d",Ans);
}