#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

void solve(int test_ind){
	int a, b;
	cin >> a >> b;
	if (a > 3){
		cout << "Yes\n";
		return;
	}
	if (a == 2)
		a = 3;
	if (a>=b)
		cout << "Yes\n";
	else
		cout << "No\n";
}

int main(){
	int t=1;
	cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}