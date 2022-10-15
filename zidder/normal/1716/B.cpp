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
    vector<vector<int> > a(n);
    for (int i=0;i<n;++i) a[0].push_back(i+1);
    for (int i=1;i<n;++i){
        a[i] = a[i-1];
        swap(a[i][i], a[i][i-1]);
    }
    cout << a.size() << endl;
    for (int i=0;i<a.size();++i){
        for (int j: a[i]) {
            printf("%d ", j);
        }
        printf("\n");
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