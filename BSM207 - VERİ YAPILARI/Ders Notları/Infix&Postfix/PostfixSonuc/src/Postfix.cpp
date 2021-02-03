// isdigit metodunu içeren kütüphane parametre olarak verilen karakterin rakam olup olmadýðýný döndürüyor.
#include <cctype> 
// strchr kullanabilmek için, string'te aranan karakterin ilk konumunu döndürür. 
#include <cstring> 
// atof  kullanýmý için   
#include <cstdlib>   

#include "Stack.hpp"

/**
 Ýþlem önceliðini kontrol eden fonksiyon
 */
bool OncelikDusukmu(char ch1, char ch2)
{
	  if (ch1 == '(')
         return false;

	  else if (ch2 == '(')
		 return false;

      else if (ch2 == ')')
		 return true;

	  else if ((ch1 == '^') && (ch2 == '^'))
          return false;

  	  else if (ch1 == '^')
          return true;
    
	  else if (ch2 == '^')
          return false;

      else if ((ch1 == '*') || (ch1 == '/'))
          return true;

      else if ((ch2 == '*') || (ch2 == '/'))
          return false;

      else
          return true;

}

string InfixtoPostfix(string infix)
{
    int uzunluk = infix.length();
    Stack<char> *stack = new Stack<char>();
    string postfix = "";
 
    for (int i = 0; i < uzunluk; i++)
    {
        if (isdigit(infix[i]))
        {
            while(isdigit(infix[i])){ postfix+=infix[i]; i++;} // Ondalik sayýlar desteklenmiyor.
			postfix+=" ";
			i--;
			continue;
        }
        else if (infix[i] == '(')
        {
            stack->push(infix[i]);
        }
        else if ((infix[i] == '*') || (infix[i] == '+') || (infix[i] == '-') || (infix[i] == '/'))
        {
            while ((!stack->Bosmu()) && (stack->top() != '('))
            {
                if (OncelikDusukmu(stack->top(), infix[i]))
                {
                    postfix+=stack->top();
					postfix+=" ";
					stack->pop();
                }
                else
                {
                    break;
                }
            }
            stack->push(infix[i]);
        }
        else if (infix[i] == ')')
        {
            while ((!stack->Bosmu()) && (stack->top() != '('))
            {
                postfix+=stack->top();
				postfix+=" ";
				postfix+=" ";
				postfix+=" ";
				postfix+=" ";
				postfix+=" ";
				stack->pop();
            }
            if (!stack->Bosmu())
                stack->pop(); // Sol parantez yýðýttan pop ediliyor.
        }
        else
        {
        }
    }
    while (!stack->Bosmu())
    {
        postfix+=stack->top();
		postfix+=" ";
		stack->pop();
    }
	delete stack;
    return postfix;
}

double PostfixHesapla(string postfix)
{
   double sonuc = -1;
   int uzunluk = postfix.length();
   Stack<double> *yigit = new Stack<double>();
   for(int i=0;i<uzunluk;i++)
   {
	 // boþluklarý geç
     if (isspace(postfix[i])) continue;
     if (isdigit(postfix[i]))
        {
		   string sayi ="";
		   while(isdigit(postfix[i])){ sayi+=postfix[i]; i++;} // Ondalik sayýlar desteklenmiyor.
		   double s;
		   s=atof(sayi.c_str());
		   yigit->push(s);
		   i--;
		   continue;
		}
	 else // Operatör ise
	  {
	     double sayi2 = yigit->top();
		 yigit->pop();
		 double sayi1 = yigit->top();
		 yigit->pop();
	     switch(postfix[i])
		 {
		   case '+':
		     yigit->push(sayi1+sayi2);
			 break;
		   case '-':
		     yigit->push(sayi1-sayi2);
			 break;
		   case '*':
		     yigit->push(sayi1*sayi2);
			 break;
		   case '/':
		     if(sayi2==0) return -1;  // Sýfýra bölünme hatasý
		     yigit->push(sayi1/sayi2);
			 break;
		   default: // Hata Desteklenmeyen operatör
		     return -1;
			 break;
		 }
	  }
   }
   if(!yigit->Bosmu()) sonuc=yigit->top();
   yigit->pop();
   delete yigit;
   return sonuc;
}

int main()
{
   string sayi;
   cout<<"Infix ifade:";
   cin>>sayi;
   string postfix = InfixtoPostfix(sayi);
   cout<<"Postfix:"<<postfix<<endl;
   cout<<"Sonuc="<<PostfixHesapla(postfix)<<endl;
   return 0;
}