#include<bits/stdc++.h>
using namespace std;
inline char read() {
    static const int IN_LEN = 1000000;
    static char buf[IN_LEN], *s, *t;
    if (s == t) {
        t = (s = buf) + fread(buf, 1, IN_LEN, stdin);
        if (s == t) return -1;
    }
    return *s++;
}
template<class T>
inline void read(T &x) {
    static bool iosig;
    static char c;
    for (iosig = false, c = read(); !isdigit(c); c = read()) {
        if (c == '-') iosig = true;
        if (c == -1) return;
    }
    for (x = 0; isdigit(c); c = read())
        x = (x + (x << 2) << 1) + (c ^ '0');
    if (iosig) x = -x;
}
const int N=4200005;
int n,m,i,j,k,l,all,x,ans;
bool b[N],c[N],bb[N];
int dfn[N],low[N],xb,st[N],w;
void dfs(int x){
	dfn[x]=low[x]=++xb;st[++w]=x;
	if(c[x] || c[all^x]){
		if(!dfn[all^x])dfs(all^x);
		if(!b[all^x] && low[all^x]<low[x])low[x]=low[all^x];
	}
	if(bb[x]){
		for(int i=0;i<m;++i)if(x>>i&1){
			int z=x^(1<<i);
			if(!dfn[z])dfs(z);
			if(!b[z] && low[z]<low[x])low[x]=low[z];
		}
	}
	if(dfn[x]==low[x]){
		bool fl=c[x];
		for(;st[w]!=x;--w)fl|=c[st[w]],b[st[w]]=1;--w;b[x]=1;
		ans+=fl;
	}
}
int main(){
	read(m);read(n);all=(1<<m)-1;
	for(i=1;i<=n;++i){
		read(x);
		bb[x^all]=c[x]=1;
	}
	for(i=2;i<=1<<m;i<<=1)
		for(j=0,k=i>>1;j<1<<m;j+=i)
			for(l=0;l<k;++l)bb[j+l]|=bb[j+l+k];
	for(i=0;i<=all;++i)if(!dfn[i])dfs(i);
	printf("%d\n",ans);
	return 0;
}