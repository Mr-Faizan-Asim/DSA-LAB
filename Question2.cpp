#include<iostream>
#include<math.h>
using namespace std;

string DecimalToBinary(int n)
{
    if(n/2 == 0)
    {
        return "1";
    }
    return DecimalToBinary(n/2) + to_string((n%2));
}
int DecimalToBinaryInt(int n)
{
    if(n/2 == 0)
    {
        return 1;
    }
    return DecimalToBinaryInt(n/2)*10 + ((n%2));
}
int GCD(int A,int B)
{
    if(A%B == 0)
    {
        return B;
    }
    return (B,A%B);
}
int main()
{
    

}