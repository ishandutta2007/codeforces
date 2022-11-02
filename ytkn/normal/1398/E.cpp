#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <queue>
#include <set>
#include <map>

using namespace std;
typedef long long ll;

class SumSet{
    public:
    set<ll> st;
    ll sum;

    SumSet(){
        st = set<ll>();
        sum = 0;
    }

    int size() {
        return st.size();
    }

    void erase(ll n){
        st.erase(n);
        sum -= n;
    }

    void insert(ll n){
        st.insert(n);
        sum += n;
    }

    bool contains(ll n){
        return st.count(n) > 0;
    }

    ll max_item(){
        auto p = st.end(); p--;
        return *p;
    }

    ll min_item(){
        return *(st.begin());
    }
};

const ll INF = 1e10;

ll set_max(set<ll> &st){
    if(st.empty()) return -INF;
    auto p = st.end(); p--;
    return *p;
}

ll set_min(set<ll> &st){
    if(st.empty()) return INF;
    return *(st.begin());
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int n; cin >> n;
    SumSet set_small, set_large;
    set<ll> st_f, st_l;
    for(int i = 0; i < n; i++){
        int tp; ll d; cin >> tp >> d;
        // fire
        if(tp == 0){
            if(d > 0) st_f.insert(d);
            else st_f.erase(-d); 
        }else{
            if(d > 0) st_l.insert(d);
            else st_l.erase(-d);
        }
        if(d > 0){
            if(set_small.size() == 0){
                set_large.insert(d);
            }else{
                ll m = set_small.max_item();
                if(m > d) set_small.insert(d);
                else set_large.insert(d);
            }
        }else{
            if(set_large.contains(-d)) set_large.erase(-d); 
            if(set_small.contains(-d)) set_small.erase(-d); 
        }

        while(set_large.size() > st_l.size()){
            ll m = set_large.min_item();
            set_large.erase(m);
            set_small.insert(m);
        }

        while(set_large.size() < st_l.size()){
            ll m = set_small.max_item();
            set_small.erase(m);
            set_large.insert(m);
        }

        // cout << st_f.size() << ' ' << st_l.size() << endl;
        // for(ll i : st_f) cout << i << ' ';
        // cout << endl;
        // for(ll i : st_l) cout << i << ' ';
        // cout << endl;
        // cout << set_small.size() << ' ' << set_large.size() << endl;
    
        if(st_l.size() == 0){
            cout << set_small.sum + set_large.sum << endl;
            continue;
        }

        if(st_f.size() == 0){
            ll m = set_min(st_l);
            cout << 2*set_large.sum -m << endl;
            continue;
        }

        if(set_max(st_f) < set_min(st_l)){
            ll m1 = set_min(st_l);
            ll m2 = set_max(st_f);
            cout << set_small.sum + 2*set_large.sum - m1 + m2 << endl;
            continue;
        }
        cout << set_small.sum + 2*set_large.sum << endl;
    }
}