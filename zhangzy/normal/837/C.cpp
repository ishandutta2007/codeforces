#include<bits/stdc++.h>
using namespace std;
int n,a[110],b[110],x,y,ans=0;

void doit(int p1,int p2){
    int aa,bb;
    aa=a[p1]+a[p2];
    bb=max(b[p1],b[p2]);
    if (aa<=x&&bb<=y||aa<=y&&bb<=x){
        ans=max(ans,a[p1]*b[p1]+a[p2]*b[p2]);
        return;
    }
    
    swap(a[p1],b[p1]);
    aa=a[p1]+a[p2];
    bb=max(b[p1],b[p2]);
    if (aa<=x&&bb<=y||aa<=y&&bb<=x){
        ans=max(ans,a[p1]*b[p1]+a[p2]*b[p2]);
        return;
    }
    
    swap(a[p2],b[p2]);
    aa=a[p1]+a[p2];
    bb=max(b[p1],b[p2]);
    if (aa<=x&&bb<=y||aa<=y&&bb<=x){
        ans=max(ans,a[p1]*b[p1]+a[p2]*b[p2]);
        return;
    }
    
    swap(a[p1],b[p1]);
    aa=a[p1]+a[p2];
    bb=max(b[p1],b[p2]);
    if (aa<=x&&bb<=y||aa<=y&&bb<=x){
        ans=max(ans,a[p1]*b[p1]+a[p2]*b[p2]);
        return;
    }
}

int main(){
    scanf("%d%d%d",&n,&x,&y);
    for (int i=1;i<=n;i++){
        scanf("%d%d",&a[i],&b[i]);
    }
    for (int i=1;i<n;i++){
        for (int j=i+1;j<=n;j++){
            doit(i,j);
        }
    }
    printf("%d",ans);
}