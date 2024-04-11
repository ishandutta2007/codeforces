#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<string>
#include<stack>
#include<cstdio>
#include<cmath>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> P;
typedef pair<int,P> P1;

#define fr first
#define sc second
#define mp make_pair
#define pb push_back
#define rep(i,x) for(int i=0;i<x;i++)
#define rep1(i,x) for(int i=1;i<=x;i++)
#define rrep(i,x) for(int i=x-1;i>=0;i--)
#define rrep1(i,x) for(int i=x;i>0;i--)
#define sor(v) sort(v.begin(),v.end())
#define rev(s) reverse(s.begin(),s.end())
#define lb(vec,a) lower_bound(vec.begin(),vec.end(),a)
#define ub(vec,a) upper_bound(vec.begin(),vec.end(),a)
#define uniq(vec) vec.erase(unique(vec.begin(),vec.end()),vec.end())
#define mp1(a,b,c) P1(a,P(b,c))

const ll INF=1000000000000000001;
const int dir_4[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
const int dir_8[8][2]={{1,0},{1,1},{0,1},{-1,1},{-1,0},{-1,-1},{0,-1},{1,-1}};

int main(){
	static int gcd[3200][3200];
	rep(i,3200)rep(j,3200){
		if(i == 0)gcd[i][j] = j;
		else if(j == 0)gcd[i][j] = i;
		else if(i > j)gcd[i][j] = gcd[j][i];
		else gcd[i][j] = gcd[i][j-i];
	}
	
	ll n,l,r;
	cin >> n >> l >> r;
	
	if(n == 1){
		printf("%I64d\n",r-l+1);
		return 0;
	}
	if(n == 2){
		printf("%I64d\n",(r-l+1)*(r-l));
		return 0;
	}
	
	static ll pow[3200];
	ll k = 0;
	while(1){
		pow[k] = 1;
		rep(i,n-1){
			pow[k] *= k;
			if(pow[k] > r)break;
		}
		if(pow[k] > r)break;
		k ++;
	}
	
	ll ret = 0;
	for(int i = 1 ; i < k ; i++){
		for(int j = i+1 ; j < k ; j ++){
			if(gcd[i][j] != 1)continue;
			ret += max((ll)0,r/pow[j]-(l+pow[i]-1)/pow[i]+1);
		}
	}
	cout << ret*2 << endl;
}