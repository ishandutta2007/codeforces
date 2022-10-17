#include<bits/stdc++.h>
#define LL long long
#define SZ(x) (int)x.size()-1
#define F(i,a,b) for (int i=a;i<=b;++i)
#define DF(i,a,b) for (int i=a;i>=b;--i)
#define pb push_back
#define ms(a,b) memset(a,b,sizeof a)
using namespace std;
int read(){
    char ch=getchar(); int w=1,c=0;
    for (;!isdigit(ch);ch=getchar()) if (ch=='-') w=-1;
    for (;isdigit(ch);ch=getchar()) c=(c<<3)+(c<<1)+(ch^48);
    return w*c;
}
const int M=1e6+10;
int n,m,a[M],b[M];
 
int s[M];
bool f[M];
#define lowbit(x) (x&-x)
void add(int x){
	for (;x<=M-5;x+=lowbit(x)) s[x]++;
}
int qry(int x){
	int ans=0;
	for (;x;x-=lowbit(x)) ans+=s[x];
	return ans;
}
int main(){
	LL ans=0,ct=0;
	n=read();
	F(i,1,n) {
		int len=read();
		f[i]=1;
		int lst=0;
		F(j,1,len){
			int x=read()+1;
			if (j==1) a[i]=x,lst=x;
			else {
				if (x>lst) f[i]=0;
			}
			if (j==len) b[i]=x;
			lst=x;
		}
		if (f[i]){
//			cout<<a[i]<<" "<<b[i]<<"\n";
			add(a[i]);
//			ct+=qry(a[i]);	
//			cout<<b[i]<<" "<<a[i]<<" "<<ct<<"\n";
		}
	}
	F(i,1,n){
		if (f[i]) ct+=qry(b[i]);
	}
	cout<<1ll*n*n-ct<<"\n";
	return 0;
}