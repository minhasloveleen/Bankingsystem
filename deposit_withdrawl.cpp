#include "add_remove_account.cpp"
using namespace std;
//FINCTION IS USED TO WITHDRAWL MONEY AND TO DEPOSIT MONEY
inline int deposit_and_withdrawl(int *total_account, int choice, long long account_number[100], long long balance[100])
{
	int j = find_account(total_account, account_number);
	int amount;
	if (choice == 4)
	{
		cout << "		ENTER THE AMOUNT OF DEPOSIT	:	";
		cin >> amount;
		balance[j] += amount;
		return j;
	}
	if (choice == 5)
	{
		cout << "		ENTER THE AMOUNT OF WITHDRAWL	:	";
		cin >> amount;
		if (balance[j] < amount)
		{
			cout << "=========================================================================================================" << endl; 
			cout << "		SORRY !! YOU DONNT HAVE SUFFICIENT BALANCE" << endl;
			cout << "=========================================================================================================" << endl; 
			return -1;
		}
		else
			balance[j] -= amount;
		return j;
	}
	return -1;
}
//FUNCTION TO DISPLAY THE WHOLE ACCOUNTS
inline void display_whole(long long account_number[100], int *total_account, char first_name[100][50], char last_name[100][50], long long balance[100])
{
	cout << "=========================================================================================================" << endl; 
	cout << "GIVEN NAME		FAMILY NAME		BALANCE		ACCOUNT NUMBER" << endl;
	cout << "=========================================================================================================" << endl; 
	for (int i = 0; i < *total_account; i++)
	{
		cout << first_name[i] << "			" << last_name[i] << "		" << balance[i] << "			" << account_number[i] << endl;
	}
}
//FUNCTION TO DISPLAY THE PARTICULAR ACCOUNT
inline void display_particular(long long account_number[100], int *total_account, char first_name[100][50], char last_name[100][50], long long balance[100], int i)
{
	cout << "=========================================================================================================" << endl; 
	cout << "GIVEN NAME		FAMILY NAME		BALANCE		ACCOUNT NUMBER" << endl;
	cout << "=========================================================================================================" << endl;
	cout << first_name[i] << "			" << last_name[i] << "				" << balance[i] << "			" << account_number[i] << endl;
}
//FUNCTION TO DISPLAY THE AVERAGE AND TOTAL BALANCE OF CLIENTS HAVING IN ACCOUNT
inline double average_and_total_balance(long long balance[100], int *total_account, int choice)
{
	double sum = 0;
	for (int i = 0; i < *total_account; i++)
	{
		sum += balance[i];
	}
	if (choice == 7)
	{
		return sum;
	}
	if (choice == 8)
	{
		return sum / *total_account;
	}
	return 0.0;
}