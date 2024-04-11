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
    vector<int> a(n);
    for (int i=0;i<n;++i) scanf("%d", &a[i]);
    const int MAX = 1000000000;
    int minc = MAX;
    for (int _2=0;_2<5;_2++){
        for (int _1=0;_1<5;_1++){
            int c = _1 + _2;
            int _3 = 0;
            for (int i=0;i<n;++i){
                int q = MAX;
                if (a[i] == 1 && _1 == 0) q = MAX;
                else if (a[i] == 2 && _2 < 1 && _1 < 2) q = MAX;
                else {
                    for (int __2=0;__2<=_2;++__2){
                        for (int __1=0;__1<=_1;__1++){
                            int d = a[i] - __1 - 2*__2;
                            if (d >= 0 && d%3==0){
                                q = min(q, d/3);
                            }
                        }
                    }
                }
                _3 = max(_3, q);
            }
            minc = min(minc, c + _3);
        }
    }
    cout << minc << endl;
}

int main(){
	int t=1;
	cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}