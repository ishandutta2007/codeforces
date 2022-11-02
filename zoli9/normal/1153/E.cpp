#include <bits/stdc++.h>
using namespace std;
int n;
int qu;
int ans1x, ans1y, ans2x, ans2y;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    int xstart=0;
    int xend=n;
    for(int i=1; i<n; i++)
    {
        cout<<"? "<<i<<" "<<1<<" "<<i<<" "<<n<<endl;
        cout.flush();
        cin>>qu;
        if(qu%2==1)
        {
            if(xstart==0) xstart=i;
            else xend=i;
        }
    }
    if(xstart!=0)
    {
        int elso1=1;
        int utolso1=n;
        while(elso1<=utolso1)
        {
            int koz=(elso1+utolso1)/2;
            cout<<"? "<<xstart<<" "<<1<<" "<<xstart<<" "<<koz<<endl;
            cout.flush();
            cin>>qu;
            if(qu%2==0) elso1=koz+1;
            else utolso1=koz-1;
        }
        int elso2=1;
        int utolso2=n;
        while(elso2<=utolso2)
        {
            int koz=(elso2+utolso2)/2;
            cout<<"? "<<xend<<" "<<1<<" "<<xend<<" "<<koz<<endl;
            cout.flush();
            cin>>qu;
            if(qu%2==0) elso2=koz+1;
            else utolso2=koz-1;
        }
        cout<<"! "<<xstart<<" "<<elso1<<" "<<xend<<" "<<elso2<<endl;
        cout.flush();
        return 0;
    }
    int ystart=0;
    int yend=n;
    for(int i=1; i<n; i++)
    {
        cout<<"? "<<1<<" "<<i<<" "<<n<<" "<<i<<endl;
        cout.flush();
        cin>>qu;
        if(qu%2==1)
        {
            if(ystart==0) ystart=i;
            else yend=i;
        }
    }
    int elso1=1;
    int utolso1=n;
    while(elso1<=utolso1)
    {
        int koz=(elso1+utolso1)/2;
        cout<<"? "<<1<<" "<<ystart<<" "<<koz<<" "<<ystart<<endl;
        cout.flush();
        cin>>qu;
        if(qu%2==0) elso1=koz+1;
        else utolso1=koz-1;
    }
    int elso2=1;
    int utolso2=n;
    while(elso2<=utolso2)
    {
        int koz=(elso2+utolso2)/2;
        cout<<"? "<<1<<" "<<yend<<" "<<koz<<" "<<yend<<endl;
        cout.flush();
        cin>>qu;
        if(qu%2==0) elso2=koz+1;
        else utolso2=koz-1;
    }
    cout<<"! "<<elso1<<" "<<ystart<<" "<<elso2<<" "<<yend<<endl;
    cout.flush();

    return 0;
}