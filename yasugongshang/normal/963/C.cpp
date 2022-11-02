#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define sqr(x) ((x)*(x))
#define mp make_pair
#define uint unsigned
#define int long long
inline char gc(){
    static char buf[100000],*p1=buf,*p2=buf;
    return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
}
#define gc getchar
inline int read(){
	int x = 0; char ch = gc(); bool positive = 1;
	for (; !isdigit(ch); ch = gc())	if (ch == '-')	positive = 0;
	for (; isdigit(ch); ch = gc())	x = x * 10 + ch - '0';
	return positive ? x : -x;
}
inline void write(int a){
    if(a>=10)write(a/10);
    putchar('0'+a%10);
}
inline void writeln(int a){
    if(a<0){
    	a=-a; putchar('-');
	}
	write(a); puts("");
}
const int N=200005,mod=998244353;
int n,w[N],h[N],c[N],kind,tt;
vector<int> v[N];
map<int,int> M;
map<int,int>::iterator it;
inline void chu(int &a,int &b){
	int t=__gcd(a,b);
	a/=t; b/=t;
}
inline bool calc(ll a,ll b,ll c,ll d){
	return a*d%mod==b*c%mod;
}
inline bool cmp(int a,int b){
	return h[a]<h[b];
}
signed main(){
	n=read();
	for(int i=1;i<=n;i++){
		w[i]=read(); h[i]=read(); c[i]=read(); tt=__gcd(c[i],tt); c[i]%=mod;
		if(!M.count(w[i]))M[w[i]]=++kind;
		v[M[w[i]]].push_back(i);
	}
	if(M.size()==1){
		int ans=0;
		for(int i=1;i<=n;i++)tt=__gcd(tt,c[i]);
		for(ll i=1;i*i<=tt;i++)if(tt%i==0){
			ans+=i*i!=tt?2:1;
		}
		cout<<ans<<endl; return 0;
	}
	int t=M.begin()->second,ans=0; it=M.begin();
	sort(v[t].begin(),v[t].end(),cmp);
	for(it++;it!=M.end();it++){
		int zs=it->second;
		if(v[zs].size()!=v[t].size()){
			puts("0"); return 0;
		}
		sort(v[zs].begin(),v[zs].end(),cmp);
		for(unsigned j=0;j<v[zs].size();j++)if(h[v[zs][j]]!=h[v[t][j]]){
			puts("0"); return 0;
		}//else cout<<h[v[zs][j]]<<" "<<h[v[t][j]]<<" "<<zs<<" "<<t<<endl;
		for(unsigned j=1;j<v[zs].size();j++){
			if(!calc(c[v[zs][j]],c[v[t][j]],c[v[zs][0]],c[v[t][0]])){
				puts("0"); return 0;
			}
		}
	}
	int tot=0;
	for(ll i=1;i*i<=tt;i++)if(tt%i==0){
		tot+=i*i!=tt?2:1;
	}
	cout<<tot<<endl;
}