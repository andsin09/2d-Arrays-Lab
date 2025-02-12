/*
Name: Andrew Sinha
Program Name: Using 2D Arrays Lab
Date: 2/12/2025
Extra: Show best class and the average in that class
*/

#include <iostream>

using namespace std;

int main(){
    //Q4
    srand(time(nullptr));
    int rows, columns;
    cout << "Enter the number of rows (1 <= number of rows <= 5)." << endl;
    cin >> rows;
    
    //error trap
    if(rows > 5 || rows < 1){
        cout << "Not in the right range." << endl;
        return 0;
    }

    cout << "Enter the number of coulmns (1 <= number of columns <= 5)." << endl;
    cin >> columns;

    //error trap again
    if(columns > 5 || columns < 1){
        cout << "Not in the right range." << endl;
        return 0;
    }
    int ranArray[5][5];

    for(int i = 0; i < rows; i++){
        for(int j = 0; j < columns; j++){
            //range of 50
            ranArray[i][j] = rand() % 50 + 1;
        }
    }

    //print
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < columns; j++){
            cout << ranArray[i][j] << " ";
        }
        cout << "\n";
    }
    
    int maxN = 0;
    int rid, cid;
    
    //get values for max element: value, row, column
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < columns; j++){
            if(ranArray[i][j] > maxN){
                maxN = ranArray[i][j];
                rid = i;
                cid = j;
            }
        }
    }

    cout << "Maximum Element: " << endl;
    cout << "Value: " << maxN << endl;
    cout << "Row: " << rid << endl;
    cout << "Column: " << cid << endl;

    
    
    //Q5
    double n;
    double nArray [10][10];

    //size it
    cout << "Enter the size of the matrix (n): " << endl;
    cin >> n;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            //random range of 100
            nArray[i][j] = rand() % 100 + 1;
        }
    }
    
    //print it
    cout << "Generated Matrix: " << endl;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << nArray[i][j] << " ";
        }

        cout << "\n";
    }
    
    //row sum/average
    double sum = 0;
    cout << "Sum and Average per Row: " << endl;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            sum += nArray[i][j];
        }
        cout << "Row " << i+1 << ": Sum = "<< sum << ", Average = " << (sum/n) << endl;
        sum = 0;
    }
    //now for the Columns
    cout << "\n";
    cout << "Sum and Average per Column: " << endl;
    for(int j = 0; j < n; j++){
        double colSum = 0;
        for(int i = 0; i < n; i++){
            colSum += nArray[i][j];
        }
        cout << "Column " << j+1 << ": Sum = "<< colSum << ", Average = " << (colSum/n) << endl;
    }



    //Q6
    double subArray[10][3];
    double numStudents = 0;

    cout << "Enter the number of students: " << endl;
    cin >> numStudents;

    for(int i = 0; i < numStudents; i++){
        for(int j = 0; j < 3; j++){
            subArray[i][j] = rand() %51 + 50;
        }
    }

    //Printing the Matrix neatly?
    cout << "Generated Exam Scores Matrix: " << endl;
    cout << "Math\t\tEnglish\t\tScience" << endl;
    for(int i = 0; i < numStudents; i++){
        for(int j = 0; j < 3; j++){
            cout << subArray[i][j] << "\t\t";
        }
        cout << "\n";
    }

    //To get subject averages
    string subs[3] =  {"Math", "English", "Science"};
    double subAvg = 0;
    double subSum = 0;
    double bestAvg = 0;
    string bestClass = " ";
    cout << "Average Scores: " << endl;
    for(int j = 0; j < 3; j++){
        for(int i = 0; i < numStudents; i++){
            subSum += subArray[i][j];
        }
        subAvg = (subSum / numStudents);
        if(subAvg > bestAvg){
            bestAvg = subAvg;
            bestClass = subs[j];
        }
        cout << subs[j] << " " << subAvg << endl; 
    }
    cout << "Your best class average was " << bestClass << " and the average in that class was: " << bestAvg << endl;

}