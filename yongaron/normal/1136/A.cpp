#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

#define ll long long

using namespace std;

int n;

int ls[123], rs[123];

int main(int argc, char const *argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i = 0; i < n; i++)
      cin>>ls[i]>>rs[i];
    int k;
    cin>>k;
    for(int i = 0; i < n; i++)
    {
      if(k <= rs[i]) 
      {
        cout<<n-i<<endl;
        return 0;
      }
    }
    cout<<0<<endl;
    return 0;
}