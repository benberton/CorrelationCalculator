#ifndef CORRELATION_CORRELATION_H
#define CORRELATION_CORRELATION_H
#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
using namespace std;


//double getAverage(vector<double> myVector);
double getTotal(vector<double> myVector);
void squareVector(vector<double> desiredVector, vector<double> &vectorSquared);
void multiplyXY(vector<double> xVector, vector<double> yVector, vector<double> &vectorXY);
double calculateTestStatistic(double n, double error);
int getColumnTestStatistic(double error);
void rejectNull(double,double);
#endif //CORRELATION_CORRELATION_H
