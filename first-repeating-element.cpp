/*
Given an array of integers arr[], The task is to find the index of first repeating element in it
i.e. the element that occurs more than once and whose index of the first occurrence is the smallest. 
Input: arr[] = {10, 5, 3, 4, 3, 5, 6}
Output: 5 
Input: arr[] = {6, 10, 5, 4, 9, 120, 4, 6, 10}
Output: 6 
*/

#include <iostream>
#include <algorithm>

int find_index( int temp[] , int start , int end , int target )
{
    if ( start < end )
        return -1 ;
    int mid = start + (( end - start)/2 ) ;

    if( temp[mid] == target )
        return mid ;
     if ( temp[mid] > target )
        return find_index( temp , start , mid-1 , target) ;

        return find_index( temp  , mid+1 , end , target) ;
}



int main()
{
    int arr[] = {10, 5, 3, 4, 3, 5, 6} ;
    //int arr[] = {6, 10, 5, 4, 9, 120, 4, 6, 10};
    int size = sizeof(arr)/sizeof(int) ;


//Solution 1 
//Time Complexity: O(n^2) , Space Complexity: O(1)

    int flag=0;

    for ( int i=0 ; i<size ; i++ )
    {
        for ( int j=i+1 ; j<size ; j++ )
        {
            if( arr[j] == arr[i])
            {
                flag = 1 ;
                std :: cout << "First Repeating Element is: " << arr[i] ;
                break ;
            }
        }
        if( flag == 1)
        break; 
    }

    if( flag == 0 )
        std :: cout << "No such element." ;

std :: cout << "\n" ;

//Solution 2
//Time Complexity: O(nlogn) , Space Complexity: O(1)

    int temp[size] ;

    for( int i=0 ; i<size ; i++ )
        temp[i]  = arr[i] ;

    std :: sort( temp , temp + size ) ;

    int index = 0 , count = 0;
    for ( int i=0 ; i<size ; i++ )
    {
        index = find_index( temp , 0 , size , arr[i] );

        count = 1; 
    }



}