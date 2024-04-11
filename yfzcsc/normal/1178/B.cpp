#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
char s[1001000];
int pre[1001000],suf[1001000];
int main(){
	int n;
	scanf("%s",s+1);
	n=strlen(s+1);
	int a=0,sum=0;
	for(int i=1;i<=n;++i){
		if(s[i]=='v')a++;
		else if(s[i]=='o')pre[i]=sum+=(a==0?0:a-1),a=0;
	}
	a=0,sum=0;
	for(int i=n;i>=1;--i){
		if(s[i]=='v')a++;
		else if(s[i]=='o')suf[i]=sum+=(a==0?0:a-1),a=0;
	}
	
	ll ans=0;
	for(int i=1;i<=n;++i)if(s[i]=='o')ans+=(ll)pre[i]*suf[i];
	printf("%lld",ans);
}