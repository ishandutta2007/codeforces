#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <cassert>
using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eb emplace_back
typedef long long ll;
typedef pair<int, int> pi;

int t;
int n;
const int maxn = 305;
string s[maxn];

int cnt[maxn];

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n;
        int k = 0;
        memset(cnt, 0, sizeof(cnt));
        for(int i = 0;i < n;i++){
            cin >> s[i];
            for(int j = 0;j < n;j++){
                if(s[i][j] == 'X'){
                    cnt[(i + j) % 3]++;
                    k++;
                }
                if(s[i][j] == 'O'){
                    k++;
                }
            }
        }
        int mx = 0;
        for(int i = 1;i < 3;i++){
            if(cnt[i] < cnt[mx]){
                mx = i;
            }
        }
        for(int i = 0;i < n;i++){
            for(int j = 0;j < n;j++){
                if(s[i][j] == 'X'){
                    if((i + j) % 3 == mx){
                        s[i][j] = 'O';
                    }
                }
            }
        }
        for(int i = 0;i < n;i++){
            cout << s[i] << endl;
        }
    } 
    return 0;
}