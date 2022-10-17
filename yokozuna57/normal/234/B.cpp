#include<iostream>
using namespace std;

int main(){
FILE*infile,*outfile;
infile=fopen("input.txt","r");
outfile=fopen("output.txt","w");
int k,n,r[2000],small;
bool F[2000],b=true;
fscanf(infile,"%d %d\n%d",&n,&k,&r[0]);
for(int i=1;i<n;i++){fscanf(infile," %d",&r[i]);}
for(int i=0;i<2000;i++){F[i]=false;}
for(int i=100;i>-1;i--){
for(int j=0;j<n;j++){
if(k==0)break;
if(r[j]==i){
F[j]=true; k--;
if(k==0){small=i; break;}}
}}
fprintf(outfile,"%d\n",small);
for(int i=0;i<n;i++){if(F[i]){
if(!b){fprintf(outfile," %d",i+1);}
if(b){fprintf(outfile,"%d",i+1); b=false;}}}
fprintf(outfile,"\n");}