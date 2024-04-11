#include<bits/stdc++.h>
using namespace std;

struct P{
    int val,id;
}p[101000];
int n,fa[101000],used[101000]={0},ans=0;
vector<int>v[101000];

bool cmp(P p1,P p2){
    return p1.val<p2.val;
}

int main(){
    scanf("%d",&n);
    for (int i=1;i<=n;i++){
        scanf("%d",&p[i].val);
        p[i].id=i;
    }
    sort(p+1,p+n+1,cmp);
    for (int i=1;i<=n;i++){
        fa[i]=p[i].id;
    }
    int p;
    for (int i=1;i<=n;i++){
        if (!used[i]){
            p=i;
            ans++;
            while (!used[p]){
                v[ans].push_back(p);
                used[p]=1;
                p=fa[p];
            }
        }
    }
    printf("%d\n",ans);
    for (int i=1;i<=ans;i++){
        printf("%d",(int)v[i].size());
        for (int j=0;j<(int)v[i].size();j++){
            printf(" %d",v[i][j]);
        }
        printf("\n");
    }
    return 0;
}