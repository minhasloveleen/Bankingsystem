#include"deposit_withdrawl.cpp"
using namespace std;
void bal_asc(long long account_number[100], char first_name[100][50], char last_name[100][50], long long balance[100], int * total_account);
inline void swp_fn(long long value[], int index);
inline void swp_string(char first_name[100][50], int j);
inline void bal_des(long long account_number[100], char first_name[100][50], char last_name[100][50], long long balance[100], int *total_account);
inline int compare(char str1[100][50], int j);
inline void family_asc(long long account_number[100], char first_name[100][50], char last_name[100][50], long long balance[100], int *total_account);
inline void family_des(long long account_number[100], char first_name[100][50], char last_name[100][50], long long balance[100], int *total_account);
inline void given_asc(long long account_number[100], char first_name[100][50], char last_name[100][50], long long balance[100], int *total_account);
inline void given_des(long long account_number[100], char first_name[100][50], char last_name[100][50], long long balance[100], int *total_account);


inline void sorting_list(long long account_number[100], char first_name[100][50], char last_name[100][50], long long balance[100], int *total_account)
{
	int ch, chh;
	cout << "Displaying the list of clients" << endl;
	cout << "1.    By Balance" << endl;
	cout << "2.    By Family name" << endl;
	cout << "3.    By Given name" << endl;
	cout << "Enter your choice";
	cin >> ch;
	while (cin.fail())
	{
		cin.clear();
		cin.ignore(512, '\n');
		cout << "Wrong input! Numerial values only from the list please";
		cin >> ch;
	}
	cout << "1.    Display list in ascending order" << endl;
	cout << "2.    Display list in descending order" << endl;
	cout << "Enter your choice";
	cin >> chh;
	while (cin.fail())
	{
		cin.clear();
		cin.ignore(512, '\n');
		cout << "Wrong input! Numerial values only from the list please";
		cin >> chh;
	}
	if (ch == 1 && chh == 1)
	{
		bal_asc(account_number, first_name, last_name, balance, total_account);
		display_whole(account_number, total_account, first_name, last_name, balance);
	}
	else if (ch == 1 && chh == 2)
	{
		bal_des(account_number, first_name, last_name, balance, total_account);
		display_whole(account_number, total_account, first_name, last_name, balance);
	}
	else if (ch == 2 && chh == 1)
	{
		family_asc(account_number, first_name, last_name, balance, total_account);
		display_whole(account_number, total_account, first_name, last_name, balance);
	}
	else if (ch == 2 && chh == 2)
	{
		family_des(account_number, first_name, last_name, balance, total_account);
		display_whole(account_number, total_account, first_name, last_name, balance);
	}
	else if (ch == 3 && chh == 1)
	{
		given_asc(account_number, first_name, last_name, balance, total_account);
		display_whole(account_number, total_account, first_name, last_name, balance);
	}
	else if (ch == 3 && chh == 2)
	{
		given_des(account_number, first_name, last_name, balance, total_account);
		display_whole(account_number, total_account, first_name, last_name, balance);
	}
	else
	{
		cout << "=========================================================================================================" << endl; 
		cout << "									Sorry you enter a wrong combination" << endl;
		cout << "=========================================================================================================" << endl;
	}
}

