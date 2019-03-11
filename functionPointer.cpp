#include <iostream>
#include <vector>
#include <list>
#include <deque>
using namespace std;
/**
template<typename valType>
bool less_than(valType val1, valType val2){
    if(val1<val2)  
        return 1;
    return 0;
}

template<typename valType>
bool greater_than(valType val1, valType val2){
    if(val1>val2)  
        return 1;
    return 0;
}
**/

template<typename containerType, typename valueType> 
containerType filter(containerType &vec, valueType val, bool (*prefunc)(valueType, valueType)){
    size_t size = vec.size();
    int i;
    containerType nvec;
    for(i=0;i<size;++i){
        if(prefunc(vec[i],val))
            nvec.push_back(vec[i]);
    }
    return nvec;
}

template<typename valueType> 
bool less_than(valueType val1, valueType val2){
    if(val1<val2)  
        return 1;
    return 0;
}

template<typename valueType> 
bool greater_than(valueType val1, valueType val2){
    if(val1>val2)  
        return 1;
    return 0;
}

int main(void){
    deque<int> vec = {1,2,3,4,5,6,7,8,9};
    deque<int> nvec;
    nvec = filter(vec,6,greater_than);
    cout << nvec[0] << endl;
    return 0;
}