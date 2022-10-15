#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

void solve(int test_ind){
    int a, b;
    cin >> a >> b;
    if (a%2!=b%2){
        cout << -1 << endl;
        return;
    }
    if (a == b && a== 0)
        cout << 0 << endl;
    else    
        cout<< (abs(a)==abs(b)?1:2)<<endl;
}

int main(){
	int t=1;
	cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}