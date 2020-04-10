/********************************************************\
File Name: main.c
Author: Liri (10/4/2020)
Purpose: This file get number of elements from user,
		 get the elements, calculate the average of the numbers,
		 and find the closest number to the average
\********************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define INITIAL_INDEX (0)

int* get_numbers_from_user_to_array(int* array_pointer,
	int number_of_elements) {
	/********************************************************\
	* Function name - get_numbers_from_user_to_array
	*
	* Function Purpose - get numbers from user and
	*					 fill the array with this numbers
	*
	* Parameters - INOUT int* array_pointe - the pointer to the array
	*				that contain the numbers from the user
	*			   IN int number_of_elements - the number of the elements
	*				in the array
	*
	* Return Value - the pointer to the array that content the numbers
	*					from the user
	*
	* Side Effects - this function change the array_pointer,
	*				 such that it add to the array the numbers from user
	*
	* Semantics - this function get numbers from user
	*			  and add them to the array
	*
	* Author - Liri
	\********************************************************/
	int index = INITIAL_INDEX;

	printf("Enter the elements:\n");
	for (index = INITIAL_INDEX; index < number_of_elements; ++index) {
		scanf_s("%d", array_pointer + index);
	}

	return(array_pointer);
}

float average_of_numbers_in_array(int* array_pointer,
	int number_of_elements) {
	/********************************************************\
	* Function name - average_of_numbers_in_array
	*
	* Function Purpose - calculate the average of the numbers in array
	*
	* Parameters - IN int* array_pointe - the pointer to the array
	*				that contain the numbers from the user
	*			   IN int number_of_elements - the number of the elements
	*				in the array
	*			   OUT float average of numbers in array
	*
	* Return Value - the average of the numbers that in the array
	*
	* Side Effects - this function has no side effects
	*
	* Semantics - this function calculate the average of the numbers
	*			  that in the array
	*
	* Author - Liri
	\********************************************************/
	int index = INITIAL_INDEX;
	int summary = INITIAL_INDEX;
	float average = INITIAL_INDEX;

	for (index = INITIAL_INDEX; index < number_of_elements; ++index)
	{
		summary += *(array_pointer + index);
	}
	average = (float)summary / number_of_elements;
	return average;
}

int closest_element_to_average(int* array_pointer,
	int number_of_elements,
	float average) {
	/********************************************************\
	* Function name - closest_element_to_average
	*
	* Function Purpose - find the closest element to the average in array
	*
	* Parameters - IN int* array_pointe - the pointer to the array
	*				that contain the numbers from the user
	*			   IN int number_of_elements - the number of the elements
	*				in the array
	*			   IN float average - the average of the numbers in array
	*			   OUT int closest element in array to the average
	*
	* Return Value - the closest element in array to the average
	*
	* Side Effects - this function has no side effects
	*
	* Semantics - this function find the closest element in array
	*				to the average, such that if there are two numbers
	*				in equal distance from average, than the first that the
	*				user typed get priority
	*
	* Author - Liri
	\********************************************************/
	float shortest_distance = INITIAL_INDEX;
	float current_distance = INITIAL_INDEX;
	int closest_element = INITIAL_INDEX;
	int index = INITIAL_INDEX;

	shortest_distance = fabsf(*(array_pointer)-average);
	closest_element = *(array_pointer);

	for (index = INITIAL_INDEX; index < number_of_elements; ++index)
	{
		current_distance = fabsf(*(array_pointer + index) - average);
		if (current_distance < shortest_distance)
		{
			/*current element is closer than the older*/
			shortest_distance = current_distance;
			closest_element = *(array_pointer + index);
		}
	}
	return closest_element;
}