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

int n, m;

int main(){
    cin >> n >> m;
    vector<vector<int> > mat(n, vector<int>(m, 0));    
    for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++){
            int val;
            scanf("%d", &val);
            mat[i][j] = val;
        }
    }
    map<int, int> mp;
    vector<int> cnt(n);
    long long ans = 0;
    for(int j = 0;j < m;j++){
        mp.clear();
        for(int i = 0;i < n;i++){
            mp[i * m + j + 1] = i;
            cnt[i] = 0;
        }
        for(int i = 0;i < n;i++){
            if(mp.count(mat[i][j]) != 0){
                int pos = mp[mat[i][j]];
                int shift = i - pos;
                if(shift < 0)
                    shift += n;
                cnt[shift]++;
            }
        }
        long long tmp = n;
        for(int i = 0;i < n;i++){
            //cout << i << " " << cnt[i] << endl;
            tmp = min(tmp, (n - cnt[i]) + i + 0LL);
        }
        //cout << tmp << endl;
        ans += tmp;
    }
    cout << ans << endl;
    return 0;
}