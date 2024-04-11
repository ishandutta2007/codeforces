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
struct P{
	ll a,b;
	friend bool operator < (P x,P y){
		return x.b>y.b;
	}
}p[101000];
ll ans,sum,w[101000],now,S,cnt,s[101000];
int n,m,T;
int main(){
	read(T);
	while(T--){
		read(n);read(m);ans=0;S=0;
		F(i,1,m)read(p[i].a),read(p[i].b);
		sort(p+1,p+1+m);F(i,1,m)w[i]=p[i].a;
		sort(w+1,w+1+m);cnt=0;now=m;F(i,1,m)s[i]=s[i-1]+w[i];
		F(i,1,m){
			while(now&&w[now]>=p[i].b)cnt++,S+=w[now],now--;
			if(cnt<=n){
				sum=S+(ll)(n-cnt)*p[i].b;if(p[i].a<p[i].b)sum+=(p[i].a-p[i].b);ans=max(ans,sum);
			}
			else ans=max(ans,s[m]-s[m-n]);
		}
		cout<<ans<<endl;
	}
	return 0;
}