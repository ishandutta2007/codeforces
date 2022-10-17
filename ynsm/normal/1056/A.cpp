#include <bits/stdc++.h>

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

int n, m, x, cnt[500];
int main(){
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> m;
		while(m--){
			cin >> x;
			cnt[x]++;
		}
	}
	for(int i = 0; i < 500; i++)
		if(cnt[i] == n)
			cout << i << " " ;
	return 0;
}