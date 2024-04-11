#include<stdio.h>
#include<vector>
#include<stack>
#define mod 1000000007
char c[1000004];
int n,m,t[1000004],f[1000004],F[1000004];
std::stack<int>S;
int cv[1000004],tp=0;
int main(){
	scanf("%s",c+1);
	for(m=0;c[m+1];m++);
	int mul=1;
	if(c[m]=='0'){
		while(m&&c[m]=='0')mul++,m--;
	}
	for(int i=1,cnt=0;i<=m;i++){
		cnt++;
		if(c[i]=='1'||i==m)t[++n]=cnt,cnt=0;
	}S.push(n+1);t[n+1]=1e7;
	for(int i=n;i;i--){
		while(!S.empty()&&t[S.top()]<=t[i])S.pop();
		F[i]=S.top();S.push(i);
	}f[0]=0;
	for(int i=1;i<=n;i++){
		if(i==1)f[i]=t[i];
		cv[i]=(cv[i]+f[i-1])%mod;
		f[i]=(1ull*f[i-1]*t[i]+f[i])%mod;
		cv[F[i]]=(cv[i]+cv[F[i]])%mod;
		f[F[i]]=(1ull*cv[i]*(t[F[i]]-t[i])+f[F[i]])%mod;
	}int ans=0;for(int i=1;i<=n;i++)ans+=f[i],ans%=mod;printf("%lld",(1ll*ans*mul+(!m?mul-1:0))%mod);
}
/*

321411

*/