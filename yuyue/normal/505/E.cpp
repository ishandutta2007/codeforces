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
#define mp make_pair
#define pii pair<LL,int> 
int n,m,k,p,h[M],a[M];
int cao[M];
bool check(LL t){
//	cout<<t<<"     --------\n";
	priority_queue<pii,vector<pii> ,greater<pii> > q; ms(cao,0);
	F(i,1,n){
		if (t-1ll*m*a[i]<h[i]){
			q.push(mp(1.0*t/a[i],i));
//			cout<<i<<"   u\n";
		}
	}
	F(i,1,m){
		F(j,1,k){
			if (q.empty()) continue;
//			cout<<q.top().first<<" "<<q.top().second<<"  gg\n";
			int x=q.top().second; q.pop(); 
			if (t+1ll*cao[x]*p-1ll*i*a[x]<0)  return 0;
			cao[x]++;
			if (t+1ll*cao[x]*p-1ll*m*a[x]<h[x]){
				q.push(mp(1.0*(t+1ll*cao[x]*p)/a[x],x));
			}
		}
	}
	F(i,1,n) if (t+1ll*cao[i]*p-1ll*m*a[i]<h[i]) return 0;  
	return 1;
}

int main(){
	n=read(); m=read(); k=read(); p=read();
	LL l=0,r=0,ans=0; 
	F(i,1,n) h[i]=read(),a[i]=read(),r=max(r,1ll*m*a[i]+h[i]);
	r+=10;
//	check(2);
	while (l<=r){
		LL mid=(l+r>>1);
		if (check(mid)) r=mid-1,ans=mid;
		else l=mid+1; 
	}
	cout<<ans<<"\n";
	return 0;
}