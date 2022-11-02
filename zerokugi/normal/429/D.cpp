#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cstring>
#include <string>
#include <cstdlib>
#include <cstdio>
#include <complex>
using namespace std;
typedef pair<int, int> pii;
typedef long long int ll;
#define REP(i,x) for(int i=0;i<(int)(x);i++)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define RREP(i,x) for(int i=(x);i>=0;i--)
#define RFOR(i,c) for(__typeof((c).rbegin())i=(c).rbegin();i!=(c).rend();++i)
#define X real()
#define Y imag()

const double EPS = 1e-8;
const double INF = 1e20;


typedef complex<double> P;
namespace std {
  bool operator < (const P& a, const P& b) {
    return real(a) != real(b) ? real(a) < real(b) : imag(a) < imag(b);
  }
}

bool compare_y(P a, P b){
	return a.Y < b.Y;
}

inline double norm(P p){
	return p.X*p.X+p.Y*p.Y;
}

pair<P, P> closestPair(vector<P>::iterator s, vector<P>::iterator t) {
	int n = t - s;
	int m = n / 2;
	if(n<=1) return pair<P, P>(P(0,0), P(INF, INF));
	double x = (s+m)->X;
	pair<P, P> d = closestPair(s, s+m);
	pair<P, P> d2 = closestPair(s+m, t);
	if(norm(d.first - d.second) > norm(d2.first - d2.second)) d = d2;
	inplace_merge(s, s+m, t, compare_y);
	
	vector<P> b;
	REP(i, n){
		if((s[i].X - x)*(s[i].X - x) >= norm(d.first - d.second)) continue;
		REP(j, b.size()){
			double dx = s[i].X - b[b.size()-j-1].X;
			double dy = s[i].Y - b[b.size()-j-1].Y;
			if((s[i].Y - b[b.size()-j-1].Y)*(s[i].Y - b[b.size()-j-1].Y) >= norm(d.first - d.second)) break;
			d2 = pair<P, P>(s[i], b[b.size()-j-1]);
			if(norm(d.first - d.second) > norm(d2.first - d2.second)) d = d2;
		}
		b.push_back(s[i]);
	}
	
	return d;
}

int n;
main(){
	scanf("%d", &n);
	vector<int> p(n+1);
	vector<P> g;
	REP(i, n){
		int y;
		scanf("%d", &p[i+1]);
	}
	REP(i, n){
		p[i+1] += p[i];
		g.push_back(P((ll)i, (ll)p[i+1]));
	}
	pair<P, P> ret = closestPair(g.begin(), g.end());
	double res = norm(ret.first - ret.second);
	cout << (int)(res+EPS) << endl;
	return 0;
}