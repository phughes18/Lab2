/* CISC-2200 - SPRING 2020
PROFESSOR HANPING XU
2/6/20
PETER HUGHES
LAB #2
*/
    
    // PROGRAM HEADERS
    
    #include "Lab_2_headers.h"
 	#include <iostream>
    #include <fstream>
    #include <vector>
 	#include <string>
 
 	using namespace std;

    const int INIT_SIZE = 10;

    // DEFAULT CONSTRUCTOR

    DollarAmount::DollarAmount ( ) : dollars(0), cents(0), decimal('.')
    {

    }

    int DollarAmount::get_dollar()
    {
        return dollars;
    }

    void DollarAmount::get_cents()
    {
        return cents;
    }

    void DollarAmount::total()
    {
        return total;
    }





    istream& operator >>(istream &instream, DollarAmount &amount)
    {
        char entry;

        instream >> amount.dollars;
        instream >> amount.decimal;
        instream >> amount.cents;

        if (amount.dollars > 9999 || amount.dollars < 0 || amount.cents > 99 || amount.cents < 0)
        {
            do
            {

                cout << "Invalid deposit. To make new deposit, enter 'y': ";
                
                    cin >> entry;

                    if (entry == 'y')
                    {

                        instream >> amount.dollars;
                        instream >> amount.decimal;
                        instream >> amount.cents;
                    }

            } while ((amount.dollars > 9999 || amount.dollars < 0 || amount.cents > 99 || amount.cents < 0) && (entry == 'y'))   

        } 

        return instream;
    }

    // OVERLOADED OUTPUT OPERATOR

    ostream& operator <<(ostream &outstream, DollarAmount &amount)
    {
        outstream << amount.dollars;
        outstream << amount.decimal;
        
        if (amount.cents < 10)
            outstream << amount.cents << endl;
        else
            outstream << "0" << amount.cents << endl;
    }

    // OVERLOADED ADDITION OPERATOR

    int operator +(DollarAmount &amount1, DollarAmount &amount2)
    {

        DollarAmount sum;
        int sum = 0;

        sum = amount1.cents + amount2.cents;

        return sum;

    }

    int operator +(DollarAmount &amount1, int amount2)
    {

        DollarAmount sum;
        int sum = 0;

        sum = amount1.cents + amount2;

        return sum;

    }



    // OVERLOADED GREATER THAN OPERATOR
/*
    bool operator >(DollarAmount &amount1, DollarAmount &amount2)
    {
        if (amount1.dollars > amount2.dollars)
        {
            return true;
        }
        else if ((amount1.dollars == amount2.dollars) && (amount1.cents > amount2.cents))
        {
            return true;
        }

        return false;
    }
*/

 	// FUNCTION TO TRANSLATE DOLLARS (INTS) WORDS (STRINGS) USING 3 VECTORS; ONES,
    // TEENS, AND TENS. USES IF-STATEMENTS TO DETERMINE SIZE OF INT AND APPENDS CORRECT
    // PREFIX TO INT

    void DollarAmount::convertDollars(int num)
    {
        vector<string> ones {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
        vector<string> teens {"ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen","sixteen", "seventeen", "eighteen", "nineteen"};
        vector<string> tens {"", "", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};

        for (num = 0; n <= 20; n++)
        {
            if (num <= 10)
            {
                if (num == 10)
                    cout << teens[0];
                else
                    cout << ones[num];
            }

            else
            {
                if (num == 20)
                    cout << tens[2];
                else 
                    cout << teens[num-10];
            }


        int n=10;

        if (num <= n)
        {
            if (num == n)
            {
                cout << (teens[0]);
            }

            else
                cout << (ones[num]);
        }

        else if (num <= (2*n))
        {
            if (num == (2*n))
                cout << tens[2];
            else
                cout << teens[num - n]
        }
        

        else if ( num <= (n^2) )
        {
            cout << tens[num / n] + ((num % n != 0) ? " " + convertDollars(num % n) : "");
        } 
        
        else if ( num =< (n^3) )
        {
            cout << convertDollars((num / (n^2)) + " hundred" + (num % (n^2) != 0) ? " " + convertDollars(num % (n^2)) : "");
        } 
        
        else if (num =< 9999) 
        {
            cout << convertDollars(num / (n^3)) + " thousand" + ((num % (n^3) != 0) ? " " + convertDollars(num % (n^3)) : "");
        } 
        
        cout << "error";
    }
/*
    bool DollarAmount::check(int num)
    {
          if ((amount.dollars > 9999 || amount.dollars < 0 || amount.cents > 99 || amount.cents < 0))   
                return false;
          return true;
    }








