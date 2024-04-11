#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <queue>
#include <set>
#include <map>

using namespace std;
typedef long long ll;
int n, k;
string s;
vector<int> v[2];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    cin >> n >> k;
    cin >> s;
    v[0].push_back(-1);
    v[1].push_back(-1);
    for(int i = 0; i < n; i++) {
        char c = s[i];
        v[c-'0'].push_back(i);
    }
    v[0].push_back(n);
    v[1].push_back(n);
    bool draw = false;
    for(int i = 0; i+k-1 < n; i++){
        int l = i, r = i+k-1;
        // 0
        {
            int s = v[1].size();
            auto pl = lower_bound(v[1].begin(), v[1].end(), l);
            pl--;
            auto pr = upper_bound(v[1].begin(), v[1].end(), r);
            if(*pl == -1 && *pr == n){
                cout << "tokitsukaze" << endl;
                return 0;
            }
            int dif;
            if(*pl == -1){
                dif = v[1][s-2]-*pr;
            }else if(*pr == n){
                dif = *pl-v[1][1];
            }else{
                dif = *pr-*pl;
            }
            // cout << *pl << ' ' << *pr << ' ' << dif << endl;
            if(dif >= k) draw = true;
        }
        // 1
        {
            int s = v[0].size();
            auto pl = lower_bound(v[0].begin(), v[0].end(), l);
            pl--;
            auto pr = upper_bound(v[0].begin(), v[0].end(), r);
            if(*pl == -1 && *pr == n){
                cout << "tokitsukaze" << endl;
                return 0;
            }
            int dif;
            if(*pl == -1){
                dif = v[0][s-2]-*pr;
            }else if(*pr == n){
                dif = *pl-v[0][1];
            }else{
                dif = *pr-*pl;
            }
            // cout << l << ' ' << r <<  ' ' << *pl << ' ' << *pr << ' ' << dif << endl;
            if(dif >= k) draw = true;
        }
    }
    if(draw){
        cout << "once again" << endl;
    }else{
        cout << "quailty" << endl;
    }
}