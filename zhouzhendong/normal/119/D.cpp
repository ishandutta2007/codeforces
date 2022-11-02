#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ULL;
const int N=1000005*2;
char a[N],b[N];
int n,Next[N],len[N];
ULL Ha[N],Hb[N],Fac[N],T=233;
ULL Get_Hash(ULL *Ha,int L,int R){
	if (L>R)
		L=n*2-L+1,R=n*2-R+1;
	return Ha[R]-Ha[L-1]*Fac[R-L+1];
}
void KMP(char *a,char *b,int n){
	for (int i=2,k=0;i<=n;Next[i]=k+=(a[k+1]==a[i]),i++)
		while (k>0&&a[k+1]!=a[i])
			k=Next[k];
	for (int i=1,k=0;i<=n;len[i]=k+=(a[k+1]==b[i]),i++)
		while (k>0&&a[k+1]!=b[i])
			k=Next[k];
}
int Get(int j){
	int L=1,R=j-1,mid,k1=0;
	while (L<=R){
		mid=(L+R)>>1;
		if (Get_Hash(Hb,1,mid)==Get_Hash(Ha,j-1,j-mid))
			L=mid+1,k1=mid;
		else
			R=mid-1;
	}
	return k1+len[j-1]<j-1?-1:len[j-1];
}
int main(){
	gets(a+1),gets(b+1);
	n=strlen(a+1);
	if (strlen(b+1)!=n)
		return puts("-1 -1"),0;
	reverse(a+1,a+n+1);
	for (int i=n+1;i<=n*2;i++)
		a[i]=a[n*2-i+1],b[i]=b[n*2-i+1];
	KMP(a,b,n);
	for (int i=Fac[0]=1;i<=n*2;i++){
		Fac[i]=Fac[i-1]*T;
		Ha[i]=Ha[i-1]*T+a[i];
		Hb[i]=Hb[i-1]*T+b[i];
	}
	int ansi=10000000,ansj=10000000,d=-1;
	for (d=n;d>1;d--)
		if (a[d]!=b[d])
			break;
	for (int i=-1,j=d+1;j<=n&&!~i;j++)
		if (~(i=Get(j)))
			ansi=i,ansj=j;
	if (ansj==10000000)
		ansi=ansj=-1;
	else
		ansi=n-ansi,ansj=n-ansj;
	printf("%d %d\n",ansj,ansi);
	return 0;
}