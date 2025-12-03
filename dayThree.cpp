#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

vector<string> vec;

void First()
{
    int finalResult = 0;
    for (string line : vec)
    {
        string strResult = "";
        int highestIx = 0;
        char highestNum = line[0];
        for(int i = 0; i < line.length() - 1; i++)
        {
            if(line[i] == '9')
            {
                highestIx = i;
                highestNum = '9';
                break;
            }

            if(line[i] - '0' > highestNum - '0')
            {
                highestIx = i;
                highestNum = line[i];
            }
        }

        strResult += highestNum;
        highestIx++;
        highestNum = line[highestIx];
        for(int i = highestIx + 1; i < line.length(); i++)
        {
            if(line[i] == '9')
            {
                highestIx = i;
                highestNum = '9';
                break;
            }

            if(line[i] - '0' > highestNum - '0')
            {
                highestIx = i;
                highestNum = line[i];
            }
        }

        strResult += highestNum;
        finalResult += stoi(strResult);
    }
    cout << finalResult << endl;
}

int main()
{
    ifstream file;
    file.open("3.txt");
    for(int i = 0; i < 200; i++)
    {
        string temp;
        file >> temp;
        vec.push_back(temp);
    }

    First();
    return 0;
}