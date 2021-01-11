/* CISC-2200 - SPRING 2020
PROFESSOR HANPING XU
2/6/20
PETER HUGHES
LAB #2
*/

    #include "Lab_2_headers.h"
    #include <fstream>
  	#include <iostream>
    #include <string>
 
 	using namespace std;


 	int main()
 	{
        DollarAmount cash;
        cout << "Enter an amount for deposit: ";
        cin >> cash;

        /* object pointer declarations, INIT_SIZE is size of dynamic array, arr_size is an int 
            equal to size of the array, arr points to dynamic array, ptr is null
        */

        DollarAmount *arr = new DollarAmount[INIT_SIZE];
        DollarAmount *ptr = NULL;
        int arr_size = INIT_SIZE;
        int arr_len = 0;
        DollarAmount total;
        bool lastInput = false;

        do
        {
            if (arr_len == arr_size)
            { 
                // ptr is double the size of new array;

                ptr = new DollarAmount[arr_size * 2];

                // copy each element of arr into new array that
                // ptr points to (use a for-loop)

                for (int i = 0; i < arr_size*2; ++i)
                    ptr[i] = arr[i];

                // deletes allocated memory for arr and assigns it to ptr,
                // array_size is doubled
                delete [] arr;
                arr = ptr;
                arr_size = arr_size * 2;
            }

            cout << "Enter the dollar amount: $";
            cin >> arr[arr_len];


            // allows for input such as 0.0

            if ( (arr[arr_lenn].get_dollar() == 0)  && (arr[arr_len].get_cents() == 0) )
                lastInput = true;
            else
                arr_len++;
            
            	
 	      } while (!lastInput);


          


          // copies everything from old array (arr) into new array (ptr)

          DollarAmount total;

          for (int i = 0; i < arr_size; i++)
          {
                total = total + arr[i];
          }


          // bubble sort for the array

          int n_size = arr_size - 1;
          
          for (int p = 0; p < arr_size; p++)
          {
                for (int j = 0; j < n_size; j++)
                {
                    if (arr[j] < arr[j+1])
                    {
                        DollarAmount temp;
                        temp = arr[j+1];
                        arr[j+1] = arr[j];
                        arr[j]= temp;
                    }
                }

                n_size = n_size - 1;
          }



          cout << "List of Sorted Elements: " << endl;
          int count = 0;

          for (int k = 0; k < arr_size; k++)
          {

            if ( (arr[k].get_dollar() == 0) && (arr[arr_len].get_cents() == 0) )
                cout << "";
            else
            {
                cout << arr[k] << endl;
                count++;
            }

          }

          total.convertDollars(total.get_dollar());
          cout << "The total is $" << total.get_dollar() << endl;
          cout << "and " << total.get_cents() << "/100" << endl;
/*
          if ( (total.check(total.get_dollar()) && (total.check(total.get_cents()) )
          {
                cout << "The total is $" << total << endl;
                total.convertDollars(get_dollar());
                cout << total.get_dollar();
                cout << "and " << total.get_cents() << "/100" << endl;
          } 
*/
          int remainder = 10 - count;
          DollarAmount median;

          if (count % 2 == 0)
          {
              median = ( arr[remainder + ((count-1)/2)] + arr[remainder + (count/2)] );
              median = median / 2;
          }

          else
          {
              median = arr[remainder + (count/2)];
          }

          cout << "The median is $" << median << endl;
          cout << "Goodbye!";

          return 0;


    }








