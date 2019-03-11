/*
 * @Author: Minchao Zhu 
 * @Date: 2019-03-10 20:59:54 
 * @Last Modified by: Minchao Zhu
 * @Last Modified time: 2019-03-10 21:34:21
 */

/*
Using the iterator template to build find()
*/
#include <iostream>
#include <vector>
using namespace std;

template<typename iterType, typename valType>
iterType find(iterType begin, iterType end, valType value){
    int i = 0;
    for(;begin<end;++begin){
        if((*begin) == value)
            return begin;
    }
    return end; 
}



int main(void){
    vector<int> intVec = {1,2,3,4,5,6};
    vector<int>::iterator  iIter;
    iIter = find(intVec.begin(),intVec.end(),5);
    cout << *iIter << endl;
    return 0;
}