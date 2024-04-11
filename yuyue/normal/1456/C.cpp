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
priority_queue<LL> q;
const int M=5e5+10;
int n,k,a[M];
int main(){
	n=read(); k=read();
	F(i,1,n){
		a[i]=read();
	}
	F(i,1,k+1) q.push(0);
	sort(a+1,a+n+1,greater<int>());
	LL sum=0;
	F(i,1,n){
		LL x=q.top(); q.pop();
		sum+=x;
		x+=a[i];
		q.push(x);
	}
	cout<<sum<<"\n";
	return 0;
}