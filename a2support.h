#ifndef A2SUPPORT_INCLUDED
#define A2SUPPORT_INCLUDED

////////////////////////////////////////////////////////////////////////////////
//
//  File          : a2support.h
//  Description   : This is the header file for the functions for assignment
//                  2 of the CMPSC311 course.  Students are required to define
//                  the following functions and implement them in another
//                  file, a2support.c.
//
//  Author        : Raghav Gupta
//  Created       : Wednesday, Feb 1st, 2017
// Functions to define
//***********DO NOT ATTEMPT TO PLAGIARIZE THIS CONTENT******************************
//***********IT IS KEPT TRACK OF BY THE AUTHOR AND PROFESSORS AT PENN STATE*********

void showFloats(float[],int);  
void showIntegers(int[],int );
float medianFloat( float[],int );
float medianInteger(int[],int );
int countBits( unsigned int );
void binaryString( char String_Array[],int,int);
unsigned short reverseBits( int );
void floatQuickSort( float[],int,int );
void integerQuickSort( int[],int ,int );
void showCDF( int[],int,int[],int[],int[] );

#endif
