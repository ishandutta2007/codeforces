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
const int M=2e5+10;
int a[M],s[M],X,c[M],n,m;
#define pii pair<int,int>
void work(){
	n=read(); m=read(); X=read();
	F(i,1,n) a[i]=read();
	priority_queue<pii,vector<pii>,greater<pii> > q;
	F(i,1,m) q.push(make_pair(a[i],i)),c[i]=i,s[i]=a[i];
	F(i,m+1,n){
		int id=q.top().second; q.pop();
		s[id]+=a[i];
		c[i]=id;
		q.push(make_pair(s[id],id));
	}
	puts("YES");
	F(i,1,n) cout<<c[i]<<" "; cout<<"\n";
	F(i,1,n) c[i]=s[i]=a[i]=0; 
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
*/