#include<bits/stdc++.h>
using namespace std;
 
typedef long long int T;
typedef long long int ll;
typedef unsigned long long int ull;
mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());//rng()
ull mul(ull a,ull b,const ull mod){ /* assuming a , b < mod */
	ll res=a*b-mod*(ull)((long double)a*b/mod);
	return res+((res<0)-(res>=(ll)mod))*mod;
}
T ksm(T x,T b,T mod){
	T res=1;
	while(b){
		if(b&1)	res=mul(res,x,mod);
		x=mul(x,x,mod);
		b>>=1;
	}
	return res;
}
vector<int> wn={2,325,9375,28178,450775,9780504,1795265022};//2,7,61
bool miller_rabin(T n,T u,int t,int a){
	T res=ksm(a,u,n);
	if(!res||res==1||res==n-1) return true;
	while(--t){
		res=mul(res,res,n);
		if(res==1)	return false;
		if(res==n-1)	return true;
	}
	return false;
}
bool isprime(T n){
	if(n<2) return false;
	if(!(n&1))	return n==2;
	T u=n-1;
	int t=0;
	for(;!(u&1);u>>=1,++t);
	for(int it:wn)   if(!miller_rabin(n,u,t,it)) return false;
	return true;
}
vector<T> fac;
T pollard(T n,T c){
	T x,y,d,i=1,k=2;
	x=y=rng()%n;
	while(true){
		i++,x=(mul(x,x,n)+c)%n,d=gcd(abs(y-x),n);
		if(d>1&&d<n)   return d;
		if(y==x) return n;
		if(i==k)  y=x,k<<=1;
	}
}
void find(T n){
	if(n==1)	return;
	if(isprime(n))   return fac.emplace_back(n),void();
	T p=n;
	while(p>=n)  p=pollard(n,rng()%(n-1)+1);
	find(n/p),find(p);
}
 
 
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	map<long long,long long> pw;
	for(int i=2;i<=1000000;i++)
		if(isprime(i)) {
			long long x = i;
			while(true) {
				pw[x] = i;
				if(1000000000000000000LL / x < i)	break;
				x *= i;
			}
		}
	int n, k;
	cin >> n >> k;
	if(k == 1) {
		cout << 0 << endl;
		return 0;
	}
	vector<long long> a(n);
	vector<vector<T>> factor(n);
	vector<long long> pure(n);
	map<long long, int> purenum;
	for(int i=0;i<n;i++) {
		cin >> a[i];
		if(isprime(a[i])) {
			pure[i] = a[i];
			factor[i].emplace_back(a[i]);
			purenum[a[i]]++;
			continue;
		}
		int x = sqrt(a[i]);
		while(1LL * x * x > a[i])	x--;
		while(1LL * (x + 1) * (x + 1) <= a[i])	x++;
		if(1LL * x * x == a[i] && isprime(x)) {
			pure[i] = x;
			factor[i].emplace_back(x);
			purenum[x]++;
			continue;
		}
		if(pw.count(a[i])) {
			pure[i] = pw[a[i]];
			factor[i].emplace_back(pw[a[i]]);
			purenum[pw[a[i]]]++;
			continue;
		}
	}
	for(int i=0;i<n;i++) 
		if(!pure[i]) {
			long long x = a[i];
			for(auto [u, v]:purenum) {
				if(v < 2 || x % u != 0)	continue;
				while(x % u == 0)	x /= u;
				factor[i].emplace_back(u);
			}
			if(x != 1)
				factor[i].emplace_back(-1);
		}
	int tot = 0;
	bool hasthree = false;
	for(int i=0;i<n;i++) 
		if(pure[i]) {
			if(purenum[pure[i]] >= 2)
				tot ++;
			if(purenum[pure[i]] > 2)
				hasthree = true;
		}
	if(tot >= k) {
		if(hasthree) {
			vector<pair<int, long long>> vp;
			for(auto it:purenum)
				vp.emplace_back(it.second, it.first);
			sort(vp.begin(), vp.end());
			reverse(vp.begin(), vp.end());
			multiset<long long> cur;
			for(int i=0;i<vp.size();i++)
				if(cur.size() + vp[i].first <= k) {
					for(int j=0;j<vp[i].first;j++)
						cur.insert(vp[i].second);
					if(k == cur.size())
						break;
				}
				else {
					if(k - cur.size() >= 2) {
						for(int j=k - cur.size();j>=1;j--)
							cur.insert(vp[i].second);
						break;
					}
					else {
						cur.insert(vp[i].second);
						cur.insert(vp[i].second);
						cur.erase(cur.find(vp[0].second));
						break;
					}
				}
			for(int i=0;i<n;i++)
				if(pure[i] && cur.count(pure[i]))
					cout << a[i] << ' ', cur.erase(cur.find(pure[i]));
		}
		else {
			if(k % 2 == 0) {
				multiset<long long> cur;
				for(auto it:purenum)
					if(cur.size() != k && it.second == 2)
						cur.insert(it.first), cur.insert(it.first);
				for(int i=0;i<n;i++)
					if(pure[i] && cur.count(pure[i]))
						cout << a[i] << ' ', cur.erase(cur.find(pure[i]));
				cout << endl;
			}
			else {
				int idx = -1, b = 0;
				for(int i=0;i<n;i++) {
					if(!pure[i]) {
						bool ok = true;
						for(T x:factor[i])
							if(purenum.count(x) && purenum[x] >= 2);
							else	ok = false;
						if(ok) {
							set<long long> st;
							for(T x:factor[i])
								st.insert(x);
							if(idx == -1 || st.size() < b) {
								b = st.size(), idx = i;
							}
						}
					}
				}
				if(idx != -1 && b * 2 + 1 <= k) {
					multiset<long long> cur;
					k--;
					cout <<	a[idx] << ' ';
					set<long long> st;
					for(T x:factor[idx])
						st.insert(x);
					for(auto x:st)
						cur.insert(x), cur.insert(x);
					for(int i=0;i<n;i++)
						if(pure[i] && purenum[pure[i]] >= 2 && cur.size() != k && !cur.count(pure[i]))
							cur.insert(pure[i]), cur.insert(pure[i]);
					for(int i=0;i<n;i++)
						if(pure[i] && cur.count(pure[i]))
							cout << a[i] << ' ', cur.erase(cur.find(pure[i]));
					cout << endl;	
				}
				else {
					cout << 0 << endl; 
				}
			}
		}
	}
	else {
		vector<int> ans;
		for(int i=0;i<n;i++)
			if(pure[i] && purenum[pure[i]] >= 2)
				ans.emplace_back(i);
		for(int i=0;i<n&&ans.size()<k;i++)
			if(!pure[i]) {
				bool ok = true;
				for(T x:factor[i])
					if(purenum.count(x) && purenum[x] >= 2);
					else	ok = false;
				if(ok)
					ans.emplace_back(i);
			}
		if(ans.size() == k) {
			for(auto x:ans)
				cout << a[x] << ' ';
			cout << endl;
		}
		else
			cout << 0 << endl;
	}
}