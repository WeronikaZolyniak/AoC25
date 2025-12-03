#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <cstdint>
using namespace std;

vector<pair<string, string>> vec;

bool IsIDInvalid(string strId)
{
    int idLen = strId.length();
    if(idLen % 2 != 0)
    {
        return false;
    }

    string firstPart = strId.substr(0, idLen / 2);
    string secPart = strId.substr(idLen / 2, idLen / 2);
    if(firstPart == secPart)
    {
        return true;
    }
    
    return false;
}

uint64_t AddAllInvalidIDsInRange(uint64_t firstId, uint64_t secId)
{
    uint64_t result = 0;
   
    for(uint64_t i = firstId; i <= secId; i++)
    {
        string strI = to_string(i);
        if(IsIDInvalid(strI))
        {
            result += i;
        }
    }
    return result;
}

void First()
{
    uint64_t res = 0;
    for(pair<string, string> pair : vec)
    {
        uint64_t firstId = stoull(pair.first);
        uint64_t secId = stoull(pair.second);
        res += AddAllInvalidIDsInRange(firstId, secId);
    }
    cout << res << endl;
}

//sec part

bool IsIDInvalidSec(string strId)
{
    int idLen = strId.length();
    for(int i = idLen; i >= 2; i--)
    {
        if (idLen % i != 0)
        {
            continue;
        }

        int lengthOfPart = idLen / i;
        string firstPart = strId.substr(0, lengthOfPart);
        bool bIsInvalid = true;
        for(int j = lengthOfPart; j < idLen; j+= lengthOfPart)
        {
            string partToCompare = strId.substr(j, lengthOfPart);
            if(partToCompare != firstPart)
            {
                bIsInvalid = false;
                break;
            }
        }

        if (bIsInvalid)
        {
            return true;
        }
    }

    return false;
}

uint64_t AddAllInvalidIDsInRangeSec(uint64_t firstId, uint64_t secId)
{
    uint64_t result = 0;
   
    for(uint64_t i = firstId; i <= secId; i++)
    {
        string strI = to_string(i);
        if(IsIDInvalidSec(strI))
        {
            result += i;
        }
    }
    return result;
}

void Second()
{
   uint64_t res = 0;
    for(pair<string, string> pair : vec)
    {
        uint64_t firstId = stoull(pair.first);
        uint64_t secId = stoull(pair.second);
        res += AddAllInvalidIDsInRangeSec(firstId, secId);
    }
    cout << res << endl;
}

int main()
{
    ifstream file;
    file.open("2.txt");
    string line;
    getline(file, line);
    stringstream strstream(line);
    string temp;
    while (getline(strstream, temp, ',')) 
    {
        int dashPos = temp.find('-');
        string firstId = temp.substr(0, dashPos);
        string secId = temp.substr(dashPos + 1, temp.length() - dashPos);
        vec.push_back(make_pair(firstId, secId));
    }

    
    //First();
    Second();
    
}
