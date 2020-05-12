#include<iostream>
#include<string.h>
using namespace std;
inline int addaccount(long long account_number[100], int *total_account, char first_name[100][50], char last_name[100][50], long long balance[100], long long *random_number)
{
	int number = *total_account;
	account_number[number] = *random_number;
	cout << "		Enter the first name";
	cin >> first_name[number];
	while (cin.fail() || cin.peek() != '\n')
	{
		cin.clear();
		cin.ignore(512, '\n');
		cout << "=========================================================================================================" << endl; 
		cout << "		PLEASE ENTER SINGLE STRINGS OF LETTERS"<<endl;
		cout << "=========================================================================================================" << endl; 
		cin >> first_name[number];
	}
	cout << "		Enter the last name";
	cin >> last_name[number];
	while (cin.fail() || cin.peek() != '\n')
	{
		cin.clear();
		cin.ignore(512, '\n');
		cout << "=========================================================================================================" << endl; 
		cout << "		PLEASE ENTER SINGLE STRINGS OF LETTERS" << endl;
		cout << "=========================================================================================================" << endl; 
		cin >> last_name[number];
	}
	balance[number] = 0;
	*total_account = *total_account + 1;
	*random_number = *random_number + 1;
	return 0;
}
inline int find_account(int *total_account, long long account_number[100])
{
	long long temp_acc;
	int p = -1;
	do {
		cout << "		ENTER THE ACCOUNT NUMBER PLEASE:	";
		cin >> temp_acc;
		while (cin.fail() && cin.peek() != '\0')
		{
			cout << "=========================================================================================================" << endl;
			cout << "		PLEASE ENTER NUMERICAL VALUES ONLY" << endl;
			cout << "=========================================================================================================" << endl;
		}
		for (int i = 0; i < *total_account; i++)
		{
			if (account_number[i] == temp_acc)
			{
				p = i;
			}
		}
		if (p == -1)
			cout << "			Sorry there is no such account by this " << temp_acc << "account number" << endl << "Please try it again" << endl;
	} while (p == -1);
	return p;
}
inline void remove(char first_name[100][50], int j)
{
	int i = 0;
	if (strlen(first_name[j]) > strlen(first_name[j + 1]))
	{
		while (i != strlen(first_name[j + 1]))
		{
			first_name[j][i] = first_name[j + 1][i];
			i++;
		}
		while (first_name[j][i] != '\0')
		{
			first_name[j][i] = '\0';
			i++;
		}
	}
	else if (strlen(first_name[j]) < strlen(first_name[j + 1]))
	{
		while (i != strlen(first_name[j + 1]))
		{
			first_name[j][i] = first_name[j + 1][i];
			i++;
		}
		while (i != 50)
		{
			first_name[j][i] = '\0';
			i++;
		}
	}
	else
	{
		while (i != strlen(first_name[j + 1]))
		{
			first_name[j][i] = first_name[j + 1][i];
			i++;
		}
	}
}