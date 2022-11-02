#include <cstdio>
#include <algorithm>
#include <cstring>
#include <set>
#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <map>
#include <cmath>
#include <queue>

using namespace std;

typedef long long LL;

LL a, b;
const int maxn = 1e5;
bool vis[maxn];

int main(){
    int i = 0;
    cin >> a >> b;
    for(;1LL * (i + 2) * (i + 1) / 2 <= a + b;i++){

    }
    vector<int> A, B;
    int j = i;
    while(j > 0 and b >= j){
        b -= j;
        B.push_back(j);
        vis[j] = true;
        j--;
    }
    if(b > 0 and j >= b){
        B.push_back(b);
        vis[b] = true;
    }
    for(int j = 1;j <= i;j++){
        if(!vis[j])
            A.push_back(j);
    }
    int sz;
    sz = A.size();
    cout << sz << endl;
    for(int i = 0;i < sz;i++){
        printf("%d%c", A[i], i == sz - 1 ? '\n' : ' ');
    }
    sz = B.size();
    cout << sz << endl;
    for(int i = 0;i < sz;i++){
        printf("%d%c", B[i], i == sz - 1 ? '\n' : ' ');
    }
    return 0;
}