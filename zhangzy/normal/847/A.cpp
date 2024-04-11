#include<bits/stdc++.h>
using namespace std;

int pre[111],nex[111],n,cnt,used[111];
void gogogo(int x){
    used[x]=1;
    for (cnt=1;cnt<n;){
        while (nex[x]){
            x=nex[x];
            used[x]=1;
            cnt++;
        }
        for (int i=1;i<=n;i++){
            if (!used[i]&&!pre[i]){
                nex[x]=i;
                pre[i]=x;
                break;
            }
        }
    }
    
}

int main(){
    cin>>n;
    for (int i=1;i<=n;i++){
        cin>>pre[i]>>nex[i];
    }
    for (int i=1;i<=n;i++){
        if (pre[i]) nex[pre[i]]=i;
        if (nex[i]) pre[nex[i]]=i;
    }
    for (int i=1;i<=n;i++){
        if (!pre[i]) gogogo(i);
    }
    for (int i=1;i<=n;i++){
        printf("%d %d\n",pre[i],nex[i]);
    }
}