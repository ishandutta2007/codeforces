#include<bits/stdc++.h>
#define int long long
#define gc() getchar()
inline int read(){
	char c=getchar();
	while (c!='-'&&(c<'0'||c>'9'))c=getchar();
	int k=1,kk=0;
	if (c=='-')c=getchar(),k=-1;
	while (c>='0'&&c<='9')
	kk=kk*10+c-'0',c=getchar();
	return kk*k;
}
using namespace std;
int gcd(int x,int y){return y==0?x:gcd(y,x%y);}
int n,L,c[500],p[500],sum,ans;
signed main(){
	memset(c,0x3f3f3f3f,sizeof(c));
	n=read();L=read();c[1]=read();p[1]=1;
	for (int i=2;i<=n;i++) {
		p[i]=p[i-1]*2;c[i]=read();
		if (c[i]>=2*c[i-1]) c[i]=2*c[i-1];
	}for (int i=n+1;i<=31;i++){
		if (c[i]>=2*c[i-1]) c[i]=2*c[i-1];
		p[i]=p[i-1]*2;
	}int i=31;ans=1e18;
	while (1){
		while (L>=p[i])L-=p[i],sum+=c[i];
		ans=min(ans,sum+c[i]);
		i--;if (L==0) break;
	}ans=min(ans,sum);cout<<ans<<endl;
}