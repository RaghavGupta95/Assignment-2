////////////////////////////////////////////////////////////////////////////////////////////
//
//  author : Raghav Gupta
//  created: Thursday, Feb 2nd, 2017
//
//  Definitions of all the functions being used in the program
//
//
//
//
//
//***********DO NOT ATTEMPT TO PLAGIARIZE THIS CONTENT******************************
//***********IT IS KEPT TRACK OF BY THE AUTHOR AND PROFESSORS AT PENN STATE*********
#include "a2support.h"
#include <stdio.h>
#include <stdarg.h>
#include <time.h>
#include <string.h>


void showFloats(float Float_array[], int length) { //Print the float array
	for(int i=0; i < length; i++) {					//
		printf("%5.2f ", Float_array[i]); 			// print the array with 5 spaces at 2 decimal points
	}								//
	printf("\n");							// print newline	
}

void showIntegers(int Integer_array[], int length){ //Print the integer array
    for(int i=0; i < length; i++){					//
        printf("%5i ", Integer_array[i]);   				// print the array with 5 spaces
    }									//
    printf("\n");							// print newline
}

int countBits(unsigned int decimal){ //Count the total number of set bits in the input decimal number 
  int Bitcount = 0;							// Bitcount initially 0 
  while (decimal != 0){							// while Decimal is not equal to 0 
  	if (decimal%2 ==1){						// if the remainder == 1				
  		Bitcount +=1;						// then add 1 to bitcount  
  		}							//
  	decimal = decimal/2;						//
	}								// new decimal = decimal / 2
  return Bitcount;                     					// return total bitcount
}

void integerQuickSort(int Integer_array[], int left, int right){ //QuickSort the input integer array starting lowest to Highest 
  int pivot, i, j, temp;					//
  if(left < right) {						//
    pivot = left;						// select a pivot element
    i = left;							//
    j = right;							//
    while(i < j) {						// increment i till you get a number smaller than the
    	while(Integer_array[i] <= Integer_array[pivot] && i < right)    // pivot element
        i++;							//
      	while(Integer_array[j] > Integer_array[pivot] )		// decrement j till you get a number greater than the pivot 
        j--;							// element
      if(i < j) {						// if i < j 
        temp = Integer_array[i];				// swap the elements in locations i and j
        Integer_array[i] = Integer_array[j];			//
        Integer_array[j] = temp;				//
      }		
    }
    temp = Integer_array[j];					// when i >= j it means the j-th position is the correct position
    Integer_array[j] = Integer_array[pivot];			// of the pivot element, hence swap the pivot element with the
    Integer_array[pivot] = temp;				// element in the j-th position
    integerQuickSort(Integer_array, left, j-1);			// Repeat quicksort for the two sub-arrays, one to the left of j
    integerQuickSort(Integer_array, j+1, right);		// and one to the right of j
}}

void floatQuickSort(float Float_array[], int left, int right){  //QuickSort the input Float array starting highest to lowest
 int pivot, i, j;
 float temp;							// Define temp as float for future swapping
  if(left < right) {						//
    pivot = left;						// select a pivot element
    i = left;							//
    j = right;							//
    while(i < j) {						// increment i till you get a number greater than the
    	while(Float_array[i] >= Float_array[pivot])  		// pivot element
        i++;							//
      	while(Float_array[j] < Float_array[pivot] )		// decrement j till you get a number smaller than the pivot 
        j--;							// element
      if(i < j) {						// if i < j 
        temp = Float_array[i];					// swap the elements in locations i and j
        Float_array[i] = Float_array[j];			//
        Float_array[j] = temp;					//
      }		
    }
    temp = Float_array[j];					// when i >= j it means the j-th position is the correct position
    Float_array[j] = Float_array[pivot];			// of the pivot element, hence swap the pivot element with the
    Float_array[pivot] = temp;					// element in the j-th position
    floatQuickSort(Float_array, left, j-1);			// Repeat quicksort for the two sub-arrays, one to the left of j
    floatQuickSort(Float_array, j+1, right);			// and one to the right of j
}}


