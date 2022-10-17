#include<iostream>
using namespace std;
long long int n,m,h[100002],p[100002];

long long int z(long long int x){
    if(x<0)return -x;
    return x;
}

long long int ma(long long int x,long long int y){
    if(x<y)return y;
    return x;
}

bool f(long long int x){
    long long int min_p=0;
    for(int i=0;i<n;i++){
        if(h[i]-p[min_p]>x)return false;
        long long int max=ma(p[min_p]+x-z(h[i]-p[min_p]),h[i]+(x-z(h[i]-p[min_p]))/2);
        while(max>=p[min_p]){min_p++; if(min_p==m)return true;}
    }
    return false;
}

long long int solv(long long int l,long long int r){
    if(l==r)return l;
    if(f((r+l)/2))return solv(l,(r+l)/2);
    else return solv((r+l)/2+1,r);
}

int main(){
    scanf("%I64d%I64d",&n,&m);
    for(int i=0;i<n;i++){
        scanf("%I64d",&h[i]);
    }
    for(int i=0;i<m;i++){
        scanf("%I64d",&p[i]);
    }
    printf("%I64d\n",solv(0,100000000000000000));
}