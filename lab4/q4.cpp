
#include <iostream>
using namespace std;

int FindMin(int a, int b) {
  int min;
  if (a < b) 
     min = a;
  else 
     min = b;
  return min;
}
int main() {
  int x; int y;
  cin >> x;
  cin >> y;  
  min = FindMin(x,y);
  cout << "The smaller number is: " << min << endl;   
  return 0;
}
