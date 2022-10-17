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

int n, s, a[N], b[N];
int main(){
	cin >> n >> s;  
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	for(int i = 1; i <= n; i++)
		cin >> b[i];
	if(a[1] && a[s]){
		cout << "YES";
		return 0;
	}

	for(int i = s; i <= n; i++)
		if(b[s] && b[i] && a[i] && a[1]){
			cout << "YES";
			return 0;
		}	
	cout << "NO";
	return 0;
}