/*
Как уже говорилось, классы можно заставлять вести себя как массивы. 
Пример ниже показывает один из способов создания такого класса. 
Взяв за основу приведенную программу, добавьте перегружаемое присваивание и перегружаемый конструктор копирования к классу Array. 
Затем добавьте к main() выражение Array arr2(arrl); и arr3=arrl; для проверки того, что перегружаемые операции работают. 
Конструктор копирования должен создать новый объект Array со своим собственным местом в памяти, выделенным для хранения элементов массива. 
И конструктор копирования, и оператор присваивания должны копировать содержимое старого объекта класса Array в новый. 
*/


#include <iostream>
using namespace std;
////////////////////////////////////////////////////////////////
class Array                     //models a normal C++ array
   {
   private:
      int* ptr;                 //pointer to Array contents
      int size;                 //size of Array
   public:
      Array(int s)              //one-argument constructor
		  {
			 size = s;              //argument is size of Array
			 ptr = new int[s];      //make space for Array
		  }
		Array(const Array &copy) : size(copy.size)
		{
			if(size > 0)
			{
				ptr = new int [size];
				for(int i = 0; i < size; ++i)  ptr[i] = copy.ptr[i];
			}
		}
      ~Array()                  //destructor
         { delete[] ptr; }
      int& operator [] (int j)  //overloaded subscript operator
         { return *(ptr+j); }
		Array& operator= (const Array &arr)
		{
			if (this == &arr)
				return *this;

			if (ptr) delete[] ptr;
 
			size = arr.size;
 
			ptr = new int[size];
			for (int i=0; i < size; ++i)
				ptr[i] = arr.ptr[i];
 
			return *this;
		}
   };
////////////////////////////////////////////////////////////////
int main()
{
   const int ASIZE = 10;        //size of array
   Array arr(ASIZE);            //make an array
   

   for(int j=0; j<ASIZE; j++)   //fill it with squares
      arr[j] = j*j;

   Array arr2(arr);

   for(int j=0; j<ASIZE; j++)       //display its contents
      cout << arr2[j] << ' ';

   Array arr3(ASIZE);
   arr3 = arr2;

   cout << endl;
   for(int j=0; j<ASIZE; j++)       //display its contents
      cout << arr3[j] << ' ';

   cout << endl;
   std::system("pause");
   return 0;
}
