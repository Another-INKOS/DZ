#include <iostream>
#include <vector>
using namespace std;

int palindrome(string palindrom)
{
	setlocale(LC_ALL, "RU");

	vector <string> s_palindrom;
	string revpalindrom;

	for (int i = palindrom.length() - 1; i >= 0; i--) 
	{
		revpalindrom += palindrom[i];
	}
	
	if (palindrom == revpalindrom) 
	{
		return true;
	}
	
	else 
	{
		return false;
	}
	
}

int main()
{
	string pal;
	cin >> pal;

	if (palindrome(pal) == 1) 
	{
		cout << "true";
	}
	
	else 
	{
		cout << "false";
	}

	return 0;
}
