#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

void solve(int test_ind){
    string s;
    cin >> s;
    int ans = 0;
    int numa = 0, numb = 0;

    for(int i=s.size()-1;i>=0;--i){
        if (s[i]=='A'){
            if (numb)numb--;
            else ans++;
        } else {
            numb++;
        }
    }
    cout << ans + numb%2 << endl;
}

int main(){
	int t=1;
	cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}