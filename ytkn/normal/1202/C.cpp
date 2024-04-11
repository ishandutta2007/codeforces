#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

ll l_min[200000], l_max[200000], r_max[200000], r_min[200000];
const ll INF = 1e+10;

int main(){
    int T;
    cin >> T;
    for(int i = 0; i < T; i++){
        string s;
        cin >> s;
        ll x = 0;
        ll y = 0;
        vector<ll> vx, vy;
        vx.push_back(0);
        vy.push_back(0);
        ll x_min = 0, x_max = 0, y_min = 0, y_max = 0;
        for(int j = 0; j < s.size(); j++){
            if(s[j] == 'W'){
                x++;
                x_max = max(x_max, x);
                vx.push_back(x);
            }else if(s[j] == 'S'){
                x--;
                x_min = min(x_min, x);
                vx.push_back(x);
            }else if(s[j] == 'A'){
                y--;
                y_min = min(y_min, y);
                vy.push_back(y);
            }else{
                y++;
                y_max = max(y_max, y);
                vy.push_back(y);
            }
        }
        ll ans = (x_max-x_min+1)*(y_max-y_min+1);
        //cout << ans << endl;
        l_min[0] = 0;
        l_max[0] = 0;
        for(int j = 1; j < vx.size(); j++){
            l_min[j] = min(l_min[j-1], vx[j]);
            l_max[j] = max(l_max[j-1], vx[j]);
        }
        r_min[vx.size()-1] = vx[vx.size()-1];
        r_max[vx.size()-1] = vx[vx.size()-1];
        for(int j = vx.size()-2; j >= 0; j--){
            r_min[j] = min(r_min[j+1], vx[j]);
            r_max[j] = max(r_max[j+1], vx[j]);
        }
        ll max_, min_;
        for(int j = 0; j < vx.size()-1; j++){
            //cout << l_max[j] << ' ' << r_max[j+1] << endl;
            //cout << l_min[j] << ' ' << r_min[j+1] << endl;
            max_ = max({l_max[j], r_max[j+1]-1, vx[j]-1});
            min_ = min({l_min[j], r_min[j+1]-1, vx[j]-1});
            ans = min(ans, (y_max-y_min+1)*(max_-min_+1));
            max_ = max({l_max[j], r_max[j+1]+1, vx[j]+1});
            min_ = min({l_min[j], r_min[j+1]+1, vx[j]+1});
            ans = min(ans, (y_max-y_min+1)*(max_-min_+1));
        }

        //y-direction
        l_min[0] = 0;
        l_max[0] = 0;
        for(int j = 1; j < vy.size(); j++){
            l_min[j] = min(l_min[j-1], vy[j]);
            l_max[j] = max(l_max[j-1], vy[j]);
        }
        r_min[vy.size()-1] = vy[vy.size()-1];
        r_max[vy.size()-1] = vy[vy.size()-1];
        for(int j = vy.size()-2; j >= 0; j--){
            r_min[j] = min(r_min[j+1], vy[j]);
            r_max[j] = max(r_max[j+1], vy[j]);
        }
        for(int j = 0; j < vy.size()-1; j++){
            max_ = max({l_max[j], r_max[j+1]-1, vy[j]-1});
            min_ = min({l_min[j], r_min[j+1]-1, vy[j]-1});
            ans = min(ans, (x_max-x_min+1)*(max_-min_+1));
            max_ = max({l_max[j], r_max[j+1]+1, vy[j]-1});
            min_ = min({l_min[j], r_min[j+1]+1, vy[j]-1});
            ans = min(ans, (x_max-x_min+1)*(max_-min_+1));
        }
        cout << ans << endl;
    }
}