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

int n;

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n;
    if(n == 1){
        cout << 0 << endl;
        cout << endl;
    }else{
        int p2 = 1;
        while(p2 * 2 <= n){
            p2 *= 2;
        }
        int offset = n - p2;
        int len = 1;
        vector<pi> op;
        while(len < p2){
            for(int i = 0; i < p2;i++){
                int j = i ^ len;
                if(i < j)
                    op.push_back(mp(i + 1, j + 1));
            }  
            len *= 2;
        }
        len = 1;
        while(len < p2){
            for(int i = 0;i < p2;i++){
                int j = i ^ len; 
                if(i < j)
                    op.push_back(mp(i + 1 + offset, j + 1 + offset));
            }
            len *= 2;
        }
        cout << op.size() << endl;
        for(auto p : op){
            cout << p.fi << " " << p.se << endl;
        }
    } 
    return 0;
}