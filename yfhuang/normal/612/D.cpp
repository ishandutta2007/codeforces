#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

int n,k,s,e,cnt=0;

typedef pair<int,int> ii;

vector<int>a;
vector<ii> b;

int main(){
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        scanf("%d%d",&s,&e);
        b.push_back(ii(s,0));
        b.push_back(ii(e,1));
    }
    sort(b.begin(),b.end());
    for(int i=0;i<b.size();i++){
        if(b[i].second){
            if(cnt==k) a.push_back(b[i].first);
            cnt--;
        }
        else{
            cnt++;
            if(cnt==k) a.push_back(b[i].first);
        }
    }
    printf("%d\n",a.size()/2);
    for(int i=0;i<a.size()/2;i++){
        printf("%d %d\n",a[2*i],a[2*i+1]);
    }
}