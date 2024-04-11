#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
int n,q;
map<int,int> u,l;
int solve(int x,int y,int typ){
    int res=0;
    if(typ==1){
        if(u.count(x)) return 0;
        auto it=u.lower_bound(x);
        if(it==u.end()) res=y;
        else res=y-(*it).second;
        l[y]=x,u[x]=y-res;
        return res;
    }
    else{
        if(l.count(y)) return 0;
        auto it=l.lower_bound(y);
        if(it==l.end()) res=x;  
        else res=x-(*it).second;
        u[x]=y,l[y]=x-res;
        return res;
    }
}

int main(){
    scanf("%d%d",&n,&q);
    while(q--){
        int x,y;char s[2];
        scanf("%d%d%s",&x,&y,s);
        printf("%d\n",solve(x,y,s[0]=='U'));
    }
    return 0;
}