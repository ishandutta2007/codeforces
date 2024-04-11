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
	static int n,m;
	static int l[100010],r[100010],q[100010];
	scanf("%d%d",&n,&m);
	rep(i,m){
		scanf("%d%d%d",&l[i],&r[i],&q[i]);
	}
	
	vector<P> vec;
	rep(i,m){
		vec.pb(P(l[i],q[i]));
		vec.pb(P(r[i]+1,-q[i]));
	}
	sor(vec);
	
	static int a[100010];
	int A[30] = {};
	int k = 0;
	rep1(i,n){
		while(k < vec.size() && vec[k].fr == i){
			if(vec[k].sc > 0){
				rep(j,30)A[j] += (vec[k].sc>>j)&1;
			}
			else {
				vec[k].sc *= -1;
				rep(j,30)A[j] -= (vec[k].sc>>j)&1;
			}
			k ++;
		}
		a[i] = 0;
		rep(j,30)if(A[j] > 0)a[i] += 1<<j;
	}
	
	static int cnt[100010][30] = {};
	rep1(i,n){
		rep(j,30){
			cnt[i][j] = cnt[i-1][j] + ((a[i]>>j)&1);
		}
	}
	
	rep(i,m){
		rep(j,30){
			if((q[i]>>j)&1){
				if(cnt[r[i]][j]-cnt[l[i]-1][j] < r[i]-l[i]+1){
					puts("NO");
					return 0;
				}
			}
			else {
				if(cnt[r[i]][j]-cnt[l[i]-1][j] == r[i]-l[i]+1){
					puts("NO");
					return 0;
				}
			}
		}
	}
	puts("YES");
	rep1(i,n)printf("%d%c",a[i],(i==n)?'\n':' ');
}