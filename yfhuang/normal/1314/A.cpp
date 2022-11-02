#include <cstdio>
#include <algorithm>
#include <cstring>
#include <set>
#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <map>
#include <cmath>
#include <queue>

using namespace std;

const int maxn = 2e5 + 5;

int n;

typedef pair<int, int> pii;

pii a[maxn];
multiset<pii> s;
int main(){
    cin >> n;
    for(int i = 1;i <= n;i++){
        scanf("%d", &a[i].first);
    }
    for(int i = 1;i <= n;i++){
        scanf("%d", &a[i].second);
        a[i].second = -a[i].second;
    }
    sort(a + 1,a + 1 + n);
    int pre = 0;
    long long ans = 0;
    for(int i = 1, j = 1;i <= n;i = j + 1, j = i){
        int val = a[i].first;
        while(val > pre + 1 and s.size()){
            auto it = s.begin();
            int cost = -it->first;
            int pos = it->second;
            ans += 1LL * (pre + 1 - pos) * cost;
            //cout << cost << " " << pos << " " << ans << endl;
            s.erase(it);
            pre++;
        }
        s.insert(make_pair(a[i].second, a[i].first));
        while(j + 1 <= n and a[j + 1].first == a[j].first){
            s.insert(make_pair(a[j + 1].second, a[j + 1].first));
            j++;
        }
        pre = val - 1;
    }
    //cout << s.size() << endl;
    while(s.size()){
        auto it = s.begin();
        int cost = -it->first;
        int pos = it->second;
        ans += 1LL * (pre + 1 - pos) * cost;
        //cout << cost << " " << pos << " " << pre << " " << ans << endl;
        s.erase(it);
        pre++;
    }
    cout << ans << endl;
    return 0;
}