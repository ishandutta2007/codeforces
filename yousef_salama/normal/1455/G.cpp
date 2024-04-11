#include <bits/stdc++.h>
using namespace std;

struct yasser{
    map <int, long long> mp;
    multiset <long long> s;
    long long shift;

    yasser(){}
};

int n, s;
vector <string> v;
vector < vector <int> > varg;
vector <int> match;

yasser solve(int l, int r, int init = 0){
    yasser y;
    y.mp[init] = 0;
    y.s.insert(0);
    y.shift = 0;

    for(int i = l; i <= r; ){
        if(v[i] == "if"){
            int j = match[i];
            if(y.mp.count(varg[i][0])){
                long long cost = y.mp[varg[i][0]] + y.shift;
                yasser yc = solve(i + 1, j - 1, varg[i][0]);
                yc.shift += cost;
                y.s.erase(y.s.lower_bound(y.mp[varg[i][0]]));
                y.mp.erase(varg[i][0]);

                if(yc.mp.size() > y.mp.size())swap(yc, y);

                for(auto z : yc.mp){
                    if(y.mp.count(z.first)){
                        if(z.second + yc.shift - y.shift < y.mp[z.first]){
                            y.s.erase(y.s.lower_bound(y.mp[z.first]));
                            y.mp[z.first] = z.second + yc.shift - y.shift;
                            y.s.insert(z.second + yc.shift - y.shift);
                        }
                    }else{
                        y.mp[z.first] = z.second + yc.shift - y.shift;
                        y.s.insert(z.second + yc.shift - y.shift);
                    }
                }
            }
            i = j + 1;
        }else{
            if(varg[i][0] == s){
                y.shift += varg[i][1];
            }else{
                long long x = (*y.s.begin()) + y.shift;
                y.shift += varg[i][1];
                if(y.mp.count(varg[i][0])){
                    if(x - y.shift < y.mp[varg[i][0]]){
                        y.s.erase(y.s.lower_bound(y.mp[varg[i][0]]));
                        y.mp[varg[i][0]] = x - y.shift;
                        y.s.insert(x - y.shift);
                    }
                }else{
                    y.mp[varg[i][0]] = x - y.shift;
                    y.s.insert(x - y.shift);
                }
            }
            i++;
        }
    }
    return y;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> s;
    
    stack <int> stk;
    match.resize(n, -1);

    for(int i = 0; i < n; i++){
        string cur;
        cin >> cur;
        v.push_back(cur);

        if(cur == "if"){
            int y;
            cin >> y;
            varg.push_back({y});

            stk.push(i);
        }else if(cur == "set"){
            int y, v;
            cin >> y >> v;
            varg.push_back({y, v});
        }else{
            varg.push_back({});

            match[stk.top()] = i;
            stk.pop();
        }
    }

    yasser y = solve(0, n - 1);
    printf("%lld\n", (*y.s.begin()) + y.shift);
    
    return 0;
}