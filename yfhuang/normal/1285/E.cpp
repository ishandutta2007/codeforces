#include <cstdio>
#include <algorithm>
#include <cstring>
#include <set>
#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <map>

using namespace std;

int t;
int n;
const int maxn = 2e5 + 5;
int l[maxn], r[maxn];
typedef pair<int, int> pii;

int main(){
    cin >> t;
    while(t--){
        cin >> n;
        vector<pii> A;
        for(int i = 1;i <= n;i++){
            int l, r;
            scanf("%d%d", &l, &r);
            r++;
            A.push_back(make_pair(l, i));
            A.push_back(make_pair(r, -i));
        }
        sort(A.begin(), A.end());
        int m = A.size();
        vector<int> cnt(m), id(m);
        set<int> B;
        for(int i = 0;i < m;i++){
            pii now = A[i];
            int cur = abs(now.second) - 1;
            if(now.second > 0){
                B.insert(cur);
            }else{
                B.erase(cur);
            }
            cnt[i] = B.size();
            if(cnt[i] == 1) id[i] = *B.begin();
        }
        int ans = 1;
        for(int i = 0;i < m - 1;i++){
            ans += (cnt[i] == 0);
        }
        vector<int> ret(n);
        for(int i = 0;i < m - 1;i++){
            if(cnt[i] == 1){
                if(cnt[i - 1] == 2 && cnt[i + 1] == 2){
                    ret[id[i]]++;
                }else if((i == 0 || cnt[i - 1] == 0) && cnt[i + 1] == 0){
                    ret[id[i]]--;
                }
            }
        }
        int best = *max_element(ret.begin(), ret.end());
        ans += best;
        cout << ans << endl;
    }
    return 0;
}