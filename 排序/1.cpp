#include<iostream>
#include<stack>
using namespace std;

int main(){
    int a=123000;
    int ans=0;
    while(a){
        int temp=a%10;
        a=a/10;
        ans=ans*10+temp;
    }
    cout<<ans<<endl;  
}