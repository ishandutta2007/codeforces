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

int n;
int u[500010],v[500010];
char c[500010];
int cnt[500010];
int cnt_[500010];

int main(){
	int T;
	scanf("%d",&T);
	for(;T>0;T--){
		scanf("%d",&n);
		rep1(i,n-1){
			scanf("%d%d",&u[i],&v[i]);
		}
		scanf("\n");
		rep1(i,n)scanf("%c",&c[i]);
		rep1(i,n)cnt[i] = 0;
		rep1(i,n-1){
			cnt[u[i]] ++;
			cnt[v[i]] ++;
		}
		
		if(n <= 2){
			puts("Draw");
			continue;
		}
		
		int d = 0;
		rep1(i,n){
			d = max( d , cnt[i] );
		}
		if(d >= 4){
			puts("White");
			continue;
		}
		if(d == 3){
			if(n == 4){
				if(c[1] == 'W' || c[2] == 'W' || c[3] == 'W' || c[4] == 'W'){
					puts("White");
				}
				else puts("Draw");
				continue;
			}
			rep1(i,n)cnt_[i] = 0;
			rep1(i,n-1){
				if(cnt[u[i]] >= 2)cnt_[v[i]] ++;
				if(cnt[v[i]] >= 2)cnt_[u[i]] ++;
			}
			bool ret = false;
			rep1(i,n){
				if(cnt[i] == 3 && cnt_[i] >= 2){
					ret = true;
					break;
				}
			}
			if(ret){
				puts("White");
				continue;
			}
			rep1(i,n){
				if(cnt[i] >= 2 && c[i] == 'W'){
					ret = true;
					break;
				}
			}
			if(ret){
				puts("White");
				continue;
			}
			rep1(i,n-1){
				if(cnt[u[i]] == 3 && cnt[v[i]] == 1 && c[v[i]] == 'W'){
					ret = true;
					break;
				}
				if(cnt[v[i]] == 3 && cnt[u[i]] == 1 && c[u[i]] == 'W'){
					ret = true;
					break;
				}
			}
			if(ret){
				puts("White");
				continue;
			}
			int CNT = 0;
			rep1(i,n){
				if(cnt[i] == 3)CNT ++;
			}
			if(CNT == 1){
				rep1(i,n)if(c[i] == 'W')CNT ++;
				if(CNT == 2 && n%2 == 0){
					puts("White");
				}
				else puts("Draw");
				continue;
			}
			else {
				if(n%2 == 1){
					puts("White");
				}
				else puts("Draw");
				continue;
			}
		}
		int cnt_w[2] = {};
		rep1(i,n){
			if(c[i] == 'W'){
				cnt_w[cnt[i]-1] ++;
			}
		}
		if(cnt_w[1] > 0){
			if(n == 3 && cnt_w[0] == 0){
				puts("Draw");
				continue;
			}
			puts("White");
			continue;
		}
		if(cnt_w[0] == 2 && (n&1)){
			puts("White");
			continue;
		}
		else puts("Draw");
	}
}