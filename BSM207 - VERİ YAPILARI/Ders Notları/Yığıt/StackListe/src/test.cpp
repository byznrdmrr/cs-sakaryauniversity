#include "Stack.hpp"

int main()
{
	Stack<int> *stack = new Stack<int>();
	stack->push(25);
	stack->push(32);
	stack->push(68);
	stack->push(74);
	stack->pop();
	cout<<stack->top();
	delete stack;
	cout<<endl;
	
	Stack<string> *stck = new Stack<string>();
	stck->push("Mehmet");
	stck->push("Veli");
	stck->push("Ahmet");
	stck->push("Sakarya");
	stck->pop();
	stck->pop();
	cout<<stck->top();
	delete stck;
	return 0;
}