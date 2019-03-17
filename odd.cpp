#include <iostream>

using namespace std;


bool evenOrOdd(unsigned long num){//odd : return 1; even return 0
    bool x = 1;
    return x&num;
}



int main(void){
    bool tag = 0;
    for(int i = 0;i<100;++i){
        if(evenOrOdd(i))
            cout<<i<<" 奇数" <<endl;
        else
            cout<<i<<" 偶数" <<endl;
    }

    return 0;
}