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
	int n,m,c;
	cin >> n >> m >> c;
	
	int a[1002] = {};
	int s = 0 , t = 0;
	for(int ppp = 0 ; ppp < m ; ppp ++){
		int p;
		cin >> p;
		
		if(p <= c/2){
			int loc = 1;
			while(1){
				if(a[loc] == 0){
					a[loc] = p;
					cout << loc << endl;
					fflush(stdout);
					s ++;
					if(s+t == n)return 0;
					break;
				}
				if(a[loc] > p){
					a[loc] = p;
					cout << loc << endl;
					fflush(stdout);
					break;
				}
				loc ++;
			}
		}
		else {
			int loc = n;
			while(1){
				if(a[loc] == 0){
					a[loc] = p;
					cout << loc << endl;
					fflush(stdout);
					t ++;
					if(s+t == n)return 0;
					break;
				}
				if(a[loc] < p){
					a[loc] = p;
					cout << loc << endl;
					fflush(stdout);
					break;
				}
				loc --;
			}
		}
	}
}