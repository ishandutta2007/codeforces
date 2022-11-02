#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <string>
#include <cstdlib>
#include <cstdio>
using namespace std;
typedef long long int ll;

int n;
main(){
	int i,j;
	while(cin >> n){
		int five=0,zero=0;
		while(n--){
			int x;
			cin >> x;
			if(!x) zero++;
			else five++;
		}
		if(!zero) cout << -1 << endl;
		else if(five<9) cout << 0 << endl;
		else cout << string(five-five%9, '5') << string(zero, '0') << endl;
	}
	return 0;
}