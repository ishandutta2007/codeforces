#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define pre(i,a,b) for(int i=a;i>=b;i--)
#define int long long 
#define N 100005
#define P 1000000007
using namespace std;
char s[N];int n,ans,c[N],d[N];
signed main(){
	scanf("%s",s+1);
	n=strlen(s+1);
	int sum=0;
	c[0]=d[0]=1;
	rep(i,1,N-5)c[i]=(c[i-1]*10+1)%P,d[i]=d[i-1]*10%P;
	rep(i,1,n-1){
		sum=(sum*10+s[i]-'0')%P;
		ans+=sum*c[n-i-1]%P;
	}
	sum=0;
	pre(i,n,2){
		sum=(sum+(s[i]-'0')*d[n-i])%P;
		ans+=sum*(i-1)%P;
	}
	printf("%lld\n",ans%P);
	return 0;
}