/******************************************************************************
 * File Name  : longestPalindrome.c
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
#include <string.h>


/*******************************************************************************
 *                               Definitions                                   *
 *******************************************************************************/

#define PALINDROME      0
#define NOT_PALINDROME  1



/***********************************************************************************************
 * Function Name      : checkpalindrome
 * Description        : a function to check if the input string  is PALINDROME or not
 * INPUTS             : a string to check it, and length of the string
 * RETURNS            : PALINDROME or NOT_PALINDROME
 ***********************************************************************************************/
int checkpalindrome(char *str,int strLength)
{
	int result = PALINDROME;
	int i = 0;
	int j = strLength - 1;
	while(i<j)
	{
		if(str[i] != str[j])
		{
			result = NOT_PALINDROME;
			break;
		}
		i++;
		j--;
	}
	return result;
}

/************************************************************************************************
 * Function Name      : stringReverse
 * Description        : function that reverse the input string (ahmad ==> damha)
 * INPUTS             : a string that wanted to be reversed
 * RETURNS            : void
 *************************************************************************************************/
void stringReverse(char *str)
{
	int i;
	int j = strlen(str) - 1;
	char temp;
	for(i=0;i<j; i++,j--)
	{
		temp = str[i];
		str[i] = str[j];
		str[j] = temp;
	}
}

/************************************************************************************************
 * Function Name      : copyPalindrome
 * Description        : function that copy the found Palindrome in a given new destination
 * INPUTS             : a destination string to save in it, a source destination and length of it
 * RETURNS            : void
 *************************************************************************************************/
void copyPalindrome(char* str1,char* str2, int palindromeLength)
{
	int i = 0;
	for(; i<palindromeLength; i++)
	{
		str1[i] = str2[i];
	}
	str1[i]   = '\0';
}

/************************************************************************************************
 * Function Name      : findLongestPalindrome
 * Description        : function that find the Longest Palindrome in a given string and prints it
 * INPUTS             : a string
 * RETURNS            : void
 *************************************************************************************************/
void findLongestPalindrome(char *str)
{
	int i;
	int j;
	int check = 0;
	int palindrome_Length = 0;
	int str_length  = strlen(str);
	char *stringcopy = (char *)malloc((str_length*sizeof(char)) + 1);
	strcpy(stringcopy,str);
	char token[] = "dqa642jn89b"; // a token that printed with the final result as we will see

	for(i = 0; i<str_length-2; i++)
	{
		for(j = i+2; j<str_length; j++)
		{
			if(str[j] == str[i])
			{
				palindrome_Length = j-i+1;
				if(checkpalindrome((str+i), palindrome_Length) == PALINDROME)
				{
					check = 1;
					break;
				}
			}
		}
		if(check == 1)
		{
			break;
		}
	}
	if(check == 1)
	{
		copyPalindrome(stringcopy,str+i,palindrome_Length);
	}
	else
	{
		strcpy(stringcopy,"none");
	}

	// printing the results
	stringReverse(stringcopy);
	printf("%s:",stringcopy);
	stringReverse(token);
	printf("%s",token);
}



/*******************************************************************************
 *                                Main                                         *
 *******************************************************************************/
int main(void)
{
	char *str = "hellosannasmith";
	findLongestPalindrome(str);
	return 0;
}
