
#include"sorting.cpp"
using namespace std;
int main()
{
	int choice;
	int total_account;
	long long random_number = 10000;
	long long account_number[100];
	char first_name[100][50], last_name[100][50];
	long long balance[100];
	int ch = 1;
	total_account = 0;//as initially there is no account
	cout << "==========================================================================================================" << endl;
	cout << "			WELCOME TO ONLINE NETBANKING" << endl;
	cout << "==========================================================================================================" << endl;
	cout << "		PLEASE SELECT OPTION ONE FROM THE MENU"<<endl;
	do {
		cout << "		Press 1: Add bank account" << endl;
		cout << "		Press 2: Remove bank account" << endl;
		cout << "		Press 3: Display information about the client" << endl;
		cout << "		Press 4: Deposit money in particular account" << endl;
		cout << "		Press 5: Deposit money in particular account" << endl;
		cout << "		Press 6: Sort and Display the list of client " << endl;
		cout << "		Press 7: Display average balance of the accounts" << endl;
		cout << "		Press 8: Display total balance of the accounts" << endl;
		cout << "		Press 9: Display information about all the client" << endl;
		cout << "		Press 10: Exit" << endl;
		cout << "		ENTER YOUR CHOICE:	";
		cin >> choice;
		switch (choice)
		{
		case 1: {
			addaccount(account_number, &total_account, first_name, last_name, balance, &random_number);
			cout << "=====================================================================================================" << endl;
			cout << "		ACCOUNT HAS BEEN SUCCESFULLY ADDED WITH $0 balance)" << endl;
			cout << "=====================================================================================================" << endl;
			display_particular(account_number, &total_account, first_name, last_name, balance, total_account - 1);
			break;
		}
		case 2: {
			if (total_account == 0)
			{
				cout << "==================================================================================================" << endl;
				cout << "		THERE IS NO ACCOUNT YET" << endl;
				cout << "==================================================================================================" << endl;
			}
			else
			{
				int j = find_account(&total_account, account_number);

				while (j < total_account - 1)
				{
					account_number[j] = account_number[j + 1];
					balance[j] = balance[j + 1];
					remove(first_name, j);
					remove(last_name, j);
					j++;
				}
				total_account = total_account - 1;
				cout << "====================================================================================================" << endl;
				cout << "		Account has been successfully deleted" << endl;
				cout << "====================================================================================================" << endl;

			}
			break;
		}
		case 3: {
			if (total_account == 0)
			{
				cout << "======================================================================================================" << endl;
				cout << "		THERE IS NO ACCOUNT YET" << endl;
				cout << "======================================================================================================" << endl;
			}
			else
			{
				cout << "=======================================================================================================" << endl;
				cout << "		TO FIND AN IMFORMATION ABOUT PARTICULATER ACCOUNT " << endl;
				cout << "=======================================================================================================" << endl;
				int j = find_account(&total_account, account_number);
				display_particular(account_number, &total_account, first_name, last_name, balance, j);
			}

			break;
		}
		case 4: {
			if (total_account == 0)
			{
				cout << "=========================================================================================================" << endl;
				cout << "		THERE IS NO ACCOUNT YET. PLEASE MAKE AN ACCOUNT FIRST" << endl;
				cout << "=========================================================================================================" << endl;
			}
			else
			{
				int r = deposit_and_withdrawl(&total_account, choice, account_number, balance);
				if (r != -1)
				{
					cout << "=========================================================================================================" << endl; 
					cout << "		Amount has been succesfully deposit" << endl;
					cout << "=========================================================================================================" << endl; 
					display_particular(account_number, &total_account, first_name, last_name, balance, r);
				}
				else
					cout << "		Oops!!!!There is error in the system" << endl;
			}

			break;
		}
		case 5: {
			if (total_account == 0)
			{
				cout << "=========================================================================================================" << endl; 
				cout << "		SORRY!! THERE IS NO ACCOUNT YET." << endl;
				cout << "=========================================================================================================" << endl;
			}
			else
			{
				int r = deposit_and_withdrawl(&total_account, choice, account_number, balance);
				if (r != -1)
				{
					cout << "=========================================================================================================" << endl; 
					cout << "		Amount has been succesfully withdrawl" << endl;
					cout << "=========================================================================================================" << endl; 
					display_particular(account_number, &total_account, first_name, last_name, balance, r);
				}
				else
					cout << "		Oops!!!!There is error in the system" << endl;
			}

			break;
		}
		case 6: {
			sorting_list(account_number, first_name, last_name, balance, &total_account);
			break;
		}
		case 7: {
			double average = average_and_total_balance(balance, &total_account, choice);
			cout << "=========================================================================================================" << endl; 
			cout << "		AVERAGE BALANCE IS:		$" << average << endl;
			cout << "=========================================================================================================" << endl;
			break;
		}
		case 8: {
			double total_amount = average_and_total_balance(balance, &total_account, choice);
			cout << "=========================================================================================================" << endl; 
			cout << "		TOTAL AMOUNT IS:		$" << total_amount << endl;
			cout << "=========================================================================================================" << endl; 
			break;
		}
		case 9: {
			cout << "=========================================================================================================" << endl;
			cout << "		LIST OF CLIENTS" << endl;
			cout << "=========================================================================================================" << endl;
			display_whole(account_number, &total_account, first_name, last_name, balance);
			break;
		}
		case 10: {
			return 0;
		}
		default:

			break;
		}
		cout << "press 0 to exit: ";
		cin >> ch;
	} while (ch != 0);


	return 0;
}