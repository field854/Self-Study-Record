#include<iostream>//库里有类的定义;引出cin/cout对象
#include<string>//string类的定义
using namespace std; //
int main(){
    string first_name,last_name;//string类中定义对象name
    cout<<"你的名是?\n";
    cin>>first_name;
    cout<<"你的姓是?\n";
    cin>>last_name;
    cout<<"hello "
        <<first_name
        <<last_name
        <<"\n";
    return 0;
}
/*

*/