#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define pb push_back
#define reset(a,b) memset(a,b,sizeof a);
#define ALL(x) x.begin(),x.end()
#define debug(x) cout<<#x<<" = "<<(x)<<endl
#define sz(x) (int)(x.size())
#define lt(x) (int)(x.length())
#define MOD 1000000007 
#define mx 100003


int main(){
	int t, a, b, n;
	cin >> t;
	while(t--){
		cin >> a >> b >> n;
		if(n % 3 == 0)
			cout << a << '\n';
		else if(n % 3 == 1)
			cout << b << '\n';
		else cout << (a ^ b) << '\n';
	}
}