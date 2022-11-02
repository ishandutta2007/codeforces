#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=a; i<(b); ++i)
#define trav(a,x) for(auto& a : x)
#define all(x) x.begin, x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef pair<int,pii> piii;

#define TESTING

#ifdef TESTING
#define TO
#else
#define TO if(0)
#endif

const int undone = -10;
const int imp = -20;

struct val{
	int s;
	int a;
	int b;
	val() : s(undone), a(0), b(0) {}
	val(int s, int a, int b):s(s),a(a),b(b) {}
};

val dp[209][209][4][4];

val solve(int a, int b, int s, int t){
	val ans = dp[a][b][s][t];
	if(ans.s != undone) return ans;
	if(s==3 || t==3){
		if(a==0 && b==0){
			dp[a][b][s][t] = val(s-t,0,0);
		}else{
			dp[a][b][s][t] = val(imp,0,0);
		}
		return dp[a][b][s][t];
	}
	int game = 25;
	if(s+t == 4) game = 15;
	ans = val(imp,0,0);
	if(a >= game){
		rep(k,0,min(b+1,game-1)){
			val cand = solve(a-game,b-k,s+1,t);
			if(cand.s > ans.s){
				ans = val(cand.s, game, k);
			}
		}
		rep(k,game-1,min(b,a-2)+1){
			val cand = solve(a-k-2,b-k,s+1,t);
			if(cand.s > ans.s){
				ans = val(cand.s, k+2, k);
			}
		}
	}
	if(b >= game){
		rep(k,0,min(a+1,game-1)){
			val cand = solve(a-k,b-game,s,t+1);
			if(cand.s > ans.s){
				ans = val(cand.s, k, game);
			}
		}
		rep(k,game-1,min(a,b-2)+1){
			val cand = solve(a-k,b-k-2,s,t+1);
			if(cand.s > ans.s){
				ans = val(cand.s, k, k+2);
			}
		}
	}
	dp[a][b][s][t] = ans;
	return ans;
}

int main(){
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	int m;
	cin >> m;
	int a,b;
	rep(i,0,m){
		cin >> a >> b;
		val ans = solve(a,b,0,0);
		if(ans.s == imp){
			cout << "Impossible" << endl;
		}else{
			int s=0,t=0;
			vector<pii> sln;
			while(a+b>0){
				a -= ans.a;
				b -= ans.b;
				if(ans.a > ans.b){
					s++;
				}else{
					t++;
				}
				sln.push_back({ans.a, ans.b});
				ans = solve(a,b,s,t);
			}
			cout << s << ":" << t << endl;
			trav(p,sln){
				cout << p.first << ":" << p.second << " ";
			}
			cout << endl;
		}
	}
}