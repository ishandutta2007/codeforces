#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

void solve(int test_ind){
    long long k;
    cin >> k;
    long long c = 1;
    int i, j;
    for (i=1;i<100;++i){
        long long c = (i * i * i * i * i);
        if (c * c >= k)
            break;
    }
    for (j=0;j<=10;j++){
        c = 1;
        for (int q=0;q<10;++q){
            if (q<j)
                c *= i;
            else
                c *= i - 1;
        }
        if (c >= k)
            break;
    }
    string ans = "codeforces";
    for (int q=0;q<10;q++){
        for(int w=0;w<i-1 + (q<j);++w){
            cout << ans[q];
        }
    }
    cout << endl;
}

int main(){
	int t=1;
	//cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}