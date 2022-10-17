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
	static int n,q,t,x;
	static int cnt[300010] = {};
	static int a[300010] = {};
	static int ret = 0;
	
	vector<int> vec;
	int k = 0;
	
	scanf("%d%d",&n,&q);
	rep(i,q){
		scanf("%d%d",&t,&x);
		if(t == 1){
			cnt[x] ++;
			ret ++;
			vec.pb(x);
		}
		if(t == 2){
			ret -= cnt[x];
			cnt[x] = 0;
			a[x] = vec.size();
		}
		if(t == 3){
			if(k < x){
				for(;k<x;k++){
					if(a[vec[k]] <= k){
						cnt[vec[k]] --;
						ret --;
					}
				}
			}
		}
		cout << ret << endl;
	}
}