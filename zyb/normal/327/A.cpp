#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
    int ans1,ans=0,i,j,k,l,s,m,n;
    int a[105],b[105][105];
    scanf("%d",&n);
    for (i=1;i<=n;i++)
     {scanf("%d",&a[i]);
      if(a[i] == 1)  
            ans++;  
}  
    if(ans==n) 
    {  
        cout << n-1 << endl;  
        return 0;  
    }  
    ans1=0;
    s=0;
    bool bb=false;
    for (i=1;i<=n;i++)
     {for (j=1;j<=n;j++)
      {l=0;
      m=0;
      for (k=i;k<=j;k++)
      if (a[k]==0)
       l++;
       else m++;
    if (l-m>ans1)
     ans1=l-m;
    }
}
               cout<<ans+ans1<<endl;
}