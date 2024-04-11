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
    vector<int> c(31, 0);
    for(int i=0;i<n;i++){
        int x;
        scanf("%d", &x);
        for(int j=30;j>=0;j--){
            if((1<<j)&x)
                c[j]++;
        }
    }
    int q = -1;
    for (int j=30;j>=0;j--){
        if (c[j] % 2){
            q = c[j];
            break;
        }
    }
    if (q == -1){
        cout << "DRAW" << endl;
        return;
    }
    if (q%2 != (q/2)%2){
        cout << "WIN" << endl;
        return;
    }
    if ((n - q) % 2){
        cout << "WIN" << endl;
        return;
    }
    cout << "LOSE" << endl;
    return;
}

int main(){
	int t=1;
	cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}