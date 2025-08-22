#include<bits/stdc++.h>
using namespace std;
void swap(int &a , int &b){
  int *ptra=&a;
  int *ptrb=&b;
  int temp=a;
  *ptra=*ptrb;
  *ptrb=temp;
}
int  main()
{
  int a=3;
  int b=5;
  swap(a,b);
  cout<<a<<" "<<b<<endl;
}
