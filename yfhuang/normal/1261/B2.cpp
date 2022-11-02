#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

int n, m;
const int maxn = 2e5 + 5;
int a[maxn];
int b[maxn];
pair<int, int> p[maxn];

pair<int, pair<int, int> > query[maxn];

void add(int p, int v){
    for(int i = p;i < maxn;i += i & -i){
        a[i] += v;
    }
}

int sum(int p){
    int ret = 0;
    for(int i = p;i > 0;i -= i & -i){
        ret += a[i];
    }
    return ret;
}

int ans[maxn];

int main(){
    cin >> n;
    for(int i = 1;i <= n;i++){
        scanf("%d", &b[i]);
        p[i] = make_pair(-b[i], i);
    }
    sort(p + 1, p + 1 + n);
    cin >> m;
    for(int i = 1;i <= m;i++){
        scanf("%d%d", &query[i].first, &query[i].second.first); 
        query[i].second.second = i;
    }
    sort(query + 1, query + 1 + m);
    memset(a, 0, sizeof(a));
    int now = 0;
    for(int i = 1;i <= m;i++){
        int k = query[i].first;
        int pos = query[i].second.first;
        int qid = query[i].second.second;
        while(now < k){
            now++;
            int x = p[now].second;
            int val = -p[now].first;
            add(x, 1);
        }
        int l = 1, r = n;
        while(l < r){
            int mid = (l + r) / 2;
            if(sum(mid) >= pos){
                r = mid;
            }else{
                l = mid + 1;
            }
        }
        ans[qid] = l;
    }
    for(int i = 1;i <= m;i++){
        printf("%d\n", b[ans[i]]);
    }
    return 0;
}