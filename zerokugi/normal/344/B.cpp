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


int a,b,c;

main(){
	int i,j;
	while(cin >> a >> b >> c){
		int x,y,z;
		x = b-c+a;
		y = c-a+b;
		z = a-b+c;
		if(x%2 || y%2 || z%2 || x<0 || y<0 || z<0) cout << "Impossible" << endl;
		else cout << x/2 << " " << y/2 << " " << z/2 << endl;
	}
	return 0;
}