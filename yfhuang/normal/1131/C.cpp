#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>

using namespace std;

const int maxn = 105;

int a[maxn];
int n;

int main(){
    cin >> n;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
    }
    sort(a + 1, a + 1 + n);
    for(int i = 1;i <= n;i += 2){
        cout << a[i] << " ";
    }
    for(int i = (n / 2) * 2;i > 0;i -= 2){
        cout << a[i] << " ";
    }
    return 0;
}