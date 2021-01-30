#include <iostream>
using namespace std;

int kontrol;
const float pi=3.14;
int Arttir(){
    static int sayim = 0;
	sayim++;
    return sayim;
}
int main(){
    cout<<Arttir()<<endl;
    cout<<Arttir()<<endl;
    cout<<Arttir()<<endl;
}