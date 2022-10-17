#include <bits/stdc++.h>                                                                                                                                                                                      //YaLoh

#define f first 
#define s second 
#define pb push_back               
#define mp make_pair 

using namespace std;                    

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int N = (int)1e5 + 123, inf = 1e9;
const ll INF = 1e18;

int main(){
	int a, b, c;
	cin >> a >> b >> c;
	cout << min(a, min(b - 1, c - 2)) * 3 + 3;
	return 0;
}