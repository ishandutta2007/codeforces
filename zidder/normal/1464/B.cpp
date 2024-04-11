#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;
long long s1(string s, long long x, long long y){
    long long ans = 0;
    long long c1 = 0, c0=0, cq=0;
    long long a1 = 0;
    for (int i=0;i<s.size();++i){
        if (s[i] == '1'){
            c1++;
            ans += c0 * x;
        }
        if (s[i] == '0'){
            c0++;
            ans += c1 * y;
            a1 += cq * y;
        }
        if (s[i] == '?'){
            cq++;
            a1 += c0 * x;
        }
    }

    long long pc1 = 0, pc0 = 0;
    long long a0 = a1;
    c1 += cq;
    for (int i=0;i<s.size();++i){
        // ans + c1 * x + pc1 * (y - x)
        // ans + c0 * y + constp * (x-y) + pc1 * (y - x)
        // pc0 + pc1 = const
        // c0 + c1 = const
        if (s[i] == '1'){
            pc1++;
            continue;
        }
        if (s[i] == '0'){
            pc0++;
            continue;
        }
        c1--;
        a1 += pc1 * y - pc0 * x;
        a1 += (c1 - pc1) * x - (c0 - pc0) * y;
        pc0++;
        c0++;
        a0 = min(a0, a1);
    }
    return ans + a0;
}
void solve(int test_ind){
    string s;
    cin >> s;
    long long x, y;
    cin >> x >> y;
    long long ans = s1(s, x, y);
    swap(x, y);
    reverse(s.begin(), s.end());
    ans = min(s1(s, x, y), ans);
    cout << ans << endl;

    // _0 a0 a1 _1 b0 b1 _0
    // a1 * x + a0 * x ... a0 * y + a1 * y
    // x < y
}

int main(){
	int t=1;
	//cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}