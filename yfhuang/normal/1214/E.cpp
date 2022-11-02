#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

struct wire{
    int id;
    int len;
    bool operator < (const wire & rhs) const{
        return len < rhs.len;
    }
};

const int maxn = 1e5 + 5;

wire a[maxn];
int n;
int x[maxn];

vector<int> G[maxn * 2];

set<pair<int, int> > s;

int main(){
    while(cin >> n){
        for(int i = 1;i <= n;i++){
            scanf("%d", &a[i].len);
            x[i] = a[i].len;
            a[i].id = i;
        }
        sort(a + 1, a + 1 + n);
        int now = 0;
        for(int i = n;i >= 1;i--){
            now++;
            G[now + a[i].len].push_back(2 * a[i].id);
            G[now].push_back(2 * a[i].id - 1);
        }
        for(int i = 1;;i++){
            if(G[i].size() == 0) break;
            for(int j = 0;j < G[i].size();j++){
                if(G[i][j] & 1){
                    if(x[(G[i][j] + 1) / 2] == 1){
                        s.insert(make_pair(G[i][j], G[i][j] + 1));
                        continue;
                    }
                    if(G[i + 1].size() > 0){
                        int le = G[i][j];
                        int ri = G[i + 1][0];
                        if(le > ri)
                            swap(le, ri);
                        s.insert(make_pair(le, ri));
                    }
                }else{
                    if(G[i - 1].size() > 0){
                        int le = G[i][j];
                        int ri = G[i - 1][0];
                        if(le > ri)
                            swap(le, ri);
                        s.insert(make_pair(le, ri));
                    }
                }
            }
        }
        for(auto p : s){
            printf("%d %d\n", p.first, p.second);
        }
    }
    return 0;
}