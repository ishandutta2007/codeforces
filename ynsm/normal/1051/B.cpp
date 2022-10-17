//BOOOOOOOOOOOOM 
#include <bits/stdc++.h>

#define f first 
#define s second 
#define pb push_back               
#define mp make_pair 

using namespace std;                    

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int N = (int)1e5 + 123, mod = (int)1e9 + 7, inf = (int)1e9;

int main(){    
    ll l,r;
    cin >> l >> r;
    cout << "YES" << endl;
    for(ll i = l; i <= r; i+=2)
    	cout << i << " " << i + 1 << endl;
	return 0;
}