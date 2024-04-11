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
const int M=5e5+10,lim=1e5;
int d[M],a[M],n;
#define lowbit(x) (x&-x)
void add(int x,int o){
	for (;x<=lim;x+=lowbit(x)) d[x]+=o;
} 
int qry(int x){
	int ret=0;
	for (;x;x-=lowbit(x)) ret+=d[x];
	return ret;
}
LL r[M];
int la[M],t[M],oe[M];
void work(){
	n=read();
	F(i,1,n) a[i]=read(),add(a[i],1),r[i]=i-qry(a[i]);
	F(i,1,n) add(a[i],-1);
	DF(i,n,1){
		add(a[i],1);	
		r[i]+=qry(a[i]-1);
	}
	bool fl=0;
	F(i,1,n){
//		cerr<<r[a[i]]<<"\n";
		if (r[i]&1){
			if (t[a[i]]&1) oe[a[i]]++;
			else oe[a[i]]--;
		}
		t[a[i]]++;
	}
	F(i,1,n) fl|=(oe[a[i]]!=0);
	cout<<(fl ? "NO" : "YES")<<"\n";
	F(i,1,n) add(a[i],-1),r[i]=t[a[i]]=la[a[i]]=oe[a[i]]=0;
}
int main(){
	int T=read();
	while (T--) work();
	return 0;
}
/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
	* DON'T GET STUCK ON ONE APPROACH
1
6
2 1 2 1 2 1
*/