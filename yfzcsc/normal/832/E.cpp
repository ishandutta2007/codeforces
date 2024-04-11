#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;
int inv[5]={1,1,3,2,4},n,m,q;
int a[510][510],tp,b[510];
char s[510];
int qpow(int a,int b){
	int ans=1,tmp=a;
	for(;b;b>>=1,tmp=1ll*tmp*tmp%mod)
		if(b&1)ans=1ll*ans*tmp%mod;
	return ans;
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i){
		scanf("%s",s+1);
		for(int j=1;j<=m;++j)
			b[j]=s[j]-'a';
		for(int j=1;j<=tp;++j){
			for(int k=1;k<=m;++k)if(a[j][k]){
				int t=b[k]*inv[a[j][k]]%5;
				for(int l=k;l<=m;++l)
					b[l]=(b[l]-t*a[j][l]%5+5)%5;
				break;
			}
		}
		for(int k=1;k<=m;++k)if(b[k]){
			tp++;
			for(int l=1;l<=m;++l)
				a[tp][l]=b[l];
			break;
		}
	}
	scanf("%d",&q);
	int res=qpow(5,n-tp);
	for(int i=1;i<=q;++i){
		scanf("%s",s+1);
		for(int j=1;j<=m;++j)
			b[j]=s[j]-'a';
		for(int j=1;j<=tp;++j){
			for(int k=1;k<=m;++k)if(a[j][k]){
				int t=b[k]*inv[a[j][k]]%5;
				for(int l=k;l<=m;++l)
					b[l]=(b[l]-t*a[j][l]%5+5)%5;
				break;
			}
		}
		bool flag=false;
		for(int j=1;j<=m;++j)flag|=b[j]>0;//,printf("<%d>",b[j]);puts("");
		printf("%d\n",flag?0:res);
		nxt:;
	}
}