#include <bits/stdc++.h>
typedef long long ll;
typedef double db;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define mp make_pair
#define fi first
#define se second
#define per(i,a,n) for (int i=int(n)-1;i>=(a);i--)
#define pb push_back
using namespace std;
const int md = int(1e9) + 7;
ll mypow(ll a,ll e){
	if(e==0) return 1;
	return e%2==0?mypow(a*a%md,e>>1):mypow(a,e-1)*a%md;
}
// head
int main(){
	char ch = 'a';
	string s; cin>>s;
	while(!s.empty()){
		if(s[0] != ch){
			puts("NO");
			return 0;
		}
		string t = "";
		for(auto i : s) if(i != ch) t += i;
		s = t;
		++ch;
	}
	puts("YES");
	return 0;
}