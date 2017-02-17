#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
#include <fstream>
#include <cassert>

using namespace std;


//Create password based on # of systems 
void password_creator(ostream& out, string mylist[], int numArgs);

// Generate 16 char password with random chars
string generatePassword();

// Test strength of password
bool isStrongPassword(string testMe);

///////////////////////////////////////////////////////////////////////////

int main()
{
	string filename;
	int arg_size;

	cout << "Enter number of systems:\t\t";
	cin >> arg_size;

	assert(arg_size > 0);

	cout << "\nEnter " << arg_size << " system names ";
	cout << "to generate passwords for:\n\nNO SPACES\n\n";

	string* cleanFields = new string[arg_size];
	string* rawFields = new string[arg_size];

	for (int k = 0; k < arg_size; k++)
	{
		cout << "Enter field #" << k+1 << ":\t";
		cin >> cleanFields[k];
		rawFields[k] = cleanFields[k];

		if (cleanFields[k].size() > 16)
		{
			cleanFields[k] = cleanFields[k].substr(0, 16);
		}
		else
			if (cleanFields[k].size() < 16)
		{
			while (cleanFields[k].size() < 16)
				cleanFields[k].push_back(' ');
		}
	}

	string temp;

	for (int i = 0; i < arg_size; i++)
	{
		temp += rawFields[i];
		if (i < arg_size - 1)
			temp += " , ";
	}
	temp += ".txt";

	filename = temp;

	ofstream outFile;
	outFile.open(filename.c_str());

	if (!outFile)
		exit(-1);

	//password_creator(cout, fields, arg_size); //testing
	password_creator(outFile, cleanFields, arg_size);

	cout << "Success!" << endl;
	cout << " Written to " << filename << endl;

	delete[] cleanFields;
	delete[] rawFields;
	outFile.close();
	
	return 0;
}

///////////////////////////////////////////////////////////////////////////

void password_creator(ostream& fout, string* mylist, int numArgs)
{
	fout << endl << "~~~" << endl << endl;
	fout << "     Passwords" << endl << " ";

	for (int n = 0; n < numArgs; n++)
		fout << "    |" << mylist[n] << "|";
	fout << endl;

	for (int n = 0; n < numArgs; n++)
	{
		if (n == 0)
			fout << " ";
		fout << "    |----------------|";
	}
	fout << endl;


	srand(time(NULL));

	for (int i = 1; i <= 100; i++)
	{
		fout << i;

		if (i < 10)
			fout << "     ";
		else
			if (i < 100)
				fout << "    ";
			else
				fout << "   ";

		for (int j = 0; j < numArgs; j++)
		{
			fout << generatePassword() << "      ";
		}

		fout << endl;
	}

}

///////////////////////////////////////////////////////////////////////////

bool isStrongPassword(string testMe)
{
	bool digitFound = false;
	bool upperFound = false;
	bool lowerFound = false;

	for (int i = 0; i < testMe.size(); i++)
	{
		if (isdigit(testMe[i]))
			digitFound = true;

		if (isupper(testMe[i]))
			upperFound = true;

		if (islower(testMe[i]))
			lowerFound = true;
	}

	if (digitFound == false || upperFound == false || lowerFound == false)
		return false;
	else
		return true;
}

///////////////////////////////////////////////////////////////////////////

/* clean */

string generatePassword()
{
	string passwd;
	int randASCII;
	char randChar;
	bool isGoodPassword = false;

	while (isGoodPassword == false)
	{
		for (int i = 0; i < 16; i++)
		{
			randASCII = (rand() % 94) + 33;

			randChar = char(randASCII);

			if (randChar == '!' || randChar == '&' || randChar == '\\')
				randChar++;

			passwd += char(randChar);
		}

		if (isStrongPassword(passwd) == true)
			isGoodPassword = true;
		else
			passwd.clear(); //reset password and regen
	}
	
	return passwd;
}





