#include<bits/stdc++.h>
#define mo 1000000007
#define N (1<<20)+4
#define inv 500000004 
using namespace std;
int n,l,ans;
int cnt[N],a[N];
char s[N];
void fwt(){
	for (int d=1;d<l;d<<=1)
		for (int i=0;i<l;i+=d<<1)
			for (int j=i;j<i+d;j++){
				int x=a[j],y=a[j+d];
				a[j]=(x+y)%mo;
				a[j+d]=(x+mo-y)%mo;
			}
}
void ufwt(){
	for (int d=1;d<l;d<<=1)
		for (int i=0;i<l;i+=d<<1)
			for (int j=i;j<i+d;j++){
				int x=a[j],y=a[j+d];
				a[j]=1ll*(x+y)*inv%mo;
				a[j+d]=1ll*(x+mo-y)*inv%mo;
			}
}
int main(){
	scanf("%d%s",&n,s);
	l=1<<n;
	for (int i=0;i<l;i++)
		a[i]=s[i]-'0';
	fwt();
	for (int i=0;i<l;i++)
		a[i]=1ll*a[i]*a[i]%mo;
	ufwt();
	for (int i=0;i<l;i++){
		cnt[i]=cnt[i/2]+(i&1);
		ans=(ans+((1ll*a[i])<<(n-cnt[i])))%mo;
	}
	printf("%I64d",3ll*ans%mo);
}