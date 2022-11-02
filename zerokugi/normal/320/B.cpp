#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
#include<cstdio>

using namespace std;

int g[101][101];

int main(){
    int n;
    cin >> n;
    vector<pair<int, int>> ra;
    for(int itr=0;itr<n;itr++){
        int t, l, r;
        cin >> t >> l >> r;
        if(t == 1){
            int k = ra.size();
            g[k][k] = 1;
            ra.emplace_back(l, r);
            for(int j=0;j<k;j++){
                int l2, r2; tie(l2, r2) = ra[j];
                if(l < l2 && l2 < r || l < r2 && r2 < r) g[j][k] = 1;
                if(l2 < l && l < r2 || l2 < r && r < r2) g[k][j] = 1;
            }
            for(int i=0;i<=k;i++)for(int j=0;j<=k;j++)for(int p=0;p<=k;p++)
                g[j][p] |= g[j][i] && g[i][p];
        }else{
            puts(g[l-1][r-1] ? "YES" : "NO");
        }
    }
    return 0;
}