#include <iostream>
#include <string>

using namespace std;

string f0 = "What are you doing at the end of the world? Are you busy? Will you save us?";
string s1 = "What are you doing while sending \"";
string s2 = "\"? Are you busy? Will you send \"";
string s3 = "\"?";

long long lenght[1000];

long long c(int n, long long k)
{
    //cout<<n<<" "<<k<<endl;
    if(n == 0)
    {
        if(k < f0.size())
            return f0[k];
        return -(int)f0.size();
    }
    if(k < s1.size())
    {
        return s1[k];
    }
    long long s = s1.size();
    if(n >= 55)
        return c(n-1, k-s);
    s += lenght[n-1];
    if(k < s)
    {
        return c(n-1, k-s+lenght[n-1]);
    }
    s += s2.size();
    if(k < s)
    {
        return s2[k-s+s2.size()];
    }
    s += lenght[n-1];
    if(k < s)
        return c(n-1, k-s+lenght[n-1]);
    if(k-s < s3.size())
        return s3[k-s];
    s += s3.size();
    //cout<<"!"<<s<<" "<<lenght[n]<<" "<<endl;
    return -s;
}

int main()
{
    int q, n;
    long long k;
    cin>>q;
    lenght[0] = f0.size();
    long long last = f0.size();
    int it = 1;
    while(last < 2000000000000000000)
    {
        last = 2*last+s1.size()+s2.size()+s3.size();
        lenght[it] = last;
        it++;
        //cout<<it<<endl;
    }
    for(int i = 0; i < q; i++)
    {
        //cout<<endl<<endl;
        cin>>n>>k;
        k--;
        long long x = c(n, k);
        if(x > 0)
            cout<<(char)x;
        else
            cout<<".";
    }
    cout<<endl;
    return 0;
}