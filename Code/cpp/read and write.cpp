#include<fstream>
#include<string>
#include<iostream>
using namespace std;
int main(){
    ofstream outfile("eg.text",ios_base::app);
    //创建ofstream类的对象outfile;第一个参数是可写入文件名
    string a;
    cin>>a;
    if(!outfile)//如果打开失败
    {
        cout<<"yes";
        cerr<<"未能打开文件";
    }
    else
    {
        cout<<"hello"<<endl;
        outfile<<a;//把a写入参数文件
    }
}

/*类中定义了对象的属性和操作,
如ofstream类中的对象有打开文件的操作,加上<<符号有写入的操作
概念:重载运算符:
    同一个符号,根据所接参数的不同,对应的操作不同(目前我还不知道这是不是要自己写)
*/