#include "Admin.h"
void Admin::login()
{
	int ID, decision;
	string pass;
	bool check = false;
	ifstream file_in("AdminID.txt");

	do {
		cout << "Enter the user ID: ";
		cin >> ID;
		while (!check)
		{
			file_in >> m_id >> m_password;
			if (m_id == ID)
				check = true;

			else if (file_in.eof())
			{
				cout << "There is no user ID maches." << endl;
				cout << "1. Try again." << endl;
				cout << "2. Sign in." << endl;
				cin >> decision;
				if (decision == 2)
					signin();
				
				break;
			}
		}
	} while (!check);

	file_in.close();

	do
	{
		cout << "Enter the password: ";
		cin >> pass;
		if (pass != m_password)
			cout << "Password is wrong. Please try again." << endl << endl;
	} while (pass != m_password);
	


}

void Admin::signin()
{
	string hold;
	int holdID;
	bool check = true;

	cout << "Creat the User ID" << endl;
	cout << "Please enter your user ID: ";
	cin >> m_id;

	ifstream file_in("AdminID.txt");
	while (!file_in.eof())
	{
		file_in >> holdID >> hold;
		if (m_id == holdID)
		{
			cout << "Your account already exist." << endl;
			check = false;
			break;
		}
	}

	
	if (check) //if account doesn't exist
	{
		cout << "Make the password" << endl;
		do {
			cout << "Please Enter the Password: ";
			cin >> m_password;
			cout << "Please Re-Enter your password: ";
			cin >> hold;
			if (m_password != hold)
			{
				check = false;
				cout << "Password does't mach. Try again." << endl << endl;
			}
		} while (!check);
	}
}

void Admin::saveInfo()
{
	ofstream file_out("AdminID.txt");
	file_out << m_id << " " << m_password << endl;
}

void Admin::addID()
{

}
void Admin::addCourses()
{

}
void Admin::addMeeting()
{

}
