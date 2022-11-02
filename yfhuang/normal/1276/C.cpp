#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <map>
#include <vector>
using namespace std;

int n;
const int maxn = 4e5 + 5;
int a[maxn];
map<int, int> mp;
map<int, int> mp1;
pair<int, int> b[maxn];
int c[maxn];
int sum[maxn];
int main(){
    cin >> n;
    for(int i = 1;i <= n;i++){
        scanf("%d", &a[i]);
        mp[a[i]]++;
    }
    int m = 0;
    for(auto pair : mp){
        int key = pair.first;
        int value = pair.second;
        b[++m] = make_pair(value, key); 
    } 
    sort(b + 1, b + 1 + m);
    sum[0] = 0;
    for(int i = 1;i <= n;i++){
        c[i] = b[i].first;
        sum[i] = sum[i - 1] + c[i];
    }
    long long ansid = 0, ans = 0;
    for(int i = 1;i <= n;i++){
        int id = upper_bound(c + 1, c + 1 + m, i) - c - 1;
        long long x = sum[id] + 1LL * i * (m - id);
        long long S = (x / i) * i;
        if(S > ans and S >= 1LL * i * i){
            ans = S;
            ansid = i;
        }
    }
    int row = ansid, col = ans / ansid;
    vector<vector<int> > G(row, vector<int>(col, 0));
    int nx = 0, ny = 0;
    vector<pair<int, int> > cand(0);
    for(int i = 1;i <= n;i++){
        mp1[a[i]]++;
        if(mp1[a[i]] <= ansid){
            cand.push_back(make_pair(-mp[a[i]], a[i])); 
        }
    }
    sort(cand.begin(), cand.end()); 
    //cout << cand.size() << endl;
    for(int i = 0;i < ans;i++){
        G[nx % row][ny % col] = cand[i].second; 
        //cout << nx << " " << ny << endl;
        ny = ny + 1;
        nx = nx + 1;
        if(nx >= row){
            nx = 0, ny += 1 - row;
        }
    }
    cout << ans << endl;
    cout << row << " " << col << endl;
    for(int i = 0;i < row;i++){
        for(int j = 0;j < col;j++){
            printf("%d%c", G[i][j], j == col - 1 ? '\n' : ' ');
        }
    }
    return 0;
}