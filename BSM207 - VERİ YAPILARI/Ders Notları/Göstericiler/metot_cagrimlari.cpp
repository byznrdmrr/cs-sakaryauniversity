#include <iostream>
using namespace std;

int k,c;

void E(int x){
       int y = 2*x;
       int z = y + 1; 
}

void F(int a,int b){
       int x,y;
       c=a*b;
       E(c);
}
int main(){
      int s=3,r=4;
      k=s+r;
      F(s,r);    
}
