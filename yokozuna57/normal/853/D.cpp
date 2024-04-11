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
typedef pair<P,P> P2;

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
#define mp2(a,b,c,d) P2(P(a,b),P(c,d))

const ll INF=1000000000000;
const int dir_4[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
const int dir_8[8][2]={{1,0},{1,1},{0,1},{-1,1},{-1,0},{-1,-1},{0,-1},{1,-1}};

int main(){
	int n;
	static int a[300010];
	scanf("%d",&n);
	rep(i,n)scanf("%d",&a[i]);
	
	if(n <= 20){
		int ret = n*2000;
		rep(i,(1<<n)){
			int sum = 0;
			int z = 0;
			for(int j = 0 ; j < n ; j ++){
				if((i>>j)&1){
					if(a[j] >= z){
						sum += a[j]-z;
						z = 0;
					}
					else {
						z -= a[j];
					}
				}
				else {
					sum += a[j];
					z += a[j]/10;
				}
			}
			ret = min ( ret , sum );
		}
		cout << ret << endl;
	}
	else {
		int cnt = 0;
		rep(j,n)cnt += a[j]/1000;
		int ret = (cnt/11)*10*1000;
		cnt %= 11;
		if(cnt != 0)ret += (cnt-1)*1000 + 1000-(cnt-1)*100;
		cout << ret << endl;
	}
}