#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> hashing;
#define f first
#define s second
const hashing mod = {998244353, 1e9+7};
const hashing base = {29,37};
hashing pw[1000010];
hashing operator+(const hashing& A,const hashing& B){
	hashing res = {A.f+B.f,A.s+B.s};
	if(res.f>=mod.f)	res.f-=mod.f;
	if(res.s>=mod.s)	res.s-=mod.s;
	return res;
}
hashing operator-(const hashing& A,const hashing& B){
	hashing res = {A.f-B.f,A.s-B.s};
	if(res.f<0)	res.f+=mod.f;
	if(res.s<0)	res.s+=mod.s;
	return res;
}
hashing operator+(const hashing& A,const int& C){
	hashing res = {A.f+C,A.s+C};
	if(res.f>=mod.f)	res.f-=mod.f;
	if(res.s>=mod.s)	res.s-=mod.s;
	return res;
}
hashing operator*(const hashing& A,const hashing& B){
	return {1LL*A.f*B.f%mod.f,1LL*A.s*B.s%mod.s};
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	pw[0] = {1, 1};
	for(int i=1;i<=1000000;i++)
		pw[i] = pw[i-1] * base;
	int T;
	cin >> T;
	while(T--) {
		int n, k;
		cin >> n >> k;
		string s;
		cin >> s;
		hashing cur = {0, 0};
		set<hashing> M;
		for(int i=0;i<k;i++) {
			hashing now = {1, 1};
			if(s[i] == '0')
				now = {2, 2};
			cur = cur * base + now;
			M.insert(cur);
		}
		for(int i=k;i<n;i++) {
			hashing now = {1, 1}, pre = {1, 1};
			if(s[i] == '0')
				now = {2, 2};
			if(s[i-k] == '0')
				pre = {2, 2};
			cur = (cur - pw[k - 1] * pre) * base + now;
			M.insert(cur);
		}
		bool ok = false;
		int lim = 1 << 20;
		if(k < 20)
			lim = 1 << k;
		cur = {0, 0};
		for(int i=0;i<k;i++)
			cur = cur * base + make_pair(1, 1);
		string t(k, '0');
		for(int z=0;z<lim;z++) {
			if(!M.count(cur)) {
				cout << "YES\n" << t << '\n';
				ok = true;
				break;
			}
			for(int j=k-1;j>=0;j--) {
				if(t[j] == '1') {
					t[j] = '0';
					cur = cur - pw[k-1-j];
				}
				else {
					t[j] = '1';
					cur = cur + pw[k-1-j];
					break;
				}
			}
		}
		if(!ok)
			cout << "NO\n";
	}
}