//
//  main.cpp
//  D
//
//  Created by  on 16/1/22.
//  Copyright  2016 . All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

const int maxn=2005;
typedef long long LL;

int a[maxn],b[maxn];

int main(int argc, const char * argv[]) {
    int n,m;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    scanf("%d",&m);
    for(int i=1;i<=m;i++)
        scanf("%d",&b[i]);
    LL suma=0,sumb=0;
    for(int i=1;i<=n;i++)
        suma+=a[i];
    for(int i=1;i<=m;i++)
        sumb+=b[i];
    vector<pair<int,int> > v;
    LL ans=llabs(suma-sumb);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++){
            if(llabs(suma-a[i]+b[j]-(sumb-b[j]+a[i]))<ans){
                ans=llabs(suma-a[i]+b[j]-(sumb-b[j]+a[i]));
                v.clear();
                v.push_back(make_pair(i,j));
            }
        }
    map<LL,pair<int,int> >f;
    for(int i=1;i<=m;i++)
        for(int j=i+1;j<=m;j++)
            f[2LL*(b[i]+b[j])]=make_pair(i, j);
    for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++){
            LL x=suma-sumb-2LL*(a[i]+a[j]);//
            map<LL,pair<int,int> > ::iterator it=f.lower_bound(-x);
            if(it!=f.end()&&x+it->first<ans){
                ans=x+it->first;
                v.clear();
                v.push_back(make_pair(i, it->second.first));
                v.push_back(make_pair(j, it->second.second));
            }if(it!=f.begin()){
                it--;
                if(-x-it->first<ans){
                    ans=-x-it->first;
                    v.clear();
                    v.push_back(make_pair(i, it->second.first));
                    v.push_back(make_pair(j, it->second.second));
                }
            }
        }
    cout<<ans<<endl;
    cout<<v.size()<<endl;
    for(int i=0;i<v.size();i++)
        printf("%d %d\n",v[i].first,v[i].second);
    return 0;
}