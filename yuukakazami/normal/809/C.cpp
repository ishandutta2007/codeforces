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

map<vector<int>,int> memo;

void addit(int&x,int c){
	x+=c;
	if(x>=md) x-=md;
}

ll sum(ll a, ll b){
	return (b-a+1)*(a+b)/2 % md;
}

int solve(int x1,int x2,int y1,int y2,int k,int pw,int add){ // [1..2^pw] * [1..2^pw] , count <= k
	x1 = max(x1,1); x2 = min(x2,1<<pw);
	y1 = max(y1,1); y2 = min(y2,1<<pw);

	if(x2 < x1 || y2 < y1) return 0;

	if(y2-y1 > x2-x1)
		return solve(y1,y2,x1,x2,k,pw,add);

	if(x1 == 1 && x2 == (1<<pw)){
		//add+1..add+(1<<pw)
		int cnt = (y2-y1 + 1);
		ll l = add + 1;
		ll r = min(0LL+add+(1<<pw),1LL*k);
		if(l<=r)
			return 1LL*cnt*sum(l,r)%md;
		else
			return 0;
	}

	int mi = x1 + y1;

	int ans = 0;
	int A = 1<<(pw-1),B=A+1;

	addit(ans,solve(x1,x2,y1,y2,k,pw-1,add));
	addit(ans,solve(x1-A,x2-A,y1,y2,k,pw-1,add+A));
	addit(ans,solve(x1,x2,y1-A,y2-A,k,pw-1,add+A));
	addit(ans,solve(x1-A,x2-A,y1-A,y2-A,k,pw-1,add));

	return ans;
}

int main(){
	int n;cin>>n;
	/*
	int a[100][100];

	rep(i,0,n){
		rep(j,0,n){
			bool has[400] = {};
			rep(r,0,i) has[a[r][j]] = 1;
			rep(c,0,j) has[a[i][c]] = 1;
			rep(x,1,400) if(!has[x]) {a[i][j] = x; break; }
		}
	}

	rep(i,0,n){
		rep(j,0,n)
			printf("% 4d ",a[i][j]);
		puts("");
	}
	*/
	//n=int(10000);
	rep(_,0,n){
		int x1,x2,y1,y2,k;
		cin>>x1>>y1>>x2>>y2>>k;
		//x1=y1=1;x2=y2=int(1e9);k=rand() % int(2e9);
		cout<<solve(x1,x2,y1,y2,k,30,0)<<endl;
	}
	return 0;
}