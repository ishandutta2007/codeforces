#include<bits/stdc++.h>
using namespace std;
int a[1100],f[100],n;
int main(){
     int k=2;
     f[1]=1;
     f[2]=1;
     a[1]=1;
	 while (f[k]<=1000)
	  {
	     f[++k]=f[k-1]+f[k-2];
	     a[f[k]]=1;
	  }
	  cin>>n;
	  for (int i=1;i<=n;i++)if (a[i]==1) cout<<"O";
	  else cout<<"o";
	  cout<<endl;
    return 0;
}