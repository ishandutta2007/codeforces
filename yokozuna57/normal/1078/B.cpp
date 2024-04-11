#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<string>
#include<stack>
#include<cstdio>
#include<bitset>
#include<cmath>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> P;
typedef pair<int,P> P1;
typedef bitset<10010> B;

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
	int a[102];
	scanf("%d",&n);
	for(int i = 1 ; i <= n ; i ++){
		scanf("%d",&a[i]);
	}
	
	int cnt[102] = {};
	for(int i = 1 ; i <= n ; i ++){
		cnt[a[i]] ++;
	}
	int ret = 1;
	for(int m = 1 ; m <= 100 ; m ++){
		if(cnt[m] <= 1)continue;
		static B dp[102];
		for(int j = 0 ; j < 102 ; j ++){
			dp[j].reset();
		}
		dp[0][0] = true;
		for(int i = 1 ; i <= n ; i ++){
			if(a[i] == m)continue;
			for(int j = cnt[m] ; j >= 1 ; j --){
				dp[j] |= (dp[j-1]<<a[i]);
			}
		}
		for(int i = 2 ; i <= cnt[m] ; i ++){
			if(dp[i][i*m])break;
			ret = max ( ret , i );
		}
	}
	
	int CNT = 0;
	for(int m = 1 ; m <= 100 ; m ++){
		if(cnt[m] > 0)CNT ++;
	}
	if(CNT <= 2){
		cout << n << endl;
	}
	else {
		cout << ret << endl;
	}
}