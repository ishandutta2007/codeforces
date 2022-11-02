#include <cstdio>
#include <algorithm>
#include <cstring>
#include <set>
#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <map>

using namespace std;

int n;
const int maxn = 1e5 + 5;
int u[maxn];
int a[maxn];

vector<int> d[maxn];
bool vis[maxn];
int cnt[maxn];
int gcd(int a, int b){
    return b == 0 ? a : gcd(b, a % b);
}
void mo(){
    for(int i = 1;i < maxn;i++){
        for(int j = i;j < maxn;j += i){
            d[j].push_back(i);
        }
        if(i == 1)
            u[i] = 1;
        else{
            if((i / d[i][1]) % d[i][1] == 0)
                u[i] = 0;
            else
                u[i] = -u[i / d[i][1]];
        }
    }
}

int coprime(int x){
    int ans = 0;
    for(auto v : d[x]){
        ans += u[v] * cnt[v];
    }
    return ans;
}

void update(int a, int val){
    for(auto v : d[a]){
        cnt[v] += val;
    }
}

int main(){
    cin >> n;
    long long ans = 0;
    for(int i = 1;i <= n;i++){
        scanf("%d", &a[i]);
        vis[a[i]] = true;
        ans = max(ans, (long long)a[i]);
    }
    mo();
    for(int i = 1;i < maxn;i++){
        stack<int> st;
        for(int j = (maxn - 1) / i;j >= 1;j--){
            if(!vis[j * i])
               continue;
            int  c = coprime(j);
            while(c > 0){
                int val = st.top();
                if(gcd(val, j) == 1){
                    ans = max(ans, 1LL * val * j * i);
                    c--;
                }
                update(val, -1);
                st.pop();
            } 
            update(j, 1);
            st.push(j);
        }
        while(!st.empty()){
            update(st.top(), -1);
            st.pop();
        }
    }
    cout << ans << endl;
    return 0;
}