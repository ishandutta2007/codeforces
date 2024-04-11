#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cmath>
#include<iomanip>
#include<cstring>
#define reg register
#define EN std::puts("")
#define LL long long
inline int read(){
    int x=0,y=1;
    char c=std::getchar();
    while(c<'0'||c>'9'){if(c=='-') y=0;c=std::getchar();}
    while(c>='0'&&c<='9'){x=x*10+(c^48);c=std::getchar();}
    return y?x:-x;
}
int n,m,p;
int main(){
    n=read();m=read();p=read();
    int a=-1,b=-1;
    for(reg int x,i=0;i<n;i++){
        x=read();
        if(x%p&&a==-1) a=i;
    }
    for(reg int x,i=0;i<m;i++){
        x=read();
        if(x%p&&b==-1) b=i;
    }
    std::printf("%d",a+b);
    return 0;
}