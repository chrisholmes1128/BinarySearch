//
//  main.cpp
//  HW1DataStruct
//
//  Created by Chris holmes on 2/7/19.
//  Copyright © 2019 Chris holmes. All rights reserved.
//

//Chris Holmes
//Quick Sort and Binary Searching Program

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <time.h>

using namespace std;

const int MAX = 1000;
const int MAX_RAND = 10000;


void quickSort(int arr[], int low, int high);
int binSearch(int arr[], int low, int high, int userNum);

int main()
{
    int randNumArray[MAX];
    //create 1000 random numbers from 0-10,000
    srand(time(0));
    
    for (int i = 0; i < MAX; i++) //change to MAX_LOOP
    {
        randNumArray[i] = 1 + (rand() % MAX_RAND);
        
    }
    
    cout << "High-Low Sorted Array:" << endl << endl;
    quickSort(randNumArray, 0, MAX);
    
    for (int i = 0; i < 20; i++)
    {
        cout << randNumArray[i]++ << endl;
    }

    //User Entry
    int userNum;
    
    cout << "Enter a number between 0 and 10,000 " << endl;
    cin >> userNum;
        
    try
    {
        if (userNum > 10000)
        {
            throw 0;
        }
        else if (userNum < 0)
        {
            throw "Invalid Entry. Number was less than 0. ";
        }
            
    }
        
    catch (int x)
    {
        cout << "Invalid Entry. Number was greater than 10,000. Error " << x << endl;
    }
    catch (const char *e)
    {
        cout << e << endl;
    }

    //Add catch block for if user enters a char or if decimal # not integer
        
    int result = binSearch(randNumArray, userNum, 0, MAX) ;
    result += 1;
    
    if (result != NULL)
    {
        cout << "Element " << userNum << " is present at index " << result << endl;
    }
    else
    {
        cout << "Element is not present. " << result << endl;
    }
     
    cin.get();
    cin.get();
    return 0;
    
}

void quickSort(int sortedA[], int low, int high)
{
    int i = low, j = high;
    int temp;
    int pivot = sortedA[(low + high) / 2];
    
    while (i <= j)
    {
        while (sortedA[i] > pivot)
        {
            i++;
        }
        while (sortedA[j] < pivot)
        {
            j--;
        }
        if (i <= j)
        {
            temp = sortedA[i];
            sortedA[i] = sortedA[j];
            sortedA[j] = temp;
            i++;
            j--;
        }
    }
    
    if (low < j)
    {
        quickSort(sortedA, low, j);
    }
    if (i < high)
    {
        quickSort(sortedA, i, high);
    }
}

int binSearch(int arr[], int userNum, int low, int high)
{
    
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] == userNum)
        {
            return mid;
        }
        else if (arr[mid] < userNum)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return -1;
    
}
