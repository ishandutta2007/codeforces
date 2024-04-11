#include<math.h>
#include<set>
#include<queue>
#include<memory.h>
#include<algorithm>
#include<map>
#include<iostream>
#include<string>
#include<functional>
#include<tuple>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef tuple<int,int,int> t3;

const int MX = 1005;
const int MM = 1000000007;

int D1[] = {1, 2, 7, 3, 6, 11}; 
int D2[] = {2, 7, 3, 6};
int main()
{
	int N;
	scanf("%d", &N);
	if( N%4 >= 2 ) return !printf("NO\n");
	printf("YES\n");
	vector<pii> L;
	for(int i = N%4 == 0? N-3 : N-4; i >= 1; i -= 4){
		for(int j = i+4; j+1 <= N; j+=2){
			L.emplace_back(i, j);
			L.emplace_back(i+1, j+1);
			L.emplace_back(i, j+1);
			L.emplace_back(i+1, j);
			L.emplace_back(i+2, j);
			L.emplace_back(i+3, j+1);
			L.emplace_back(i+2, j+1);
			L.emplace_back(i+3, j);
		}
		if( N%4 == 1 ){
			for(int j = i; j <= i+3; j+=2){
				L.emplace_back(j, N);
				L.emplace_back(j, j+1);
				L.emplace_back(j+1, N);
			}

			for(int t = 0; t < 4; t++){
				L.emplace_back(i+D2[t]/4, i+D2[t]%4);
			}
		}
		else{
			for(int t = 0; t < 6; t++){
				L.emplace_back(i+D1[t]/4, i+D1[t]%4);
			}
		}
	}
	int X[1005] = {};
	for(int i = 1; i <= N; i++) X[i] = i;
	set<pii> P;
	for(pii &c : L){
		if( c.first > c.second ) swap(c.first, c.second);
		swap(X[c.first], X[c.second]);
		printf("%d %d\n", c.first, c.second);
		P.insert(c);
	}
}