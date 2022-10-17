#include<cstdio>
int main()
{
    int a,b,yin,e=0,s=0,max;
    scanf("%d%d",&a,&b);
    if(a>b) max=a; else max=b;
    yin=7-max;
    if(yin%2==0) yin/=2,e++;
    if(yin%3==0) yin/=3,s++;
    if(e==0&&s==0) printf("%d/%d",yin,6);
    else printf("%d/%d",yin,6/(e*2+s*3));
    return 0;
}