#include <iostream>
using namespace std;

void insertionSort(int arr[], int n)
{
    int comparisons = 0;
    int shifts = 0;

    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0)
        {
            comparisons++;

            // For descending order
            if (arr[j] < key)
            {
                arr[j + 1] = arr[j];
                j--;
                shifts++;
            }
            else
            {
                break;
            }
        }

        arr[j + 1] = key;
    }

    cout << "\nTotal Comparisons: " << comparisons << endl;
    cout << "Total Shifts: " << shifts << endl;
}

int main()
{
    int n;
    do
    {
        cout << "Enter number of students (5-15): ";
        cin >> n;

        if (n < 5 || n > 15)
        {
            cout << "Invalid number! Please enter between 5 and 15.\n";
        }

    } while (n < 5 || n > 15);

    int marks[15];
    for (int i = 0; i < n; i++)
    {
        do
        {
            cout << "Enter marks for student " << i + 1 << ": ";
            cin >> marks[i];

            if (marks[i] < 0 || marks[i] > 100)
            {
                cout << "Invalid marks! Enter marks between 0 and 100.\n";
            }

        } while (marks[i] < 0 || marks[i] > 100);
    }
    
    int highest = marks[0];
    int lowest = marks[0];
    int sum = 0;
    bool highAchiever = false;

    for (int i = 0; i < n; i++)
    {
        sum += marks[i];

        if (marks[i] > highest)
        {
            highest = marks[i];
        }

        if (marks[i] < lowest)
        {
            lowest = marks[i];
        }

        if (marks[i] >= 90)
        {
            highAchiever = true;
        }
    }

    double average = (double)sum / n;
    insertionSort(marks, n);

    cout << "\nHighest Marks: " << highest << endl;
    cout << "Lowest Marks: " << lowest << endl;
    cout << "Average Marks: " << average << endl;

    cout << "Sorted Marks: ";

    for (int i = 0; i < n; i++)
    {
        cout << marks[i] << " ";
    }

    cout << endl;

    if (highAchiever)
    {
        cout << "High Achiever(s) Present" << endl;
    }
    else
    {
        cout << "No High Achiever" << endl;
    }

    return 0;
}