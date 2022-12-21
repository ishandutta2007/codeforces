#include<bits/stdc++.h>
#define re register
#define ll long long
#define LL inline ll
#define I inline int
#define V inline void
#define FOR(i,a,b) for(re int i=(a),i##i=(b) ; i<=i##i ; ++i)
#define ROF(i,a,b) for(re int i=(a),i##i=(b) ; i>=i##i ; --i)
#define gc getchar()
//#define gc (fs==ft&&(ft=(fs=buf)+fread(buf,1,1<<18,stdin),fs==ft))?0:*fs++
using namespace std;
const int N=5010,mo=1e9+7;
char *fs,*ft,buf[1<<18];
LL read(){
    ll p=0; char ch=gc; bool w=0;
    while(!isdigit(ch)) w=ch=='-'?1:0,ch=gc;
    while(isdigit(ch)) p=p*10+ch-'0',ch=gc;
    return w?-p:p;
}
int T,n;
char ch[N];
V cz(int &x,int& y,char s){
	if(s=='L') x-=1;
	if(s=='R') x+=1;
	if(s=='U') y+=1;
	if(s=='D') y-=1;
}
I ck(int x,int y){
	int s=0,t=0,ss=s,tt=t;
	FOR(i,1,n) {
		ss=s,tt=t;
		cz(s,t,ch[i]);
		if(s==x&&t==y) s=ss,t=tt;
	}
	if(s==0&&t==0) return 1;
	return 0;
}
V sol(){
	int x=0,y=0;
	FOR(i,1,n){
		cz(x,y,ch[i]);
		if(ck(x,y)) return printf("%d %d\n",x,y),void();
	} 
	printf("%d %d\n",0,0);
	return ;
}
int main(){
	T=read();
	while(T--){
		scanf("%s",ch+1),n=strlen(ch+1);
		sol();
	}
	return 0;
}