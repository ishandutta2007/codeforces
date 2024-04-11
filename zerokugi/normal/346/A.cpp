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


int n;

int gcd(int a,int b){
	return b>0?gcd(b,a%b):a;
}

main(){
	while(cin >> n){
		int Max=0;
		int Gcd=0;
		for(int i=0;i<n;i++){
			int x;
			cin >> x;
			Max = max(x, Max);
			if(!Gcd) Gcd = x;
			else Gcd = gcd(x, Gcd);
		}
		cout << ((Max/Gcd-n)%2?"Alice":"Bob") << endl;
	}
	return 0;
}