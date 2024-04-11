//
//  main.cpp
//  C
//
//  Created by  on 15/11/14.
//  Copyright  2015 . All rights reserved.
//

/*#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

const int maxn=100000+10;
struct point{
    int x,y;
    //double k;
    int id;
    double l;
} points[maxn],s1[maxn],s2[maxn];
int n;

bool cmp(point a,point b){
    return a.x/a.l>b.x/b.l;
}

int main(int argc, const char * argv[]) {
    scanf("%d",&n);
    int num1=0,num2=0;
    //bool y1=false,y2=false;
    for(int i=1;i<=n;i++){
        scanf("%d%d",&points[i].x,&points[i].y);
        points[i].l=sqrt(1.0*points[i].x*points[i].x+1.0*points[i].y*points[i].y);
        points[i].id=i;
        int b=points[i].y;
        if(b>=0) s1[++num1]=points[i];
        else  s2[++num2]=points[i];
    }
    sort(s1+1,s1+num1+1,cmp);
    sort(s2+1,s2+num2+1,cmp);
    //for(int i=1;i<=num1;i++){
    //    printf("%d %d\n",s1[i].x,s1[i].y);
    //}
    //for(int i=1;i<=num2;i++){
    //    printf("%d %d\n",s2[i].x,s2[i].y);
    //}
    double ans=-10;int id1=0x3f3f3f3f,id2=0x3f3f3f3f;
    for(int i=1;i<num1;i++){
        double cos=(1.0*s1[i].x*s1[i+1].x+1.0*s1[i].y*s1[i+1].y)/s1[i].l/s1[i+1].l;
        if(cos>ans) {ans=cos;id1=s1[i].id,id2=s1[i+1].id;}
    }
    for(int i=1;i<num2;i++){
        double cos=(1.0*s2[i].x*s2[i+1].x+1.0*s2[i].y*s2[i+1].y)/s2[i].l/s2[i+1].l;
        if(cos>ans) {ans=cos;id1=s2[i].id,id2=s2[i+1].id;}
    }
    if(num1>0&&num2>0){
        double cos1=(1.0*s1[1].x*s2[1].x+1.0*s1[1].y*s2[1].y)/s1[1].l/s2[1].l;
        double cos2=(1.0*s1[num1].x*s2[num2].x+1.0*s1[num1].y*s2[num2].y)/s1[num1].l/s2[num2].l;
        if(cos1>ans) {ans=cos1;id1=s1[1].id,id2=s2[1].id;}
        if(cos2>ans) {ans=cos2;id1=s1[num1].id,id2=s2[num2].id;}
    }
    //printf("%d %d %d %d",s1[1].x,s1[1].y,s2[1].x,s2[1].y);
    printf("%d %d\n",id1,id2);
    //printf("%lf\n",ans);
    return 0;
}*/
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector< pair<long double,int > > v;

int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        int x,y;scanf("%d%d",&x,&y);
        v.push_back({atan2(y,x),i});
    }
    sort(v.begin(),v.end());
    int x=0,y=0;
    long double z=360;
    for(int i=0;i<v.size();i++){
        if(fabs(v[(i+1)%n].first-v[i].first)<z){ z=fabs(v[(i+1)%n].first-v[i].first);
        x=v[(i+1)%n].second;
            y=v[i].second;}
        if(2*acos(-1)-fabs(v[(i+1)%n].first-v[i].first)<z){ z=2*acos(-1)-fabs(v[(i+1)%n].first-v[i].first);
            x=v[(i+1)%n].second;
            y=v[i].second;}
    }
    cout<<x<<" "<<y<<endl;
}