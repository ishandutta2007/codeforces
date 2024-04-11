#include <bits/stdc++.h>

#define f first
#define s second
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int N = (int)2e5 + 123, inf = 1e9, mod = 1e9 + 7;
const ll INF = 1e18;

int n, a[4][4];
int main()
{                   
	a[0][0] = 8;
	a[0][1] = 3;	
	a[0][2] = 0;	
	a[0][3] = 6;	
	a[1][0] = 9;
	a[1][1] = 12;	
	a[1][2] = 2;	
	a[1][3] = 10;	
	a[2][0] = 1;
	a[2][1] = 7;	
	a[2][2] = 4;	
	a[2][3] = 15;	
	a[3][0] = 13;
	a[3][1] = 5;	
	a[3][2] = 11;	
	a[3][3] = 14;
		
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++)
			printf("%d ", a[i & 3][j & 3] + 16 * (i / 4 * n / 4+ j / 4));
		printf("\n");
	}
	return 0;
}