#include<bits/stdc++.h>
using namespace std;
set<string> ss;
int n,i,j,ii;
string a,b;
int main(){
	cin>>n;
	for(ii=1;ii<=n;++ii){
		cin>>a;b.clear();
		for(i=0;i<(int)a.size()-1;++i){
			if(a[i]=='k'){
				for(j=i;j<(int)a.size() && a[j]=='k';++j);
				if(j<(int)a.size() && a[j]=='h'){
					i=j,b=b+'h';
				}else b=b+a[i];
			}else if(a[i]=='u')b=b+"oo";
					else b=b+a[i];
		}
		if(i==(int)a.size()-1){
			if(a[i]=='u')b=b+"oo";
				else b=b+a[i];
		}
		//cout<<b<<"?"<<endl;
		ss.insert(b);
	}
	printf("%d\n",int(ss.size()));
	return 0;
}