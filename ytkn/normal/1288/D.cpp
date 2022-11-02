#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <queue>
#include <set>
#include <map>

using namespace std;
typedef long long ll;

int a[300000][8];
int n, m;
int s[300000];
int cnt[1<<8];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> a[i][j];
        }
    }
    int l = 0, r = 1000000001;
    while(r-l > 1){
        int c = (l+r)/2;
        for(int i = 0; i < (1<<m); i++) cnt[i] = 0;
        for(int i = 0; i < n; i++){
            s[i] = 0;
            for(int j = 0; j < m; j++){
                int p = 1<<j;
                if(a[i][j] >= c){
                    s[i] += p;
                }
            }
            cnt[s[i]]++;
        }
        bool judge = false;
        for(int i = 0; i < (1<<m); i++) {
            for(int j = 0; j < (1<<m); j++) {
                if((i|j) == ((1<<m)-1)){
                    if(cnt[i] > 0 && cnt[j] > 0)judge = true;
                }
            }
        }
        if(judge) l = c;
        else r = c;
    }
    for(int i = 0; i < (1<<m); i++) cnt[i] = 0;
    for(int i = 0; i < n; i++){
        s[i] = 0;
        for(int j = 0; j < m; j++){
            int p = 1<<j;
            if(a[i][j] >= l){
                s[i] += p;
            }
        }
        // cout << s[i] << endl;
        cnt[s[i]] = i+1;
    }
    // cout << l << endl;
    for(int i = 0; i < (1<<m); i++) {
        for(int j = 0; j < (1<<m); j++) {
            if((i|j) == ((1<<m)-1)){
                if(cnt[i] > 0 && cnt[j] > 0){
                    // cout << i << ' '  << j << endl;
                    cout << cnt[i] << ' ' << cnt[j] << endl;
                    return 0;
                }
            }
        }
    }
}