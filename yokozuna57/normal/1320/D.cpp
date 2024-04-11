#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> P;

#define fr first
#define sc second

template <int N = 200010,int lnN = 18>
struct String{
	string S;
	int sa[N][lnN];
	void sa_init(){
		if(true){
			vector<P> vec;
			for(int i = 0 ; i < S.size() ; i ++){
				vec.push_back(P(S[i],0));
			}
			sort(vec.begin(),vec.end());
			for(int i = 0 ; i < S.size() ; i ++){
				sa[i][0] = lower_bound(vec.begin(),vec.end(),P(S[i],0)) - vec.begin();
			}
		}
		for(int t = 1 ; t < lnN ; t ++){
			vector<P> vec;
			for(int i = 0 ; i < S.size() ; i ++){
				if(i+(1<<(t-1)) < S.size())vec.push_back(P(sa[i][t-1],sa[i+(1<<(t-1))][t-1]));
				else vec.push_back(P(sa[i][t-1],-1));
			}
			sort(vec.begin(),vec.end());
			for(int i = 0 ; i < S.size() ; i ++){
				if(i+(1<<(t-1)) < S.size()){
					sa[i][t] = lower_bound(vec.begin(),vec.end(),P(sa[i][t-1],sa[i+(1<<(t-1))][t-1]))-vec.begin();
				}
				else {
					sa[i][t] = lower_bound(vec.begin(),vec.end(),P(sa[i][t-1],-1)) - vec.begin();
				}
			}
		}
	}
	bool eq(int x,int y,int l){
		for(int t = lnN-1 ; t >= 0 ; t--){
			if(l < (1<<t))continue;
			if(sa[x][t] != sa[y][t])return false;
			l -= 1<<t;
			x += 1<<t;
			y += 1<<t;
		}
		return true;
	}
};

int main(){
	static int n;
	static string t;
	static int q;
	static int a[200010],b[200010],c[200010];
	scanf("%d",&n);
	cin >> t;
	scanf("%d",&q);
	for(int i = 0 ; i < q ; i ++){
		scanf("%d%d%d",&a[i],&b[i],&c[i]);
	}
	
	t = "$"+t;
	static int imos[200010] = {};
	for(int i = 1 ; i <= n ; i ++){
		if(t[i] == '0')imos[i] = 1;
	}
	for(int i = 1 ; i <= n ; i ++){
		imos[i] += imos[i-1];
	}
	
	static String<> s;
	s.S = "";
	static int nex[200010];
	static int num[200010];
	static int pre = 0;
	for(int i = 1 ; i <= n ; i ++){
		if(t[i] == '0'){
			nex[i] = i;
			num[i] = s.S.size();
			if((i-pre)&1)s.S += "a";
			else s.S += "b";
			pre = i;
		}
		else nex[i] = -1;
	}
	nex[n+1] = n+1;
	for(int i = n ; i >= 1 ; i --){
		if(nex[i] == -1)nex[i] = nex[i+1];
	}
	s.sa_init();
	
	for(int i = 0 ; i < q ; i ++){
		int x = imos[a[i]+c[i]-1]-imos[a[i]-1];
		int y = imos[b[i]+c[i]-1]-imos[b[i]-1];
		if(x != y){
			puts("No");
			continue;
		}
		if(x == 0){
			puts("Yes");
			continue;
		}
		if((nex[a[i]]-a[i])%2 != (nex[b[i]]-b[i])%2){
			puts("No");
			continue;
		}
		if(s.eq(num[nex[a[i]]]+1,num[nex[b[i]]]+1,x-1)){
			puts("Yes");
		}
		else puts("No");
	}
}