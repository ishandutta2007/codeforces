#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

int Q;

int ask(int a, int b){
    while (Q == 0);
    Q--;
    cout << "? " << a << " " << b << endl;
    fflush(stdout);
    int x;
    cin >> x;
    return x;
}

void answer(int a) {
    cout << "! " << a << endl;
    fflush(stdout);
}

void solve(int test_ind){
	int n;
    cin >> n;
    int m = (1<<n);
    Q = (m*2+2) / 3;
    // 1 3 -> 
    //        0 -> eliminate 1, 3
    //        1 -> eliminate 2, 3
    //        2 -> eliminate 1, 4
    vector<int> p(m);
    for (int i=0;i<m;++i) p[i] = i + 1;
    while (n > 1) {
        vector<int> p1;
        for (int i=0;i<m;i+=4){
            int a = ask(p[i], p[i+2]);
            if (a == 0) {
                p1.push_back(p[i+1]);
                p1.push_back(p[i+3]);
            }
            if (a == 1) {
                p1.push_back(p[i]);
                p1.push_back(p[i+3]);
            }
            if (a == 2) {
                p1.push_back(p[i+2]);
                p1.push_back(p[i+1]);
            }
        }
        p = p1;
        n--;
        m /= 2;
    }
    answer(p[ask(p[0], p[1])-1]);
}

int main(){
	int t=1;
	cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}