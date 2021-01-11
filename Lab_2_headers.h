/* CISC-2200 - SPRING 2020
PROFESSOR HANPING XU
2/6/20
PETER HUGHES
LAB #2
*/

#ifndef _LAB2_H_
#define _LAB2_H_

    // PROGRAM HEADERS

 	#include <iostream>
    #include <fstream>
 	#include <string>
    #include <vector>
 
 	using namespace std;

    const int INIT_SIZE = 10;

    // CLASS NAME WITH DEFAULT CONSTRUCTOR, MEMBER FUNCTIONS AND PRIVATE VARIABLES

 	class DollarAmount
 	{
 		public:

		DollarAmount( );

        void convertDollars(int num);

        friend istream& operator >>(istream &instream, DollarAmount &amount);

        friend ostream& operator <<(ostream &outstream, DollarAmount &amount);

        friend DollarAmount operator +(DollarAmount &amount1, DollarAmount &amount2);

        friend int operator +(DollarAmount &amount1, int amount2);
/*        
        friend bool operator >(DollarAmount &amount1, DollarAmount &amount2);
*/
        int get_dollar();

        int get_cents();

        int get_total();


 		private:

 		int dollars, cents;
        char decimal;


 	};

#endif







