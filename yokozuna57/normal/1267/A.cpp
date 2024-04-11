#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> P;
typedef pair<ll,P> P1;
#define fr first
#define sc second
#define mp1(a,b,c) P1(a,P(b,c))

const ll INF = 2000000000000000000LL;

int main(){
	static ll n;
	static ll a[200010];
	static ll b[200010];
	static ll t[200010];
	scanf("%lld",&n);
	for(int i = 0 ; i < n ; i ++){
		scanf("%lld%lld%lld",&a[i],&b[i],&t[i]);
	}
	
	static ll m;
	static ll d[400010];
	static ll r[400010];
	static ll s[400010];
	
	vector<ll> X;
	for(int i = 0 ; i < n ; i ++){
		X.push_back(a[i]);
		X.push_back(b[i]-t[i]+1);
	}
	sort(X.begin(),X.end());
	X.erase(unique(X.begin(),X.end()),X.end());
	m = X.size();
	for(int i = 0 ; i < m ; i ++){
		d[i] = X[i];
	}
	
	vector<P1> vec;
	for(int i = 0 ; i < n ; i ++){
		vec.push_back(mp1(a[i],1,t[i]));
		vec.push_back(mp1(b[i]-t[i]+1,-1,t[i]));
	}
	sort(vec.begin(),vec.end());
	
	multiset<ll> S;
	for(int i = 0 ; i < m ; i ++){
		r[i] = INF;
		s[i] = INF;
	}
	int kk = 0;
	for(int i = 0 ; i < m ; i ++){
		while(kk < vec.size() && vec[kk].fr == d[i]){
			P1 p = vec[kk];
			if(p.sc.fr == 1){
				S.insert(p.sc.sc);
				if(i>0)s[i-1] = min( s[i-1] , p.fr+p.sc.sc );
			}
			else {
				S.erase(S.find(p.sc.sc));
			}
			kk ++;
		}
		if(S.size() == 0)r[i] = -1;
		else r[i] = *S.begin();
	}
	for(int i = m-2 ; i >= 0 ; i --){
		s[i] = min( s[i] , s[i+1] );
	}
	
	/*cout << m << endl;
	for(int i = 0 ; i < m ; i ++){
		cout << d[i] << " ";
	}cout << endl;
	for(int i = 0 ; i < m ; i ++){
		cout << r[i] << " " << s[i] << endl;
	}*/
	
	ll ret = 0;
	ll loc = 0;
	for(int i = 0 ; i+1 < m ; i ++){
		if(r[i] == -1)continue;
		loc = max( loc , d[i] );
		ll x = (min(s[i],d[i+1]+r[i]-1)-loc)/r[i];
		ret += x;
		loc += x*r[i];
		if(loc < d[i+1]){
			ret ++;
			loc = s[i];
		}
	}
	cout << ret << endl;
}