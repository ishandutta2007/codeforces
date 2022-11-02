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

const int maxn = 1005;

int n;
pair<int, int> a[maxn];

int op[maxn][maxn];

vector<int> cur;

int id[maxn];

int main(){
    cin >> n;
    for(int i = 1;i <= n;i++){
        scanf("%d", &a[i].first);
        a[i].second = i;
    } 
    sort(a + 1, a + 1 + n);
    for(int i = 1;i <= n;i++){
        id[i] = a[i].second;
    }
    if(n == 1){
        if(a[1].first == 1){
            cout << 1 << endl;
            cout << 1 << endl;
        }else{
            cout << 0 << endl;
        }
        return 0;
    }else{
        int st;
        if(a[n].first == a[n - 1].first){
            cur.push_back(1);
            cur.push_back(a[n].first - 1);
            cur.push_back(1);
            op[1][id[n]] = 1;
            for(int i = 2;i <= a[n].first;i++){
                op[i][id[n]] = 1;
                op[i][id[n - 1]] = 1;
            }
            op[a[n].first + 1][id[n - 1]] = 1;
            st = n - 2;
        }else{
            cur.push_back(a[n].first);
            for(int i = 1;i <= a[n].first;i++){
                op[i][id[n]] = 1;
            } 
            st = n - 1;
        }
        for(int i = st;i >= 1;i--){
            int mxid = 0;
            for(int j = 1;j < cur.size();j++){
                if(cur[j] > cur[mxid]){
                    mxid = j;
                }
            }
            if(a[i].first >= cur[mxid]){
                int pre = 0;
                vector<int> tmp;
                for(int j = 0;j < mxid;j++){
                    pre += cur[j];
                    tmp.push_back(cur[j]);
                }
                tmp.push_back(cur[mxid] - 1);
                tmp.push_back(1);
                for(int j = mxid + 1;j < cur.size();j++){
                    tmp.push_back(cur[j]);
                }
                int suf = pre + cur[mxid] - 1;
                for(int j = pre + 1;j <= suf;j++){
                    op[j][id[i]] = 1;
                }
                int left = a[i].first - (cur[mxid] - 1);
                for(int j = 1;j <= n + 1;j++){
                    if((j <= pre or j > suf + 1) and op[j][id[i]] == 0 and left > 0){
                        op[j][id[i]] = 1;
                        left--;
                    }
                }
                cur = tmp;
            }else{
                int pre = 0;
                vector<int> tmp;
                for(int j = 0;j < mxid;j++){
                    pre += cur[j];
                    tmp.push_back(cur[j]);
                }
                tmp.push_back(a[i].first);
                tmp.push_back(cur[mxid] - a[i].first);
                for(int j = mxid + 1;j < cur.size();j++){
                    tmp.push_back(cur[j]);
                }
                int suf = pre + a[i].first;
                for(int j = pre + 1;j <= suf;j++){
                    op[j][id[i]] = 1;
                }
                cur = tmp;
            }
        }
    }
    int num = 0;
    for(int i = 1;i <= n + 1;i++){
        bool flag = false;
        for(int j = 1;j <= n;j++){
            if(op[i][j] != 0){
                flag = true;
            }
        }
        if(flag)
            num++;
    }
    cout << num << endl;
    for(int i = 1;i <= num;i++){
        for(int j = 1;j <= n;j++){
            printf("%d", op[i][j]);
        }
        puts("");
    }
    return 0;
}