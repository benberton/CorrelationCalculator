#include "correlation.h"




int main() {
    double xTotal, yTotal, xyTotal, xsTotal, ysTotal, rValue, nValue, mValue, bValue, tValue;
    vector<double> xValues;
    vector<double> yValues;



    //taking in the x and y values
    bool run = true;
    int count = 0;
    string pushBackValue;

    cout << "Enter your x values\nWhen finished, enter 'Stop'" << endl;
    while(run)
    {

        cin >> pushBackValue;

        if(pushBackValue == "Stop" || pushBackValue == "stop")
        {
            run = false;
            cout << count << " x values were entered" << endl;
        }else{
             xValues.push_back(std::stod(pushBackValue));
             count++;
        }

    }

    run = true;
    cout << "Enter your y values\nWhen finished, enter 'Stop'" << endl;
    count = 0;
    while(run)
    {

        cin >> pushBackValue;

        if(pushBackValue == "Stop" || pushBackValue == "stop")
        {
            run = false;
            cout << count << " y values were entered" << endl;
        }else{
            yValues.push_back(std::stod(pushBackValue));
            count++;
        }

    }

    if (xValues.size() > yValues.size())
    {
        cout << "Error: more x values than y values entered" << endl;
        return 0;
    }else if(xValues.size() < yValues.size()){
        cout << "Error: more y values than x values entered" << endl;
        return 0;
    }

    cout << "Your data set is..." << endl;
    for(int i = 0; i < xValues.size(); i++)
    {
        cout << "(" << xValues[i] << "," << yValues[i] << ")";
    }
    cout << endl;

    //creating other necessary vectors
    vector<double> xSquared(xValues.size()); //will hold the xValues squared
    vector<double> ySquared(xValues.size()); //will hold the yValues squared
    vector<double> xy(xValues.size()); //will hold the value of x*y
    nValue = xValues.size();squareVector(xValues, xSquared);
    squareVector(yValues, ySquared);
    multiplyXY(xValues, yValues, xy);

    //calculating totals
    xTotal = getTotal(xValues);
    yTotal = getTotal(yValues);
    xyTotal = getTotal(xy);
    xsTotal = getTotal(xSquared);
    ysTotal = getTotal(ySquared);

    //calculating values
    rValue = (nValue * xyTotal - xTotal * yTotal) /
             (sqrt((nValue * xsTotal - pow(xTotal, 2)) * (nValue * ysTotal - pow(yTotal, 2))));
    mValue = (nValue * xyTotal - xTotal * yTotal) / (nValue * xsTotal - pow(xTotal, 2));
    bValue = (yTotal * xsTotal - xTotal * xyTotal) / (nValue * xsTotal - pow(xTotal, 2));
    tValue = rValue * sqrt((nValue - 2) / (1 - pow(rValue, 2)));


    cout << "r = " << rValue << endl;
    cout << "y = " << mValue << "x + " << bValue << endl;
    cout << "t = " << tValue << endl;

    double error;
    double criticalValue;
    cout << "What is your desired confidence level?" << endl;
    cout << "Choose 0,50,60,70,80,90,95,98,99,99.8,or 99.9" << endl;
    cout << "(Set for a two tailed test)" << endl;
    cin >> error;
    criticalValue = calculateTestStatistic(nValue, error);
    cout << "Critical Value = +/-" << criticalValue << endl;
    rejectNull(criticalValue,tValue);
    return 0;
}
