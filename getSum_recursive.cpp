#include<bits/stdc++.h>
using namespace std;

int getsum(int n)
{
    if(n==0)
        return 0;
    return (n%10+getsum(n/10));
}

int main()
{
    int n;
    cin>>n;
    cout<<getsum(n)<<endl;
}
