#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cstring>
#include <string>
#include <cstdlib>
#include <cstdio>
using namespace std;
typedef pair<int, int> pii;
typedef long long int ll;
#define REP(i,x) for(int i=0;i<(int)(x);i++)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define RREP(i,x) for(int i=(x);i>=0;i--)
#define RFOR(i,c) for(__typeof((c).rbegin())i=(c).rbegin();i!=(c).rend();++i)

int n;
main(){
	int i,j;
	while(cin >> n){
		vector<int> arr(n)	;
		REP(i, n) cin >> arr[i];
		sort(arr.begin(), arr.end());
		int j = (n+1)/2;
		int ans = 0;
		for(int i=0;i<(n+1)/2;i++){
			while(j < n && arr[i]*2 > arr[j]) j++;
			if(j < n){
				ans ++;
				j ++;
			}else break;
		}
		cout << n-ans << endl;
	}
	return 0;
}