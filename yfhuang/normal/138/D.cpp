//
//  main.cpp
//  138D
//
//  Created by  on 16/1/26.
//  Copyright  2016 . All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <set>
#include <vector>
#include <cstring>
using namespace std;

int n,m;
char grid[22][22];
int mem[42][42][42][42];
int flag;

int get(int al,int ar,int bl,int br){
    if(bl>br||al>ar) return 0;
    if(mem[al][ar][bl][br]!=-1) return mem[al][ar][bl][br];
    set<int> sg;
    for(int i=0;i<n;i++){
        for(int j=((i%2)^flag);j<m;j+=2){
            int a=i+j,b=j-i+20;
            if(al<=a&&a<=ar&&b>=bl&&b<=br){
                int t;
                if(grid[i][j]=='R')
                    t=get(al,ar,b+2,br)^get(al,ar,bl,b-2);
                else if(grid[i][j]=='L')
                    t=get(al,a-2,bl,br)^get(a+2,ar,bl,br);
                else{
                    t=get(al,a-2,bl,b-2)^
                    get(al,a-2,b+2,br)^
                    get(a+2,ar,bl,b-2)^
                    get(a+2,ar,b+2,br);
                }
                sg.insert(t);
            }
        }
    }
    int r=0;
    while(sg.count(r)) r++;
    return mem[al][ar][bl][br]=r;
}


int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin>>n>>m;
    for(int i=0;i<n;i++)
        cin>>grid[i];
    int a,b;
    memset(mem,-1,sizeof(mem));
    flag=1;
    a=get(0,40,0,40);
    memset(mem,-1,sizeof(mem));
    flag=0;
    b=get(0,40,0,40);
    cout<<(((a^b)==0)?"LOSE":"WIN")<<endl;
    return 0;
}