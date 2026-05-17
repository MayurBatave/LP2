// #include <iostream>
// using namespace std;

// int main() {

//     int attendance, project, communication, technical;
//     int total, average;

//     cout << "===== Employee Performance Evaluation Expert System =====" << endl;

//     // Input
//     cout << "Enter Attendance Marks (out of 100): ";
//     cin >> attendance;

//     cout << "Enter Project Work Marks (out of 100): ";
//     cin >> project;

//     cout << "Enter Communication Skill Marks (out of 100): ";
//     cin >> communication;

//     cout << "Enter Technical Skill Marks (out of 100): ";
//     cin >> technical;

//     // Calculate total and average
//     total = attendance + project + communication + technical;
//     average = total / 4;

//     cout << "\n===== Performance Result =====" << endl;

//     cout << "Average Score: " << average << endl;

//     // Expert System Rules
//     if (average >= 85) {

//         cout << "Performance: Excellent" << endl;
//         cout << "Suggestion: Promotion Recommended" << endl;
//     }

//     else if (average >= 70 && average < 85) {

//         cout << "Performance: Good" << endl;
//         cout << "Suggestion: Performance is satisfactory" << endl;
//     }

//     else if (average >= 50 && average < 70) {

//         cout << "Performance: Average" << endl;
//         cout << "Suggestion: Needs Improvement" << endl;
//     }

//     else {

//         cout << "Performance: Poor" << endl;
//         cout << "Suggestion: Training Required" << endl;
//     }

//     return 0;
// }

#include <iostream>
#include <string>
using namespace std;

int main()
{

    string symptom;

    cout << "===== Hospital Expert System =====" << endl;

    cout << "Enter your symptom: ";
    getline(cin, symptom);

    // Expert System Rules

    if (symptom == "fever")
    {

        cout << "\nPossible Disease: Viral Infection" << endl;
        cout << "Medicine Suggestion: Paracetamol" << endl;
        cout << "Advice: Take rest and drink plenty of water." << endl;
    }

    else if (symptom == "cough")
    {

        cout << "\nPossible Disease: Common Cold" << endl;
        cout << "Medicine Suggestion: Cough Syrup" << endl;
        cout << "Advice: Drink warm water and avoid cold food." << endl;
    }

    else if (symptom == "headache")
    {

        cout << "\nPossible Disease: Migraine or Stress" << endl;
        cout << "Medicine Suggestion: Pain Reliever" << endl;
        cout << "Advice: Take proper sleep and avoid stress." << endl;
    }

    else if (symptom == "stomach pain")
    {

        cout << "\nPossible Disease: Acidity or Indigestion" << endl;
        cout << "Medicine Suggestion: Antacid" << endl;
        cout << "Advice: Avoid oily and spicy food." << endl;
    }

    else if (symptom == "chest pain")
    {

        cout << "\nPossible Disease: Heart-related Problem" << endl;
        cout << "Advice: Consult a doctor immediately!" << endl;
    }

    else
    {

        cout << "\nSymptom not found in database." << endl;
        cout << "Please consult a doctor." << endl;
    }

    return 0;
}