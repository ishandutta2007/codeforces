#include<stdio.h>
#include<algorithm>
int a[200002],n,m;
struct node{
    int s,t,num;
    node(){s=t=num=0;}
    bool operator<(const node &p)const{return s<p.s;}
}h[200003];
int l=0,r=0,tnum=0,ans=0;
int main(){
    scanf("%d%d",&n,&m);ans=n;
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        if(h[a[i]].s==0)h[a[i]].s=i;
        h[a[i]].t=i;h[a[i]].num++;
    }std::sort(h+1,h+200001);h[200001].s=200001;
    for(int i=1;i<=200001;i++){
        if(h[i].s<=r){
            if(h[i].t>r)r=h[i].t;
            if(h[i].num>tnum)tnum=h[i].num;
        }else{
            ans-=tnum;
            l=h[i].s;r=h[i].t;tnum=h[i].num;
        }
    }printf("%d",ans);
}