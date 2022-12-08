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

ll pw(ll a, ll b = MM-2){
	ll r = 1;
	while(b){
		if(b&1) r = r*a % MM;
		a = a*a%MM; b /= 2;
	}
	return r;
}

struct UF{
	int t[MX], cnt[MX];
	int find(int x){
		return t[x] ? t[x] = find(t[x]) : x;
	}
	int merge(int a, int b){
		a = find(a), b = find(b);
		if( a == b ) return 0;
		cnt[a] += cnt[b]; t[b] = a;
		return 1;
	}
}uf;

ll T[MX][MX], U[MX];
char D[MX][MX];

int main()
{
	int N, M;
	scanf("%d%d", &M, &N);
	for(int i = 1; i <= M; i++) uf.cnt[i] = 1;
	for(int i = 1; i <= N; i++) scanf("%s", D[i]+1);
	N++; for(int j = 1; j <= M; j++) D[N][j] = '1';
	for(int i = 1; i <= M; i++){
		for(int j = i+1; j <= M; j++){
			int ch = 0;
			for(int k = 1; k <= N; k++){
				if( D[k][i] == D[k][j] ) ch |= 1;
				if( D[k][i] != D[k][j] ) ch |= 2;
			}
			if( ch == 1 ) uf.merge(i, j);
		}
	}

	T[1][1] = 1;
	for(int i = 1; i <= M; i++){
		for(int j = 1; j <= M; j++){
			T[i+1][j] = (T[i+1][j] + T[i][j] * j) % MM;
			T[i+1][j+1] = (T[i+1][j+1] + T[i][j]) % MM;
			U[i] = (U[i] + T[i][j]) % MM;
		}
	}
	ll ans = 1;
	for(int i = 1; i <= M; i++){
		if( uf.find(i) == i ) ans = ans * U[uf.cnt[i]] % MM;
	}
	printf("%lld\n", ans);
}