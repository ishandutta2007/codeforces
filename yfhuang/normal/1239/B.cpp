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

int n;
const int maxn = 3e5 + 5;

int S[maxn * 2];
vector<int> U;
vector<int> T;
char str[maxn];

int main(){
    cin >> n; 
    scanf("%s", str + 1);
    int minval = 0, pos = n;
    for(int i = 1;i <= n;i++){
        S[i] = S[i - 1];
        if(str[i] == '(')
            S[i] += 1;
        else
            S[i] -= 1;
        if(S[i] < minval){
            minval = S[i];
            pos = i;
        }
    }
    if(S[n] != 0){
        cout << 0 << endl;
        printf("1 1\n");
        return 0;
    }
    for(int i = 1;i <= n;i++){
        S[pos + i] = S[(pos + i - 1) % n + 1];
    }
    for(int i = pos;i <= pos + n;i++){
        if(S[i] == minval){
            U.push_back(i);
        }
    }
    int ans = U.size() - 1, tb = 1, te = 1;
    int sz = U.size();
    for(int i = 0;i + 1 < sz;i++){
        T.clear();
        for(int j = U[i] + 1;j < U[i + 1];j++){
            if(S[j] == minval + 1)
                T.push_back(j);
        }
        for(int j = 0;j + 1 < T.size();j++){
            int b = T[j] + 1, e = T[j + 1], tmp = sz - 1;
            for(int k = T[j] + 1;k < T[j + 1];k++){
                if(S[k] == minval + 2)
                    tmp++;
            }
            if(ans < tmp){
                ans = tmp;
                tb = b;
                te = e;
            }
        }
        if(ans < T.size()){
            ans = T.size();
            tb = U[i] + 1;
            te = U[i + 1];
        }
    }
    tb = (tb - 1) % n + 1;
    te = (te - 1) % n + 1;
    printf("%d\n%d %d\n", ans, tb, te);
    return 0;
}