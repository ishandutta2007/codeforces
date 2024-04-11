#include <cstdio>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>
#include <map>
#include <ctime>



using namespace std;

int ask(int n){
    printf("? %d\n",n);
    fflush(stdout);
}

const int maxn = 50000 + 5;

bool vis[maxn];
int v[maxn];
int ne[maxn];
int p[maxn];

void read(int id){
    int val,nex;
    scanf("%d%d",&val,&nex);
    v[id] = val,ne[id] = nex;
}

int main() {
    srand(time(NULL));
    int n, start, x;
    //cout << 1 << endl;
    scanf("%d%d%d", &n, &start, &x);
    int ans = -1;
    int ans1 = -1;
    for(int i = 1;i <= n;i++) p[i] = i;
    random_shuffle(p + 1,p + 1 + n);
    ask(start);
    read(start);
    if(v[start] >= x){
        printf("! %d\n",v[start]);
        fflush(stdout);
        return 0;
    }else{
        for(int i = 1;i <= min(n,1000);i++){
            ask(p[i]);
            read(p[i]);
            if(v[p[i]] >= x){
                if(ans == -1){
                    ans = v[p[i]];
                }else{
                    ans = min(ans,v[p[i]]);
                }
            }else{
                if(ans1 == -1){
                    ans1 = p[i];
                }else{
                    if(v[ans1] < v[p[i]]) ans1 = p[i];
                }
            }
        }
        int now;
        if(ans1 == -1) now = start;
        else now = ne[ans1];
        for(int i = 1;i <= 998;i++){
            if(now == -1) break;
            ask(now);
            read(now);
            if(v[now] >= x){
                if(ans == -1){
                    ans = v[now];
                }else{
                    ans = min(ans,v[now]);
                }
            }
            now = ne[now];
        }
        printf("! %d\n",ans);
    }
    return 0;
}