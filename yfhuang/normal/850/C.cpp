#include<cstdio>
#include<iostream>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<map>
#include <vector>
#include <unordered_map>
#include <map>
using namespace std;

int sg[(1 << 16) + 5];
bool vis[(1 << 16) + 5];
void init(){
    sg[0] = 0;
    for(int i = 1;i < (1 << 16);i++){
        for(int j = 1;j <= 16;j++){
            int st = i & ((1 << (j - 1)) - 1);
            st = (i >> j) | st;
            if(st == i) continue;
            vis[sg[st]] = 1;
        }
        for(int j = 0;j < (1 << 16);j++){
            if(vis[j] == 0){
                sg[i] = j;
                break;
            }
        }
        for(int j = 1;j <= 16;j++){
            int st = i & ((1 << (j - 1)) - 1);
            st = (i >> j) | st;
            if(st == i) continue;
            vis[sg[st]] = 0;
        }
    }
}

unordered_map<int,int> mp;

int cal(int x){
    if(x < (1 << 16)) return sg[x];
    if(mp.count(x)) return mp[x];

    bool ok[100] = {0};
    for(int j = 1;j <= 31;j++){
        int st = x & ((1 << (j - 1)) - 1);
        st = (x >> j) | st;
        if(st == x) continue;
        ok[cal(st)] = 1;
    }
    int res = 0;
    for(int j = 0;j < 100;j++){
        if(ok[j] == 0){
            res = j;
            break;
        }
    }
    mp[x] = res;
    return res;
}
const int N = 100000 + 5;
int prime[N],tot;
bool v[N];

void mu(){
    v[1] = 1;
    for(int i = 2;i < N;i++){
        if(!v[i]){
            prime[++tot] = i;
        }
        for(int j = 1;j <= tot && i * prime[j] < N;j++){
            v[prime[j] * i] = 1;
            if(i % prime[j] == 0) break;
        }
    }
}

void duipai(){
    for(int i = 0;i < (1 << 16);i++){
        if(cal(i) != sg[i]) cout << i << endl;
    }
}

map<int,int> ss;

int a[105];
int n;

int main(){
    mu();
    init();
    cin >> n;
    for(int i = 1;i <= n;i++){
        scanf("%d",a + i);
        int tmp = a[i];
        for(int j = 1;j <= tot;j++){
            if(tmp % prime[j]) continue;
            int res = 0;
            while(tmp % prime[j] == 0){
                tmp /= prime[j];
                res++;
            }
            ss[prime[j]] |= (1 << (res - 1));
        }
        if(tmp > 1) ss[tmp] |= 1;
    }
    int nim = 0;
    for(auto x : ss){
        int tmp = x.second;
        nim ^= cal(x.second);
    }
    if(nim != 0) cout << "Mojtaba" << endl;
    else cout << "Arpa" << endl;
    return 0;
}