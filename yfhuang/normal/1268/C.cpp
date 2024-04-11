#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
#include <set>
using namespace std;

const int maxn = 2e5 + 5;
int c[maxn];

int sum(int p){
    int ret = 0;
    for(int i = p;i > 0;i -= i & -i){
        ret += c[i];
    }
    return ret;
}

void add(int p, int v){
    for(int i = p;i < maxn;i += i & -i){
        c[i] += v;
    }
}

int pos[maxn];
int a[maxn];
int n;

int main(){
    cin >> n;
    for(int i = 1;i <= n;i++){
        scanf("%d", &a[i]);
        pos[a[i]] = i;
    }
    long long ans1 = 0, ans2 = 0;
    long long suml = 0, sumr = 0;
    set<int> L, R;
    for(int i = 1;i <= n;i++){
        ans1 += (i - 1) - sum(pos[i]);
        add(pos[i], 1);
        if(L.size() and pos[i] < *L.rbegin()){
            L.insert(pos[i]);
            suml += pos[i];
        }else{
            R.insert(pos[i]);
            sumr += pos[i];
        }
        while(L.size() < R.size()){
            auto it = R.begin();
            sumr -= *it;
            suml += *it;
            L.insert(*it);
            R.erase(it);
        }
        while(L.size() > R.size() + 1){
            auto it = L.rbegin();
            suml -= *it;
            sumr += *it;
            R.insert(*it);
            L.erase(*it);
        }
        int mid = (i + 1) / 2;
        //cout << suml << " " << sumr << endl;
        //cout << L.size() << " " << R.size() << endl;
        //cout << "L: " << endl;
        //for(auto it : L){
        //    cout << it << " ";
        //}
        //cout << endl;
        //cout << "R: " << endl;
        //for(auto it : R){
        //    cout << it << " ";
        //}
        //cout << endl;
        ans2 = 1LL * mid * (*L.rbegin());
        ans2 -= suml;
        ans2 -= 1LL * (i - mid) * (*L.rbegin());
        ans2 += sumr;
        ans2 -= 1LL * mid * (mid - 1) / 2;
        ans2 -= 1LL * (i - mid) * (i - mid + 1) / 2;
        printf("%lld%c", ans1 + ans2, i == n ? '\n' : ' ');
    }
    return 0;
}