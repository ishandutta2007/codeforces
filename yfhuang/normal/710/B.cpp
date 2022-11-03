#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>

using namespace std;

const int maxn = 3e5 + 5;

int x[maxn];

int main(){
    int n;
    cin >> n;
    for(int i = 1;i <= n;i++){
        scanf("%d",x + i);
    }
    sort(x + 1,x + 1 + n);
    if(n & 1) printf("%d\n",x[(n + 1) / 2]);
    else printf("%d\n",x[n / 2]);
}