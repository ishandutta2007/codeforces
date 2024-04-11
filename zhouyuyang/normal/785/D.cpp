#include<bits/stdc++.h>
#define mo 1000000007
#define N 200005
using namespace std;
char s[N];
int fac[N],inv[N];
int suf[N];
int main(){
	scanf("%s",s+1);
	int n=strlen(s+1);
	fac[0]=inv[0]=inv[1]=1;
	for (int i=2;i<=n;i++)
		inv[i]=1ll*inv[mo%i]*(mo-mo/i)%mo;
	for (int i=1;i<=n;i++){
		fac[i]=1ll*fac[i-1]*i%mo;
		inv[i]=1ll*inv[i-1]*inv[i]%mo;
	}
	for (int i=n;i;i--)
		suf[i]=suf[i+1]+(s[i]==')');
	int ans=0,sum=0;
	for (int i=1;i<=n;i++)
		if (s[i]=='('){
			if (suf[i])
				ans=(ans+1ll*fac[sum+suf[i]]*inv[sum+1]%mo*inv[suf[i]-1]%mo)%mo;
			sum++;
		}
	printf("%d",ans);
}
//sigma C(x-1,x-i)*C(y,i)