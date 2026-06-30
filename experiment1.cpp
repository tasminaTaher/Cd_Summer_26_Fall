
#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    int choice;

    cout << "========== MENU ==========\n";
    cout << "1. Check Numeric\n";
    cout << "2. Check Operator\n";
    cout << "3. Check Comment\n";
    cout << "4. Check Identifier\n";
    cout << "5. Calculate Average\n";
    cout << "6. Find Min and Max\n";
    cout << "7. Concatenate First and Last Name\n";
    cout << "Enter your choice: ";
    cin >> choice;
    cin.ignore();

    if(choice == 1)
    {
        string c;

        cout << "Enter The Value: ";
        cin >> c;

        bool numeric = true;

        for(int i = 0; i < c.length(); i++)
        {
            if(c[i] < '0' || c[i] > '9')
            {
                numeric = false;
                break;
            }
        }

        if(numeric)
            cout << "Numeric";
        else
            cout << "Not Numeric";
    }

    else if(choice == 2)
    {
        string c;

        cout << "Enter The Value: ";
        cin >> c;

        for(int i = 0; i < c.length(); i++)
        {
            switch(c[i])
            {
                case '+':
                    cout << "Operator: + (Addition)\n";
                    break;
                case '-':
                    cout << "Operator: - (Subtraction)\n";
                    break;
                case '*':
                    cout << "Operator: * (Multiplication)\n";
                    break;
                case '/':
                    cout << "Operator: / (Division)\n";
                    break;
                case '%':
                    cout << "Operator: % (Modulus)\n";
                    break;
                case '=':
                    cout << "Operator: = (Assignment)\n";
                    break;
                default:
                    cout << c[i] << " is not an operator\n";
            }
        }
    }

    else if(choice == 3)
    {
        char str[200];

        cout << "Enter the input: ";
        cin.getline(str, 200);

        int len = strlen(str);

        if(len >= 2 && str[0] == '/' && str[1] == '/')
        {
            cout << "Single Line Comment";
        }
        else if(len >= 2 && str[0] == '/' && str[1] == '*')
        {
            cout << "Multi Line Comment";
        }
        else if(len >= 2 && str[len-2] == '*' && str[len-1] == '/')
        {
            cout << "Multi Line Comment";
        }
        else
        {
            cout << "Not a Comment";
        }
    }

    else if(choice == 4)
    {
        string str;

        cout << "Enter Input: ";
        getline(cin, str);

        bool valid = true;

        if(str.length() == 0)
            valid = false;
        else if(!((str[0] >= 'A' && str[0] <= 'Z') ||
                  (str[0] >= 'a' && str[0] <= 'z') ||
                   str[0] == '_'))
            valid = false;

        for(int i = 1; i < str.length() && valid; i++)
        {
            if(!((str[i] >= 'A' && str[i] <= 'Z') ||
                 (str[i] >= 'a' && str[i] <= 'z') ||
                 (str[i] >= '0' && str[i] <= '9') ||
                  str[i] == '_'))
            {
                valid = false;
            }
        }

        if(valid)
            cout << "Valid Identifier";
        else
            cout << "Not an Identifier";
    }

    else if(choice == 5)
    {
        int n;
        float sum = 0, avg;

        cout << "Enter Size: ";
        cin >> n;

        int arr[n];

        cout << "Enter Elements: ";

        for(int i = 0; i < n; i++)
        {
            cin >> arr[i];
            sum += arr[i];
        }

        avg = sum / n;

        cout << "Average = " << avg;
    }

    else if(choice == 6)
    {
        int n;

        cout << "Enter  the number of elements: ";
        cin >> n;

        int arr[n];

        cout << "Enter Elements: ";

        for(int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        int min = arr[0];
        int max = arr[0];

        for(int i = 1; i < n; i++)
        {
            if(arr[i] < min)
                min = arr[i];

            if(arr[i] > max)
                max = arr[i];
        }

        cout << "Minimum = " << min << endl;
        cout << "Maximum = " << max;
    }

    else if(choice == 7)
    {
        string firstName, lastName, fullName;

        cout << "Enter First Name: ";
        cin >> firstName;

        cout << "Enter Last Name: ";
        cin >> lastName;

        fullName = firstName + " " + lastName;

        cout << "Full Name = " << fullName;
    }

    else
    {
        cout << "Invalid Choice";
    }

    return 0;
}
