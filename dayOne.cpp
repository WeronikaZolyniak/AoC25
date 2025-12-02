#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

vector<string> vec;

void First()
{
    int currentPoint = 50;
    int res = 0;

    for(string line : vec)
    {
        char direction = line[0];
        string lineNumStr = line.substr(1,line.length());
        int lineNum = stoi(lineNumStr);
        cout << line << endl;

        if(direction == 'L')
        {
            lineNum *= -1;
        }

        currentPoint = (currentPoint + lineNum) % 100;
        if (currentPoint == 0)
        {
            res++;
        }
        cout << res << " currentPoint: " << currentPoint << endl;
    }

    cout << endl << res;
}

void Second()
{
    int currentPoint = 50;
    int res = 0;
    cout << "Currentpoint: 50" << "; result: " << res << endl;
    for(string line : vec)
    {
        //---
        char direction = line[0];
        string lineNumStr = line.substr(1,line.length());
        cout << line << endl;
        int lineNum = stoi(lineNumStr);
        if(direction == 'L')
        {
            lineNum *= -1;
        }

        res += abs(lineNum / 100);
        lineNum = lineNum % 100;
        //----

        int start = currentPoint;
        int end = start + lineNum;

        if(end < 0)
        {
            if(start != 0)
            {
                res++;
            }
            
            currentPoint = 100 + end;
        }
        else if (end > 99)
        {
            res++;
            currentPoint = end - 100;
        }
        else
        {
            currentPoint = end;
        }

        if(end == 0)
        {
            res++;
        }

        cout << "Currentpoint: " << currentPoint << "; result: " << res << endl;
    }

    cout << endl << res;
}

int main()
{
    ifstream file;
    file.open("1.txt");
    for(int i = 0; i < 4498; i++)
    {
        string temp;
        file >> temp;
        vec.push_back(temp);
    }

    //First();
    Second();
    return 0;
}
