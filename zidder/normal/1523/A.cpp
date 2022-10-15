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
    string s;
    cin >> s;
    
    set<int> ones;
    for (int i=0;i<n;++i)
        if (s[i] == '1')
            ones.insert(i);
    if (!ones.empty())
    for (int i=0;i<n;++i) {
        auto p = ones.lower_bound(i);
        auto p1 = p;
        if (p == ones.begin()){
            if ((*p) - i <= m)
                s[i] = '1';
            continue;
        }
        p1--;
        if (p == ones.end()){
            if (i - (*p1) <= m)
                s[i] = '1';
            continue;
        }
        if ((*p) - i <= m || i - (*p1) <= m){
            if ((*p) - i == i - (*p1))
                continue;
            s[i] = '1';
        }
    }
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