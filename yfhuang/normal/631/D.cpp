//
//  main.cpp
//  d
//
//  Created by  on 16/3/4.
//  Copyright  2016 . All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int maxn=(int) 2e5+1;

struct Part{
    char c;
    long long l;
    bool operator == (const Part& rhs) const{
        return (c==rhs.c)&&(l==rhs.l);
    }
    bool operator <= (const Part& rhs) const{
        return (c==rhs.c)&&(l<=rhs.l);
    }
};

int n,m,f[maxn];
Part a[maxn],b[maxn];
long long ans;

void compress(Part *a,int &n){
    int m=0;
    for(int i=0;i<n;i++){
        if(m==0||a[m-1].c!=a[i].c)
            a[m++]=a[i];
        else
            a[m-1].l+=a[i].l;
    }
    n=m;
}

int main(int argc, const char * argv[]) {
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++){
        scanf("%I64d-%c",&a[i].l,&a[i].c);
    }
    for(int i=0;i<m;i++){
        scanf("%I64d-%c",&b[i].l,&b[i].c);
    }
    compress(a,n); compress(b,m);
    ans=0;
    if(m==1){
        for(int i=0;i<n;i++){
            if(b[0]<=a[i]){
                ans+=a[i].l-b[0].l+1;
            }
        }
    }else if(m==2){
        for(int i=0;i<n-1;i++){
            if(b[0]<=a[i]&&b[1]<=a[i+1])
                ans++;
        }
    }else{
        f[1]=0;
        for (int i=2; i<m-1;i++) {
            int j=f[i-1];
            while (j>0&&!(b[j+1]==b[i]))
                j=f[j];
            if (b[j+1]==b[i])
                j++;
            f[i]=j;
        }
        for (int i=1, j=0; i<n-1; i++) {
            while (j>0&&!(b[j+1]==a[i]))//kmp
                j=f[j];
            if (b[j+1]==a[i])
                j++;
            if (j==m-2) {
                if (b[0]<=a[i-j]&&b[j+1]<=a[i+1])
                    ans++;
                j=f[j];
            }
        }
    }
    printf("%I64d",ans);
    return 0;
}