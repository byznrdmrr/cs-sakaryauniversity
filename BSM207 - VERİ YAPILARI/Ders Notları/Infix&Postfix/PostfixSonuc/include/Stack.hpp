#ifndef STACK_HPP
#define STACK_HPP
 
#include <iostream>
using namespace std;

/**
	Generic yapý tasarlanacaðý zaman generic yapý ile ilgili tüm metot içerikleri baþlýk dosyasý içinde olmalýdýr.
*/
template <typename Nesne>
class Stack
{
   private:
      /**
		struct'ta public veya private tanýmý yapýlmadýðý sürece içerdiði elemanlar varsayýlan olarak publictir.
	  */
      struct Dugum
	  {
	      Nesne eleman;
		  Dugum *ileri;
		  Dugum(const Nesne &yeniEleman, Dugum *n=NULL)
		  {
		     eleman=yeniEleman;
			 ileri=n;
		  }
	  };
	  Dugum *stackBasi; // Yýðýtýn en üstünü tutuyor.
	  
	public:
		/**
			Varsayýlan Yapýcý metot
		*/
	   Stack()  
	   {
	      stackBasi=NULL;
	   }
	   /**
		 Kopyalama iþlemi yapan yapýcý metot (copy constructor)
	   */
	   Stack(const Stack &sag) 
	   {
	       stackBasi=NULL;
		   *this=sag;
	   }
	   ~Stack()  
	   {
	       Bosalt();
	   }
	   
	   /**
		Sadece okunabilir bir fonskiyon Yýðýtýn boþ olup olmadýðýný kontrol ediyor.
		*/
	   bool Bosmu() const 
	   {
	     // stackBasi NULL ise true döndür.
	      return stackBasi == NULL; 
	   }
	   
	   const Nesne &top() const
	   {
	      //if(Bosmu()) Hata kontrolü yapýlmasý gerekir.			
   
		  return stackBasi->eleman;
	   }
	   
	   /**
		 Yýðýtý boþaltýr.
	   */
	   void Bosalt() 
	   {
	     // Boþ olmadýðý sürece eleman çýkar.
	      while(!Bosmu()) 
		   {
			  pop();
		   }
	   }
	   
	   void pop()  
	   {
	       if(Bosmu()) return; // Hata oluþur
   
		   Dugum *eskiTepe = stackBasi;
		   stackBasi=stackBasi->ileri;
		   delete eskiTepe;
	   }
	   void push(const Nesne& x)  
	   {
	      stackBasi = new Dugum(x,stackBasi);
	   }
	   
	   /**
		Yýðýt Atama
	   */
	   const Stack& operator=(const Stack& sag)
	   {
	      if(this != &sag)
		   {
			  Bosalt(); // Sol taraftaki stack'i boþalt.
			  if(sag.Bosmu()) return *this;
			  
			  Dugum *rptr = sag.stackBasi;
			  Dugum *ptr = new Dugum(rptr->eleman);
			  stackBasi=ptr;
			  
			  for(rptr=rptr->ileri;rptr!=NULL;rptr=rptr->ileri)
				  ptr=ptr->ileri=new Dugum(rptr->eleman);
		   }
		   return *this;
	   }
};
#endif