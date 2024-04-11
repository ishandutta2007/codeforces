#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
typedef vector<int> VI;
typedef long long ll;
typedef pair<int,int> PII;
const ll mod=1000000007;
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
// head

typedef long long ll;

const int MAX_N = 2000 + 10;
const ll INF = 1LL << 60;
int n;

int edge[MAX_N][MAX_N];

int min_edge;

ll dist[MAX_N][3];

int main(){
	cin>>n;

	min_edge = int(1e9) + 10;

	vector<int> end_points;

	rep(i,0,n){
		rep(j,i+1,n){
			scanf("%d",edge[i]+j);
			edge[j][i] = edge[i][j];
			if(edge[i][j] < min_edge){
				min_edge = edge[i][j];
				end_points.clear();
			}

			if(edge[i][j] == min_edge){
				end_points.pb(i);
				end_points.pb(j);
			}
		}
	}

	rep(i,0,n) rep(j,0,n) if(i!=j) edge[i][j] -= min_edge;

	static bool used[MAX_N][3];

	rep(i,0,n) rep(j,0,3) {
		dist[i][j] = INF;
		used[i][j] = 0;
	}

	for(auto u : end_points) dist[u][0] = 0; //0:first step, 1: then*2, 2: normal

	rep(_,0,n*3){
		int u = -1, v; rep(i,0,n) rep(j,0,3) if(!used[i][j] && (u == -1 || dist[i][j] < dist[u][v])) u = i,v = j;

		used[u][v] = 1;

		ll d = dist[u][v];

		//cout<<u<<" "<<v<<" "<<d<<endl;

		rep(j,0,n) if(edge[u][j] > 0){
			if(v==0){
				dist[j][1] = min(dist[j][1], d);
				dist[j][2] = min(dist[j][2], d + edge[u][j]);
			} else if(v==1){
				dist[j][2] = min(dist[j][2], d + edge[u][j] * 2);
			} else {
				dist[j][2] = min(dist[j][2], d + edge[u][j]);
			}
		}
	}

	rep(i,0,n){
		ll ans = min(dist[i][0],dist[i][2]) + 1LL * min_edge * (n-1);
		cout<<ans<<endl;
	}
	return 0;
}