#include<bits/stdc++.h>
#define ll long long
using namespace std;
int k,tot;
ll n,ans[23333];
int main(){
	scanf("%lld%d",&n,&k);
	ans[0]=n; tot=0;
	for (;ans[tot]<0||ans[tot]>=k;tot++)
		if (ans[tot]>=0){
			ans[tot+1]=-(ans[tot]/k);
			ans[tot]%=k;
		}
		else{
			int tmp=(k-(-ans[tot])%k);
			ans[tot+1]=(-ans[tot])/k+1-tmp/k;
			ans[tot]=tmp%k;
		}
	printf("%d\n",tot+1);
	for (int i=0;i<=tot;i++)
		printf("%lld ",ans[i]);
}