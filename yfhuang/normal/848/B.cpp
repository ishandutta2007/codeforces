#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int n;
int W,H;
const int maxn = 100000 + 5;

int g[maxn],p[maxn],t[maxn];

int delta = 100005;
vector<pair<int,int> > h[2 * maxn],v[maxn * 2];

int x[maxn],y[maxn];

int main(){
    cin >> n >> W >> H;
    for(int i = 1;i <= n;i++){
        scanf("%d%d%d",&g[i],&p[i],&t[i]);
        if(g[i] == 1){
            v[p[i] - t[i] + delta].push_back(make_pair(p[i],i));
        }else{
            h[p[i] - t[i] + delta].push_back(make_pair(p[i],i));
        }
    }
    for(int i = 0;i < 2 * maxn;i++){
        if(v[i].size() == 0 && h[i].size() == 0){
            continue;
        }
        if(v[i].size() == 0){
            for(int j = 0;j < h[i].size();j++){
                pair<int,int> p = h[i][j];
                int id = p.second;
                x[id] = W;
                y[id] = p.first;
            }
            continue;
        }
        if(h[i].size() == 0){
            for(int j = 0;j < v[i].size();j++){
                pair<int,int> p = v[i][j];
                int id = p.second;
                x[id] = p.first;
                y[id] = H;
            }
        }
        sort(v[i].begin(),v[i].end());
        sort(h[i].begin(),h[i].end());
        for(int j = 0;j < v[i].size();j++){
            pair<int,int> p = v[i][j];
            int id = p.second;
            int r = (int)v[i].size() - (j + 1);
            int u = (int)h[i].size();
            if(r >= u){
                x[id] = v[i][j + u].first;
                y[id] = H;
            }else{
                x[id] = W;
                y[id] = h[i][r].first;
            }
        }
        for(int j = 0;j < h[i].size();j++){
            pair<int,int> p = h[i][j];
            int id = p.second;
            int u = (int)h[i].size() - (j + 1);
            int r = (int) v[i].size();
            if(r <= u){
                x[id] = W;
                y[id] = h[i][j + r].first;
            }else{
                x[id] = v[i][u].first;
                y[id] = H;
            }
        }
    }
    for(int i = 1;i <= n;i++){
        printf("%d %d\n",x[i],y[i]);
    }
    return 0;
}