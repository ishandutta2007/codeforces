#include<bits/stdc++.h>
#define maxn 210000
#define mod 1000000007
using namespace std;
int fac[maxn],inv[maxn],n,M=2e5+10;
char A[maxn],B[maxn];
int qpow(int a,int b){
	int ans=1;
	for(;b;b>>=1,a=1ll*a*a%mod)
		if(b&1)ans=1ll*ans*a%mod;
	return ans;
}
int C(int x,int y){
	if(y<0||y>x)return 0;
	return 1ll*fac[x]*inv[y]%mod*inv[x-y]%mod;
}
int sol(int n,int k){
	if(n<0||k<0)return 0;
	if(n==0&&k==0)return 1;
	return C(n+k-1,k-1);
}
int cal(int pre,int c00,int c01,int c10,int c11){
	int ans=0;
	if(c00<0||c01<0||c10<0||c11<0)return 0;
	if(pre==-1){
		//010
//		if(c01==c10)ans=(ans+1ll*sol(c00,c01+1)*sol(c11,c01))%mod;
		//101
		if(c01==c10)ans=(ans+1ll*sol(c00,c01)*sol(c11,c01+1))%mod;
		//0101
//		if(c01==c10+1)ans=(ans+1ll*sol(c00,c01)*sol(c11,c01))%mod;
		//1010
		if(c10==c01+1)ans=(ans+1ll*sol(c00,c10)*sol(c11,c10))%mod;
	} else if(pre==0){
		//0 010
		if(c01==c10)ans=(ans+1ll*sol(c00-1,c01+1)*sol(c11,c01))%mod;
		//0 101
		if(c01-1==c10)ans=(ans+1ll*sol(c00,c01-1)*sol(c11,c01-1+1))%mod;
		//0 0101
		if(c01==c10+1)ans=(ans+1ll*sol(c00-1,c01)*sol(c11,c01))%mod;
		//0 1010
		if(c10==c01-1+1)ans=(ans+1ll*sol(c00,c10)*sol(c11,c10))%mod;//,puts("YES");
	} else if(pre==1){
		//1 010
		if(c01==c10-1)ans=(ans+1ll*sol(c00,c01+1)*sol(c11,c01))%mod;
		//1 101
		if(c01==c10)ans=(ans+1ll*sol(c00,c01)*sol(c11-1,c01+1))%mod;
		//1 0101
		if(c01==c10-1+1)ans=(ans+1ll*sol(c00,c01)*sol(c11,c01))%mod;
		//1 1010
		if(c10==c01+1)ans=(ans+1ll*sol(c00,c10)*sol(c11-1,c10))%mod;
	}
	return ans;
}
char c[maxn];
int sol(char* A,int n,int c00,int c01,int c10,int c11){
	int ans=0;
	memset(c,0,sizeof(c));
	for(int i=1;i<n;++i)if(i-1==c00+c01+c10+c11)
		ans=(ans+cal(-1,c00,c01,c10,c11))%mod;//,printf("{%d}",i);
	for(int i=n;i>=1;--i){
		if(A[i]=='1'&&i<n){
			if(c[i+1]=='0')c00--;
			else if(c[i+1]=='1')c10--;
//			printf("[%d(%d,%d,%d,%d)]\n",c00+c01+c10+c11,c00,c01,c10,c11);
			if(i==1)ans+=(c00==0&&c01==0&&c10==0&&c11==0);
			else if(i-1==c00+c01+c10+c11)
				ans=(ans+cal(0,c00,c01,c10,c11))%mod;//,puts("OK");
			if(c[i+1]=='0')c00++;
			else if(c[i+1]=='1')c10++;
		}
		c[i]=A[i];
		if(c[i+1]=='0'&&c[i]=='0')c00--;
		else if(c[i+1]=='0'&&c[i]=='1')c01--;
		else if(c[i+1]=='1'&&c[i]=='0')c10--;
		else if(c[i+1]=='1'&&c[i]=='1')c11--;
//		printf("<%d:%d,%d,%d,%d>\n",c00+c01+c10+c11,c00,c01,c10,c11);
		if(c00<0||c01<0||c10<0||c11<0)break;
		if(i==1)ans+=(c00==0&&c01==0&&c10==0&&c11==0);
	}
//	printf("{%d,%d,%d,%d}",c00,c01,c10,c11);
//	printf("[%d]",ans);
	return ans;
}
int main(){
	scanf("%s%s",A+1,B+1);
	int c00,c01,c10,c11;
	scanf("%d%d%d%d",&c00,&c01,&c10,&c11);
	fac[0]=inv[0]=1;
	for(int i=1;i<=M;++i)fac[i]=1ll*fac[i-1]*i%mod;
	inv[M]=qpow(fac[M],mod-2);
	for(int i=M-1;i>=1;--i)inv[i]=1ll*inv[i+1]*(i+1)%mod;
	int n=strlen(B+1),m=strlen(A+1);
	reverse(A+1,A+m+1);
	reverse(B+1,B+n+1);
	int ans=(sol(B,n,c00,c01,c10,c11)-sol(A,m,c00,c01,c10,c11)+mod)%mod;
	for(int i=m-1;i>=1;--i){
		c[i]=A[i];
		if(c[i+1]=='0'&&c[i]=='0')c00--;
		else if(c[i+1]=='0'&&c[i]=='1')c01--;
		else if(c[i+1]=='1'&&c[i]=='0')c10--;
		else if(c[i+1]=='1'&&c[i]=='1')c11--;
	}
	if(c00==0&&c01==0&&c10==0&&c11==0)ans=(ans+1)%mod;
	printf("%d",ans);
}