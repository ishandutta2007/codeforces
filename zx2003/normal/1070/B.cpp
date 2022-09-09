#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned int ui;
inline int min(const int&a,const int&b){return a<b?a:b;}
inline int max(const int&a,const int&b){return a>b?a:b;}
inline void upi(int&a,const int&b){a>b?a=b:0;}
inline void upa(int&a,const int&b){a<b?a=b:0;}
char ibuf[1<<25],*ih=ibuf,obuf[1<<25],*oh=obuf;
template<typename T>inline void read(T&x){
	int f=1;
	for(;!isdigit(*ih);++ih);
	for(x=0;isdigit(*ih);x=x*10+*ih++-48);x*=f;
}
inline void readstr(char*c){
	for(;isspace(*ih);++ih);
	for(;!isspace(*ih);*c++=*ih++);*c=0;
}
template<typename T>inline void write(T x){
	if(x<0)*oh++='-',x=-x;
	if(x==0)return void(*oh++='0');
	static int buf[30],xb;
	for(xb=0;x;x/=10)buf[++xb]=x%10;
	for(;xb;)*oh++=buf[xb--]|48;
}
template<typename T,int L>struct MP{//memory pool
	T a[L],*b[L];
	int w;
	inline MP(){for(w=0;w<L;++w)b[w]=a+w;}
	inline T*New(){return b[--w];}
	inline void Del(T*x){b[w++]=x;}
};
inline ui R(){
    static ui seed=time(0);
    return seed^=seed>>5,seed^=seed<<17,seed^=seed>>13;
}
int n,i,a,b,c,d,x;
unsigned int u;
struct node{
	int ch[2],s[2];
}t[7000000];int rt,xb;
struct atom{
	int a,b,c,d,x;
	atom(unsigned int v=0,int _x=0):a(v>>24&255),b(v>>16&255),c(v>>8&255),d(v&255),x(_x){}
};
vector<atom>ans;
void ins(int&x,unsigned int v,int z,int nd,int md){
	if(!x)x=++xb;
	if(nd==md){++t[x].s[z];return;}
	ins(t[x].ch[v>>(31-nd)&1],v,z,nd+1,md);
}
void dfs1(int u,bool fl0,bool fl1){
	if(!u)return;
	fl0|=t[u].s[0];fl1|=t[u].s[1];
	if(fl1 && t[u].s[0]){puts("-1");exit(0);}
	if(fl0 && t[u].s[1]){puts("-1");exit(0);}
	dfs1(t[u].ch[0],fl0,fl1);dfs1(t[u].ch[1],fl0,fl1);
}
void dfs(int u,unsigned int y,int z){
	if(!u)return;
	dfs(t[u].ch[0],y,z+1);
	dfs(t[u].ch[1],y|((1ll<<(31ll-z))),z+1);
	if(t[t[u].ch[0]].s[0] && t[t[u].ch[1]].s[1]){
		ans.push_back(atom(y,z+1));
		t[u].ch[0]=0;
	}
	if(t[t[u].ch[0]].s[1] && t[t[u].ch[1]].s[0]){
		ans.push_back(atom(y|((1ll<<(31ll-z))),z+1));
		t[u].ch[1]=0;
	}
	t[u].s[0]+=t[t[u].ch[0]].s[0]+t[t[u].ch[1]].s[0];
	t[u].s[1]+=t[t[u].ch[0]].s[1]+t[t[u].ch[1]].s[1];
}
int main(){
	fread(ibuf,1,1<<25,stdin);
	read(n);
	for(i=1;i<=n;++i){
		for(;*ih!='-' && *ih!='+';++ih);int z=*ih=='+';
		read(a);read(b);read(c);read(d);
		if(*ih=='/')read(x);else x=32;
		u=a;
		u=(u<<24)|(b<<16)|(c<<8)|d;
		ins(rt,u,z,0,x);
	}
	dfs1(rt,0,0);
	dfs(rt,0,0);
	if(t[rt].s[0])ans.push_back(atom(0,0));
	write(ans.size());*oh++='\n';
	for(i=0;i<ans.size();++i){
		write(ans[i].a);*oh++='.';
		write(ans[i].b);*oh++='.';
		write(ans[i].c);*oh++='.';
		write(ans[i].d);*oh++='/';
		write(ans[i].x);*oh++='\n';
	}
	return fwrite(obuf,1,oh-obuf,stdout),0;
}