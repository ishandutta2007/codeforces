//
//  main.cpp
//  A
//
//  Created by  on 15/11/5.
//  Copyright  2015 . All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
using namespace std;

const int maxn=120;
string a[maxn];
int ans;

int main(int argc, const char * argv[]) {
    int n;
    bool f;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    ans=0;
    for(int x='a';x<='z';x++){
        for(int y='a';y<='z';y++){
            int sum=0;
            for(int i=1;i<=n;i++){
                f=true;
                for(int j=0;j<a[i].size();j++){
                    if(a[i][j]!=x&&a[i][j]!=y){
                        f=false; break;
                    }
                }
                if(f==true) sum+=a[i].size();
            }
            ans=max(ans,sum);
        }
    }
    cout<<ans<<endl;
    return 0;
}