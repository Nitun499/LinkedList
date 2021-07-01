#include<bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; i++)
using namespace std;
void Swap(int & x,int &y){
    int temp=x;
    x=y;
    y=temp;
}

int main(){
    int a=1,b=2;
    cout<<a<<" "<<b<<endl;
    Swap(a,b);
     cout<<a<<" "<<b<<endl;
    return 0;
}