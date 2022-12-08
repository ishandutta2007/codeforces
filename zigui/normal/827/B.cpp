#include<stdio.h>
#include<string>
#include<map>
#include<cmath>
#include<set>
#include<vector>
#include<algorithm>

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

const int MM = 1000000007;
const int MX = 2000005;

string D[MX];
vector<int> E[MX];
char buf[MX];

int main()
{
	int N, K;
	scanf("%d%d", &N, &K);
	int d = (N-1-K)%K, e = K-d;
	int a = (N-1-K)/K + 1, b = a-1;
	if( d == 0 ) printf("%d\n", b*2+2);
	else if( d == 1 ) printf("%d\n", b*2+3);
	else printf("%d\n", b*2+4);
	int t = 1;
	for(int i = 0; i < d; i++){
		printf("%d %d\n", 1, ++t);
		for(int j = 1; j <= a; j++){
			printf("%d %d\n", t, t+1);
			t++;
		}
	}
	for(int i = 0; i < e; i++){
		printf("%d %d\n", 1, ++t);
		for(int j = 1; j <= b; j++){
			printf("%d %d\n", t, t+1);
			t++;
		}
	}
}