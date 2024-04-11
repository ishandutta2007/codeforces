#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

void solve(int test_ind){
    int n, k;
    cin >> n >> k;
    long long a12, a13, a23, o12, o13, o23;
    cout << "and 1 2" << endl;
    fflush(stdout);
    cin >> a12;
    cout << "or 1 2" << endl;
    fflush(stdout);	
    cin >> o12;
    cout << "and 1 3" << endl;
    fflush(stdout);
    cin >> a13;
    cout << "or 1 3" << endl;
    fflush(stdout);	
    cin >> o13;
    cout << "and 3 2" << endl;
    fflush(stdout);
    cin >> a23;
    cout << "or 3 2" << endl;
    fflush(stdout);	
    cin >> o23;

    long long a1 = 0, a2 = 0, a3 = 0;
    a1 |= a12;
    a2 |= a12;
    a1 |= a13;
    a2 |= a23;
    a3 |= a13;
    a3 |= a23;
    
    long long o123 = o12 | o13;
    
    a3 |= o123 ^ o12;
    a1 |= o123 ^ o23;
    a2 |= o123 ^ o13;
    
    vector<long long> a(n);
    a[0] = a1;
    a[1] = a2;
    a[2] = a3;

    for (int i=3;i<n;++i){
        cout << "and " << i + 1 << " " << 1 << endl;
        fflush(stdout);
        long long an, o;
        cin >> an;
        cout << "or " << i + 1 << " 1" << endl;
        fflush(stdout);
        cin >> o;

        a[i] = an | (o ^ a[0]);
    }
    sort(a.begin(), a.end());

    cout << "finish " << a[k-1] << endl;
    fflush(stdout);
}

int main(){
	int t=1;
	//cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}