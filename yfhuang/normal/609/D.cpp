//
//  main.cpp
//  D
//
//  Created by  on 15/12/20.
//  Copyright  2015 . All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int n,m,k;
long long s;
int num1,num2;

const int maxn=2e5+5;

long long a[maxn][2];

pair<long long,int> b[maxn];
pair<long long,int> c[maxn];

bool ok(int x){
    long long doll_min=1e7;
    long long pound_min=1e7;
    for(int i=1;i<=x;i++){
        if(a[i][0]<doll_min) doll_min=a[i][0];
        if(a[i][1]<pound_min) pound_min=a[i][1];
    }
    //printf("%d %d\n",doll_min,pound_min);
    long long sum=0;
    int t=0;
    int rear1=0,rear2=0;
    while(t<k){
        if(rear1>=num1&&rear2>=num2) return false;
        else if(rear1>=num1&&rear2<num2){
            sum+=pound_min*c[rear2].first;
            rear2++;
            t++;
        }
        else if(rear1<num1&&rear2>=num2){
            sum+=doll_min*b[rear1].first;
            rear1++;
            t++;
        }
        else{
            if(doll_min*b[rear1].first<=pound_min*c[rear2].first){
                sum+=doll_min*b[rear1].first;
                rear1++;
                t++;
            }
            else{
                sum+=pound_min*c[rear2].first;
                rear2++;
                t++;
            }
        }
    }
    //printf("%d ",sum);
    return sum<=s;
}

int main(int argc, const char * argv[]) {
    cin>>n>>m>>k>>s;
    for(int i=1;i<=n;i++){
        scanf("%I64d",&a[i][0]);
    }
    for(int i=1;i<=n;i++){
        scanf("%I64d",&a[i][1]);
    }
    num1=0,num2=0;
    for(int i=1;i<=m;i++){
        int x;
        scanf("%d",&x);
        if(x==1) {scanf("%I64d",&b[num1].first);b[num1++].second=i;}
        else {scanf("%I64d",&c[num2].first);c[num2++].second=i;}
    }
    sort(b,b+num1);
    sort(c,c+num2);
    int l=0,r=n;
    while(l<r){
        int mid=(l+r)/2;
        if(ok(mid)) r=mid;
        else l=mid+1;
    }
    long long min1=1e7,min2=1e7;
    int d1=0,d2=0;
    //if(ok(0)) printf("! ");
    //printf("%d ",r);
    bool flag=true;
    if(!ok(n)) flag=false;
    if(flag){
        for(int i=1;i<=r;i++){
            if(a[i][0]<min1) {min1=a[i][0];d1=i;}
            if(a[i][1]<min2) {min2=a[i][1];d2=i;}
        }
        printf("%d\n",r);
        int t=0;
        int rear1=0,rear2=0;
        //int nun=0;
        while(t<k){
            if(rear1>=num1&&rear2<num2){
                printf("%d %d\n",c[rear2].second,d2);
                rear2++;
                t++;
            }
            else if(rear1<num1&&rear2>=num2){
                printf("%d %d\n",b[rear1].second,d1);
                rear1++;
                t++;
            }
            else{
                if(min1*b[rear1].first<=min2*c[rear2].first){
                    printf("%d %d\n",b[rear1].second,d1);
                    rear1++;
                    t++;
                }
                else{
                    printf("%d %d\n",c[rear2].second,d2);
                    rear2++;
                    t++;
                }
            }
        }
    }
    else printf("-1\n");
    return 0;
}