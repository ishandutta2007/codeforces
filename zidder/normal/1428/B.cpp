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
    string s, sf="";
    cin >> s;
    set<int> ret;
    for (int i=0;i<n;++i){
        int nxt = (i + 1) % n;
        if (s[i] == '-'){
            ret.insert(i);
            ret.insert(nxt);
        } else{
            sf += s[i];
        }
    }
    int d = n - ret.size();
    for (int i=0;i<sf.size();++i)
        if (sf[i] != sf[0])
            d = 0;
    cout << ret.size() + d << endl;
}

int main(){
	int t=1;
	cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}