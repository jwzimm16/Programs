#include <iostream>
#include <string>
using namespace std;

int GetUserInput(int minimum, int maximum)
{
    int choice;
    bool done = false;
    while ( !done )
    {
        cout << endl << ">> ";
        cin >> choice;

        if ( choice < minimum || choice > maximum)
        {
            cout << endl << "Incorrect choice, try again." << endl;
        }
        else
        {
            done = true;
        }
    }

    return choice;
}

void DisplayMainMenu()
{
    cout << "1. Add class" << endl;
    cout << "2. Remove last class" << endl;
    cout << "3. Update class" << endl;
    cout << "4. View all classes" << endl;
    cout << "5. Clear all classes" << endl;
    cout << "6. Exit" << endl;
}

void AddClass(string classTitles[], string dateTime[], int classStudentCount[], int& classCount)
{
    if (classCount < 10)
    {
        cout << endl << "New class title: ";
        cin.ignore();
        string title;
        getline(cin, title);
        classTitles[classCount] = title;
		cout << "New class time/date: ";
		string time;
		getline(cin, time);
		dateTime[classCount] = time;
        cout << "New student count: ";
        cin >> classStudentCount[classCount];
        classCount++;
        cout << endl;
    }
    else
    {
        cout << "Maximum classes reached." << endl;
    }
}

void RemoveLastClass(string classTitles[], string dateTime[], int classStudentCount[], int& classCount)
{
    if (classCount > 0)
    {
        classTitles[classCount - 1] = "";
		dateTime[classCount - 1] = "";
        classStudentCount[classCount - 1] = 0;
        classCount--;
        cout << endl;
    }
    else
    {
        cout << endl << "Class list is already empty." << endl << endl;
    }
}

void clearList(string classTitles[], string dateTime[], int classStudentCount[], int& classCount)
{
    char clear;
    bool done = false;
    while ( !done )
    {
        cout << endl << "Are you sure? Y or N >> ";
        cin >> clear;
        if ( clear == 'Y' || clear == 'y' )
        {
            for ( int i = classCount; i > 0; i--)
            {
                classTitles[i - 1] = "";
				dateTime[i - 1] = "";
                classStudentCount[i - 1] = 0;
                classCount--;
            }
            done = true;
        }
        else if (clear == 'N' || clear == 'n')
        {
            cout << endl << "Aborting" << endl;
            done = true;
        }
        else
        {
            cout << endl << "Invalid choice" << endl;
        }
        cout << endl;
    }
}

void UpdateClass(string classTitles[], string dateTime[], int classStudentCount[], int& classCount)
{
    for (int i = 0; i < classCount; i++)
    {
        cout << endl << i + 1 << ". " << classTitles[i] << ", " << dateTime[i] << ", " << classStudentCount[i];
    }

    cout << endl;
    int index = GetUserInput(1, classCount);

    cout << endl << "New class title: ";
    cin.ignore();
    string title;
    getline(cin, title);
    classTitles[index - 1] = title;
	cout << "New class time/date: ";
	string time;
	getline(cin, time);
	dateTime[index - 1] = time;
    cout << "New student count: ";
    cin >> classStudentCount[index - 1];
    cout << endl;
}

void ViewAllClasses(string classTitles[], string dateTime[], int classStudentCount[], int& classCount)
{
    for (int i = 0; i < classCount; i++)
    {
        cout << endl << classTitles[i] << ", " << dateTime[i] << ", " << classStudentCount[i];
    }
    cout << endl << endl;
}

int main()
{
    string classTitles[10];
	string dateTime[10];
    int classStudentCount[10];
    int classCount = 0;
    bool done = false;

    while ( !done )
    {
        DisplayMainMenu();
        int choice = GetUserInput(1,6);
        if ( choice == 1 )
        {
            AddClass(classTitles, dateTime, classStudentCount, classCount);
        }
        else if ( choice == 2 )
        {
			RemoveLastClass(classTitles, dateTime, classStudentCount, classCount);
        }
        else if ( choice == 3 )
        {
			UpdateClass(classTitles, dateTime, classStudentCount, classCount);
        }
        else if ( choice == 4 )
        {
			ViewAllClasses(classTitles, dateTime, classStudentCount, classCount);
        }
        else if ( choice == 5 )
        {
			clearList(classTitles, dateTime, classStudentCount, classCount);
        }
        else if ( choice == 6 )
        {
            done = true;
        }
    }

    return 0;
}
