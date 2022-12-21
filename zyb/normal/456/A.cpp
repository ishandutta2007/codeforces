#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<string>
#define maxn 100005
using namespace std;
struct node
{
    int a,b;
}
c[maxn];
bool cmp(node u,node v)
{
  return u.a<v.a;
}
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
        scanf("%d%d",&c[i].a,&c[i].b);
    sort(c,c+n,cmp);
    bool flag=0;
    for(int i=1;i<n;i++)
    {
        if(c[i].b<c[i-1].b)
        {
            flag=1;
            break;
        }
    }
    if(flag==1) cout<<"Happy Alex"<<endl;
    else cout<<"Poor Alex"<<endl;
    return 0;

}