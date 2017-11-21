#include <cstring>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdint.h>
#include <iostream>

using namespace std;

union bigRand {
    long long ll;
    uint32_t ii[2];   
};

uint64_t rand64() {
    bigRand b;
    b.ii[0] =  rand();
    b.ii[1] =  rand();
    return b.ll;
}

void Union (long long var) //С использованием только union
{           
    union 
    {
        long long varULong;  //varULong - переменная требуемого типа
        long long bytes;
    } byte;
    byte.varULong = var;
	for (int i=63; i>=30; i--)                                                  
        (byte.bytes >> i) = 0;
	cout<<" long long: "<< byte.varULong << endl;
    cout <<"  bity:  ";
        for (int i=63; i>=0; i--)                                                  
        cout<<" "<<((byte.bytes >> i) & 1);
    cout<<endl;
}

int main(){
	
	srand (time(NULL));
	long long p = 1234123412341234;
	long long p2 = 99999999999;
	printf("%lld\n", p);
	long long number = rand64();
	printf("%lld\n", number);
	long long ll = rand();
	printf("%lld\n", ll);
	Union(p2);
	return 0;
}
