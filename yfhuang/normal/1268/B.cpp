#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>

using namespace std;

const int maxn = 3e5 + 5;

int a[maxn];
int n;
int main(){
    memset(a, 0, sizeof(a));
    cin >> n;
    for(int i = 1;i <= n;i++){
        scanf("%d", &a[i]);
    } 
    long long A = 0, B = 0;
    for(int i = 1;i <= n;i++){
        if(i & 1){
            A += (a[i] + 1) / 2;
            B += a[i] / 2;
        }else{
            A += a[i] / 2;
            B += (a[i] + 1) / 2;
        }
    }
    cout << min(A, B) << endl;
    return 0;
}