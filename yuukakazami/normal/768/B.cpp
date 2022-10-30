#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for(int i=(a);i<(n);i++)

typedef long long int64;

int64 sz(int64 n){
	if(n<=1) return 1;
	return sz(n/2)*2 + 1;
}

int64 solve(int64 n,int64 l,int64 r){//[l,r)
	if(l>=r) return 0;
	if(n<=1) return n;
	int64 a = sz(n/2);//[0,a)
	int64 ans = 0;
	if(l<a)
		ans += solve(n/2,l,min(r,a));
	//a
	if(l <= a && a < r)
		ans += n%2;
	//>a [a+1,
	if(r>a+1)
		ans += solve(n/2,max(l-a-1,0LL),r-a-1);

	return ans;
}

int main(){
	int64 n,l,r;cin>>n>>l>>r;--l;
	cout<<solve(n,l,r)<<endl;
	return 0;
}