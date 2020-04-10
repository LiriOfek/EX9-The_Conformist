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
#define GET_NUMBER_OF_ELEMENTS ("Enter the number of the elements:\n")
#define GET_INTEGER ("%d")
#define ERROR_MEMORY_ALLOCATION_FAILED ("Error! memory allocation failed.\n")
#define STRING_PRINT_AVERAGE ("The average is: %f\n")
#define STRING_PRINT_CLOSEST_ELEMENT_TO_AVERAGE ("The closest number to the average is: %d\n")

enum return_values { FAILURE, SUCCESS };

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

	/*calculate distance by the absolute value of the difference 
		between element and the average*/
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

int* print_average_and_closest_number_to_it(int* array_pointer, 
										int number_of_elements) {
	/********************************************************\
	* Function name - print_average_and_closest_number_to_it
	*
	* Function Purpose - get the number of elements from user,
	*					 and the elements, save them to array,
	*						calculate the average of the array,
	*						and find the closest element in array
	*						to the average
	*
	* Parameters - INOUT int* array_pointe - the pointer to the array
	*				that contain the numbers from the user
	*			   IN int number_of_elements - the number of the elements
	*				in the array
	*
	* Return Value - the pointer to the array that contain 
	*				 the numbers from the user
	*
	* Side Effects - this function change the array_pointer,
	*				 such that it add to the array the numbers from user
	*
	* Semantics - this function call functions that 
	*			  get number of elements from user,
	*			  get the elements, calculate the
	*			  average and find the closest element to the average
	*
	* Author - Liri
	\********************************************************/
	float average = INITIAL_INDEX;
	int closest_element = INITIAL_INDEX;

	/*fill the array with the numbers from user*/
	array_pointer = get_numbers_from_user_to_array(array_pointer,
		number_of_elements);

	/*print the average of the numbers in array*/
	average = average_of_numbers_in_array(array_pointer,
		number_of_elements);
	printf(STRING_PRINT_AVERAGE,
		average);

	/*print the closest element to the average*/
	closest_element = closest_element_to_average(array_pointer,
		number_of_elements,
		average);
	printf(STRING_PRINT_CLOSEST_ELEMENT_TO_AVERAGE,
		closest_element);

	return array_pointer;
}

int main() {
	/********************************************************\
	* Function name - main
	*
	* Function Purpose - get the number of elements from user,
	*					 and the elements, save them to array,
	*						calculate the average of the array,
	*						and find the closest element in array
	*						to the average
	*
	* Parameters - no Input/Output parameters
	*
	* Return Value - if allocation of memory failed - FAILURE
	*				 otherwise - SUCCESS
	*
	* Side Effects - this function allocate memory in order to save
	*				 the numbers from user and free the memory in
	*				 the end of the running
	*
	* Semantics - this function allocate memory for array of numbers,
	*			  call function that get number of elements from user,
	*			  get the elements, that calculate the
	*			  average and find the closest element to the average
	*
	* Author - Liri
	\********************************************************/
	int number_of_elements = INITIAL_INDEX;
	int *array_pointer;
	float average = INITIAL_INDEX;
	int closest_element = INITIAL_INDEX;

	/*get number of elements*/
	printf(GET_NUMBER_OF_ELEMENTS);
	scanf_s(GET_INTEGER, &number_of_elements);

	/*allocate memory for array of numbers from user*/
	array_pointer = (int*)malloc(number_of_elements * sizeof(int));
	if (NULL == array_pointer)
	{
		printf(ERROR_MEMORY_ALLOCATION_FAILED);
		return FAILURE;
	}

	array_pointer = print_average_and_closest_number_to_it(array_pointer, 
														number_of_elements);

	free(array_pointer);
	return SUCCESS;
}