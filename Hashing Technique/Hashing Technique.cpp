#include <iostream>
#include "Node.h"
#include "HashingFunctions.h"
using namespace std;

int main()
{
    Node *HT[10];  /*for chaning*/
    int i;

    int HT1[10]; /*for linear probing*/

    for (i = 0; i < 10; i++)
        HT1[i] = 0;

    int size = sizeof(HT1) / sizeof(int);

    for (i = 0; i < 10; i++)
        HT[i] = NULL;
    
    /*
    HashingFunctions::InsertChaning(HT, 12);
    HashingFunctions::InsertChaning(HT, 22);
    HashingFunctions::InsertChaning(HT, 42);
    HashingFunctions::InsertChaning(HT, 32);
    HashingFunctions::SearchChaning(HT, 23);
    HashingFunctions::DeleteChaning(HT, 32);
    */

    HashingFunctions::InsertDH(HT1, 5,size);
    HashingFunctions::InsertDH(HT1, 25,size);
    HashingFunctions::InsertDH(HT1, 15,size);
    HashingFunctions::InsertDH(HT1, 35,size);
    HashingFunctions::InsertDH(HT1, 95, size);



    cout<<"key is found at index "<<HashingFunctions::SearchDH(HT1, 101, size)<<endl;


}
