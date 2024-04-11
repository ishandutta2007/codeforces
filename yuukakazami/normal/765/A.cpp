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
	int n;cin>>n;
	puts(n%2==0?"home":"contest");
	return 0;
}