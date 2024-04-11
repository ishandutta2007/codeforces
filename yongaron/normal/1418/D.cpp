#include <iostream>
#include <queue>
#include <set>

using namespace std;

struct usek{
    long long del, zac, kon;
};

bool operator<(const usek &a, const usek &b){
    return a.del < b.del;
}

int main()
{
    priority_queue< usek > halda;
    set< long long > piles;
    int n, q;
    cin >> n >> q;
    bool vd = 1;
    long long x;
    long long ma = 0;
    long long mi = 10e9+5;
    for(int i = 0; i < n + q; i++){
        if(i >= n) cin >> vd;
        cin >> x;
        if(vd){
            ma = max(ma, x);
            mi = min(mi, x);

            auto it = piles.upper_bound(x);
            if(it != piles.end()) halda.push({*it - x, x, *it});
            piles.insert(x);

            it = piles.upper_bound(-x);
            if(it != piles.end() && *it < 0) halda.push({*it + x, -*it, x});
            piles.insert(-x);
        }
        else{
            auto it = piles.upper_bound(x);
            auto ite = piles.upper_bound(-x);
            if(it != piles.end() && ite != piles.end() && *ite < 0) halda.push({*it + *ite, -*ite, *it});
            if(ma == x){
                if(ite == piles.end() || *ite > 0) ma = 0;
                else ma = -*ite;
            }
            if(mi == x){
                if(it == piles.end()) mi = 10e9+5;
                else mi = *it;
            }
            piles.erase(x);
            piles.erase(-x);
        }
        usek dl;
        if(!halda.empty()){
            dl = halda.top();
            auto it = piles.upper_bound(dl.zac);
            while(!halda.empty() && (it == piles.end() || *it != dl.kon || !piles.count(dl.zac))){
                halda.pop();
                dl = halda.top();
                it = piles.upper_bound(dl.zac);
            }
        }
        if(piles.size()<4 && i >= n-1) cout << 0 << endl;
        else if(i >= n-1) cout << ma - mi - dl.del << endl;
    }
    return 0;
}