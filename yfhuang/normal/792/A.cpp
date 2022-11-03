#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int maxn = 2e5 + 5;

int a[maxn];

int main(){
    int n;
    scanf("%d",&n);
    for(int i = 1;i <= n;i++){
        scanf("%d",a + i);
    }
    sort(a + 1,a + 1 + n);
    int mi = 2e9;
    for(int i = 1;i < n;i++){
        mi = min(a[i + 1] - a[i],mi);
    }
    int num = 0;
    for(int i = 1;i < n;i++){
        if(a[i + 1] - a[i] == mi) num++;
    }
    cout << mi << " " << num << endl;
    return 0;
}