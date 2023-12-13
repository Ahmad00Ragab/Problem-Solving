/******************************************************************************
 * File Name  : Class_Seats.c
 * Description: 
 * Author     : Ahmad Haroun
 * Date       : Dec 13 2023
 *******************************************************************************/

/*
 * problem: 
 *
 */

/*******************************************************************************
 *                                INCLUDES                                     *
 *******************************************************************************/
#include <stdio.h>
#include <stdlib.h>



/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
 
#define OCCUPIED       0
#define NOT_OCCUPIED   1




/*******************************************************************************
 *                              Functions Definitions                          *
 *******************************************************************************/
 
 
 
 
 
/***********************************************************************************************
 * Function Name      : checkOccupied
 * Description        : a function to check if the input seat number is occupied or not 
 * INPUTS             : seat number , array of the occupied seats , and length of this array
 * RETURNS            : OCCUPIED or NOT_OCCUPIED
 ***********************************************************************************************/
int checkOccupied(int number, int arr[], int arrLenght)
{
	int result = NOT_OCCUPIED;
	for(int i = 0; i < arrLenght; i++)
	{
		if(number == arr[i])
		{
			result = OCCUPIED;
			break;
		}
	}
	return result;
}



/***********************************************************************************************************
 * Function Name      : countNumberofSeatingWays
 * Description        : function that calculates the number of ways of setting two new students in the class
 * INPUTS             : array that contains the number of seats in the class and the occupied seats
 * RETURNS            : void
 ***********************************************************************************************************/
void countNumberofSeatingWays(int arr[], int arrLength)
{
	
   int i;
   int j;
   int k;
   int m;
   int counter = 0;
   int numberOfSeats = arr[0];
   int check;
   for(i = 1; i <= numberOfSeats; i++)
   {
		if(checkOccupied(i,(arr+1),(arrLength-1)) == NOT_OCCUPIED)
		{
			
			if(i%2==0)
			{
				j = i+2;
				k = i-2;
				m = i-1;
				if(j <= numberOfSeats)
				{
					if(checkOccupied(j,(arr+1),(arrLength-1)) == NOT_OCCUPIED)
					{
						counter++;
					}
				}
				if(k >= 1)
				{
					if(checkOccupied(k,(arr+1),(arrLength-1)) == NOT_OCCUPIED)
					{
						counter++;
					}
				}
				if(m >= 1)
				{
					if(checkOccupied(m,(arr+1),(arrLength-1)) == NOT_OCCUPIED)
					{
						counter++;
					}
				}
			}
			else
			{
				j = i+2;
				k = i-2;
				m = i+1;
				if(j <= numberOfSeats)
				{
					if(checkOccupied(j,(arr+1),(arrLength-1)) == NOT_OCCUPIED)
					{
						counter++;
					}
				}
				if(k >= 1)
				{
					if(checkOccupied(k,(arr+1),(arrLength-1)) == NOT_OCCUPIED)
					{
						counter++;
					}
				}
				if(m <= numberOfSeats)
				{
					if(checkOccupied(m,(arr+1),(arrLength-1)) == NOT_OCCUPIED)
					{
						counter++;
					}
				}
				i +=2;
			}
			
		}
   }
  
   printf("%d",counter);
	
}



/*******************************************************************************
 *                                Main                                         *
 *******************************************************************************/
int main(void)
{
   int  arr[10] = {16,1,2,3,4,5,6,7,8,9};  /* arr[0] represents the total number of seats in the class */
   ArrayChallenge(arr,10);                 /* the rest of array elements represent the occupied seats  */
   return 0;
}
