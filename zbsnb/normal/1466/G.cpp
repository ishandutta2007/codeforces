#include<bits/stdc++.h>
using namespace std;

const int maxn=2000010;
struct node {
	int a,b; node(){}
	node(int a,int b):a(a),b(b){}
	friend ostream& operator <<(ostream& out,node x){ return out<<"("<<x.a<<","<<x.b<<")"; }  
} base(131,137),Hmod(1e9+7,1e9+9);
bool operator==(node x, node y) { return x.a==y.a&&x.b==y.b; }
node operator*(node x, node y) { return node(1ll*x.a*y.a%Hmod.a,1ll*x.b*y.b%Hmod.b); }
node operator+(node x, char c) { return node((x.a+c)%Hmod.a,(x.b+c)%Hmod.b); }
node operator+(node x, node y) { return node((x.a+y.a)%Hmod.a,(x.b+y.b)%Hmod.b); }
node operator-(node x, node y) { return node((x.a+Hmod.a-y.a)%Hmod.a,(x.b+Hmod.b-y.b)%Hmod.b); }
struct mybase{
	node bas[maxn];
	mybase(){ 
		bas[0]={1,1};
		for(int i=1;i<maxn;i++) bas[i]=bas[i-1]*base;
	}
} B;
struct myhash{
	vector<node> has;
    // 1
    myhash(string &s){
		has.reserve(s.size()+1);
		has.push_back({0,0});
        for(int i=0;i<int(s.size());i++) has.push_back(has[i]*base+s[i]);
    }
	node str(int l,int r){
		return has[r]-has[l-1]*B.bas[r-l+1];
	}
};

#define ll long long
const ll mod=1e9+7;
ll mypow(ll a,ll b){
    ll ret=1;
    while(b){
        if(b&1)ret=ret*a%mod;
        a=a*a%mod;b>>=1;
    }
    return ret;
}
ll dp[26][100010];
ll p2[100010];
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
    int N,q;cin>>N>>q;
	string s,t;cin>>s>>t;
	// 260W
	p2[0]=1;
	for(int i=1;i<=N;i++){
		p2[i]=p2[i-1]*500000004%mod;
		for(int j=0;j<26;j++){
			dp[j][i]=dp[j][i-1];
			if(j+'a'==t[i-1]) dp[j][i]=(dp[j][i]+mypow(2,N-i))%mod;
		}
	}
	while(q--){
		int k;cin>>k;string p;cin>>p;
		string now=s;int ind=0;
		// 200W
		while(ind<k&&p.size()>now.size()) now=now+t[ind++]+now;

		int n=now.size(),m=p.size(),ret=0;
		myhash h1(now),h2(p);
		for(int i=1;i<=n-m+1;i++){
			ret+=h2.str(1,m)==h1.str(i,m+i-1);
		}
		ll ans=ret*mypow(2,k-ind)%mod;

		// 260W*lg
		ll cnt[26]={};
		for(int i=0;i<26;i++) cnt[i]=(dp[i][k]+mod-dp[i][ind])*p2[N-k]%mod;
		
		for(int i=0;i<m;i++){
			if(i<=n&&m-i-1<=n&&h1.str(n-i+1,n)==h2.str(1,i)&&h1.str(1,m-i-1)==h2.str(i+2,m))
				ans=(ans+cnt[p[i]-'a'])%mod;
		}
		cout<<ans<<"\n";
	}
}