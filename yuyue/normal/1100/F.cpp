#include<bits/stdc++.h>
#define LL long long
#define pb push_back
#define SZ(x) ((int)x.size()-1)
#define ms(a,b) memset(a,b,sizeof a)
#define F(i,a,b) for (int i=(a);i<=(b);++i)
#define DF(i,a,b) for (int i=(a);i>=(b);--i)
using namespace std;
int read(){
	char ch=getchar(); int w=1,c=0;
	for(;!isdigit(ch);ch=getchar()) if (ch=='-') w=-1;
	for(;isdigit(ch);ch=getchar()) c=(c<<1)+(c<<3)+(ch^48);
	return w*c;
}
const int M=5e5+10;
int p[M][21],b[M][21];
int n,q;
void ins(int x,int r){
	int id=r;
	DF(i,20,0){
		if (!(x>>i&1)) continue;
		if (!b[r][i]){
			p[r][i]=id;
			b[r][i]=x;
			return ;
		}
		if (p[r][i]<id) swap(x,b[r][i]),swap(id,p[r][i]);
		x^=b[r][i];
	}
}
int work(int l,int r){
	int ret=0;
	DF(i,20,0){
		if (b[r][i] && p[r][i]>=l) ret=max(ret,ret^b[r][i]);
	}
	return ret;
}
int main(){
	n=read();
	F(i,1,n){
		int x=read();
		memcpy(b[i],b[i-1],sizeof(int)*21);
		memcpy(p[i],p[i-1],sizeof(int)*21);
		ins(x,i);
	}
	q=read();
	while(q--){
		int l=read(),r=read();
		cout<<work(l,r)<<"\n";
	}
	return 0;
}