//BALANCE IN ASCENDING ORDER
inline void bal_asc(long long account_number[100], char first_name[100][50], char last_name[100][50], long long balance[100], int *total_account)
{
	for (int i = 0; i < *total_account - 1; i++)
	{
		for (int j = 0; j < *total_account - 1; j++)
		{
			if (balance[j] > balance[j + 1])
			{
				swp_fn(balance, j);
				swp_fn(account_number, j);
				swp_string(first_name, j);
				swp_string(last_name, j);
			}
		}
	}
}
//BALANCE IN DESCENDING ORDER
inline void bal_des(long long account_number[100], char first_name[100][50], char last_name[100][50], long long balance[100], int *total_account)//balance in descending order
{
	for (int i = 0; i < *total_account - 1; i++)
	{
		for (int j = 0; j < *total_account - 1; j++)
		{
			if (balance[j] < balance[j + 1])
			{
				swp_fn(balance, j);
				swp_fn(account_number, j);
				swp_string(first_name, j);
				swp_string(last_name, j);
			}
		}
	}
}
//FUNCTION TO COMPARE TWO STRINGS
//It returns 0 if the strings are identical, 1 if the first comes after the second (appears later in the dictionary), and -1 if the first comes before the second (appears earlier in the dictionary).
inline int compare(char str1[100][50], int j)
{
	int i = 0;
	while (str1[j][i] != '\0' || str1[j + 1][i] != '\0')
	{
		if (str1[j][i] == str1[j + 1][i])
			i++;
		else if (str1[j][i] < str1[j + 1][i])
			return 1;
		else
			return -1;
	}
	if (strlen(str1[j]) == strlen(str1[j + 1]))
		return 0;
	else if (strlen(str1[j]) > strlen(str1[j + 1]))
		return 1;
	else
		return -1;
}
//FUNCTION TO ARRANGE FAMILY NAME IN ASCENDING ORDER
inline void family_asc(long long account_number[100], char first_name[100][50], char last_name[100][50], long long balance[100], int *total_account)//family name in ascending order
{
	for (int i = 0; i < *total_account - 1; i++)
	{
		for (int j = 0; j < *total_account - 1; j++)
		{
			int a = compare(last_name, j);
			if (a == -1)
			{
				swp_fn(balance, j);
				swp_fn(account_number, j);
				swp_string(first_name, j);
				swp_string(last_name, j);
			}
		}
	}
}
//FUNCTION TO ARRANGE FAMILY NAME IN DESCENDING ORDER
inline void family_des(long long account_number[100], char first_name[100][50], char last_name[100][50], long long balance[100], int *total_account)//family name in descending order
{
	for (int i = 0; i < *total_account - 1; i++)
	{
		for (int j = 0; j < *total_account - 1; j++)
		{
			int a = compare(last_name, j);
			if (a == 1)
			{
				swp_fn(balance, j);
				swp_fn(account_number, j);
				swp_string(first_name, j);
				swp_string(last_name, j);
			}
		}
	}
}
//FUNCTION TO ARRANGE GIVEN NAME IN ASCENDING ORDER
inline void given_des(long long account_number[100], char first_name[100][50], char last_name[100][50], long long balance[100], int *total_account)//given name in ascending order
{
	for (int i = 0; i < *total_account - 1; i++)
	{
		for (int j = 0; j < *total_account - 1; j++)
		{
			int a = compare(first_name, j);
			if (a == 1)
			{
				swp_fn(balance, j);
				swp_fn(account_number, j);
				swp_string(first_name, j);
				swp_string(last_name, j);
			}
		}
	}
}
//FUNCTION TO ARRANGE GIVEN NAME IN DESCENDING ORDER
inline void given_asc(long long account_number[100], char first_name[100][50], char last_name[100][50], long long balance[100], int *total_account)//given name in descending order
{
	for (int i = 0; i < *total_account - 1; i++)
	{
		for (int j = 0; j < *total_account - 1; j++)
		{
			int a = compare(first_name, j);
			if (a == -1)
			{
				swp_fn(balance, j);
				swp_fn(account_number, j);
				swp_string(first_name, j);
				swp_string(last_name, j);
			}
		}
	}
}

//SWAPING TWO VALUES Of INTEGER
inline void swp_fn(long long value[], int index)
{

	long long temp;
	temp = value[index];
	value[index] = value[index + 1];
	value[index + 1] = temp;

}

//SWAPING STRINGS
inline void swp_string(char first_name[100][50], int j)
{
	char temp[50];
	int i = 0;//flag for temp
	while (i != strlen(first_name[j]))
	{
		temp[i] = first_name[j][i];
		i++;
	}
	int k = 0;
	while (k != strlen(first_name[j + 1]))
	{
		first_name[j][k] = first_name[j + 1][k];
		k++;
	}
	first_name[j][k] = '\0';
	k = 0;
	while (k != i)
	{
		first_name[j + 1][k] = temp[k];
		k++;
	}
	first_name[j + 1][k] = '\0';

}