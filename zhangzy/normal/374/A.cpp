#include<bits/stdc++.h>
using namespace std;

int n,m,x,y,a,b,tp,ans=10000000;

void C(int xx,int yy){
    int an=max(xx,yy);
    if ((an-xx)&1) return;
    if ((an-yy)&1) return;
        if (xx<an) {
            if (n<x+a&&x-a<1) return;
        }
        if (yy<an) {
            if (m<y+b&&y-b<1) return;
        }
    ans=min(an,ans);
}

int main(){
    cin>>n>>m>>x>>y>>a>>b;
    if ((x-1)%a==0&&(y-1)%b==0){
        C((x-1)/a,(y-1)/b);
    }
    if ((x-1)%a==0&&(m-y)%b==0){
        C((x-1)/a,(m-y)/b);
    }
    if ((n-x)%a==0&&(y-1)%b==0){
        C((n-x)/a,(y-1)/b);
    }
    if ((n-x)%a==0&&(m-y)%b==0){
        C((n-x)/a,(m-y)/b);
    }
    if (ans==10000000)
        puts("Poor Inna and pony!");
    else
        cout<<ans;
}