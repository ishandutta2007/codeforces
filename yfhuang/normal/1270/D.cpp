#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

const int maxn = 505;

int k, n;

int a[maxn];

int main(){
    cin >> n >> k;
    for(int i = 1; i <= n;i++){
        a[i] = i;
    }
    cout << "?";
    for(int i = 1;i <= k;i++){
        cout << " " << i;
    }
    cout << endl;
    fflush(stdout);
    int pos, val;
    int pos1, val1;
    cin >> pos >> val;
    cout << "?";
    for(int i = 1;i <= k;i++){
        if(i != pos)
            cout << " " << i;
    }
    cout << " " << k + 1;
    cout << endl;
    fflush(stdout);
    cin >> pos1 >> val1;
    int ans = 0;
    for(int i = 1;i <= k;i++){
        if(i == pos)
            continue;
        cout << "?";
        for(int j = 1;j <= k;j++){
            if(j == i)
                continue;
            cout << " " << a[j];
        }
        cout << " " << a[k + 1];
        cout << endl;
        fflush(stdout);
        int pos2, val2;
        cin >> pos2 >> val2;
        if(val2 == val){
            if(val1 < val)
                ans++;
        }else{
            if(val1 > val)
                ans++;
        }
    }
    cout << "! " << ans + 1 << endl;
    fflush(stdout);
    return 0;
}