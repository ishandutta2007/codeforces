//
//  main.cpp
//  C
//
//  Created by  on 16/3/16.
//  Copyright  2016 . All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <map>
#include <string>
#include <set>
using namespace std;

int n;
const int maxn = 100005;

string hostname[maxn];
string path[maxn];

map<string,int> mp1;
map<int,string> mp1_;
map<string,int> mp2;
map<int,set<string>> mp3;
map<string,int> mp4;


struct address{
    int id;
    string path;
    bool empty;
}A[maxn];

bool cmp(address a,address b){
    return a.path<b.path;
}

bool flag[maxn];

string change(int a){
    string c;
    if(a==0) c+=('0'+a);
    else while(a>0){
        c+=('0'+a%10);
        a/=10;
    }
    return c;
}

int main(int argc, const char * argv[]) {
    scanf("%d",&n);
    string a;
    memset(flag,true,sizeof(flag));
    mp1.clear();
    mp1_.clear();
    mp3.clear();
    int total1=0;
    int total2=0;
    for(int i=0;i<n;i++){
        cin>>a;
        int j;
        for(j=7;j<a.length();j++){
            if(a[j]=='/') break;
        }
        hostname[i]=a.substr(0,j);
        path[i]='!';
        path[i]+=a.substr(j,a.size()-j);
        if(mp1.count(hostname[i])==0){
            mp1[hostname[i]]=total1;
            mp1_[total1]=hostname[i];
            total1++;
        }
        if(mp2.count(path[i])==0){
            mp2[path[i]]=total2++;
        }
    }
    for(int i=0;i<n;i++){
        if(flag[i]){
            int id=mp1[hostname[i]];
            mp3[id].insert(change(mp2[path[i]]));
        }
    }
    for(int i=0;i<total1;i++){
        set<string>::iterator it;
        A[i].id=i;
        A[i].empty=false;
        
        if(!mp3[i].empty())for(it=mp3[i].begin();it!=mp3[i].end();it++){
            A[i].path+='$';
            A[i].path+=*it;
        }
    }
    sort(A,A+total1,cmp);
    int ans=0;
    for(int i=0,j=0;i<total1;i=j+1,j=i){
        while(j<total1-1&&A[j].path==A[j+1].path) j++;
        if(j>i) ans++;
    }
    cout<<ans<<endl;
    for(int i=0,j=0;i<total1;i=j+1,j=i){
        while(j<total1-1&&A[j].path==A[j+1].path) j++;
        if(j>i){
            for(int k=i;k<=j;k++){
                cout<<mp1_[A[k].id];
                printf("%c",k==j ? '\n' :' ');
            }
        }
    }
    return 0;
}