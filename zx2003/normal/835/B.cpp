#include<cstdio>
#include<iostream>
using namespace std;
long long a[15],k,i,ans,s;
char c[100005];
int main(){
	cin>>k;
	scanf("%s",c+1);
	for(i=1;c[i];++i)++a[c[i]-'0'],s+=c[i]-'0';
	if(s>=k)return puts("0"),0;
	s=k-s;
	for(i=0;i<10;++i)if(a[i]){
		if(1ll*(9-i)*a[i]<s)s-=1ll*(9-i)*a[i],ans+=a[i];
			else{
				ans+=(s-1)/(9-i)+1;
				break;
			}
	}	
	cout<<ans<<endl;
	return 0;
}