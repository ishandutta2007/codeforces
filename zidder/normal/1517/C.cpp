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
    vector<vector<int> > v(n, vector<int>(n));
    for (int i=0;i<n;++i)
        cin >> v[i][i];
    for (int i=0;i<n;++i){
        int cnt = v[i][i];
        int y=i, x=i;
        for (int j=0;j<cnt;j++){
            v[y][x] = cnt;
            if (x && v[y][x-1] == 0){
                x--;
            } else{
                y++;
            }
        }
    }
    for (int i=0;i<n;++i){
        for (int j=0;j<=i;++j)
            cout << v[i][j] << " ";
        cout << endl;
    }
}

int main(){
	int t=1;
	//cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}