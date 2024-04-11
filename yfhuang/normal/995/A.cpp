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
#include <random>
#include <chrono>
using namespace std;

int n, k;

const int maxn = 1005;

int a[4][maxn];
bool vis[maxn];
bool match(int id){
    for(int i = 0;i < n;i++){
        if(a[1][i] == id){
            if(a[0][i] == id){
                return true;
            }else{
                return false;
            }
        }
    }
    for(int i = 0;i < n;i++){
        if(a[2][i] == id){
            if(a[3][i] == id){
                return true;
            }else{
                return false;
            }
        }
    }
    return false;
}

pair<int, int> nxt(int i, int j){
    if(i == 1 and j < n - 1){
        return make_pair(i, j + 1);
    }
    if(i == 1 and j == n - 1){
        return make_pair(i + 1, j);
    }
    if(i == 2 and j > 0){
        return make_pair(i, j - 1);
    }
    if(i == 2 and j == 0){
        return make_pair(i - 1, j);
    }
}

pair<int, int> pre(int i, int j){
    if(i == 1 and j > 0){
        return make_pair(i, j - 1);
    }
    if(i == 1 and j == 0){
        return make_pair(i + 1, j);
    }
    if(i == 2 and j < n - 1){
        return make_pair(i, j + 1);
    }
    if(i == 2 and j == n - 1){
        return make_pair(i - 1, j);
    }
}

vector<pair<int, pair<int, int> > > ans;

void shift(){
    pair<int, int> st;
    for(int i = 0;i < n;i++){
        if(a[1][i] == 0){
            st = make_pair(1, i);
        }
    } 
    for(int i = n - 1;i >= 0;i--){
        if(a[2][i] == 0){
            st = make_pair(2, i);
        }
    }
    pair<int, int> cur = pre(st.first, st.second);
    //cout << st.first << " " << st.second << endl;
    while(cur != st){
        //cout << cur.first << " " << cur.second << endl;
        if(a[cur.first][cur.second] != 0){
            pair<int, int> to = nxt(cur.first, cur.second);
            ans.push_back(make_pair(a[cur.first][cur.second], to)); 
            swap(a[to.first][to.second], a[cur.first][cur.second]); 
        }
        cur = pre(cur.first, cur.second);
    }
}

int main(){
    cin >> n >> k;
    for(int i = 0;i < 4;i++){
        for(int j = 0;j < n;j++){
            scanf("%d", &a[i][j]);
        }
    }
    int cnt = 0;
    for(int i = 1;i <= k;i++){
        if(match(i)){
            for(int j = 0; j < n;j++){
                if(a[1][j] == i){
                    ans.push_back(make_pair(i, make_pair(0, j)));
                    a[1][j] = 0;
                }
            }
            for(int j = 0;j < n;j++){
                if(a[2][j] == i){
                    ans.push_back(make_pair(i, make_pair(3, j)));
                    a[2][j] = 0;
                }
            } 
            vis[i] = true;
            cnt++;
        }
    }
    if(cnt == 0 and k == 2 * n){
        cout << -1 << endl;
        return 0;
    }
    while(cnt < k){
        int id = -1;
        for(int i = 1;i <= k;i++){
            if(vis[i])
                continue;
            if(match(i))
                id = i;
            //cout << i << endl;
        }        
        if(id == -1){
            shift();
        }else{
            for(int j = 0; j < n;j++){
                if(a[1][j] == id){
                    ans.push_back(make_pair(id, make_pair(0, j)));
                    a[1][j] = 0;
                }
            }
            for(int j = 0;j < n;j++){
                if(a[2][j] == id){
                    ans.push_back(make_pair(id, make_pair(3, j)));
                    a[2][j] = 0;
                }
            } 
            cnt++;
        }
    }
    cout << ans.size() << endl;
    for(int i = 0;i < ans.size();i++){
        pair<int, pair<int, int> > p = ans[i];
        printf("%d %d %d\n", p.first, p.second.first + 1, p.second.second + 1);
    }
    return 0;
}