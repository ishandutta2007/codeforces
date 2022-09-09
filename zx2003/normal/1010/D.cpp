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
	for(;!isdigit(*ih);++ih)if(*ih=='-')f=-1;
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
const int N=1000005;
int n,i,ch[N][2],op[N];
bool v[N],tr[N][2];
char c[10],ans[N+1];
void getv(int x){
	if(op[x]==5)return;
	if(ch[x][0])getv(ch[x][0]);
	if(ch[x][1])getv(ch[x][1]);
	if(op[x]==1)v[x]=v[ch[x][0]] && v[ch[x][1]];
	if(op[x]==2)v[x]=v[ch[x][0]] || v[ch[x][1]];
	if(op[x]==3)v[x]=v[ch[x][0]] ^ v[ch[x][1]];
	if(op[x]==4)v[x]=!v[ch[x][0]];
}
void gettr(int x){
	if(op[x]==5){
		ans[x]=tr[x][!v[x]]+48;
		return;
	}
	int l=ch[x][0],r=ch[x][1];
	if(op[x]==1){
		tr[l][0]=tr[x][0 && v[r]];
		tr[l][1]=tr[x][1 && v[r]];
		tr[r][0]=tr[x][0 && v[l]];
		tr[r][1]=tr[x][1 && v[l]];
	}
	if(op[x]==2){
		tr[l][0]=tr[x][0 || v[r]];
		tr[l][1]=tr[x][1 || v[r]];
		tr[r][0]=tr[x][0 || v[l]];
		tr[r][1]=tr[x][1 || v[l]];
	}
	if(op[x]==3){
		tr[l][0]=tr[x][0 ^ v[r]];
		tr[l][1]=tr[x][1 ^ v[r]];
		tr[r][0]=tr[x][0 ^ v[l]];
		tr[r][1]=tr[x][1 ^ v[l]];
	}
	if(op[x]==4){
		tr[l][0]=tr[x][1];
		tr[l][1]=tr[x][0];
	}
	if(l)gettr(l);if(r)gettr(r);
}
int main(){
	fread(ibuf,1,1<<25,stdin);
	read(n);
	for(i=1;i<=n;++i){
		readstr(c);
		if(*c=='A'){
			op[i]=1;
			read(ch[i][0]);read(ch[i][1]);
		}
		if(*c=='O'){
			op[i]=2;
			read(ch[i][0]);read(ch[i][1]);
		}
		if(*c=='X'){
			op[i]=3;
			read(ch[i][0]);read(ch[i][1]);
		}
		if(*c=='N'){
			op[i]=4;
			read(ch[i][0]);
		}
		if(*c=='I')op[i]=5,read(v[i]);
	}
	tr[1][0]=0;tr[1][1]=1;
	getv(1);
	gettr(1);
	//puts(ans+1)
	for(i=1;i<=n;++i)if(op[i]==5)putchar(ans[i]);
	puts("");
	return 0;
}