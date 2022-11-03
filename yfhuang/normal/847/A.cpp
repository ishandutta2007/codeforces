#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

int n;
const int maxn = 105;
struct node{
    int l,r;
    void read(){
        cin >> l >> r;
    }
}a[maxn];

int head[maxn],rear[maxn];
int tot;
int main(){
    tot = 0;
    cin >> n;
    for(int i = 1;i <= n;i++){
        scanf("%d%d",&a[i].l,&a[i].r);
    }
    for(int i = 1;i <= n;i++){
        if(a[i].l == 0){
            int j = i;
            while(a[j].r != 0){
                j = a[j].r;
            }
            head[++tot] = i;
            rear[tot] = j;
        }
    }
    for(int i = 2;i <= tot;i++){
        int u = rear[1],v = head[i];
        a[u].r = v;
        a[v].l = u;
        rear[1] = rear[i];
    }
    for(int i = 1;i <= n;i++){
        printf("%d %d\n",a[i].l,a[i].r);
    }
    return 0;
}