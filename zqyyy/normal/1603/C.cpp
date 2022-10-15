#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read(){
	int f=1,r=0;char c=getchar();
	while(!isdigit(c))f^=c=='-',c=getchar();
	while(isdigit(c))r=(r<<1)+(r<<3)+(c&15),c=getchar();
	return f?r:-r;
}
const int N=1e5+7,mod=998244353;
int n,l[N],r[N],cnt[N],a[N];
inline void work(){
	n=read();
	for(int i=1;i<=n;i++)a[i]=l[i]=r[i]=read(),cnt[i]=1;
	int ans=0,sum=0;
	for(int i=1;i<=n;i++){
		int j=i-1;
		while(j && r[j]>l[j+1]){
			int t=(a[j]+l[j+1]-1)/l[j+1];
			sum=(sum+1ll*j*(t-cnt[j]))%mod,cnt[j]=t;
			l[j]=a[j]/t,r[j]=l[j]+(a[j]%t!=0);
			j--;
		}
		ans=(ans+sum)%mod;
	}
	printf("%d\n",ans);
}
int main(){
	int test=read();
	while(test--)work();
	return 0;	
}