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

int D[MX];
double Y[MX];
int N, R;

vector<int> T[MX];
int main()
{
	scanf("%d%d", &N, &R);
	for(int i = 1; i <= N; i++) scanf("%d", D+i);
	for(int i = 2; i <= N; i++){
		for(int j = i-1; j >= 1; j--){
			if( D[j]-2*R <= D[i] && D[i] <= D[j]+2*R ){
				T[j].push_back(i);
			}
		}
	}
	for(int i = 1; i <= N; i++) Y[i] = R;
	for(int x = 1; x <= N; x++){
		for(int c : T[x]){
			double dx = fabs(D[x] - D[c]);
			double dy = sqrt(max(0.0, 4.0*R*R - dx*dx));
			Y[c] = max(Y[x] + dy, Y[c]);
		}
	}
	for(int i = 1; i <= N; i++) printf("%.10lf ", Y[i]);
}