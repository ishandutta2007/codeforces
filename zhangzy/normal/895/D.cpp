#include<bits/stdc++.h>
#define mod 1000000007
#define ll long long
using namespace std;

int cnt[26],l,t[26],now;
char a[2001000],b[2001000];
ll jc[1001000],inv[1001000];

ll K(ll x,int y=mod-2){
	ll t=1; for (;y;y>>=1,x=x*x%mod) if (y&1) t=t*x%mod; return t;
}
ll C(int x,int y){
	return jc[x] *inv[y]%mod *inv[x-y]%mod;
}
ll KC(int x,int y){
	return inv[x] *jc[y]%mod *jc[x-y]%mod;
}

int doit(char s[]){
	ll res=0,an;
	memcpy(t,cnt,sizeof t);
	register int i,j;
	for (i=1;i<=l;++i){
		an=1,now=0;
		for (j=0;j<26;++j) an=an*C(now+=t[j],t[j])%mod;
		for (j=0;j<s[i]-'a';++j) if (t[j]){
			res=(res+an *KC(now,t[j])%mod *C(now-1,t[j]-1))%mod;
		}
		if (t[s[i]-'a']--<=0) break;
	}
	return res;
}

int main(){
	scanf("%s%s",a+1,b+1); l=strlen(a+1);
	jc[0]=1; for (int i=1;i<=l;i++) jc[i]=jc[i-1]*i%mod;
	inv[l]=K(jc[l]); for (int i=l;i>0;i--) inv[i-1]=inv[i]*i%mod;
	for (int i=1;i<=l;i++) cnt[a[i]-'a']++;
	cout<<(doit(b)-doit(a)-1+mod)%mod;
}