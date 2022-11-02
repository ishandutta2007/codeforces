#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=200005;
int n,m;
char s[N];
LL mod1=998244353,t1=233333333;
LL mod2=1e9+7,t2=19260817;
LL pw1[N],pw2[N],iv1[N],iv2[N];
LL Ha1[26][N],Ha2[26][N];
LL Pow(LL x,LL y,LL mod){
	if (y==0)
		return 1LL;
	LL xx=Pow(x,y/2,mod);
	xx=xx*xx%mod;
	if (y&1LL)
		xx=xx*x%mod;
	return xx;
}
LL geth1(int c,int L,int R){
	return (Ha1[c][R]-Ha1[c][L-1]*pw1[R-L+1]%mod1+mod1)%mod1;
}
LL geth2(int c,int L,int R){
	return (Ha2[c][R]-Ha2[c][L-1]*pw2[R-L+1]%mod2+mod2)%mod2;
}
struct hs{
	LL h1,h2;
}hhx[26],hhy[26];
bool cmp(hs a,hs b){
	if (a.h1==b.h1)
		return a.h2<b.h2;
	return a.h1<b.h1;
}
bool check(){
	for (int i=0;i<26;i++)
		if (hhx[i].h1!=hhy[i].h1||hhx[i].h2!=hhy[i].h2)
			return 0;
	return 1;
}
int main(){
	scanf("%d%d",&n,&m);
	scanf("%s",s+1);
	pw1[0]=pw2[0]=iv1[0]=iv2[0]=1;
	pw1[1]=t1;
	pw2[1]=t2;
	iv1[1]=Pow(t1,mod1-2,mod1);
	iv2[1]=Pow(t2,mod2-2,mod2);
	for (int i=2;i<=n;i++){
		pw1[i]=pw1[i-1]*pw1[1]%mod1;
		pw2[i]=pw2[i-1]*pw2[1]%mod2;
		iv1[i]=iv1[i-1]*iv1[1]%mod1;
		iv2[i]=iv2[i-1]*iv2[1]%mod2;
	}
	for (int c=0;c<26;c++)
		for (int i=1;i<=n;i++){
			Ha1[c][i]=(Ha1[c][i-1]*t1+((bool)(s[i]-'a'==c)))%mod1;
			Ha2[c][i]=(Ha2[c][i-1]*t2+((bool)(s[i]-'a'==c)))%mod2;
		}
	while (m--){
		int x,y,len;
		scanf("%d%d%d",&x,&y,&len);
		for (int i=0;i<26;i++){
			hhx[i].h1=geth1(i,x,x+len-1);
			hhx[i].h2=geth2(i,x,x+len-1);
			hhy[i].h1=geth1(i,y,y+len-1);
			hhy[i].h2=geth2(i,y,y+len-1);
		}
		sort(hhx,hhx+26,cmp);
		sort(hhy,hhy+26,cmp);
		puts(check()?"YES":"NO");
	}
	return 0;
}