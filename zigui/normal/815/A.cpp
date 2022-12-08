#include<stdio.h>
#include<assert.h>
#include<vector>
#include<string.h>
#include<algorithm>
#include<memory.h>
#include<cmath>
#include<string>
#include<iostream>
#include<set>
#include<unordered_set>
#include<map>
#include<queue>
#include<functional>
#include<list>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<double, double> pdd;
typedef tuple<int,int,int> t3;

const int MX = 105;
const int MM = 1000000007;

int A[MX], B[MX], D[MX][MX];

vector<string> L;
bool ans = 0;
int main()
{
	int N, M, r = -1;
	scanf("%d%d", &N, &M);
	for(int i = 1; i <= N; i++){
		for(int j = 1; j <= M; j++) scanf("%d", D[i] + j);
	}
	int mn = 1e9;
	for(int i = 0; i <= 500; i++){
		A[1] = i;
		for(int j = 1; j <= M; j++) B[j] = D[1][j] - A[1];
		for(int j = 2; j <= N; j++) A[j] = D[j][1] - B[1];

		int ch = 1, tot = 0;
		for(int j = 1; j <= N; j++){
			if( A[j] < 0 ) ch = 0;
			tot += A[j];
		}
		for(int j = 1; j <= M; j++){
			if( B[j] < 0 ) ch = 0;
			tot += B[j];
		}
		for(int j = 1; j <= N; j++){
			for(int k = 1; k <= M; k++){
				if( A[j] + B[k] != D[j][k] ) ch = 0;
			}
		}
		if( ch && mn > tot) mn = tot, r = i;
	}
	if( r == -1 ) return !printf("-1\n");
	printf("%d\n", mn);
	for(int i = r; i <= r; i++){
		A[1] = i;
		for(int j = 1; j <= M; j++) B[j] = D[1][j] - A[1];
		for(int j = 2; j <= N; j++) A[j] = D[j][1] - B[1];

		int ch = 1, tot = 0;
		for(int j = 1; j <= N; j++){
			if( A[j] < 0 ) ch = 0;
		}
		for(int j = 1; j <= M; j++){
			if( B[j] < 0 ) ch = 0;
		}
		for(int j = 1; j <= N; j++){
			for(int k = 1; k <= M; k++){
				if( A[j] + B[k] != D[j][k] ) ch = 0;
			}
		}
			for(int i = 1; i <= N; i++){
				for(int j = 1; j <= A[i]; j++){
					printf("row %d\n", i);
				}
			}
			for(int i = 1; i <= M; i++){
				for(int j = 1; j <= B[i]; j++){
					printf("col %d\n", i);
				}
			}
	}
}