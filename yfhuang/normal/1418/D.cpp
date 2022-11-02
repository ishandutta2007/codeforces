#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <cassert>
using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eb emplace_back
typedef long long ll;
typedef pair<int, int> pi;

int n, q;
const int maxn = 1e5 + 5;
int p[maxn];
set<int> s;
set<pi> interval;
multiset<int> len;

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> q;
    for(int i = 1;i <= n;i++){
        cin >> p[i];
        s.insert(p[i]);
    }
    sort(p + 1, p + 1 + n);
    for(int i = 1;i < n;i++){
        interval.insert(mp(p[i], p[i+1]));
        len.insert(p[i+1]-p[i]);
    }
    if(s.size() <= 1){
        cout << 0 << endl;
    }else{
        cout << ((*s.rbegin()) - (*s.begin())) - (*len.rbegin()) << endl;
    }
    for(int i = 1;i <= q;i++){
        int t, x;
        cin >> t >> x;
        if(t == 0){
            auto it = s.find(x);
            auto it1 = it;
            if(s.size() == 1){
                s.erase(it);
            }else{
                it1++;
                int y = -1, z = -1;
                if(it1 != s.end()){
                    y =  *it1; 
                    interval.erase(mp(x, y));
                    auto it3 = len.find(y - x);
                    len.erase(it3);
                }
                if(it != s.begin()){
                    auto it2 = it;
                    it2--;
                    z = *it2;
                    interval.erase(mp(z, x));
                    auto it3 = len.find(x - z);
                    len.erase(it3);
                }
                if(y != -1 and z != -1){
                    interval.insert(mp(z, y));
                    len.insert(y - z);
                }
                s.erase(it);
            }
        }else{
            if(s.size() == 0){
                s.insert(x); 
            }else{
                auto it = s.lower_bound(x);
                int y = -1, z = -1;
                if(it != s.end() and it != s.begin()){
                    auto it1 = it, it2 = it;
                    it2--; 
                    y = *it1;
                    z = *it2;
                    interval.erase(mp(z, y));
                    auto it3 = len.find(y - z);
                    len.erase(it3);
                    interval.insert(mp(z, x));
                    len.insert(x-z);
                    interval.insert(mp(x, y));
                    len.insert(y-x);
                    s.insert(x);
                }else if(it == s.end()){
                    auto it1 = it;
                    it1--;
                    z = *it1;
                    interval.insert(mp(z, x));
                    len.insert(x-z);
                    s.insert(x);
                }else if(it == s.begin()){
                    auto it1 = it;
                    y = *it1;
                    interval.insert(mp(x, y));
                    len.insert(y-x);
                    s.insert(x);
                }
            }
        }
        if(s.size() <= 1){
            cout << 0 << endl;
        }else{
            cout << ((*s.rbegin()) - (*s.begin())) - (*len.rbegin()) << endl;
        }
    }
    return 0;
}