#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

string s;

long long g(int m, int n){
    // m + m + m + ... + m + (m + 1) + ... + (n - 1) + n
    // m * n + 1 + ... + (n - m)
    return m * 1ll * n + (n - m) * 1ll * (n - m + 1) / 2;
}

long long f(int lft, int rgt){
    vector<pair<int, int> > qq;
    qq.emplace_back(lft, rgt);
    long long allans = 0;
    while(!qq.empty()){
        lft = qq.back().first;
        rgt = qq.back().second;
        qq.pop_back();
    if (lft >= rgt){
        continue;
    }
    long long n = rgt - lft;
    vector<long long> ones(n);
    for(int i=lft;i<rgt;++i){
        if (s[i] == '0')
            ones[i - lft] = 0;
        else{
            if (i == lft)
                ones[i - lft] = 1;
            else ones[i - lft] = ones[i - lft - 1] + 1;
        }
    }
    long long mx = 0;
    for (int i=n-1;i>=0;--i){
        if (ones[i] == 0)
            continue;
        mx = max(ones[i], mx);
    }
    if (mx == 0)
        continue;
    long long l = -1, r=0;
    for(int i=lft;i<rgt;++i){
        if (ones[i-lft] == mx){
            l = i - mx + 1;
            r = i + 1;
            break;
        }
    }
    long long ans = (l + 1 - lft) * (rgt - r + 1) * mx;
    for (int i=1;i<r-l;++i){
        ans += i * (r - l - i + 1);
    }
    if (l!=lft)
        ans += g(0, r-l-1); // l - 1
    if (r!=rgt)
        ans += g(0, r-l-1); // r

    long long one = 0;
    for(int i = l - 2; i >= lft; i--){ // s[l-1]=0
        if (ones[i-lft])
            one++;
        else
            one = 0;
        ones[i-lft] = max(one, ones[i - lft + 1]);
        ans += g(ones[i-lft], r - l - 1);
    }
    for(int i = r + 1; i < rgt; i++){ // s[r] = 0
        ones[i-lft] = max(ones[i-lft], ones[i - 1-lft]);
        ans += g(ones[i-lft], r - l - 1);
    }
    allans += ans;
    qq.emplace_back(lft, l);
    qq.emplace_back(r, rgt);
    }
    return allans;
}

void solve(int test_ind){
    int n;
    cin >> n;
    cin >> s;
    cout << f(0, n);
}

int main(){
	int t=1;
	//cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}