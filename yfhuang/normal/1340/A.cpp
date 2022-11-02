#include <bits/stdc++.h>
using namespace std;

int T;

const int maxn = 1e5 + 5;

int p[maxn], pos[maxn];
int n;

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> T;
    while(T--){
        cin >> n;
        for(int i = 1;i <= n;i++){
            cin >> p[i];
            pos[p[i]] = i;
        }        
        int cur = 1;
        bool flag = true;
        while(cur <= n){
            int P = pos[cur];
            if(P > n + 1 - cur)
                flag = false;
            for(int i = P;i <= n + 1 - cur;i++){
                if(p[i] != cur + (i - P))
                    flag = false;
            }
            if(!flag)
                break;
            cur += n + 1 - cur + 1 - P;
        }
        if(flag){
            cout << "Yes" << endl;
        }else{
            cout << "No" << endl;
        }
    }
    return 0;
}