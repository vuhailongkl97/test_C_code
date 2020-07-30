#include <iostream>

using namespace std;

int main(void)
{
 try
  {
    int* myarray= new int[1000];
	int x,y,z;
	z = 0;
	y = x/z;
  }
  catch (exception& e)
  {
    cout << "Standard exception: " << e.what() << endl; 
	cout << "okay";
  }
	return 0;
}
