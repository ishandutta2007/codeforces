#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

void solve(int test_ind){
	int n, m;
	cin >> n >> m;
	vector<int> a(n);
	for (int &i: a) scanf("%d", &i);
	int s = 0;
	for (int i: a) s += i;
	s -= m;
	s = max(s, 0);
	cout << s << endl;	
}

int main(){
	int t=1;
	cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}