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
#define min_3(a,b,c) min(a,min(b,c))
#define max_3(a,b,c) max(a,max(b,c))
#define mp1(a,b,c) P1(a,P(b,c))
#define pque(a) priority_queue<a>
#define rpque(a) priority_queue<a,vector<a>,greater<a>>

const int INF=1000000000;
const int dir_4[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
const int dir_8[8][2]={{1,0},{1,1},{0,1},{-1,1},{-1,0},{-1,-1},{0,-1},{1,-1}};
const int kaijou[10]={1,1,2,6,24,120,720,5040,40320,362880};

vector<int> G[30];
vector<int> rG[30];
bool used[30];
string ans = "";

void dfs(int v){
	if(used[v])return;
	rep(i,rG[v].size()){
		if(!used[rG[v][i]])dfs(rG[v][i]);
	}
	ans += 'a' + v;
	used[v] = true;
}

int main(){
	int n;
	string s[102];
	
	cin >> n;
	rep(i,n){
		cin >> s[i];
	}
	
	int d[30][30];
	rep(i,30)rep(j,30){
		if(i == j)d[i][j] = 0;
		else d[i][j] = INF;
	}
	
	bool pos = true;
	rep1(i,n-1){
		bool t = false;
		rep(j,min(s[i].size(),s[i-1].size())){
			if(s[i][j] != s[i-1][j]){
				d[s[i-1][j]-'a'][s[i][j]-'a'] = 1;
				t = true;
				break;
			}
		}
		if(!t){
			if(s[i-1].size() > s[i].size()){
				pos = false;
				break;
			}
		}
	}
	
	rep(k,26){
		rep(i,26){
			rep(j,26){
				d[i][j] = min ( d[i][j] , d[i][k] + d[k][j] );
			}
		}
	}
	
	rep(i,26){
		rep(j,26){
			if(i == j)continue;
			if(d[i][j] < INF && d[j][i] < INF)pos = false;
		}
	}
	
	if(!pos)puts("Impossible");
	else {
		rep(i,26){
			rep(j,26){
				if(i == j)continue;
				if(d[i][j] < INF){
					G[i].pb( j );
					rG[j].pb( i );
				}
			}
		}
		rep(i,30)used[i] = false;
		rep(i,26)dfs(i);
		cout << ans << endl;
	}
}