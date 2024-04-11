#include <bits/stdc++.h>
using namespace std;

int calc_time(int m, int x1, char d1, int x2, char d2){
    if(d1 == 'R' && d2 == 'L'){
        return (x2 - x1) / 2;
    }
    if(d1 == 'L' && d2 == 'L'){
        return x1 + (x2 - x1) / 2;
    }
    if(d1 == 'R' && d2 == 'R'){
        return (m - x2) + (x2 - x1) / 2;
    }

    return x1 + (m - x2) + (x2 - x1) / 2;
}

struct robot{
    int x;
    char d;
    int ind;

    robot(){}

    bool operator<(const robot& r){
        return x < r.x;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    while(t--){
        int n, m;
        cin >> n >> m;

        vector <robot> v(n);
        for(int i = 0; i < n; i++){
            cin >> v[i].x;
            v[i].ind = i;
        }
        for(int i = 0; i < n; i++){
            cin >> v[i].d;
        }
        sort(v.begin(), v.end());

        vector <int> res(n, -1);
        stack <robot> stk[2];

        for(int i = 0; i < n; i++){
            if(v[i].d == 'R' || stk[v[i].x & 1].empty()){
                stk[v[i].x & 1].push(v[i]);
                continue;
            }

            int collision_time = calc_time(m, stk[v[i].x & 1].top().x, stk[v[i].x & 1].top().d,
                                             v[i].x, v[i].d);

            res[stk[v[i].x & 1].top().ind] = collision_time;
            res[v[i].ind] = collision_time;

            stk[v[i].x & 1].pop();
        }

        for(int j = 0; j < 2; j++){
            while(stk[j].size() >= 2){
                robot p = stk[j].top();
                stk[j].pop();

                robot q = stk[j].top();
                stk[j].pop();

                int collision_time = calc_time(m, q.x, q.d, p.x, p.d);
            
                res[p.ind] = collision_time;
                res[q.ind] = collision_time;
            }
        }

        for(int i = 0; i < n; i++){
            if(i > 0)cout << ' ';
            cout << res[i];
        }
        cout << '\n';
    }
    return 0;
}