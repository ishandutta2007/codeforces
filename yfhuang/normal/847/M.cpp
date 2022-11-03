#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

int n;

const int maxn = 1005;
int t[maxn];

int main(){
    cin >> n;
    for(int i = 1;i <= n;i++){
        scanf("%d",&t[i]);
    }
    if(n == 2){
        cout << 2 * t[2] - t[1] << endl;
        return 0;
    }
    int d = t[2] - t[1];
    for(int i = 3;i <= n;i++){
        if(t[i] - t[i - 1] != d){
            cout << t[n] << endl;
            return 0;
        }
    }
    cout << t[n] + d << endl;
    return 0;
}