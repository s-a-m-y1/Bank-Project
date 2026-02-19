#include<iostream>
#include"clsBankClient.h"
using namespace std;
int main()
{
	clsBankClient Client = clsBankClient::Find("A1 , 0120");

	return 0;
}