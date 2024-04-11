#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>
#include <set>
using namespace std;

const int maxn = 5e5 + 5;
int t;
int n;
int a[maxn], b[maxn];
int cnt1[maxn], cnt2[maxn];
vector<int> A[maxn], B[maxn];
int minv[maxn << 2];
#define lson o*2,l,mid
#define rson o*2+1,mid+1,r

void pushup(int o){
    minv[o] = min(minv[o*2],minv[o*2+1]);
}

void build(int o, int l, int r){
    if(l == r){
        minv[o] = a[l];
        return;
    }
    int mid = (l + r) / 2;
    build(lson);
    build(rson);
    pushup(o);
}

void update(int o, int l, int r, int p, int v){
    if(l == r){
        minv[o] = v;
        return;
    }
    int mid = (l + r) / 2;
    if(p <= mid)
        update(lson, p, v);
    if(p > mid)
        update(rson, p, v);
    pushup(o);
}
int querymin(int o, int l, int r, int ql, int qr){
    if(ql <= l && r <= qr){
        return minv[o];
    }
    int mid = (l + r) / 2;
    if(qr <= mid)
        return querymin(lson, ql, qr);
    if(ql > mid)
        return querymin(rson, ql, qr);
    return min(querymin(lson, ql, qr), querymin(rson, ql, qr));
}

multiset<pair<int, int>> setA, setB;
int main(){
    cin >> t;
    while(t--){
        cin >> n;
        for(int i = 1;i <= n;i++){
            cnt1[i] = cnt2[i] = 0;
            A[i].clear(), B[i].clear();
        }
        for(int i = 1;i <= n;i++){
            scanf("%d", &a[i]);
            cnt1[a[i]]++;
            A[a[i]].push_back(i);
        }
        for(int i = 1;i <= n;i++){
            scanf("%d", &b[i]);
            cnt2[b[i]]++;
            B[b[i]].push_back(i);
        }
        bool flag = true;
        for(int i = 1;i <= n;i++){
            if(cnt1[i] != cnt2[i]){
                flag = false;
            }
            cnt1[i] = cnt2[i] = 0;
        }
        build(1, 1, n);
        if(flag){
            setA.clear();
            setB.clear();
            for(int i = 1;i <= n;i++){
                setA.insert(make_pair(i, a[i]));
                setB.insert(make_pair(i, b[i]));
            }
            for(int i = 1;i <= n;i++){
                auto it1 = setA.begin();
                auto it2 = setB.begin();
                int val = it2->second;
                if(it1->second == it2->second){
                    update(1, 1, n, it1->first, 1e9);
                    setA.erase(it1);
                    setB.erase(it2);
                }else if(it1->second < it2->second){
                    flag = false;
                    break;
                }else{
                    int pos = A[val][cnt1[val]];
                    int minval = querymin(1, 1, n, 1, pos);
                    if(minval < val){
                        flag = false;
                    }
                    it1 = setA.lower_bound(make_pair(pos, val));
                    update(1, 1, n, pos, 1e9);
                    setA.erase(it1);
                    setB.erase(it2);
                }
                cnt1[val]++;
                cnt2[val]++;
            }
        }
        if(flag){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
    } 
    return 0;
}