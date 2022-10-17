#include<bits/stdc++.h>
using namespace std;
int a[301]={0};
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,last=0;
        cin>>n;
        string s;
        cin>>s;
        if(n==2&&s[0]>=s[1])
        {
            cout<<"NO"<<endl;
            continue;
        }
        cout<<"YES"<<endl<<2<<endl;
        cout<<s[0]<<" ";
        for(int i=1;i<n;i++)cout<<s[i];cout<<endl;
    }
    return 0;
}