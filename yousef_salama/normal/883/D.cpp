#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    string s;
    cin >> n >> s;

    vector <int> v, w;
    for(int i = 0; i < n; i++){
        if(s[i] == 'P')v.push_back(i);
        if(s[i] == '*')w.push_back(i);
    }

    if(v.size() == 1){
        int i = 0;
        while(i < (int)w.size() && w[i] < v[0])i++;

        pair <int, int> res = make_pair(0, 0);
        if(i > 0)res = make_pair(i, v[0] - w[0]);
        if(i < (int)w.size()){
            pair <int, int> p = make_pair((int)w.size() - i, w.back() - v[0]);
            if(p.first > res.first || (p.first == res.first && p.second < res.second))res = p;
        }
        printf("%d %d\n", res.first, res.second);

        return 0;
    }

    auto calc = [&](int vi, int vj, int wi, int wj){
        auto ok = [&](int k, int vi, int vj, int wi, int wj){
            if(wi > wj)return true;
            if(vi > vj)return false;

            int w1 = wi, w2 = wi;
            if(w2 <= wj && w[w2] < v[vi]){
                if(v[vi] - w[w2] > k)return false;
                while(w2 <= wj && w[w2] < v[vi])w2++;
            }else{
                while(w2 <= wj && w[w2] - v[vi] <= k)w2++;
            }
            vi++;

            while(vi <= vj){
                int w2_ = w2;
                if(w2_ <= wj && w[w2_] < v[vi]){
                    if(v[vi] - w[w2_] <= k){
                        while(w2_ <= wj && w[w2_] < v[vi])w2_++;
                    }
                }else{
                    while(w2_ <= wj && w[w2_] - v[vi] <= k)w2_++;
                }

                int w1_ = w1;
                if(w1_ <= wj && w[w1_] < v[vi - 1] && v[vi] - w[w1_] <= k){
                    while(w1_ <= wj && w[w1_] <= v[vi - 1] + k)w1_++;
                }

                w1 = w2;
                w2 = max(w1_, w2_);

                vi++;
            }

            return (w2 > wj);
        };

        int L = 0, R = n - 1;
        while(L < R){
            int mid = (L + R) / 2;
            if(ok(mid, vi, vj, wi, wj))R = mid;
            else L = mid + 1;
        }
        return L;
    };

    int res = 0;
    for(int i = 0, p = 0, j = 0; i < (int)v.size(); i++){
        if(i + 1 == (int)v.size()){
            res = max(res, calc(p, i, j, (int)w.size() - 1));
        }else{
            bool found = false;
            for(int k = v[i] + 1; k < v[i + 1]; k++){
                if(s[k] == '*'){
                    found = true;
                    break;
                }
            }

            if(!found){
                int nj = j;
                while(nj < (int)w.size() && w[nj] < v[i + 1])nj++;

                res = max(res, calc(p, i, j, nj - 1));
                p = i + 1;
                j = nj;
            }
        }
    }
    printf("%d %d\n", (int)w.size(), res);

    return 0;
}