#include<bits/stdc++.h>
using namespace std;

int gdc(int a,int b)
{
    if(b!=0)
        return gdc(b,a%b);
    else
        return a;
}
int main()
{
    int a,b;
    cin>>a>>b;
    cout<<gdc(a,b)<<endl;
}
