#include<bits/stdc++.h>
#define mo 1000000007
using namespace std;
int f[705][10][705];
char s[705];
int n,p[705],ans;
int dp(int b,int id,int sum,int top){
	if (!b) return sum?0:1;
	if (!top&&f[b][id][sum]!=-1)
		return f[b][id][sum];
	int ans=0;
	for (int i=0;i<=(top?s[b]-'0':9);i++)
		ans=(ans+dp(b-1,id,max(0,sum-(i>=id?1:0)),top&(i==s[b]-'0')))%mo;
	if (!top) f[b][id][sum]=ans;
	return ans;
}
int main(){
	scanf("%s",s+1); 
	n=strlen(s+1);
	reverse(s+1,s+n+1);
	p[1]=1;
	for (int i=2;i<=n;i++)
		p[i]=1ll*p[i-1]*10%mo;
	memset(f,-1,sizeof(f));
	for (int i=1;i<=n;i++)
		for (int j=0;j<=9;j++){
			int tmp=dp(n,j,i,1);
			if (j!=9) tmp=(tmp+mo-dp(n,j+1,i,1))%mo;
			ans=(ans+1ll*tmp*p[i]%mo*j)%mo;
		}
	printf("%d",ans);
}