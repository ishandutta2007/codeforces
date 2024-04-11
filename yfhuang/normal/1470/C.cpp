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

int query(int v){
    cout << "? " << v + 1 << endl;
    fflush(stdout);
    int ans;
    cin >> ans;
    return ans;
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, k; 
    cin >> n >> k;
    int B = sqrt(n) - 1;
    for(int i = 0;i < B;i++){
        query(i);
    }
    int x = 0;
    int v = query(x);
    while(v == k){
        x = (x + B) % n;
        v = query(x);
    }
    if(v < k){
        while(query((x + B) % n) < k){
            x = (x + B) % n; 
        }
        while(query((x + 1) % n) < k){
            x = (x + 1) % n;
        }
        x = (x + 1) % n;
    }else{
        while(query((x - B + n) % n) > k){
            x = (x - B + n) % n;
        } 
        while(query((x - 1 + n) % n) > k){
            x = (x - 1 + n) % n;
        } 
        x = (x - 1 + n) % n;
    }
    cout << "! " << x + 1 << endl;
    return 0;
}