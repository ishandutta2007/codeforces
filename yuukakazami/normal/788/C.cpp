#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for(int i=(a);i<(n);i++)
#define per(i,a,n) for(int i=(n)-1;i>=(a);i--)

const int MAX_N = 1000 + 10;
int n,k;

bitset<MAX_N*3> am,nam;
bool has[MAX_N];

int main(){
	cin>>n>>k;

	int minx = MAX_N, maxx = -MAX_N;

	rep(it,0,k){
		int x;scanf("%d",&x);has[x] = 1;
		minx = min(minx,x);
		maxx = max(maxx,x);
	}

	if(minx > n || maxx < n){
		puts("-1");
		return 0;
	}

	am[MAX_N] = 1;

	rep(t,0,MAX_N){
		if(t>0 && am[MAX_N]){
			cout<<t<<endl;
			return 0;
		}
		am = am >> n;
		nam.reset();
		rep(it,0,MAX_N) if(has[it])
			nam |= am << it;
		am = nam;
	}
	return 0;
}