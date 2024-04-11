#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define mp make_pair
#define PI pair<int,int>
#define poly vector<int>
#define For(i,l,r) for(int i=(int)(l);i<=(int)(r);i++)
#define Rep(i,r,l) for(int i=(int)(r);i>=(int)(l);i--)
#define pb push_back
#define mem(a) memset((a),0,sizeof(a))
#define fi first
#define se second
inline char gc(){
    static char buf[100000],*p1=buf,*p2=buf;
    return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
}
#define gc getchar
inline ll read(){
	ll x = 0; char ch = gc(); bool positive = 1;
	for (; !isdigit(ch); ch = gc())	if (ch == '-')	positive = 0;
	for (; isdigit(ch); ch = gc())	x = x * 10 + ch - '0';
	return positive ? x : -x;
}
inline void write(ll a){
    if(a<0){
    	a=-a; putchar('-');
	}
    if(a>=10)write(a/10);
    putchar('0'+a%10);
}
inline void writeln(ll a){write(a); puts("");}
inline void wri(ll a){write(a); putchar(' ');}
const int N=3005;
PI a[N];
vector<int> v[N];
int pre[N],nxt[N],zyk[N],sum;
ll ans;
inline void inc(int x){
	sum+=(a[nxt[x]].fi-a[x].fi)*a[zyk[x]].fi;
}
inline void dec(int x){
	sum-=(a[nxt[x]].fi-a[x].fi)*a[zyk[x]].fi;
}
int main(){
	int r=read(),c=read(),n=read(),K=read();
	For(i,1,n){a[i].fi=read(); a[i].se=read(); }
	sort(a+1,a+n+1);
	For(i,1,n)v[a[i].se].pb(i); a[n+1].fi=r+1;
	For(i,1,c){
		int lst=0;
		For(j,1,n)if(a[j].se>=i){
			pre[j]=lst; nxt[lst]=j; lst=j; 
		}
		nxt[n+1]=nxt[lst]=n+1; pre[n+1]=lst;
		int jb=0; sum=0;
		For(j,1,K){jb=nxt[jb]; zyk[jb]=0;}if(!jb)continue;
		for(int dq=nxt[0];jb<=n;jb=nxt[jb],dq=nxt[dq]){
			zyk[jb]=dq; inc(jb); 
		}
		Rep(j,c,i){
			ans+=sum;
			for(auto k:v[j]){
				dec(pre[k]);
				nxt[pre[k]]=nxt[k];
				inc(pre[k]);
				dec(k);//if(i==4)cout<<jb<<" "<<k<<" "<<sum<<" "<<zyk[4]<<endl;
				for(int o=1,jj=nxt[k];o<K&&jj<=n;o++,jj=nxt[jj]){
					dec(jj);
					zyk[jj]=pre[zyk[jj]];
					inc(jj);
				}
				pre[nxt[k]]=pre[k];
			}
		}
	}
	cout<<ans<<endl;
}