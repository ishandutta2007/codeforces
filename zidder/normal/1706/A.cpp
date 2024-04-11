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
    for (int &i: a) if (m + 1 - i < i) i = m + 1 - i;
    sort(a.begin(), a.end());
    string s = "";
    for (int i=0;i<m;++i) s += 'B';
    for (int i=0;i<n;++i) if (s[a[i]-1] == 'B') s[a[i]-1] = 'A'; else s[m-a[i]] = 'A';
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