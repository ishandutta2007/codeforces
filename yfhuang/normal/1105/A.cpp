#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

int n;
int a[1005];

int main(){
    cin >> n;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
    }
    int v = 1e9, id = 0;
    for(int i = 1;i <= 100;i++){
        int tmp = 0;
        for(int j = 1;j <= n;j++){
            tmp += max(0, abs(a[j] - i) - 1);
        }
        if(tmp < v){
            v = tmp;
            id = i;
        }
    }
    cout << id << " " << v << endl;
    return 0;
}