float medianFloat(float Input_Array[], int size){ 			//Calculate the median of the float Array
    if(size%2==0) { 					    		// if there are even number of elements 
        return((Input_Array[size/2] + Input_Array[size/2 - 1]) / 2.0);  // return mean of the two elements in the middle 
    } else {								//
        								// else return the element in the middle
        return Input_Array[size/2];
    }
}

float medianInteger(int Input_Array[], int size){ //Calculate the median of the integer Array
    if(size%2==0) { 							// if there are even number of elements
        return((Input_Array[size/2] + Input_Array[size/2 - 1]) / 2.0);	// return mean of the two elements in the middle
    } else {								//
        return Input_Array[size/2];					// else return the element in the middle
    }
}

unsigned short reverseBits( int decimal){// Reverseses the bits of the decimal number
    unsigned int count = sizeof(decimal) * 4 - 1;			// The total number of Bits required.
    unsigned int reverse_dec = decimal;					// Declaring the reverse Decimal to be returned
    decimal >>= 1; 							// Right shift the decimal by 1 bit
    while(decimal){ 							// 		
       reverse_dec <<= 1;       					// Left shft the reverse Decimal by 1
       reverse_dec |= decimal & 1;					// Reverse Decimal is the bitwise inclusive OR of the
       decimal >>= 1;							// Decimal and 1. Then decimal is right shifted by 1/
       count--;								// count = count - 1
    }									//
    reverse_dec <<= count;						// shift the reverse Decimal by the remaining count
    return reverse_dec;							// return the reverse Decimal
}

void binaryString(char String_Array[], int length, int decimal){ //Fill the character array with Binary of the Decimal 
  for (int i=0;i<length-1;i++){						// Loop through the array 
    int temp = decimal%2;						// evaluate temp to the decimal remainder of/2
    decimal = decimal/2;						// 
    if (temp == 1){							// If the remainder ==1 
      String_Array[15-i]='1';						// add 1 to the end of character Array
    }									//
    else {								//
      String_Array[15-i] = '0';     					// Else add 0 to the end of the character Array
    }									//
  }									//
  String_Array[16] = '\0';						// The last element of the character is the NULL char
}	

void showCDF(int Integer_Array[], int length,int y_values[], int y_axis[], int x_axis[]){ //Calculates the CDF and stores it in "y_values"  	
	int i=1;							// i initialized at 1
	//int y_axis[20];							//
	int size_of_x = Integer_Array[length-1]- Integer_Array[0]+1;	// size of x is the difference between the first and 
	//int x_axis[size_of_x];						//  last element of input array.
	x_axis[0] = Integer_Array[0];					// first element of x is the first element of input array
	//printf("%d ", x_axis[0]);					// print out the first element
	while (x_axis[i-1]<Integer_Array[length-1]){			// while previous element of x < last element of Input
		x_axis[i]= x_axis[i-1]+1;				// adding the previous value of x to 1 store as this value
		//printf("%d ", x_axis[i]);				// print out all consecutive elements of x
		i +=1;							//  
		}							// 
									//
	printf("\n");							//
	for (i=20;i>=0;i--){						//
		y_axis[i] = 5*(20-i);					//
		//printf("%d \n",y_axis[i]);				//
		}							//
	//int y_values[size_of_x + 1];					// size of y is dependant on the size of x
	for (int j=0; j < size_of_x +1 ; j++){				// 
		float n = 0;						// Count to show total, initialized at 0
		int i= 0;						//  
	 	while (x_axis[j] >= Integer_Array[i] && i<length){	// While x at j is greater than or equal to values of 
	 			n ++;					//  Integer_array at i, AND i is less than length.
	 			i ++;					// Then increase the count and i
	 	}							//  else:
	 	y_values[j]=(n/length)*100;				// Then corresponding y at j= % of n / length (or the cdf)
	 	//printf( "%d ", y_values[j]);				// print out the cdf
	 	} }						
							

