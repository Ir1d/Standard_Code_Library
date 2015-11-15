/**
 * @name euler_primelist_generating.cpp
 * @subject Math
 * @author CJSoft(egwcyh@qq.com)
 * @Copyright DWTFABG
 * @comment returns a vector containing primes from 2 to upperBound
 */

// I used DocBlockr to make this comment!
// Simply type '/**' in the first line

/**
 * Need memory.h or cstring for memset func.
 * Need vector for whatever...
 */

#include <cstring>
#include <vector>

std::vector<int> genPrime(int upperBound){
    bool *isPrime=new bool[upperBound+7];
    int *prime=new int[upperBound+7];
    memset(isPrime,true,upperBound+7);
    memset(prime,0,(upperBound+7)*4);
    int cursor=0;
    for(int i=2;i<=upperBound;++i){
        if(isPrime[i])prime[cursor++]=i;
        for(int j=0;(j<cursor) && (i*prime[j]<=upperBound);++j){
            isPrime[i*prime[j]]=false;
            if(i%prime[j]==0)break;
        }
    }
    std::vector<int> vec_rtn(prime,prime+cursor);
    return vec_rtn;
}

/*-------------------------------------------------------*/

#include <iostream>
int main(){
    using namespace std;
    vector<int> p=genPrime(1000);
    for(int i=0;i<p.size();++i){
        cout<<p[i]<<endl;
    }
}