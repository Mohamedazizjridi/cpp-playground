#include<bits/stdc++.h>
using namespace std;
int  main()
{
  
  int arr[5]={1,2,3,4,5};
  int*ptr =arr;
  // array name is an adress of the first elt 
  cout<<*ptr<<endl;
  
  // Three Ways to Access Array Elements
      // 1-suisng idx arr[i]
      //2- Using Pointer Arithmetic
      cout<<arr[1]<<" "<<*(ptr+1)<<endl;
      //3- Using Pointer Arithmetic
      cout<<*(arr+2)<<" "<<arr[2]<<endl;
  
  // Important Differences: Array vs Pointer
  cout<<sizeof(ptr)<<endl; // 8 pointer size 
  cout<<sizeof(arr)<<endl; // 20 (5 * 4 bytes)
  
  // Difference 2: arr is constant, ptr is not
    ptr++;      // OK - ptr now points to arr[1]
    // arr++;   // ERROR! Can't change array name
  
  // & operator
  cout<<&arr<<endl;// Address of entire array
  cout<<&ptr<<endl; // Address of pointer varaible
  
  
}
