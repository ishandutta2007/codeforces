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
    // 0 1 1 0 0 1
    // 1 0 0 1 1 0
    for (int i=0;i<n;++i) {
        for (int j=0;j<m;++j) {
            printf("%d ", (i + j + (i/2+j/2)%2)%2);
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