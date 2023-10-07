#include<iostream>
#include<math.h>
using namespace std;

int Power(int x,int y, int M)
{
    if(y == 0)
    {
        return 1;
    }
    return x * Power(x,y-1,M);
}
int main()
{

}
