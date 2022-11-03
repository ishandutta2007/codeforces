//
//  main.cpp
//  C
//
//  Created by  on 15/12/13.
//  Copyright  2015 . All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
using namespace std;

int main(){
    string s1,s2,s3;
    int n,t;
    cin>>n>>t>>s1>>s2;
    s3.resize(n);
    int k1=n-t,k2=n-t,t1=t,t2=t;
    for(int i=0;i<n&&k1&&k2;i++){
        if(s1[i]==s2[i])
            k1--,k2--,s3[i]=s1[i];
    }
    for(int i=0;i<n;i++){
        if(!s3[i]){
            if(k1) s3[i]=s1[i],k1--,t2--;
            else if(k2) s3[i]=s2[i],k2--,t1--;
            else{
                t1--,t2--;
                char x='a';
                while(!(x!=s1[i]&&x!=s2[i])) x++;
                s3[i]=x;
            }
        }
    }
    if(!t1&&!t2&&!k1&&!k2) cout<<s3<<endl;
    else printf("-1\n");
}