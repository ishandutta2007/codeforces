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
    bool ok = true;
    vector<vector<int> > v(n, vector<int>(m));
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            cin >> v[i][j];
            int cnt = 0;
            if (i)
                cnt++;
            if (j)
                cnt++;
            if (i+1<n)
                cnt++;
            if (j+1<m)
                cnt++;
            if (v[i][j] > cnt)
                ok=false;
            v[i][j] = cnt;
        }
    }
    if (!ok){
        cout << "NO"<<endl;
        return;
    }
    cout << "YES" << endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)
            cout << v[i][j] << " ";
        cout << endl;
    }
}

int main(){
	int t=1;
    cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}