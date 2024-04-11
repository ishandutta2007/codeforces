#include<bits/stdc++.h>
using namespace std;
int n,x,y;
long long ans=1ll<<60;
char s[1001000];
int main(){
	scanf("%d%d%d",&n,&x,&y);
	scanf("%s",s+1);
	int cnt0=0;
	for(int i=1;i<=n;++i){
		if(s[i]!=s[i-1])
			cnt0+=s[i]=='0';
	}
	if(!cnt0)ans=0;
	for(int i=0;i<cnt0;++i){
		ans=min(ans,1ll*i*x+1ll*(cnt0-i)*y);
	}
	printf("%lld",ans);
	
}