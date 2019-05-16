#include <iostream>
#include <string>
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
	  virtual bool isOveersize()
	  {
		  return false;
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
	  bool isOveersize()
	  {
		  if(pages > 800) return true;
			  else return false;
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
	  bool isOveersize()
	  {
		  if(time > 90) return true;
			  else return false;
	  }
   };
////////////////////////////////////////////////////////////////
int main()
   {
   publication* pubarr[100];          //array of ptrs to pubs
   int n = 0;                         //number of pubs in array
   char choice;                       //user's choice
   
   do {
      cout << "\nEnter data for book or tape (b/t)? ";
      cin >> choice;
      if( choice=='b' )               //make book object
         pubarr[n] = new book;        //   put in array
      else                            //make tape object
         pubarr[n] = new tape;        //   put in array
      pubarr[n++]->getdata();         //get data for object
      cout << "   Enter another (y/n)? ";  //another pub?
      cin >> choice;
      }
   while( choice =='y');              //cycle until not 'y'

   for(int j=0; j<n; j++)             //cycle thru all pubs
   {
	   pubarr[j]->putdata();
	   cout << endl;
	   if(pubarr[j]->isOveersize()) cout << "Excess size!" << endl;
   }
   cout << endl;
   std::system("pause");
   return 0;
  }
