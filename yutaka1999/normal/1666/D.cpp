#include <bits/stdc++.h>
using namespace std;

using ll=long long;

#define rng(i,a,b) for(int i=int(a);i<int(b);i++)
#define rep(i,b) rng(i,0,b)
#define gnr(i,a,b) for(int i=int(b)-1;i>=int(a);i--)
#define per(i,b) gnr(i,0,b)
#define bg begin()
#define ed end()
#define all(x) x.bg,x.ed
#define eb emplace_back
#define si(x) int(x.size())
#define a first
#define b second

template<class t>using vc=vector<t>;

using pi=pair<int,int>;
using vi=vc<int>;

void NO(){
	cout<<"NO"<<endl;
}

void YES(){
	cout<<"YES"<<endl;
}

void slv(){
	string s,t;cin>>s>>t;
	int cnt[26]{};
	for(auto c:t)cnt[c-'A']++;
	string x;
	per(i,si(s)){
		int j=s[i]-'A';
		if(cnt[j]){
			cnt[j]--;
			x+=s[i];
		}
	}
	rep(i,26)if(cnt[i]){
		return NO();
	}
	reverse(all(x));
	if(x!=t)return NO();
	YES();
}

signed main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	cout<<fixed<<setprecision(20);
	
	int t;cin>>t;
	rep(_,t)slv();
}