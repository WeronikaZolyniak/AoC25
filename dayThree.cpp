#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <map>
#include <cstdint>
#include <algorithm>
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

uint64_t ResolveNumberForLine(string line)
{
    map<char, vector<int>> m;
    for(int i = 0; i < line.length(); i++)
    {
        m[line[i]].push_back(i);
        sort(m[line[i]].begin(), m[line[i]].end(), greater<int>());
    }

    char highStart = line[0];
    int highStartIx = 0;
    
    for(int i = 1; i < line.length() - 12; i++)
    {
        if(line[i] - '0' > highStart - '0')
        {
            highStart = line[i];
            highStartIx = i;
        }
    }
    
    map<int, char> mapNum;
    for (auto it = m.rbegin(); it != m.rend(); ++it)
    { 
        for(int i = 0; i < it->second.size(); i++)
        {
            if(it->second[i] == highStartIx)
            {
                continue;
            }
            if(it->second[i] > highStartIx)
            {
                mapNum[it->second[i]] = it->first;
            }
            
            if(mapNum.size() == 11)
            {
                break;
            }
        }

        if(mapNum.size() == 11)
        {
            break;
        }
    }

    string strRes = "";
    strRes += highStart;
    for(pair<int, char> pair : mapNum)
    {
        strRes += pair.second;
    }
    uint64_t result = stoull(strRes);
    cout << result << endl;
    return result;
}

void Second()
{
    uint64_t result = 0;
    for (string line : vec)
    {
        result += ResolveNumberForLine(line);
    }
    cout << endl << endl << endl << result << endl;
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

    //First();
    Second();
    
    return 0;
}