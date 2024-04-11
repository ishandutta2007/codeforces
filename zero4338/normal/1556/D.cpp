#include<iostream>
#include<cstdio>
#include<algorithm>
#define ll long long
using namespace std;
int read()
{
    int ret=0;char c=getchar();
    while(c>'9'||c<'0')c=getchar();
    while(c>='0'&&c<='9')ret=(ret<<3)+(ret<<1)+(c^48),c=getchar();
    return ret;
}
int queryand(int i,int j){printf("and %d %d\n",i,j);fflush(stdout);return read();}
int queryor(int i,int j){printf("or %d %d\n",i,j);fflush(stdout);return read();}
void answer(int x){printf("finish %d\n",x);return;}
int querysum(int i,int j){return queryand(i,j)+queryor(i,j);}
const int maxn=1e4+5;
int n,k;
int a[maxn];
int main()
{
    n=read();k=read();
    int a12=querysum(1,2),a13=querysum(1,3),a23=querysum(2,3);
    ll tmp=((ll)a12+a13+a23)/2;
    a[1]=tmp-a23;a[2]=tmp-a13;a[3]=tmp-a12;
    for(int i=4;i<=n;i++)a[i]=querysum(1,i)-a[1];
    nth_element(a+1,a+k,a+n+1);
    answer(a[k]);
    return 0;
}