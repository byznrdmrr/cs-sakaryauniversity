#include <iostream>
using namespace std;

int topla(int x,int y)
{
    return x+y;
}
int main()
{
  int (*p)(int,int);
  p=topla;
  cout<<(*p)(25,30);
}
