//ISHAAN GUPTA
//UID: 905917973


#include <iostream>
#include <cctype>
#include <string>
#include <cassert>
using namespace std;

bool isValidPollString(string pollData);

int countSeats(string pollData, char party, int& seatCount);

bool isValidUppercaseStateCode(string stateCode);

int main()
{

}


//this method counts the number of seats for a particular party within the poll data string
int countSeats(string pollData, char party, int& seatCount)
{
    int tempSeatCount = 0;
    
    //if the poll string is not a valid poll string return 1
    if (!(isValidPollString(pollData)))
    {
        return 1;
    }
    
    //if the party were looking for is not a valid party return 2
    if (!(isalpha(party)))
    {
        return 2;
    }
    
    //iterate through the poll data string
    for (int i = 0; i < pollData.size() - 1; i++)
    {
        //if its a single digit then the party letter
        if (isdigit(pollData.at(i)) && isalpha(pollData.at(i+1)))
        {
            //if the party letter matches the party we're looking for, add the number before the party letter to the seat count
            if ((char)toupper(pollData.at(i+1)) == (char)toupper(party))
            {
                string temp;
                temp += pollData.at(i);
                tempSeatCount += stoi(temp);
            }
            
        }
        //if its 2 digits and then the party letter
        else if (i < pollData.size() - 3 && isdigit(pollData.at(i)) && isdigit(pollData.at(i+1)) && isalpha(pollData.at(i+2)))
        {
            //if the party letter matches the party we're looking for, add the double digit number before the party letter to the seat count
            if ((char)toupper(pollData.at(i+2)) == (char)toupper(party))
            {
                string tempNum;
                tempNum += pollData.at(i);
                tempNum += pollData.at(i+1);
                tempSeatCount += stoi(tempNum);
            }
            i++;
        }
    }
    
    seatCount = tempSeatCount;
    
    return 0;
}

//checks if the poll data string is a valid poll data string
bool isValidPollString(string pollData)
{
    if (pollData.size() == 0)
    {
        return true;
    }
    //iterate through the string
    for (int i = 0; i < pollData.size() - 1; i++)
    {
        string stateLetters = "";
        
        stateLetters += toupper(pollData.at(i));
        stateLetters += toupper(pollData.at(i+1));
                                                             
        //check if the first two letters are valid state codes
        if (!(isValidUppercaseStateCode(stateLetters)))
        {
            return false;
        }
        
        i+=2;
        
        //keep going through the string until there is a comma or its the end of the string
        while (i < pollData.size() && pollData.at(i) != ',')
        {
            //if after the state code its not a digit return false
            if (!(isdigit(pollData.at(i))))
            {
                return false;
            }
            
            i++;
            
            //if its not a digit or a letter after the first digit return false
            if (!(isdigit(pollData.at(i)) || isalpha(pollData.at(i))))
            {
                return false;
            }
            
            //if its a digit and there is not a party letter after it return false
            if (isdigit(pollData.at(i)))
            {
                if (!isalpha(pollData.at(i+1)))
                {
                    return false;
                }
                i++;
            }
            
            i++;
        }
        
    }
    
    return true;
}

//*************************************
//  isValidUppercaseStateCode
//*************************************

// Return true if the argument is a two-uppercase-letter state code, or
// false otherwise.

bool isValidUppercaseStateCode(string stateCode)
{
    const string codes =
        "AL.AK.AZ.AR.CA.CO.CT.DE.FL.GA.HI.ID.IL.IN.IA.KS.KY."
        "LA.ME.MA.MD.MI.MN.MS.MO.MT.NE.NV.NH.NJ.NM.NY.NC.ND."
        "OH.OK.OR.PA.RI.SC.SD.TN.TX.UT.VT.VA.WA.WV.WI.WY";
    return (stateCode.size() == 2  &&
            stateCode.find('.') == string::npos  &&  // no '.' in stateCode
            codes.find(stateCode) != string::npos);  // match found
}
