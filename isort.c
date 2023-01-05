#include<stdio.h>
#include<stdlib.h>
#define SIZE 50


void shift_element(int* arr, int i);
void insertion_sort(int* arr , int len);

void shift_element(int* arr, int i){
    
    for (int j = i; j >= 0; j--)
    {    
        *(arr+j+1) = *(arr+j);

    }

}
void insertion_sort(int* arr , int len){
    int key=0,j=0,temp=0,y=0;
    for (int step = 1; step < len; step++) {
        key = *(arr + step);
        j = step - 1;
        y=1;
        while (key < *(arr+j) && j >= 0) {
            temp = key;
            shift_element(arr + j,0);
            *(arr + step-y)=temp;
            --j;
            y++;
        }
   
    }  
     
}
void enterNumber(int* arr){
         for (int i = 0; i < SIZE; i++)
    {
        scanf("%d",arr + i);
    }
}

void printArr(int *arr){
    for (int i = 0; i < SIZE; i++)
    {
       printf("%d",*(arr +i));
       if(i+1 != SIZE)printf(",");
       
    }
    printf("\n");
}

int main(){

    int arr[SIZE];
   
    enterNumber(arr);

   insertion_sort(arr , SIZE);

    printArr(arr);
    
    return 0;
}