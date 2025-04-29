// Code/bmi.h
#ifndef BMI_H
#define BMI_H

//Declaration headers for each function in bmi.cpp
double ounces2pounds(int ounces);
double stones2pounds(int stones);
double weight2kg(int stones, int pounds, int ounces);
double height2metres(int feet, int inches);
char categorise(double kg, double metre);

#endif
