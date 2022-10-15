#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

void umin(int& a, int b, bool c=false){
    if (b == -1)
        return;
    if (a==-1 || a>b+c)
        a = b + c;
}

void solve(int test_ind){
    int n;
    cin >> n;
    int I0=-1, I1=-1, F0=0, F1=-1;
    for(int i=0;i<n;++i){
        int x;
        scanf("%d", &x);
        int i1=-1, i0=-1, f1=-1, f0=-1;
        umin(i1, F1, 0);
        umin(i0, F1, x);
        umin(f1, F0, x);
        umin(i1, I0, 0);
        umin(f0, I1, 0);
        umin(f1, I1, x);
        I1=i1;
        I0=i0;
        F1=f1;
        F0=f0;
    }
    int ans = -1;
    umin(ans, I0);
    umin(ans, I1);
    umin(ans, F0);
    umin(ans, F1);
    cout << ans << endl;
}

int main(){
	int t=1;
	cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}