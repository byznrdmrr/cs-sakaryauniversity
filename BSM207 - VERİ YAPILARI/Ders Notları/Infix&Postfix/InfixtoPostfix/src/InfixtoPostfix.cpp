// isdigit metodunu içeren kütüphane parametre olarak verilen karakterin rakam olup olmadýðýný döndürüyor.
#include <cctype>  
// strchr kullanabilmek için, string'te aranan karakterin ilk konumunu döndürür.
#include <cstring>    

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
            while(isdigit(infix[i])){ postfix+=infix[i]; i++;}
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
		postfix += " ";
		stack->pop();
    }
	delete stack;
    return postfix;
}

int main()
{
   string sayi;
   cout<<"Infix ifade:";
   cin>>sayi;
   cout<<"Postfix:"<<InfixtoPostfix(sayi)<<endl;
   return 0;
}