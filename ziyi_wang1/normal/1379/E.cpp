#include<bits/stdc++.h>
using namespace std;
#define re register int
#define F(x,y,z) for(re x=y;x<=z;x++)
#define FOR(x,y,z) for(re x=y;x>=z;x--)
typedef long long ll;
#define I inline void
#define IN inline int
#define C(x,y) memset(x,y,sizeof(x))
#define STS system("pause")
template<class D>I read(D &res){
	res=0;register D g=1;register char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-')g=-1;
		ch=getchar();
	}
	while(isdigit(ch)){
		res=(res<<3)+(res<<1)+(ch^48);
		ch=getchar();
	}
	res*=g;
}
int fa[101000],cnt;
IN getmx(int x){return max(0,(x-3)>>1);}
inline bool ck(int n,int k){
	if(n==9&&k==2)return false;
	if(!(n&1))return false;
	if(!k)return __builtin_popcount(n+1)==1;
	if(k>1)return getmx(n)>=k;
	return __builtin_popcount(n+1)!=1;
}
inline bool chk(int x,int y,int k,int &ans){
	if(k<0)return false;
	for(re sz=min(k,min(10,getmx(x)));sz>=0;sz--){
		if(!ck(x,sz)||!ck(y,k-sz))continue;
		return ans=sz,true;
	}
	for(re sz=min(k,min(10,getmx(y)));sz>=0;sz--){
		if(!ck(x,k-sz)||!ck(y,sz))continue;
		return ans=k-sz,true;
	}
	return false;
}
I D_1(int n,int k,int fat=0){
	re x=++cnt,ls,lk,sn;fa[x]=fat;
	if(n==1)return;
	ls=1;sn=0;
	while(ls<n){
		if(ls>2*(n-1-ls)||ls*2<n-1-ls)sn=1;else sn=0;
		if(chk(ls,n-1-ls,k-sn,lk))return D_1(ls,lk,x),D_1(n-1-ls,k-sn-lk,x),void();
		ls+=2;
	}
}
int main(){
	re n,k;
	read(n);read(k);
	if(!ck(n,k))return cout<<"NO",0;
	D_1(n,k);
	cout<<"YES"<<endl;re ct=0;
	F(i,1,n)cout<<fa[i]<<" ";
//	F(i,1,n)if(!fa[i])ct++;cout<<ct;
	return 0;
}