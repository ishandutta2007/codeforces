#include<stdio.h>
#include<iostream>
#include<map>
#include<algorithm>
#include<string.h>
#include<vector>
#include<math.h>
#include<stdlib.h>
#include<set>
#include<string>
#include<ctype.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const int MM = 1000000007;
const int MX = 1005;

char D[MX][MX];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int main()
{
	int N, M;
	scanf("%d%d", &N, &M);
	for(int i = 0; i < N; i++) scanf("%s", D[i]);
	
	pii st, en;
	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			if( D[i][j] == 'S' ) st = pii(i, j);
			if( D[i][j] == 'E' ) en = pii(i, j);
		}
	}
	string X;
	cin >> X;

	int O[4] = {0, 1, 2, 3};
	int ans = 0;
	do{
		pii cur = st;
		int ch = 1;
		for(char c : X){
			int dir = O[c-'0'];
			pii d = pii(cur.first + dx[dir], cur.second + dy[dir]);
			if( d.first < 0 || d.first >= N || d.second < 0 || d.second >= M || D[d.first][d.second] == '#' ) ch = 0;
			cur = d;
			if( cur == en ) break;
		}
		if( cur != en ) ch = 0;
		ans += ch;
	}while(next_permutation(O, O+4));
	printf("%d\n", ans);
}