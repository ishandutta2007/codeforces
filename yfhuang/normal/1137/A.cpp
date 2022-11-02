#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int n, m;
const int maxn = 1005;
int a[maxn][maxn];
int row[maxn], col[maxn];
int b[maxn][maxn];
int c[maxn][maxn];

void cal(vector<pair<int, int> > val, int type, int id){
    sort(val.begin(), val.end());
    int tot = 0;
    for(int i = 0, j = 0;i < val.size();i = j + 1, j = i){
        while(j + 1 < val.size() && val[j + 1].first == val[j].first){
            j++;
        }
        ++tot;
        for(int k = i;k <= j;k++){
            if(type == 0){
                b[id][val[k].second] = tot;
            }else{
                c[val[k].second][id] = tot;
            }
        }
    }
}
int main(){
    while(cin >> n >> m){
        for(int i = 1;i <= n;i++){
            for(int j = 1;j <= m;j++){
                scanf("%d", &a[i][j]);
            }
        }
        for(int i = 1;i <= n;i++){
            vector<pair<int,int> > v(0);
            for(int j = 1;j <= m;j++){
                v.push_back(make_pair(a[i][j], j));
            }
            cal(v, 0, i);
        }
        for(int i = 1;i <= m;i++){
            vector<pair<int,int> > v(0);
            for(int j = 1;j <= n;j++){
                v.push_back(make_pair(a[j][i], j));
            }
            cal(v, 1, i);
        }
        memset(row, 0, sizeof(row));
        memset(col, 0, sizeof(col));
        for(int i = 1;i <= n;i++){
            for(int j = 1;j <= m;j++){
                row[i] = max(row[i], b[i][j]);
            }
        }
        for(int i = 1;i <= m;i++){
            for(int j = 1;j <= n;j++){
                col[i] = max(col[i], c[j][i]);
            }
        }
        for(int i = 1;i <= n;i++){
            for(int j = 1;j <= m;j++){
                if(b[i][j] >= c[i][j]){
                    printf("%d", max(row[i], col[j] + b[i][j] - c[i][j]));
                }else{
                    printf("%d", max(row[i] + c[i][j] - b[i][j], col[j]));
                }
                if(j == m)
                    cout << endl;
                else
                    printf(" ");
            }
        }
    }
    return 0;
}