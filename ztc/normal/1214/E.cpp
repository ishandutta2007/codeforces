#include<stdio.h>
#include<algorithm>
struct node{
    int id,val;
    bool operator<(const node &p)const{return val>p.val;}
}d[100002];
int a[200002],top,n;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",&d[i].val),d[i].id=i;
    std::sort(d+1,d+n+1);top=n;
    for(int i=1;i<=n;i++)a[i]=d[i].id*2-1;
    for(int i=1;i<n;i++)printf("%d %d\n",a[i],a[i+1]);
    for(int i=1;i<=n;i++){
        int x=i+d[i].val-1;
        printf("%d %d\n",a[x],d[i].id*2);
        if(x==top)a[++top]=d[i].id*2;
    }
}