#include<bits/stdc++.h>
using namespace std;
int s,a1,a2,b1,b2,t1,t2;
int main(){
    cin>>s>>a1>>a2>>b1>>b2;
    t1=s*a1+b1+b1;
    t2=s*a2+b2+b2;
    if (t1<t2){
        printf("First");
    }else if (t1>t2){
        printf("Second");
    }else{
        printf("Friendship");
    }
}