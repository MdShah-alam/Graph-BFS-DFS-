#include<bits/stdc++.h>
using namespace std;

string reverse_recursive(string s)
{
    if(s.size()==0)
        return "" ;
    return reverse_recursive(s.substr(1))+s[0];
}

int main()
{
    string s;
    cin>>s;
    string st=reverse_recursive(s);
    cout<<st<<endl;
}
