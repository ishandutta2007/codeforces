#include<stdio.h>
#include<vector>
#include<cmath>
#include<algorithm>
#include<tuple>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef tuple<int,int,int> t3;
ll abs(ll x){ return x < 0? -x : x; }

pii operator-(const pii &l, const pii &r){
	return pii(l.first - r.first, l.second - r.second);
}

ll operator/(const pii &l, const pii &r){
	return (ll)l.first * r.second - (ll)l.second * r.first;
}

const int MX = 1000;
const int MM = 1000000007;

int N;
int G[MX][MX];

int main()
{
	scanf("%d", &N);
	if( N == 3){
		printf("2\n3 1 2 3\n3 1 2 3");
		return 0;
	}
	int ch = 0;
	if( N%2 == 1 ) ch = 1; N /= 2;
	vector<vector<int>> ans;
	for(int t = 1; t < N; t++){
		for(int i = 0; i < N; i++){
			vector<int> X = {i, (i+t)%N, i+N, (i+t)%N+N};
			if( !ch || ch && t != 1 ) ans.push_back(X);
		}
	}
	if( ch == 1 ){
		for(int i = 0; i < N; i++){
			vector<int> X = {i, (i+1)%N, i+N, 2*N};
			ans.push_back(X);
			vector<int> Y = {i, (i+1)%N+N, i+N, 2*N};
			ans.push_back(Y);
		}
	}

	for(auto c : ans){
		int b = -1;
		for(int d : c){
			if( b != -1 ) G[d][b]++, G[b][d]++;
			b = d;
		}
		G[c[0]][b]++, G[b][c[0]]++;
	}
	for(int i = 0; i < ans.size(); i++){
		if( ans[i].size() < 4 ) continue;
		int a = ans[i][0], b = ans[i][2], c = ans[i][1], d = ans[i][3];
		if( G[a][b] == 0 ){
			ans[i] = ans.back(); i--; ans.pop_back();
			ans.push_back({a, c, b});
			ans.push_back({a, d, b});
			G[a][b] = 2;
		}
	}
	N = N*2+ch;
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++) G[i][j] = 0;
	}
	printf("%d\n", ans.size());
	for(auto c : ans){
		printf("%d ", c.size());
		int b = -1;
		for(int d : c){
			printf("%d ", d+1);
			if( b != -1 ) G[d][b]++, G[b][d]++;
			b = d;
		}
		G[c[0]][b]++, G[b][c[0]]++;
		printf("\n");
	}
}