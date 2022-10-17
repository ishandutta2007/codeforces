#include<bits/stdc++.h>
#define LL long long
#define pb push_back
#define SZ(x) ((int)x.size()-1)
#define ms(a,b) memset(a,b,sizeof a)
#define F(i,a,b) for (int i=(a);i<=(b);++i)
#define DF(i,a,b) for (int i=(a);i>=(b);--i)
using namespace std;
inline int read(){
	char ch=getchar(); int w=1,c=0;
	for(;!isdigit(ch);ch=getchar()) if (ch=='-') w=-1;
	for(;isdigit(ch);ch=getchar()) c=(c<<1)+(c<<3)+(ch^48);
	return w*c;
}
const int M=3e5+10; 
int a[M],ans[M],ct;
int t[M],n;
int mex(){
	F(i,0,1111) t[i]=0;
	F(i,1,n) t[a[i]]++;
	F(i,0,1111) if (!t[i]) return i;
}
void swp(int x,int y){
//	int tmp=mex();
	ans[++ct]=y; ans[++ct]=x; ans[++ct]=y;
}
int main(){
	int T=read();
	while (T--){
		n=read(); ct=0; 
		F(i,1,n) a[i]=read();
		int i=1;
		while(1){
			if (i==n+1) break; 
			if (a[i]==i-1) {
				i++; 
				continue;
			}
			int tmp=mex();
			if (tmp==n){
				int pos=0;
				F(j,i+1,n) if (a[j]!=j-1) pos=j;
				ans[++ct]=pos; a[pos]=tmp;
			}
			else a[tmp+1]=tmp,ans[++ct]=tmp+1;
		}
		cout<<ct<<"\n"; 
		F(i,1,ct) cout<<ans[i]<<" "; cout<<"\n";
//		F(i,1,n) assert(a[i]==i-1);
	}
	return 0;
}