#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

int n;

long long ask(int t, int i, int j, int k){
    cout << t << " " << i << " " << j << " " << k << endl;
    fflush(stdout);
    long long ret;
    cin >> ret;
    return ret;
}

vector<int> v[2];
vector<pair<long long, int> > u[2];
vector<int> ans;
const int maxn = 1005;
long long S[maxn];
int sign[maxn];
int main(){
    cin >> n; 
    for(int i = 3;i <= n;i++){
        long long ret;
        ret = ask(2, 1, 2, i);
        if(ret == -1)
            v[0].push_back(i);
        else
            v[1].push_back(i);
        ret = ask(1, 1, 2, i);
        S[i] = ret;
    } 
    for(int i = 0;i < 2;i++){
        ans.push_back(i + 1);
        if(v[i].size() == 0)
            continue;
        int pivot = v[i][0];
        for(int j = 1;j < v[i].size();j++){
            if(S[v[i][j]] > S[pivot]){
                pivot = v[i][j];
            }
        } 
        u[0].clear(), u[1].clear();
        for(int j = 0;j < v[i].size();j++){
            int now = v[i][j];
            if(now == pivot)
                continue;
            long long ret = ask(2, i + 1, pivot, now);
            if(ret < 0)
                u[0].push_back(make_pair(S[now], now));
            else
                u[1].push_back(make_pair(-S[now], now));
        }        
        for(int j = 0;j < 2;j++){
            sort(u[j].begin(), u[j].end());
            for(auto it : u[j]){
                ans.push_back(it.second);
            }
            if(j == 0)
                ans.push_back(pivot);
        }
    }
    cout << "0";
    for(auto x : ans){
        cout << " " << x;
    }
    cout << endl;
    fflush(stdout);
    return 0;
}