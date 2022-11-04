#include<iostream>
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
using namespace std;
string s,ss;
int n,l,d,p,a,b;
int main(){
	cin>>n>>s;
	while (1){
		l=s.length();
		ss="";
		d=0;
		p=0;
		for (int i=0;i<l;i++)
			if (s[i]=='D'){
				d=1;
				if (b) b--;
				else{
					ss+='D';
					a++;
				}
			}
			else{
				p=1;
				if (a) a--;
				else{
					ss+='R';
					b++;
				}
			}
		if (d==0){
			printf("R");
			return 0;
		}
		if (p==0){
			printf("D");
			return 0;
		}
		s=ss;
	}
}