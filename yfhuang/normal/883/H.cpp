#include <iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
#include<map>
#include<set>
using namespace std;
const int N=410000;
char st[N],x[N];
int cnt[300];
int main()
{
    int len;
    cin>>len;
    scanf("%s",st);
    for(int i=0;i<len;i++)cnt[st[i]]++;
    int p=1;
    int k=0;
    for(int i=0;i<300;i++)if(cnt[i]&1)
    {
        k++;
       // cout<<(char)i<<"   "<<cnt[i]<<endl;
    }
    int ans=0;
    while(len%(p*2)==0)p*=2;
   // cout<<"k:"<<k<<endl;
    if(k==0)ans=1;
    else
    {
        //ans=m*p;//m*p>=k
        for(int i=1;i<=len;i++)if(len%(i*p)==0)
        if(i*p>=k)
        {
            ans=i*p;
            break;
            
        }
    }
    cout<<ans<<endl;
    int pos=0,ch=0,siz=len/ans;
    for(int i=1;i<=ans;i++)
    {
        for(int j=1;j<=siz/2;j++)
        {
            while(cnt[ch]<2)ch++;
            x[pos+j]=x[pos+siz+1-j]=ch;
           // printf("x[%d]:%c\n",pos+j,ch);
            //printf("x[%d]:%c\n",pos+siz+1-j,ch);
            cnt[ch]-=2;
        }
        pos+=siz;
    }
    pos=siz/2+1;
    ch=0;
    if(siz&1)
    {
        for(int i=1;i<=ans;i++){
            while(cnt[ch]<1)ch++;
            x[pos]=ch;
           // printf("x[%d]:%c\n",pos,ch);
            cnt[ch]--;
            pos+=siz;
        }
    }
    pos=0;
    for(int i=1;i<=ans;i++)
    {
        for(int j=1;j<=siz;j++)printf("%c",x[pos+j]);
        if(i<ans)cout<<" ";else cout<<endl;
        pos+=siz;
    }
}