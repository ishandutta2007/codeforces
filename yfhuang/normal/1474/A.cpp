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
const int maxn = 1e5 + 5;
string b;
string a;

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n;
        cin >> b;
        a = "";
        for(int i = 0;i < n;i++){
            if(i == 0){
                a += "1"; 
            }else{
                int sum = (a[i - 1] - '0' + b[i - 1] - '0');
                for(int j = 1;j >= 0;j--){
                    if(j + b[i] - '0' != sum){
                        a += (char)(j + '0'); 
                        break;
                    }
                }
            }
        }
        cout << a << endl;
    }
    return 0;
}