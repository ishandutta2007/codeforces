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
    string a, b;
    cin >> a >> b;
    vector<vector<int> > va(n, vector<int>(26, -1)), vb(m, vector<int>(26, -1));
    vector<vector<int> > ans(n, vector<int>(m));
    for(int i=n-2;i>=0;--i){
        for(int j=0;j<26;++j){
            va[i][j] = va[i+1][j];
        }
        va[i][a[i+1]-'a'] = i+1;
    }
    for(int i=m-2;i>=0;--i){
        for(int j=0;j<26;++j){
            vb[i][j] = vb[i+1][j];
        }
        vb[i][b[i+1]-'a'] = i+1;
    }

    int aans = 0;
    for(int i=n-1;i>=0;--i){
        for(int j=m-1;j>=0;--j){
            if (i+1<n)
                ans[i][j] = max(ans[i][j], ans[i+1][j] - 1);
            if (j+1<m)
                ans[i][j] = max(ans[i][j], ans[i][j+1] - 1);
            if (a[i] == b[j]){
                if (i+1 < n && j+1 < m)
                    ans[i][j] = max(ans[i][j], 2 + ans[i+1][j+1]);
                else
                    ans[i][j] = 2;
            }
            aans = max(aans, ans[i][j]);
        }
    }
    cout << aans << endl;
}

int main(){
	int t=1;
	//cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}