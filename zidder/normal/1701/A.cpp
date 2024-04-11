#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

void solve(int test_ind){
	vector<int> a(4);
    for (int &i: a) scanf("%d", &i);
    int s = 0;
    for (int i: a) s += i;
    cout << (s + 2) / 3 << endl;
}

int main(){
	int t=1;
	cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}