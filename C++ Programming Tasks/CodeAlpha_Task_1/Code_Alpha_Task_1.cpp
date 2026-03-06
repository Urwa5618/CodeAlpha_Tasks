#include <iostream>
using namespace std;

int main(){
    int no_of_courses;
    
    cout << "Enter number of courses: " << endl;
    cin >> no_of_courses;

    float grade;
    float gradepoints;
    int credit_hours;
    float totalgrade = 0;
    float totalcredits = 0;

    for(int i=0;i<no_of_courses;i++){
        cout << "\nCourse:" << i+1 << endl;
        
        cout << "Enter Grade:" << endl;
        cin >> grade;

        cout << "Enter credit hours:" << endl;
        cin >> credit_hours;

        gradepoints = grade * credit_hours;

        totalgrade += gradepoints;
        totalcredits += credit_hours;
    }
        float GPA = totalgrade / totalcredits;

        cout << "\n--------------------" << endl;
        cout << "\nSemester GPA:" << GPA << endl;
        cout << "\n--------------------\n" << endl;
        char choice;
        
        cout << "Do you want to calculate overall CGPA (y/n):" << endl;
        cin >> choice;
        
        if(choice == 'Y' || choice == 'y'){
            float previousCGPA;
            float previouscredit;

            cout << "Enter previous GPA:" << endl;
            cin >> previousCGPA;
            
            cout << "Enter previous credit:" << endl;
            cin >> previouscredit;
            
            float CGPA = ((previousCGPA * previouscredit) + (GPA * totalcredits))  / (previouscredit + totalcredits);
            
            cout << "overall CGPA:" << CGPA << endl;

        }
        
        cout << "Program Finished successfully!" << endl;
    
        return 0;
}