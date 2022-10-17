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

int n, a[N], b[N], x[N], y[N];
map< int, map<int, int> > was;
void check(int x, int y){
	for(int i = 1; i <= n; i++)
		if(!was[x - a[i]][y - b[i]])
			return;
	cout << x << " " << y << endl;
	exit(0);
}
int main(){
	cin >> n;               
	for(int i = 1; i <= n; i++)
		cin >> a[i] >> b[i];
	for(int i = 1; i <= n; i++){
		cin >> x[i] >> y[i];
		was[x[i]][y[i]] = 1;
	}
	for(int i = 1; i <= n; i++)
		check(a[1] + x[i], b[1] + y[i]);
}