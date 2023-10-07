#include<iostream>
#include<math.h>
using namespace std;

int MUL(int A,int B)
{
    if(B == A -1)
    {
        return 1;
    }
    return B * MUL(A,B-1);
}

int ADD(int A,int B)
{
    if(B == A -1)
    {
        return 1;
    }
    return B + ADD(A,B-1);
}

