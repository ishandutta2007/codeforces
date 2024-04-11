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

const int maxn = (1 << 16) + 5;
int ans[maxn];
int a[maxn];
int pos[maxn];

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n;
    for(int i = 2;i <= n;i++){
        cout << "XOR " << 1 << " " << i << endl;
        fflush(stdout);
        cin >> ans[i];
    }
    bool flag = false;
    int id;
    for(int i = 2;i <= n;i++){
        if(ans[i] == 0){
            flag = true;
            id = i;
        }
    }
    if(flag){
        cout << "AND " << 1 << " " << id << endl;
        fflush(stdout);
        cin >> a[1];
    }else{
        int b, c;
        for(int i = 2;i <= n;i++){
            if(pos[ans[i]] != 0){
                b = pos[ans[i]];
                c = i;
                flag = true;
                break;
            }
            pos[ans[i]] = i;
        } 
        if(flag){
            cout << "AND " << b << " " << c << endl;
            fflush(stdout);
            cin >> a[b];
            a[1] = ans[b] ^ a[b];
        }
        else{
            int x, y;
            cout << "AND " << 1 << " " << pos[1] << endl;
            fflush(stdout);
            cin >> x;
            cout << "AND " << pos[1] << " " << pos[3] << endl;
            fflush(stdout);
            cin >> y;
            if(y & 1){
                a[1] = x;
            }else{
                a[1] = x ^ 1;
            }
        }
    }
    for(int i = 2;i <= n;i++){
        a[i] = a[1] ^ ans[i];
    }
    cout << "!";
    for(int i = 1;i <= n;i++){
        cout << " " << a[i];
    }
    cout << endl;
    return 0;
}