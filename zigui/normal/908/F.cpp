#include<stdio.h>
#include<iostream>
#include<map>
#include<algorithm>
#include<string.h>
#include<vector>
#include<math.h>
#include<stdlib.h>
#include<set>
#include<string>
#include<ctype.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const int MM = 1000000007;
const int MX = 1005;

ll pw(ll a, ll b = MM-2){
	ll r = 1;
	while(b){
		if(b&1) r = r*a % MM;
		a = a*a%MM; b /= 2;
	}
	return r;
}

int main()
{
	int N;
	scanf("%d", &N);
	int st = -1e9;
	vector<int> R, B;
	
	ll ans = 0;
	for(int i = 1; i <= N; i++){
		int a;
		char c, buf[10];
		scanf("%d%s", &a, buf); c = buf[0];
		
		if( c == 'G' ){
			if(st == -1e9){
				if( R.size()) ans += a - R[0];
				if( B.size()) ans += a - B[0];
			}
			else{
				int cur = (a - st) * 2;
				int mr = 0, mb = 0;
				R.push_back(a); B.push_back(a);
	
				for(int i = 0; i+1 < R.size(); i++) mr = max(mr, R[i+1] - R[i]);
				for(int i = 0; i+1 < B.size(); i++) mb = max(mb, B[i+1] - B[i]);
	
				cur = min((ll)cur, 3ll*(a - st) - mr - mb);
				ans += cur;
			}
			st = a;
			R.clear(); B.clear();
			R.push_back(a);
			B.push_back(a);
		}
		else if( c == 'B' ) B.push_back(a);
		else R.push_back(a);
	}
	if( st == -1e9 ){
		if( R.size() >= 2 ) ans += R.back() - R[0];
		if( B.size() >= 2 ) ans += B.back() - B[0];
	}
	else{
		if(R.size()) ans += R.back() - st;
		if(B.size()) ans += B.back() - st;
	}
	printf("%lld\n", ans);
}