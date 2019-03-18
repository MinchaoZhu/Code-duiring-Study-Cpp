#include <iostream>
#include <stdlib.h>
#include <cstring>
using namespace std;



class stack{
    public:
        stack(){
            _size = 0;
            _capacity = 20;
            _s = (char*)malloc(_capacity*sizeof(char)); 

        }
        stack(const stack & _s0 ){
            _size = _s0.size();
            _capacity = _s0._capacity;
            _s = (char*)malloc(_capacity*sizeof(char)); 
            memcpy(_s,_s0._s,_capacity*sizeof(char));
        }
        ~stack(){
            free(_s);
        }
        char push(char);
        char pop();
        char seek() const;
        void freeArr(char*);
        bool find(char) const;
        bool empty() const;
        int size() const;
        void print()const;

    private:
        char* _s;
        int _size;
        int _capacity;

};
char stack::push(char ch){
    if(_size >= _capacity){
        _s = (char*)realloc(_s,2*_capacity);
        _capacity *= 2;
    }
    _s[_size] = ch;
    ++_size;
    return ch;
}
char stack::pop(){
    if(!_size){
        return 0;
    }
    --_size;
    return _s[_size];
}
char stack::seek()const{
    if(!_size){
        return 0;
    }
    return _s[_size-1];

}

bool stack::empty()const{
    if(!_size){
        return 1;
    }
    return 0;
}
int stack::size()const{
    return _size;
}
bool stack::find(char ch)const{
    int size = _size;
    for(int i = 0;i<size;++i){
        if(_s[i]==ch)
            return 1;
    }
    return 0;
}
void stack::freeArr(char * _s){
    free(_s);
}
void stack::print()const{
    for(int i = 0;i<_size;++i){
        cout<<_s[i]<<endl;
    }
}


int main(void){
    stack iS;
    for(int i = 0;i<29;++i){
        iS.push('a'+i%26);
    }
    stack iS2 = iS;
    cout<< "size is "<< iS2.size()<<endl;
    iS2.print();

    return 0;
}