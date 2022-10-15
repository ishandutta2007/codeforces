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
    vector<int> v(n);
    for (int i=0;i<n;++i) cin >> v[i];
    
    int odd = 0;
    for (int i=0;i<n;++i) if (v[i]%2) odd++;
    int even = n - odd;
    long long a = -1;
    if (even >= odd && even <= odd+1){
        long long ind = 0, a1=0;
        for (int i=0;i<n;++i){
            if (v[i]%2==0){
                a1 += abs(i - ind);
                ind += 2;
            }
        }
        a = a1;
    }
    if (even >= odd-1 && even <= odd){
        long long ind = 0, a1=0;
        for (int i=0;i<n;++i){
            if (v[i]%2){
                a1 += abs(i - ind);
                ind += 2;
            }
        }
        if (a==-1 || a > a1)
            a = a1;
    }
    cout << a << endl;
}

int main(){
	int t=1;
	cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}