#include<bits/stdc++.h>
using namespace std;

int p[400010];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--){
		int g=0,s=0,b=0;
		int n;
		cin>>n;
		for(int i=1;i<=n;i++)
			cin>>p[i];
		int c=1;
		while(c+1<=n&&p[c+1]==p[c])
			c++;
		g=c;
		c++;
		while(c<=n){
			while(c+1<=n&&p[c+1]==p[c])
				c++;
			s=c-g;
			if(s>g)	break;
			c++;
		}
		while(c<=n){
			while(c+1<=n&&p[c+1]==p[c])
				c++;
			if(c*2>n)	break;
			b=c-g-s;
			c++;
		}
		if(b==0||s==0||g==0||(b+s+g)*2>n||b<=g||s<=g)
			cout<<0<<' '<<0<<' '<<0<<'\n';
		else
			cout<<g<<' '<<s<<' '<<b<<'\n';

	}
}