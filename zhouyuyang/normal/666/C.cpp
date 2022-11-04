#include<cstdio>
#include<cstring>
using namespace std;
int pow25[100010],fac[100010],inv[100010],f[450][100010],mp[100010],n,m,l,op,cnt;
char s[100010];const int mod=1e9+7;
void dp(int x){
	f[mp[x]][x]=1;
	for(int i=x+1;i<=100000;++i)
		f[mp[x]][i]=(26ll*f[mp[x]][i-1]%mod+1ll*pow25[i-x]*fac[i-1]%mod*inv[x-1]%mod*inv[i-x]%mod)%mod;
}
int main(){
	pow25[0]=fac[0]=inv[0]=fac[1]=inv[1]=1;pow25[1]=25;
	for(int i=2;i<=100000;++i){
		fac[i]=1ll*fac[i-1]*i%mod;
		pow25[i]=25ll*pow25[i-1]%mod;
		inv[i]=1ll*(mod-mod/i)*inv[mod%i]%mod;
	}
	for(int i=2;i<=100000;++i)inv[i]=1ll*inv[i]*inv[i-1]%mod;
	scanf("%d%s",&n,s);
	l=strlen(s);
	mp[l]=++cnt;
	dp(l);
	while(n--){
		scanf("%d",&op);
		if(op&1){
		       scanf("%s",s);
		       l=strlen(s);
		       if(!mp[l])mp[l]=++cnt,dp(l);
		}
		else{
		    scanf("%d",&m);
		    printf("%d\n",f[mp[l]][m]);
		}
	}
}