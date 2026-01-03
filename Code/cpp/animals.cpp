#include<string>
#include<vector>
#include<iostream>
using namespace std;
class animals{
    protected:
    string _name;

    public:
    virtual void sound() = 0;/*纯虚函数*/
    animals(string &name ) :_name(name){};/*构造函数,(&引用传递),:后赋值*/
    virtual ~animals() {};/*虚拟析构函数,同时释放子类的多态*/

};

class dog : public animals{ /* :表示继承的子类*/
    public: 
    dog(string name) : animals(name){};/*构造函数,引用传参,注:<name>传给了aniamls类的中的_name*/
    void sound(){
        cout<<"woof!\n";
    }
};

class cat : public animals{/*同理*/
    public: 
    cat (string name) : animals(name){};
    void sound(){
        cout<<"meow\n";
    }
};
//指针和数组名在很多场景下是可以互换使用的
class arr { 
    private :
    animals** data; /*二级指针,指向一个<指向animals类的的指针>*/
        size_t cap; //无符号整型
        size_t count;

    public:
    arr (size_t cap) : cap(cap),count(0){ //构造函数同时赋值
       data = new animals*[cap]; //给data分配内存,大小为存放cap个animals指针的数组大小(指针数组)
    }
    void add(animals* a) { data[count++] = a; };//函数:给数组赋值

    class Iterator{ //迭代器
        private:
        animals** p;//二级指针
        public:

        Iterator (animals** p) :p(p){};//构造函数

        animals*& operator*() { return *p; } //运算符重载,返回animals指针
        Iterator& operator++(){ //让p指向下一个animals类指针,返回迭代器对象
            p++; 
            return *this;
        };
        bool operator!=(const Iterator other){
            return p !=other.p; //运算符重载,判断迭代器是否相等
        };
   
    };

        Iterator begin() { return Iterator(data); };
        Iterator end() { return Iterator(data + count); };
        ~arr() { delete[] data; } //注意,释放数组内存时要加[]
};
int main(){
    arr zoo(10);//创建指针数组

    zoo.add(new dog("dog"));//
    zoo.add(new cat("cat"));

    for(animals* a :zoo) //迭代器的语法糖
    {
        a->sound();
    }

    return 0;
}