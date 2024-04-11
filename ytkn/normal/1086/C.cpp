#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <tuple>
#include <cmath>
#include <numeric>
#include <functional>
#include <cassert>
#include <random>

std::random_device rnd;
std::mt19937 mt(rnd());

int randint(const int l, const int r){
    return mt()%(r - l) + l;
}

#define debug_value(x) cerr << "line" << __LINE__ << ":<" << __func__ << ">:" << #x << "=" << x << endl;
#define debug(x) cerr << "line" << __LINE__ << ":<" << __func__ << ">:" << x << endl;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

using namespace std;
typedef long long ll;

string gen_str(int len, int n_chars){
    string ans;
    for(int i = 0; i < len; i++){
        ans += randint(0, n_chars)+'a';
    }
    return ans;
}

template<typename T>
vector<vector<T>> vec2d(int n, int m, T v){
    return vector<vector<T>>(n, vector<T>(m, v));
}

template<typename T>
vector<vector<vector<T>>> vec3d(int n, int m, int k, T v){
    return vector<vector<vector<T>>>(n, vector<vector<T>>(m, vector<T>(k, v)));
}

template<typename T>
void print_vector(vector<T> v, char delimiter=' '){
    if(v.empty()) {
        cout << endl;
        return;
    }
    for(int i = 0; i+1 < v.size(); i++) cout << v[i] << delimiter;
    cout << v.back() << endl;
}

using P = pair<bool, string>;

P solve(int k, string s, string a, string b){
    int n = s.size();
    vector<int> vs(n), va(n), vb(n);
    for(int i = 0; i < n; i++){
        vs[i] = s[i]-'a';
        va[i] = a[i]-'a';
        vb[i] = b[i]-'a';
    }
    int head = 0;
    for(int i = 0; i < n; i++){
        if(a[i] != b[i]) break;
        head++;
    }
    vector<int> ans(k, -1);
    vector<bool> used(k);
    for(int i = 0; i < head; i++){
        if(ans[vs[i]] == -1){
            if(used[va[i]]){
                return P(false, "");
            }
            ans[vs[i]] = va[i];
            used[va[i]] = true;
        }else{
            if(ans[vs[i]] != va[i]){
                return P(false, "");
            }
        }
    }
    auto fill_ans = [&](){
        for(int i = 0; i < k; i++){
            if(ans[i] != -1) continue;
            for(int j = 0; j < k; j++){
                if(used[j]) continue;
                ans[i] = j;
                used[j] = true;
                break;
            }
        }
    };
    auto make_str = [&](){
        string s;
        for(int i = 0; i < k; i++) s += (char)('a'+ans[i]);
        return s;
    };
    if(head == n){
        fill_ans();
        return P(true, make_str());
    }
    auto ok_same_a = [&]() -> bool{ // ans[vs[head]] = va[head]
        ans[vs[head]] = va[head];
        used[va[head]] = true;
        for(int i = head+1; i < n; i++){
            if(ans[vs[i]] == -1){
                for(int x = va[i]+1; x < k; x++){
                    if(!used[x]){
                        ans[vs[i]] = x;
                        used[x] = true;
                        return true;
                    }
                }
                if(!used[va[i]]){
                    ans[vs[i]] = va[i];
                    used[va[i]] = true;
                }else{
                    return false;
                }
            }else{
                if(ans[vs[i]] < va[i]) return false;
                if(ans[vs[i]] > va[i]) return true;
            }
        }
        return true;
    };
    auto ok_same_b = [&]() -> bool{ // ans[vs[head]] = vb[head]
        ans[vs[head]] = vb[head];
        used[vb[head]] = true;
        for(int i = head+1; i < n; i++){
            if(ans[vs[i]] == -1){
                for(int x = 0; x < vb[i]; x++){
                    if(!used[x]){
                        ans[vs[i]] = x;
                        used[x] = true;
                        return true;
                    }
                }
                if(!used[vb[i]]){
                    ans[vs[i]] = vb[i];
                    used[vb[i]] = true;
                }else{
                    return false;
                }
            }else{
                if(ans[vs[i]] > vb[i]) return false;
                if(ans[vs[i]] < vb[i]) return true;
            }
        }
        return true;
    };
    int v = vs[head];
    if(ans[v] == -1){
        for(int x = va[head]+1; x < vb[head]; x++){
            if(used[x]) continue;
            ans[v] = x;
            used[x] = true;
            fill_ans();
            return P(true, make_str());
        }
        if(!used[va[head]]){
            auto org_ans = ans;
            auto org_uesd = used;
            if(ok_same_a()){
                fill_ans();
                return P(true, make_str());
            }
            ans = org_ans;
            used = org_uesd;
        }
        if(!used[vb[head]]){
            auto org_ans = ans;
            auto org_uesd = used;
            if(ok_same_b()){
                fill_ans();
                return P(true, make_str());
            }
            ans = org_ans;
            used = org_uesd;
        }
        return P(false, "");
    }else{ // 
        if(ans[v] < va[head] || ans[v] > vb[head]){
            return P(false, "");
        }
        if(ans[v] > va[head] && ans[v] < vb[head]){
            fill_ans();
            return P(true, make_str());
        }
        if(ans[v] == va[head]){
            if(ok_same_a()){
                fill_ans();
                return P(true, make_str());
            }else{
                return P(false, "");
            }
        }else{
            assert(ans[v] == vb[head]);
            if(ok_same_b()){
                fill_ans();
                return P(true, make_str());
            }else{
                return P(false, "");
            }
        }
    }
}

void test(int n, int k){
    for(int i = 0; i < 100; i++){
        auto s = gen_str(n, k);
        auto a = gen_str(n, k);
        auto b = gen_str(n, k);
        auto convert = [&](string t){
            string ss;
            for(int i = 0; i < n; i++){
                int idx = s[i]-'a';
                ss += t[idx];
            }
            return ss;
        };
        if(a > b) swap(a, b);
        auto [f, t] = solve(k, s, a, b);
        if(f) {
            vector<bool> used(k);
            cout << "YES" << endl;
            cout << s << ' ' << a << ' ' << b << endl;
            cout << t << endl;
            for(int i = 0; i < k; i++){
                assert('a' <= t[i]);
                assert('a'+k >= t[i]);
                assert(!used[t[i]-'a']);
                used[t[i]-'a'] = true;
            }
            auto ss = convert(t);
            assert(a <= ss);
            assert(ss <= b);
        }else{
            cout << "NO" << endl;
            vector<int> p(k);
            iota(p.begin(), p.end(), 0);
            do{
                string t;
                for(int i = 0; i < k; i++) t += 'a'+p[i];
                auto ss = convert(t);
                if(a <= ss && ss <= b){
                    cout << s << endl;
                    cout << a << endl;
                    cout << b << endl;
                    cout << t << endl;
                    assert(false);
                }
            }while(next_permutation(p.begin(), p.end()));
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    // test(10, 3);
    // return 0;
    int t; cin >> t;
    while(t--) {
        int k; cin >> k;
        string s, a, b; cin >> s >> a >> b;
        auto [f, ss] = solve(k, s, a, b);
        if(f){
            cout << "YES\n";
            cout << ss << '\n';
        }else{
            cout << "NO\n";
        }
    }
}