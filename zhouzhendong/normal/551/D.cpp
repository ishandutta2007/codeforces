#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL n,k,l,mod;
LL read(){
	LL x=0;
	char ch=getchar();
	while (!('0'<=ch&&ch<='9'))
		ch=getchar();
	while ('0'<=ch&&ch<='9')
		x=x*10+ch-48,ch=getchar();
	return x;
}
struct Mat{
	LL a[2][2];
	Mat(){}
	Mat(int x){
		memset(a,0,sizeof a);
		if (x==1)
			a[0][0]=a[1][1]=1;
		if (x==2)
			a[0][0]=a[1][0]=a[0][1]=1;
	}
	Mat operator * (Mat x){
		Mat ans(0);
		for (int i=0;i<2;i++)
			for (int j=0;j<2;j++)
				for (int k=0;k<2;k++)
					ans.a[i][j]=(ans.a[i][j]+a[i][k]*x.a[k][j])%mod;
		return ans;
	}
	Mat operator ^ (LL y){
		Mat ans(1),x=*this;
		while (y>0){
			if (y&1LL)
				ans=ans*x;
			x=x*x;
			y>>=1;
		}
		return ans;
	}
}M;
LL Pow(LL x,LL y){
	LL ans=1;
	while (y){
		if (y&1LL)
			ans=ans*x%mod;
		x=x*x%mod;
		y>>=1;
	}
	return ans;
}
int main(){
	LL ans=1;
	n=read(),k=read(),l=read(),mod=read();
	M=Mat(2);
	M=M^(n+1);
	LL v=M.a[0][0],v2=(Pow(2,n)-v+mod)%mod;
	if (l<64&&(k>>l)){
		puts("0");
		return 0;
	}
	while (l--){
		if ((k>>l)&1LL)
			ans=ans*v2%mod;
		else
			ans=ans*v%mod;
	}
	printf("%I64d",ans%mod);
	return 0;
}