#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
char ibuf[1<<25],*ih=ibuf,obuf[1<<25],*oh=obuf;
template<typename T>inline void read(T&x){
	int f=1;
	for(;!isdigit(*ih);++ih)if(*ih=='-')f=-1;
	for(x=0;isdigit(*ih);x=x*10+*ih++-48);x*=f;
}
template<typename T>inline void write(T x){
	if(x==0)return void(*oh++='0');
	static int buf[30],xb;
	for(xb=0;x;x/=10)buf[++xb]=x%10;
	for(;xb;)*oh++=buf[xb--]|48;
}
const int N=400005;
struct node{
	int l,r,mx,sz;ll s;
}t[N*20];
int xb,Q,i,rt[N],o,dep[N];
ll la,p,q;
void ins(int x,int&y,int l,int r,int v){
	t[y=++xb]=t[x];if(l==r){t[y].sz=1;t[y].s=t[y].mx=v;return;}
	int m=(l+r)>>1;
	if(t[t[y].l].mx>=v && t[t[y].l].sz==m-l+1)ins(t[x].r,t[y].r,m+1,r,v);
		else ins(t[x].l,t[y].l,l,m,v),t[y].r=0;
	t[y].s=t[t[y].l].s+t[t[y].r].s;t[y].sz=t[t[y].l].sz+t[t[y].r].sz;
	t[y].mx=t[y].r?t[t[y].r].mx:t[t[y].l].mx;
}
ll query(int x,int l,int r,ll v){
	if(l==r)
		return t[x].sz && t[x].s<=v;
	int m=(l+r)>>1;
	if(t[t[x].r].s>=v && t[t[x].r].s)return query(t[x].r,m+1,r,v);
		else return query(t[x].l,l,m,v-t[t[x].r].s)+t[t[x].r].sz;
}
int main(){
	fread(ibuf,1,1<<25,stdin);
	read(Q);ins(0,rt[1],i=1,Q,0);dep[1]=1;
	for(int j=0;j<Q;++j){
		read(o),read(p),read(q);p^=la,q^=la;
		if(o==1)ins(rt[p],rt[++i],1,Q,q),dep[i]=t[rt[i]].sz;
			else write(la=query(rt[p],1,Q,q)),*oh++='\n';
	}
	return fwrite(obuf,1,oh-obuf,stdout),0;
}