#include<iostream>
#include<iomanip>
#include<fstream>
#include<stdlib.h>
#include<string.h>
using namespace std;

struct ClassGradeReport {
    char FirstName[100];
    char LastName[100];
    double t1, t2, t3, t4, t5;
    double StudentAverage;
    char LetterGrade;
};

 struct ClassGradeReport CGReport[25];

class Students {
  public:
    double StudentGrades, TotalGradeAvg;
    double testAvg[5] = {0};
    double avg;
    double highestGrades;
    void ReadFile(ifstream & inFile) {
      inFile.open("CIT1325.txt");
      for (int i = 1; i <= 25; i++) {
      inFile >> CGReport[i].FirstName;
      inFile >> CGReport[i].LastName;
      inFile >> CGReport[i].t1;
      testAvg[0] += CGReport[i].t1;
      inFile >> CGReport[i].t2;
      testAvg[1] += CGReport[i].t2;
      inFile >> CGReport[i].t3;
      testAvg[2] += CGReport[i].t3;
      inFile >> CGReport[i].t4;
      testAvg[3] += CGReport[i].t4;
      inFile >> CGReport[i].t5;
      testAvg[4] += CGReport[i].t5;
    }
    inFile.close();
 }
 public:
   void printdata() {
     for (int i = 1; i <= 25; i++) {
        cout << setw(15) << left << CGReport[i].FirstName;
        cout << setw(15) << left << CGReport[i].LastName;
        cout << setw(10) << left << CGReport[i].t1;
        cout << setw(10) << left << CGReport[i].t2;
        cout << setw(10) << left << CGReport[i].t3;
        cout << setw(10) << left << CGReport[i].t4;
        cout << setw(10) << left << CGReport[i].t5 << endl;
      }
    }

 public:
   void FindGrades() {
      avg = 0;
      for(int i = 0; i < 5; i++){
        testAvg[i] /= 25;
        avg += testAvg[i];
      }
      avg /= 5;
      StudentGrades = 0, highestGrades = 0;
      for (int i = 1; i <= 25; i++) {
        TotalGradeAvg = (CGReport[i].t1 + CGReport[i].t2 + CGReport[i].t3 + CGReport[i].t4 + CGReport[i].t5);
        CGReport[i].StudentAverage = TotalGradeAvg / 5;
        if (CGReport[i].StudentAverage > 80)
          CGReport[i].LetterGrade = 'A';
        else if (CGReport[i].StudentAverage > 70 && CGReport[i].StudentAverage <= 80)
          CGReport[i].LetterGrade = 'B';
        else if (CGReport[i].StudentAverage > 60 && CGReport[i].StudentAverage < 70)
          CGReport[i].LetterGrade = 'C';
        else if (CGReport[i].StudentAverage > 50 && CGReport[i].StudentAverage < 60)
          CGReport[i].LetterGrade = 'D';
        StudentGrades = StudentGrades + TotalGradeAvg;
        if (highestGrades < CGReport[i].StudentAverage) {
          highestGrades = CGReport[i].StudentAverage;
        }
      }
    }

 public:
    void GradesReport(ofstream & outFile) {
      outFile.open("GradeReport.txt");
      outFile << setw(50) << setfill('#') << right << " San Jacinto Class Grade Report ";
      outFile << setw(37) << right << "" << endl << endl;
      outFile << setfill(' ') << setw(15) << left << "First Name";
      outFile << setw(15) << left << "Last Name";
      outFile << setw(10) << left << "Test 1";
      outFile << setw(10) << left << "Test 2";
      outFile << setw(10) << left << "Test 3";
      outFile << setw(10) << left << "Test 4";
      outFile << setw(10) << left << "Final";
      outFile << setw(15) << left << "Grade Average";
      outFile << setw(15) << left << "Letter Grade" << endl;
      cout << setw(50) << setfill('*') << right << " San Jacinto Class Grade Report ";
      cout << setw(37) << right << "" << endl << endl;
      cout << setfill(' ') << setw(15) << left << "First Name";
      cout << setw(15) << left << "Last Name";
      cout << setw(10) << left << "Test 1";
      cout << setw(10) << left << "Test 2";
      cout << setw(10) << left << "Test 3";
      cout << setw(10) << left << "Test 4";
      cout << setw(10) << left << "Final";
      cout << setw(15) << left << "Grade Average";
      cout << setw(15) << left << "Letter Grade" << endl;
      for (int i = 1; i <= 25; i++) {
        outFile << setw(15) << left << CGReport[i].FirstName;
        outFile << setw(15) << left << CGReport[i].LastName;
        outFile << setw(10) << left << CGReport[i].t1;
        outFile << setw(10) << left << CGReport[i].t2;
        outFile << setw(10) << left << CGReport[i].t3;
        outFile << setw(10) << left << CGReport[i].t4;
        outFile << setw(10) << left << CGReport[i].t5;
        outFile << setw(15) << left << CGReport[i].StudentAverage;
        outFile << setw(15) << left << CGReport[i].LetterGrade << endl;
        cout << setw(15) << left << CGReport[i].FirstName;
        cout << setw(15) << left << CGReport[i].LastName;
        cout << setw(10) << left << CGReport[i].t1;
        cout << setw(10) << left << CGReport[i].t2;
        cout << setw(10) << left << CGReport[i].t3;
        cout << setw(10) << left << CGReport[i].t4;
        cout << setw(10) << left << CGReport[i].t5;
        cout << setw(15) << left << CGReport[i].StudentAverage;
        cout << setw(15) << left << CGReport[i].LetterGrade << endl;
      }
      for(int i = 0; i < 5; i++){
        cout << "\nAverage of Test " << i + 1 << " = " << testAvg[i];
        outFile << "\nAverage of Test " << i + 1 << " = " << testAvg[i];
      }
      cout << "\n\nAverage of All tests = " << avg << endl;
      outFile << "\n\nAverage of All tests = " << avg << endl;
      cout << "\nThe Student with the Highest Grade Average is: Bobby Best " << highestGrades << endl;
      outFile << "\nStudent with Highest Grade : Bobby Best " << highestGrades << endl;
      cout << "\n GradeReport Saved Successfully to the Outputfile" << endl;
      outFile.close();
    }
};

int main() {
    Students students;
    cout << "\n------------------------------" << endl;
    cout << "\n *** San Jacinto Class Grade Report ***" << endl;
    cout << "\n------------------------------" << endl;
    ifstream inFile;
    students.ReadFile(inFile); //reading input file.
    cout << "\nData from the input File is:" << endl;
    students.printdata();
    cout << "\nCalculating Grades..........." << endl;
    students.FindGrades();
    cout << "\n the Grade Report is " << endl;
    cout << "\n------------------------------" << endl;
    ofstream outFile;
    students.GradesReport(outFile);
    return 0;
}
