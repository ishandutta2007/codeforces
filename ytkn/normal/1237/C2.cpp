    #include <iostream>
    #include <algorithm>
    #include <iomanip>
    #include <vector>
    #include <set>
    #include <map>
     
    using namespace std;
     
    typedef pair<int, int> P_;
    typedef pair<P_, P_> P;
     
    int n;
    int x[100000], y[100000], z[100000];
    map<int, vector<P>> mp;
     
    int main(){
        ios::sync_with_stdio(false);
        cin.tie(0);
        cout << setprecision(10) << fixed;
        cin >> n;
        for(int i = 0; i < n; i++){
            cin >> x[i] >> y[i] >> z[i];
            mp[x[i]].push_back(P(P_(y[i], z[i]), P_(i+1, y[i]+z[i])));
        }
        //cout << 'H' << endl;
        vector<int> p;
        for(auto iter = mp.begin(); iter != mp.end(); iter++){
            sort(iter->second.begin(), iter->second.end());
            vector<P> v = iter->second;
            int s = v.size();
            vector<int> u;
            for(int j = 0; j+1 < s; j++){
                if(v[j].first.first == v[j+1].first.first || j+1 == s-1){
                    cout << v[j].second.first << ' ' <<  v[j+1].second.first << endl;
                    j++;
                    if(j+1 == s-1) u.push_back(v[j+1].second.first);
                }else{
                    u.push_back(v[j].second.first);
                }
            }
            if(s == 1) u.push_back(v[0].second.first);
            int t = u.size();
            if(t%2 == 1){
                p.push_back(u[0]);
                for(int j = 1; j+1 < t; j+=2){
                    cout << u[j] << ' ' << u[j+1] << endl;
                }
            }else{
                for(int j = 0; j+1 < t; j+=2){
                    cout << u[j] << ' ' << u[j+1] << endl;
                }
            }
        }
        //cout << 'p' << endl;
        for(int j = 0; j+1 < p.size(); j+=2){
            cout << p[j] << ' ' << p[j+1] << endl;
        }
    }