#include <cstdio>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <climits>
#include <queue>
#include <stack>
#include <algorithm>
#include <list>
#include <vector>
#include <set>
#include <map>
#include <iostream>
#include <deque>
#include <complex>
#include <string>
#include <iomanip>
#include <sstream>
#include <bitset>
#include <valarray>
#include <iterator>
using namespace std;
typedef long long int lli;
typedef unsigned int uint;
typedef unsigned char uchar;
typedef unsigned long long ull;

#define REP(i,x) for(int i=0;i<(int)(x);i++)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();i++)
#define RREP(i,x) for(int i=(x);i>=0;i--)
#define RFOR(i,c) for(__typeof((c).rbegin())i=(c).rbegin();i!=(c).rend();i++)


lli a,b;

main(){
	int i,j;
	while(cin >> a >> b){
		lli ans=0;
		while(a&&b){
			if(a>=b){
				ans += a/b;
				a%=b;
			}else{
				if(b/a==1){
					ans ++;
					b = b-a;
				}else{
					ans += b/a-1;
					b -= (b/a-1) * a;
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}