#include<bits/stdc++.h>
const int N=1000005,mo=1000000007;
int n,i,j,x,f[N],g[N],ch[N][26],fail[N],sf[N],lst,len[N],xb,dif[N],anc[N];
char c[N],cc[N];
int gf(int x){while(c[i-len[x]-1]!=c[i])x=fail[x];return x;}
int main(){
	n=fread(cc+1,1,N,stdin);while(!isalpha(cc[n]))--n;
	for(i=1;i<=n;++i)c[i]=i&1?cc[(i+1)>>1]:cc[n-(i>>1)+1];
	len[1]=-1;fail[0]=xb=1;f[0]=1;
	for(i=1;i<=n;++i){
		x=gf(lst);
		if(!ch[x][c[i]-'a']){
			j=gf(fail[x]);fail[++xb]=ch[j][c[i]-'a'];
			len[ch[x][c[i]-'a']=xb]=len[x]+2;
			dif[xb]=len[xb]-len[fail[xb]];
			anc[xb]=dif[xb]==dif[fail[xb]]?anc[fail[xb]]:fail[xb];
		}lst=ch[x][c[i]-'a'];
		for(x=lst;x;x=anc[x]){
			g[x]=f[i-len[anc[x]]-dif[x]];
			if(anc[x]!=fail[x])g[x]=(g[x]+g[fail[x]])%mo;
			if(!(i&1))f[i]=(f[i]+g[x])%mo;
		}
	}
	return printf("%d\n",f[n]),0;
}