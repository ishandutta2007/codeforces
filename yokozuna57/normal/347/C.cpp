#include<iostream>
using namespace std;

int gcd(int a,int b){
    if(b==0)return a;
    else return gcd(b,a%b);
}

int main(){
    int n,a[1000+2],gc=0,max=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++){scanf("%d",&a[i]); gc=gcd(a[i],gc); if(max<a[i])max=a[i];}
    if(((max/gc)-n)%2==1)printf("Alice\n");
    else printf("Bob\n");
}