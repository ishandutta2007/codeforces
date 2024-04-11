//
//  main.cpp
//  A
//
//  Created by  on 16/1/11.
//  Copyright  2016 . All rights reserved.
//

#include <iostream>
#include <cstdio>
using namespace std;

char grid[55][55];
int n,m;

char aim[4]={'f','a','c','e'};

int dx[4]={0,1,0,1};
int dy[4]={0,0,1,1};

int main(int argc, const char * argv[]) {
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        scanf("%s",grid[i]+1);
    }
    int cnt=0;
    bool flag;
    bool flag1;
    for(int i=1;i<=n-1;i++){
        for(int j=1;j<=m-1;j++){
            flag=true;
            for(int k=0;k<4;k++){
                flag1=false;
                for(int l=0;l<4;l++){
                    int nx=i+dx[l],ny=j+dy[l];
                    if(aim[k]==grid[nx][ny]){
                        flag1=true;
                        break;
                    }
                }
                if(!flag1) flag=false;
            }
            if(flag) cnt++;
        }
    }
    cout<<cnt<<endl;
    return 0;
}