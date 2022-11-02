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

int cnt1[maxn];
int cnt2[maxn];

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n;
        int k = 0;
        memset(cnt1, 0, sizeof(cnt1));
        memset(cnt2, 0, sizeof(cnt2));
        for(int i = 0;i < n;i++){
            cin >> s[i];
            for(int j = 0;j < n;j++){
                if(s[i][j] == 'X'){
                    cnt1[(i + j) % 3]++;
                    k++;
                }
                if(s[i][j] == 'O'){
                    cnt2[(i + j) % 3]++;
                    k++;
                }
            }
        }
        int a, b;
        for(int i = 0;i < 3;i++){
            for(int j = 0;j < 3;j++){
                if(i == j)
                    continue;
                if(cnt1[i] + cnt2[j] <= k / 3){
                    a = i, b = j;
                    break;
                }
            }
        }
        for(int i = 0;i < n;i++){
            for(int j = 0;j < n;j++){
                if(s[i][j] == 'X'){
                    if((i + j) % 3 == a){
                        s[i][j] = 'O';
                    }
                }else if(s[i][j] == 'O'){
                    if((i + j) % 3 == b){
                        s[i][j] = 'X';
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