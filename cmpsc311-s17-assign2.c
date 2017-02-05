////////////////////////////////////////////////////////////////////////////////
//
//  File          : cmpsc311-s17-assign2.c
//  Description   : This is the main code file for the CMPSC311 assignment 2.
//                  see class assignment for details on what needs to be added.
//
//  Author        : raghav gupta 
//  Created       : Thu,Feb 2nd, 2017
//***********DO NOT ATTEMPT TO PLAGIARIZE THIS CONTENT******************************
//***********IT IS KEPT TRACK OF BY THE AUTHOR AND PROFESSORS AT PENN STATE*********

#define NUMBER_ENTRIES 20
#include <math.h>
#include <stdio.h>
#include <a2support.h>
////////////////////////////////////////////////////////////////////////////////
//
// Function     : main
// Description  : This is the main function for the cmpsc311-s17-assign2 program.
//
// Inputs       : none
// Outputs      : 0 if successful, -1 otherwise

int main( void ) {

	// Local variables
	int integerArray[NUMBER_ENTRIES], i;                      
	float FloatArray[NUMBER_ENTRIES]; 
	char String_Array[17];
	// Read the integer values
	for ( i=0; i<NUMBER_ENTRIES; i++ ) {
	    scanf( "%d", &integerArray[i] );				// create integerArray using the input values
	    if( i%2 == 0){						// if even 
		FloatArray[i] = cos(integerArray[i]);			// take cos(integerArray) and put in FloatArray
	    }else{							// if odd
		FloatArray[i] = sin(integerArray[i]); 			// Else put sin(integerArray) in FloatArray
	}
}
	showIntegers(integerArray, NUMBER_ENTRIES);                    	// Call ShowIntegers function to Print Integer Array
	showFloats(FloatArray, NUMBER_ENTRIES);				// Call ShowFloats to print Float Array
	for (i=0; i <NUMBER_ENTRIES; i++){
		int bitCount = countBits(integerArray[i]);		// count the total bits set to 1 in a given element 
		printf("The integer array value %0x has %d bits \n",integerArray[i],bitCount);	
		}							// Print That Element
			
	integerQuickSort(integerArray,0,19);				//Function call to Sort the IntegerArray 
	floatQuickSort(FloatArray,0,NUMBER_ENTRIES-1); 			//Function call to Reverse Sort the FloatArray
	printf("The Sorted Floats are: ");				//
	showFloats(FloatArray, NUMBER_ENTRIES); 			// Print the Sorted Float Array
	printf("The Sorted Integers are: ");				//
	showIntegers(integerArray, NUMBER_ENTRIES); 			// Print the Sorted Ineger Array
	printf("The median Value of the Integer array is %f \n",medianInteger(integerArray, NUMBER_ENTRIES)); // Calculate and print median of the Integer Array
	printf("The median Value of the Float array is %f \n",medianFloat(FloatArray, NUMBER_ENTRIES)); //Same as above for Float
	for (i=0; i < NUMBER_ENTRIES; i++){                                      
		printf("The unsigned short value of 0x%x is: \n", integerArray[i]);
		binaryString(String_Array, 17, integerArray[i]);	// Function Call to Create the Binary of the Decimal
		printf("Original Str: ");				// Print the Original Decimal in Binary
		for(int j=0; j < 17 ; j++){				//
			printf("%c",String_Array[j]); 			// Print Each element	
		}
		printf("\n");			
		printf("Reverse Str:  ");				// Print the Reverse Decimal in Binary
		binaryString(String_Array, 17, reverseBits(integerArray[i])); // Function Call to set Binary of the reverse
		for(int j=0; j <17; j++){				      // decimal 
			printf("%c",String_Array[j]);			// Print Each element
		}
		printf ("\n");
		}
	int length = integerArray[NUMBER_ENTRIES-1]-integerArray[0]+1;	// Define variables to call in the pointer
	int y_values[length];						// 
	int y_axis[21];							//
	int x_axis[length];						//
	 showCDF(integerArray, NUMBER_ENTRIES,y_values,y_axis,x_axis);	// Call the function and pointer variables
	 for (i = 0; i <21; i++){					// for each iteration of y_axis(which is 5);
	 	printf( "%d  +",y_axis[i]);				// plot y_axis.
	  	for (int j=0;j<length;j++){				// for all y_values[j] less than or equal to the correspon-
	  		if (y_values[j] <= y_axis[i]){			// ding y_axis[i] print a space, else pring '*'
	  			printf("   ");}				//
	  		else{						//
	  			printf("*");}}				//
	 	printf("\n");						//print on a new line for each new y_axis element
	 	}							//
	 	printf ("  %d ",x_axis[0]);				// Print the x_axis  values
	for(i=1;i<length;i++){						//
		printf("%d ",x_axis[i]);}				//
	 
 	// Return successfully
	return( 0 );
}
