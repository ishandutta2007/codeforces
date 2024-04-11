#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>

using namespace std;


const int maxn = 2e5 + 5;

pair<int,int> A[maxn],B[maxn];

int ans[maxn];

int main(){
    int n;
    scanf("%d",&n);
    for(int i = 1;i <= n;i++){
        scanf("%d",&A[i].first);
        A[i].second = i;
    }
    sort(A + 1,A + 1 + n);
    for(int i = 1;i <= n;i++){
        scanf("%d",&B[i].first);
        B[i].second = i;
    }
    sort(B + 1,B + 1 + n);
    for(int i = 1;i <= n;i++){
        ans[B[n + 1 - i].second] = A[i].first;
    }
    for(int i = 1;i <= n;i++){
        printf("%d ",ans[i]);
    }

    return 0;
}