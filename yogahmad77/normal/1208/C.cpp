#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define pb push_back
#define reset(a,b) memset(a,b,sizeof a);
#define ALL(x) x.begin(),x.end()
#define debug(x) cout<<#x<<" = "<<(x)<<endl
#define sz(x) (int)(x.size())
#define lt(x) (int)(x.length())
#define MOD 1000000007 
#define mx 100003
int a[1003][1003];
int main(){
	int n;
	cin >> n;
	int idx = -1;
	for(int i = 0; i < n; i += 4){
		for(int j = 0; j < n; j += 4){
			for(int x = 0 + i; x < 4 + i; x++){
				for(int y = 0 + j; y < 4 + j; y++){
					a[x][y] = ++idx;
				}
			}
		}
	}
	// set<int> ini;
	// for(int i = 0; i < n; i++){
	// 	int has = 0;
	// 	for(int j = 0; j < n; j++){
	// 		has ^= a[i][j];
	// 	}
	// 	ini.insert(has);
	// }
	// for(int i = 0; i < n; i++){
	// 	int has = 0;
	// 	for(int j = 0; j < n; j++){
	// 		has ^= a[j][i];
	// 	}
	// 	ini.insert(has);
	// }
	// debug(sz(ini));
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++)
			cout << a[i][j] << ' ';
		cout << '\n';
	}
}