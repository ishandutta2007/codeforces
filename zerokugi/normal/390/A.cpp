#include <iostream>
#include <set>
#include <cstdio>
using namespace std;
typedef long long int ll;
#define REP(i,x) for(int i=0;i<(int)(x);i++)

main(){
	int n, x, y;
	scanf("%d", &n);
	set<int> X, Y;
	REP(i, n){
		scanf("%d%d", &x, &y);
		X.insert(x);Y.insert(y);
	}
	cout << min(X.size(), Y.size()) << endl;
	return 0;
}