// https://codeforces.com/problemset/problem/1618/F

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

bool revget(long long x, long long y){
    string sx = "", sy = "";
    long long x1 = x, y1=y;
    while (x1){
        sx = (x1%2 == 0 ? "0" : "1") + sx;
        x1 /= 2;
    }
    while (y1){
        sy = (y1%2 == 0 ? "0" : "1") + sy;
        y1 /= 2;
    }

    for (int i=0;i<=(int)sy.size()-(int)sx.size();++i){
        if (sy.substr(i, sx.size()) == sx){
            bool ok = true;
            for (int j=i + sx.size();j<(int)sy.size();++j){
                if (sy[j] != '1'){
                    ok = false;
                }
            }
            if (ok){
                return true;
            }
        }
        if (sy[i] != '1'){
            break;
        }
    }
    reverse(sx.begin(), sx.end());
    for (int i=0;i<=(int)sy.size()-(int)sx.size();++i){
        if (sy.substr(i, sx.size()) == sx){
            bool ok = true;
            for (int j=i + sx.size();j<(int)sy.size();++j){
                if (sy[j] != '1'){
                    ok = false;
                }
            }
            if (ok){
                return true;
            }
        }
        if (sy[i] != '1'){
            break;
        }
    }
    return false;
}
bool get(long long x, long long y){
    // 10100100
    // 11010010011
    if (y%2 == 0){
        return x == y;
    }
    if (revget(x * 2 + 1, y)){
        return true;
    }
    while (x % 2 == 0) x/= 2;
    return revget(x, y);
}

void solve(int test_ind){
	long long x, y;
    cin >> x >> y;
    if (get(x, y)){
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}

int main(){
	int t=1;
	//cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}