// KJN - it is good practice to insert comment about intended use, context, contributors, etc

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Convert ounces to pounds
double ounces2pounds(int ounces)
{
    return ounces / 16.0;
}

// Convert stones to pounds
double stones2pounds(int stones)
{
    return stones * 14.0;
}

// Convert stones, pounds, and ounces to kilograms
double weight2kg(int stones, int pounds, int ounces)
{
    return (stones2pounds(stones) + pounds + ounces2pounds(ounces)) / 2.2;
}

// Convert feet and inches to metres
double height2metres(int feet, int inches)
{
    return (feet + inches / 12.0) / 3.28;
}

// Categorise BMI into a specific class
char categorise(double kg, double metre)
{
    double bmi = kg / (metre * metre);
    char cat;
    if (bmi < 19)
        cat = 'A';
    else if (bmi < 25)
        cat = 'B';
    else if (bmi < 30)
        cat = 'C';
    else
        cat = 'D';
    return cat;
}

//Go through the input and output files to determine BMI category for each person
void process_data(char* input_file, char* output_file)
{
    ifstream f_in;
    ofstream f_out;
    string person_id;
    int stones, pounds, ounces, feet, inches;
    double kg, m;
    char cat;

    f_in.open(input_file, ios::in);
    f_out.open(output_file, ofstream::out);

    while (f_in >> person_id >> stones >> pounds >> ounces >> feet >> inches)
    {
        kg = weight2kg(stones, pounds, ounces);
        m = height2metres(feet, inches);
        cat = categorise(kg, m);
        f_out << person_id << " " << cat << endl;
    }

    f_in.close();
    f_out.close();
}
