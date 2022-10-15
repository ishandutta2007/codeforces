#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read(){
	int f=1,r=0;char c=getchar();
	while(!isdigit(c))f^=c=='-',c=getchar();
	while(isdigit(c))r=(r<<1)+(r<<3)+(c^48),c=getchar();
	return f?r:-r;
}
#define fi first
#define se second
const int N=307;
int n,l[N],c[N];
map<int,int>f,t;
inline void upd(int i,int j){
	if(!t.count(i))t[i]=j;
	else t[i]=min(t[i],j);
}
int main(){
	n=read();int G=0;
	for(int i=1;i<=n;i++)l[i]=read(),G=__gcd(G,l[i]);
	if(G>1)puts("-1"),exit(0);
	for(int i=1;i<=n;i++)c[i]=read();
	f[0]=1;
	for(int j=1;j<=n;j++){
		t.clear();
		for(auto i:f){
			upd(i.fi,i.se);
			upd(__gcd(i.fi,l[j]),i.se+c[j]);
		}
		f=t;
	}
	printf("%d\n",f[1]-1);
	return 0;
}