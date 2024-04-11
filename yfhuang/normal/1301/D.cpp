#include <cstdio>
#include <algorithm>
#include <cstring>
#include <set>
#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <map>
#include <cmath>
#include <queue>

using namespace std;

typedef long long LL;
LL n, m;
LL k;

string S = "RUD";

int main(){
    cin >> n >> m >> k;
    LL num = 4 * m * n - 2 * n - 2 * m;
    if(num >= k){
        cout << "YES" << endl;
        vector<pair<int, string> > ans;
        LL step = 0;
        if(true){
            int x = min(m - 1, k - step);
            string s = "R";
            if(x != 0)
                ans.push_back(make_pair(x, s));
            step += x;
        }
        if(true){
            int x = min(m - 1, k - step);
            string s = "L";
            if(x != 0)
                ans.push_back(make_pair(x, s));
            step += x;
        } 
        for(int i = 2;i <= n;i++){
            if(true){
                int x = min(1LL, k - step);
                string s = "D";
                if(x != 0)
                    ans.push_back(make_pair(x, s));
                step += x;
            } 
            if(true){
                int x = min(3 * (m - 1), k - step);
                x /= 3;
                string s = "RUD";
                if(x != 0)
                    ans.push_back(make_pair(x, s));
                step += x * 3;
                string s1 = "";
                if(x < (m - 1) and k - step < 3 and k - step > 0){
                    for(int i = 0;i < k - step;i++){
                        s1.push_back(S[i]);
                    }
                    ans.push_back(make_pair(1, s1));
                    step += k - step;
                }
            }
            if(true){
                int x = min(m - 1, k - step);
                string s = "L";
                if(x != 0)
                    ans.push_back(make_pair(x, s));
                step += x;
            } 
        }
        if(true){
            int x = min(n - 1, k - step);
            string s = "U";
            if(x != 0)
                ans.push_back(make_pair(x, s));
            step += x;
        }
        cout << ans.size() << endl;
        for(auto it : ans){
            if(it.first != 0)
                cout << it.first << " " << it.second << endl;
        }
    }else{
        cout << "NO" << endl;
    }
    return 0;
}