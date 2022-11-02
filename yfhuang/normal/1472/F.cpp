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

int t;
int n, m;

const int maxn = 2e5 + 5;
pi b[maxn];

bool check(int s1, int e1, int s2, int e2){
    if(s1 == s2){
        if(e1 == e2)
            return true;
        else
            return false;
    }else{
        if((e1 - s1 + 1) % 2 == 0 and (e2 - s2 + 1) % 2 == 0)
            return true;
        else
            return false;
    }
}

pi c[maxn];

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n >> m;
        for(int i = 1;i <= m;i++){
            cin >> b[i].se >> b[i].fi;
        }
        sort(b + 1, b + 1 + m);
        int l = 0;
        for(int i = 1;i <= m;i++){
            if(i + 1 <= m and b[i].fi == b[i + 1].fi){
                c[++l] = mp(b[i].fi, 3);
                i++;
            }else{
                c[++l] = b[i];
            }
        }
        c[0] = mp(0, 3);
        c[++l] = mp(n + 1, 3);
        int s1 = 1, s2 = 1;
        bool flag = true;
        for(int i = 0;i < l;i++){
            if(c[i + 1].se == 3){
                if(!check(s1, c[i + 1].fi - 1, s2, c[i + 1].fi - 1))
                   flag = false; 
            }else if(c[i + 1].se == 1){
                if(!check(s1, c[i + 1].fi - 1, s2, c[i + 1].fi - 1)){
                    if(!check(s1, c[i + 1].fi - 1, s2, c[i + 1].fi)){
                        flag = false;
                    }else{
                        s1 = c[i + 1].fi + 1;
                        s2 = c[i + 1].fi + 1;
                    } 
                }else{
                    s1 = c[i + 1].fi + 1;
                    s2 = c[i + 1].fi;
                }
            }else{
                if(!check(s1, c[i + 1].fi - 1, s2, c[i + 1].fi - 1)){
                    if(!check(s1, c[i + 1].fi, s2, c[i + 1].fi - 1)){
                        flag = false;
                    }else{
                        s1 = c[i + 1].fi + 1;
                        s2 = c[i + 1].fi + 1;
                    } 
                }else{
                    s1 = c[i + 1].fi;
                    s2 = c[i + 1].fi + 1;
                }
            }
        }
        if(flag){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
    }
    return 0;
}