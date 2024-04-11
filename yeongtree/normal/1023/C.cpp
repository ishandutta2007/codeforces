#include <iostream>
#include <stack>

using namespace std;

int main()
{
    int n,k; cin>>n>>k;
    bool arr[n]; bool check[n]; char a;
    for(int i=0;i<n;i++) {cin>>a; arr[i]=(a=='('); check[i]=false;}
    int x=(n-k)/2;
    stack<int> br;
    for(int i=0;i<n;i++)
    {
        if(arr[i])
        {
            br.push(i);
            if(x)
            {
                check[i]=true;
                x--;
            }
        }
        else
        {
            int j=br.top(); br.pop();
            if(check[j]) {check[i]=true;}
        }
    }
    for(int i=0;i<n;i++)
    {
        if(check[i]) continue;
        if(arr[i]) cout<<'(';
        else cout<<')';
    }
    return 0;
}