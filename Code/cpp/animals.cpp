#include<bits/stdc++.h>
#include<string>
#include<vector>
using namespace std;
class animals{
    protected:
    string _name;

    public:
    virtual void sound() = 0;
    animals(string &name ) :_name(name){};
    virtual ~animals() {};

};

class dog : public animals{
    public: 
    dog(string name) : animals(name){};
    void sound(){
        cout<<"woof!\n";
    }
};

class cat : public animals{
    public: 
    cat (string name) : animals(name){};
    void sound(){
        cout<<"meow\n";
    }
};

class arr {
    private :
    animals** data;
        size_t cap;
        size_t count;

    public:
    arr (size_t cap) : cap(cap),count(0){
       data = new animals*[cap];
    }
    void add(animals* a) { data[count++] = a; };

    class Iterator{
        private:
        animals** p;
        public:

        Iterator (animals** p) :p(p){};

        animals*& operator*() { return *p; }
        Iterator& operator++(){
            p++;
            return *this;
        };
        bool operator!=(const Iterator other){
            return p !=other.p;
        };
   
    };

        Iterator begin() { return Iterator(data); };
        Iterator end() { return Iterator(data + count); };
        ~arr() { delete[] data; }
};
int main(){
    arr zoo(10);

    zoo.add(new dog("dog"));
    zoo.add(new cat("cat"));

    for(animals* a :zoo)
    {
        a->sound();
    }

    return 0;
}