#include<bits/stdc++.h>
using namespace std;
char s[233];
int l,c;

int C(char x){
	if (x=='a'||x=='e'||x=='i'||x=='o'||x=='u') return 1;
	if (x=='1'||x=='3'||x=='5'||x=='7'||x=='9') return 1;
	return 0;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>s; l=strlen(s);
    for (int i=0;i<l;++i) c+=C(s[i]);
	cout<<c;
}