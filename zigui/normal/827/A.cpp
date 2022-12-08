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
	int N, M;
	scanf("%d", &N);
	for(int i = 1; i <= N; i++){
		scanf("%s", buf);
		D[i] = buf;
		int a, b;
		scanf("%d", &a);
		for(int j = 1; j <= a; j++){
			scanf("%d", &b);
			E[b].push_back(i);
			M = max(M, b + (int)D[i].size() - 1);
		}
	}
	string ans = "";
	int wi = -1, lst = 1, st = 0;
	for(int i = 1; i <= M; i++){
		for(int c : E[i]){
			if( i + D[c].size() >= lst) lst = i + D[c].size(), st = i, wi = c;
		}
		if( lst > i ) ans += D[wi][i-st];
		else ans += 'a';
	}
	printf("%s\n", ans.c_str());
}