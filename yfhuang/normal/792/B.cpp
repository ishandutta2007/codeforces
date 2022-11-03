#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int maxn = 105;

int a[maxn];

bool vis[maxn];

int n,k;

int main(){
    cin >> n >> k;
    for(int i = 1;i <= k;i++){
        scanf("%d",a + i);
    }
    int s = 0;
    int K = k;
    memset(vis,false,sizeof(vis));
    while(K--){
        int t = a[k - K] % (n - k + K + 1);
        for(;t;){
            s = (s + 1) % n;
            if(!vis[s]){
                t--;
            }
        }
        vis[s] = true;
        cout << s + 1 << endl;
        for(;;){
            s = (s + 1) % n;
            if(!vis[s]) break;
        }
        //cout << s + 1 << endl;
    }
    //cout << s << endl;
    return 0;
}