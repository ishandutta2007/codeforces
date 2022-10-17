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
typedef pair<int,int> P;
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

const int INF=1000000000;
const int dir_4[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
const int dir_8[8][2]={{1,0},{1,1},{0,1},{-1,1},{-1,0},{-1,-1},{0,-1},{1,-1}};

int main(){
	int n;
	string s[52];
	cin >> n;
	rep(i,n)cin >> s[i];
	int m = s[0].size();
	
	static ld cnt[1<<20];
	cnt[0] = 0.0;
	for(int i = 1 ; i < (1<<20) ; i ++){
		cnt[i] = cnt[i/2] + (ld)(i&1);
	}
	
	//puts("DEBUG");
	
	static ll dp0[1<<20];
	rep(i,n){
		rep(j,n){
			if(i == j)continue;
			int a = 0;
			rep(k,m){
				if(s[i][k] == s[j][k])a += 1<<k;
			}
			dp0[a] |= ((ll)1)<<i;
		}
	}
	rrep(i,(1<<20)){
		rep(j,20){
			if((i>>j)&1)dp0[i^(1<<j)] |= dp0[i];
		}
	}
	
	//puts("DEBUG");
	
	
	static ld e[1<<20];
	rep(i,(1<<20)){
		e[i] = n;
		while(dp0[i] > 0){
			e[i] -= dp0[i]%2;
			dp0[i] >>= 1;
		}
		e[i] /= (ld)n;
	}
	
	/*puts("DEBUG");
	rep(i,8){
		printf("%d %lf\n",i,e[i]);
	}*/
	
	
	ld ret = 0.0;
	static ld dp1[1<<20];
	static ld dp2[1<<20];
	dp1[0] = 1.0;
	rep(i,(1<<m)){
		ld sum = dp1[i]+dp2[i];
		ret += (sum*e[i]-dp2[i])*cnt[i];
		dp2[i] = sum*e[i];
		dp1[i] = sum*(1.0-e[i]);
		rep(j,m){
			if(((i>>j)&1) == 0){
				dp1[i|(1<<j)] += dp1[i]/((ld)m-cnt[i]);
				dp2[i|(1<<j)] += dp2[i]/((ld)m-cnt[i]);
			}
		}
	}
	cout.precision(20);
	cout << ret << endl;
}