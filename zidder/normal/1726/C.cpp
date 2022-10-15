#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

void solve(int test_ind){
	int n;
    cin >> n;
    string s;
    cin >> s;
    int c = 0;
    for (int i=0;i<2*n-1;++i) if (s[i] == ')' && s[i+1] == '(') c++;
    for (int i=0;i<2*n;++i) if (s[i] == ')') c++;
    cout << 2 * n - c << endl;
}

int main(){
	int t=1;
	cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}