#include <iostream>
#include <string>
#include <list>
using namespace std;
////////////////////////////////////////////////////////////////
class publication
   {
   private:
      string title;
      float price;
   public:
      virtual void getdata()
         {
			 cout << "\nEnter title: "; cin >> title;
			 cout << "Enter price: "; cin >> price;
         }
      virtual void putdata()
         {
			 cout << "\n\nTitle: " << title;
			 cout << "\nPrice: " << price;
         }
   };
////////////////////////////////////////////////////////////////
class book : public publication
   {
   private:
      int pages;
   public:
      void getdata()
         {
			 publication::getdata();
			 cout << "Enter number of pages: "; cin >> pages;
         }
      void putdata()
         {
			 publication::putdata();
			 cout << "\nPages: " << pages;
         }
   };
////////////////////////////////////////////////////////////////
class tape : public publication
   {
   private:
      float time;
   public:
      void getdata()
         {
			 publication::getdata();
			 cout << "Enter playing time: "; cin >> time;
         }
      void putdata()
         {
			 publication::putdata();
			 cout << "\nPlaying time: " << time;
         }
   };
////////////////////////////////////////////////////////////////
int main()
{
   std::list<publication *> pubarr;          //array of ptrs to pubs
   int n = 0;                         //number of pubs in array
   char choice;                       //user's choice
   
   do {
      cout << "\nEnter data for book or tape (b/t)? ";
      cin >> choice;
      if( choice=='b' ) 
	  {
		  book * newBook = new book();
		  newBook->getdata();
          pubarr.push_back(newBook);        
	  }
      else
	  {
		  tape * newTape = new tape();
		  newTape->getdata();
          pubarr.push_back(newTape);      
	  }   
      cout << "   Enter another (y/n)? ";  
      cin >> choice;
   }
   while( choice =='y');              //cycle until not 'y'

   for (std::list<publication *>::iterator iter = pubarr.begin(); iter != pubarr.end(); iter++)
   {
        (*iter)->putdata();
   }
   cout << endl;
   std::system("pause");
   return 0;
  }
