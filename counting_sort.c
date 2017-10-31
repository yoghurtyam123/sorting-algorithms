#include <stdio.h>
#include <stdlib.h>
#include <math.h>

///////////////////counting sort/////////////////////


///////////////////declaring global variables//////////////////

int array_size;




//////////////////basic predetermined functions////////////////

int * countingSort(int a[],int array_size, int digit);

int digitEjector(int a,int digit){
	printf("The entered number is : %d\n",a );
	printf("The entered digit is : %d\n",digit );

	int temp;
	int modpow = 1, divpow = 1;
	for (int i = 0; i < digit; ++i)
	{
		modpow = modpow * 10;		
	}
	divpow = modpow/10;

	printf("modpow = %d divpow = %d\n",modpow, divpow);

	temp = (int)(((float)(a%modpow))/(float)divpow);
	printf("temp = %d\n",temp );

	return temp;	
}
	



int digitFinder(int num){
	int digits,i;

	for (digits = 1,i = 1; num/digits >= 0 ;i++ ) 
	{
		digits = digits*10;
	}
	return i;
}

int findMax(int a[], int array_size){
	int max = -9999;
	for (int i = 0; i < array_size; ++i)
	{
		if (a[i]>max)
		{
			max = a[i];
		}
	}
	return max;
}

void printArray(int *a, int array_size){

	printf("{");	

	for (int i = 0; i < array_size; ++i)
	{
		printf("%d ", a[i]);
	}

	printf("}");
}




void main(){

	printf("you are now going to sort using the counting sort algorithm\n");	

	printf("please enter the size of the array : \n");
	scanf("%d", &array_size);
	printf("size of the array you have given : %d\n",array_size );

	int *pArray, i;

	pArray = (int*)calloc(array_size,sizeof(int));


	for(i = 0; i < array_size; i++){
		printf("please enter the element number %d : ", i + 1);
		scanf("%d", &pArray[i]);
	}

	printf("The unsorted array is :\n");
	printArray(pArray, array_size);

	int whatever = digitEjector(1234, 3);

	printf("this is the value of the ejected digit : %d\n",whatever );

	countingSort(pArray, array_size, 2);




}

int * countingSort(int a[],int array_size, int digit){

	printf("We've reached here!\n");
	printf("the array can be accessed as : \n");
	printArray(a, array_size);

	int *p;
	p = (int*)calloc(array_size, sizeof(int));

	for (int j = 0; j < array_size; j++)
	{
		p[j] = digitEjector(a[j], digit);
	}

	printf("this is the array we are gonna work on : \n");
	printArray(p, array_size);

	int max_number_in_working_array = findMax(p, array_size);
	printf("max number in working array = %d\n",max_number_in_working_array );

	// int number_of_digits = digitFinder(max_number_in_working_array);

	// printf("number of digits in the max number = %d\n", number_of_digits);

	int *q;
	q = (int*)calloc(max_number_in_working_array + 1, sizeof(int));

	int *sortedArray;
	sortedArray = (int*)calloc(array_size, sizeof(int));

	for (int i = 0; i < array_size; ++i)
	{
		q[p[i]]++;
	};


	printf("the array which has the numbers \"q\" is :\n");
	printArray(q, max_number_in_working_array + 1);

	for (int i = 0, temp = 0; i < max_number_in_working_array + 1; ++i)
	{
		
		temp = temp + q[i];
		q[i] = temp;
	}

	printf("Now the array \"q\" is :\n");
	printArray(q, max_number_in_working_array + 1);

	for (int i = 0; i < array_size; ++i)
	{
			
		sortedArray[q[p[i]]-1] = p[i];
		q[p[i]]--;
	}

	printf("The final sorted array is :\n");
	printArray(sortedArray, array_size);

}