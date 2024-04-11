#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read(){
    int f=1,r=0;char c=getchar();
    while(!isdigit(c))f^=c=='-',c=getchar();
    while(isdigit(c))r=(r<<1)+(r<<3)+(c&15),c=getchar();
    return f?r:-r;
}
const int N=4e6+7;
int n,mod,f[N],sum[N];
int main(){
	n=read(),mod=read();
	f[n]=1;
	for(int i=n;i;i--){
		f[i]=(f[i]+sum[i+1])%mod;
		for(int j=i+i;j<=n;j+=i){
			int res=sum[j];
			if(j+j/i<=n)res=(res+mod-sum[j+j/i])%mod;
			f[i]=(f[i]+res)%mod;
		}
		sum[i]=(sum[i+1]+f[i])%mod;
	}
	printf("%d\n",f[1]);
	return 0;
}