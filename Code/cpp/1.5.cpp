#include<iostream>
#include<string>
using namespace std;
int main(){
    string name;
    cout<<"你的名字是?\n";
    cin>>name;
    if(name.size()>=2)
    {
        cout<<"ok "<<name<<endl;
    }
}
