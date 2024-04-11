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
using namespace std;
typedef pair<int, int> pii;
typedef long long int ll;
#define REP(i,x) for(int i=0;i<(int)(x);i++)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define RREP(i,x) for(int i=(x);i>=0;i--)
#define RFOR(i,c) for(__typeof((c).rbegin())i=(c).rbegin();i!=(c).rend();++i)

class Jaccard{
	public:
	map<int, int> Q, T;
	int n, m, q; //n = |T|, m = |T and Q|
	Jaccard(map<int, int> qts){
		Q = qts;
		n=0;m=0;q=0;
		FOR(it, qts) q += it->second;
	}
	
	void add(int s){
		if(Q[s] > T[s]) m ++;
		T[s] ++;
		n ++;
	}
	void sub(int s){
		if(T.count(s) == 0){
			printf("%d is not found.\n", s);
			return ;
		}
		if(Q.count(s) && Q[s] >= T[s]) m --;
		T[s] --;
		n --;
		if(T[s] == 0) T.erase(s);
	}
	double get(){
		return (double)m / (q + n - m);
	}
};


main(){
	string n;
	int m;
	cin >> n;
	vector<int> x(n.size()+1, 0), y(n.size()+1, 0), z(n.size()+1, 0);
	REP(i, n.size()){
		x[i+1] = x[i];
		y[i+1] = y[i];
		z[i+1] = z[i];
		if(n[i] == 'x') x[i+1] ++;
		if(n[i] == 'y') y[i+1] ++;
		if(n[i] == 'z') z[i+1] ++;
	}
	cin >> m;
	REP(i, m){
		int l,r;
		cin >> l >> r;
		if(r-l+1 <= 2) cout << "YES" << endl;
			else{
			int X = x[r] - x[l-1];
			int Y = y[r] - y[l-1];
			int Z = z[r] - z[l-1];
			if(abs(X-Y)<=1 && abs(Z-Y)<=1 && abs(X-Z)<=1) cout << "YES" << endl;
			else cout << "NO" << endl;
		}
	}
	return 0;
}