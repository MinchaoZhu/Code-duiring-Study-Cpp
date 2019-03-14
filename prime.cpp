#include <iostream>
#include <math.h>

using namespace std;

bool isPrime(unsigned long num)
{
   unsigned long endCheck = sqrt(num);
    for(unsigned long i = 2; i< endCheck+1;++i){
        if(!(num%i))
            return 0;
    }
    return 1;
}

void checkPrime(unsigned long start,unsigned long end)
{
    unsigned long i;
    for(i = start;i<end+1;++i){
        if(isPrime(i)){
            cout<<i<<endl;
        }
    }
    return;
}




int main(void){
    unsigned long start = 2;
    unsigned long end = 4294967295-1;
    checkPrime(start,end);
    return 0;
}
