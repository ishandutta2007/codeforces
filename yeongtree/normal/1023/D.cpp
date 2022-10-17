#include <iostream>
#include <stack>

using namespace std;

int main()
{
    int n,q; cin>>n>>q; int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    int c_0=-1; int c_q=-1; int l_n=-1;
    for(int i=n-1;i>=0;i--)
    {
        if(arr[i]==0) c_0=i;
        if(arr[i]==q) c_q=i;
        if(arr[i]!=0) l_n=i;
    }
    if(c_0==-1&&c_q==-1) {cout<<"NO"; return 0;}
    if(c_q==-1) arr[c_0]=q;
    else {for(int i=0;i<l_n;i++) arr[i]=arr[l_n];}
    stack<int> s; bool check[q+1]; for(int i=1;i<=q;i++) check[i]=false;
    s.push(-1);
    for(int i=0;i<n;i++)
    {
        if(arr[i]==0) arr[i]=arr[i-1];
        if(s.top()>arr[i])
        {
            while(s.top()>arr[i])
            {
                check[s.top()]=true;
                s.pop();
            }
        }
        if(s.top()==arr[i]) continue;
        if(s.top()<arr[i])
        {
            if(check[arr[i]]) {cout<<"NO"; return 0;}
            s.push(arr[i]);
        }
    }
    cout<<"YES"<<endl;
    for(int i=0;i<n;i++) cout<<arr[i]<<" ";
    return 0;
}