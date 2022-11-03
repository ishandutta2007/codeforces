#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

int n;

const int maxn = 2e5 + 5;

int a[maxn];
int b[maxn];
vector<int> G[maxn];
int main(){
    cin >> n;
    for(int i = 1;i <= n;i++){
        scanf("%d",a + i);
        int x = lower_bound(b + 1,b + 1 + n,a[i]) - b;
        x--;
        b[x] = a[i];
        G[x].push_back(a[i]);
    }
    for(int i = n;i >= 1;i--){
        for(int j = 0;j < G[i].size();j++){
            printf("%d%c",G[i][j],j == G[i].size() - 1 ? '\n' : ' ');
        }
    }
    return 0;
}