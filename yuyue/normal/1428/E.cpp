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
const int M=1e5+10;
int n,k,a[M],c[M];
LL calc(int x,int y){
	int len=x/y;
	return 1ll*len*len*(y-x%y)+1ll*(len+1)*(len+1)*(x%y);
}
#define pii pair<LL,int> 
#define mp make_pair
priority_queue<pii> q;
int main(){
	n=read(); k=read();
	LL ans=0;
	F(i,1,n){
		a[i]=read();
		ans+=1ll*a[i]*a[i];
		c[i]=1;
		q.push(mp(calc(a[i],1)-calc(a[i],2),i));
	}
	int tim=k-n;
	while (tim--){
		pii x=q.top(); q.pop();
		int id=x.second; c[id]++;
		ans-=x.first;
		q.push(mp(calc(a[id],c[id])-calc(a[id],c[id]+1),id));
	}
	cout<<ans<<"\n";
	return 0;
}