#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>

using namespace std;

typedef pair<int, int> P;

map <int, P> mp;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int q;
    cin >> q;
    for(int dummy = 0; dummy < q; dummy++){
        int n;
        cin >> n;
        for(int i = 0; i < n; i++){
            int a;
            cin >> a;
            if(mp.count(a) == 0){
                mp[a] = P(i, i);
            }else{
                mp[a].second = i;
            }
        }
        int tmp = 1;
        int cnt_max = 1;
        auto ptr = mp.begin();
        P prev = ptr->second;
        ptr++;
        int unique = 1;
        for(auto iter = ptr; iter != mp.end(); iter++){
            P p = iter->second;
            unique++;
            if(prev.second < p.first){
                tmp++;
            }else{
                cnt_max = max(cnt_max, tmp);
                tmp = 1;
            }
            prev = p;
        }
        cnt_max = max(cnt_max, tmp);
        cout << unique-cnt_max << endl;
        mp.clear();
    }
}