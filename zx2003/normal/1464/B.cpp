#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+5;
int n,i,j,x,y,c1[N],c2[N];
char c[N];
ll f1[N],f2[N],ans=1e18;
int main(){
	scanf("%s%d%d",c+1,&x,&y);n=strlen(c+1);
	if(x<y){swap(x,y);for(i=1;i<=n;++i)if(isdigit(c[i]))c[i]^=1;}
	for(i=1;i<=n;++i)if(c[i]=='0')c1[i]=c1[i-1],f1[i]=f1[i-1]+1ll*c1[i-1]*y;
		else c1[i]=c1[i-1]+1,f1[i]=f1[i-1]+1ll*(i-1-c1[i-1])*x;
	for(i=n;i;--i)if(c[i]=='1')c2[i]=c2[i+1]+1,f2[i]=f2[i+1]+1ll*(n-i-c2[i+1])*y;
		else c2[i]=c2[i+1],f2[i]=f2[i+1]+1ll*c2[i+1]*x;
	for(i=0;i<=n;++i)ans=min(ans,f1[i]+f2[i+1]+1ll*(i-c1[i])*c2[i+1]*x+1ll*c1[i]*(n-i-c2[i+1])*y);
	printf("%lld\n",ans);
}