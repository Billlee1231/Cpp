/*
 * Bus tickets are numbered with a 6 digits number from 000000 to 999999. 
 * Write a program that counts number of all 'lucky' bus tickets. A Ticket is considered to be 'lucky' 
 * if the sum of the first 3 digit equals the sum of last 3 digits. Example 123321 when broken a part 
 * is (1+2+3=6) and (3+2+1=6). 
 */

/* 
 * File:   main.cpp
 * Author: yichu
 *
 * Created on March 11, 2018, 8:12 PM
 */

#include <iostream>
#include <math.h>

using namespace std;

// A recursive function that returns the number of combinations given the sum and number of digits left
int wayCount(int sum, int noDigit){
	if (noDigit>1)
	{
		int count	=	0;
		// j must be greater or equal to 0 and smaller or equal to 9
		for (int j=max(0,(sum-(noDigit-1)*9));j<=min(sum,9);j++)
		{
			count+=wayCount(sum-j, noDigit-1);
		}
		return count;
	}
	else if (noDigit==1) // ending condition
		return 1;
	else return 0; // error handling
}

int main(){
	int totalCount	=	0;
	for (int sum=0;sum<=27;sum++){// the total sum of 3 digits could range from 0 to 27
		totalCount+=pow(double(wayCount(sum,3)),2.0); // power to 2 because of multiplication rule
	}
	cout<<"The total count of lucky tickets is: "<<totalCount<<"."<<endl;
	
	// The fix
	char a;
	cout<<"Enter any key to exit...";
	cin>>a;
        return 0;
}
