#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    int count = 0; //for temp variable generation. 
    string line = "a = b / d * c + d - e + f";
    vector <string> tokens;
    stringstream check1(line);
    string intermediate;
     
    // Tokenizing w.r.t. space ' '
    while(getline(check1, intermediate, ' '))
    {
        tokens.push_back(intermediate);
    }
     
    // Printing the token vector
    for(int i = 0; i < tokens.size(); i++)
        cout << tokens[i] << '\n';
    
    
    for(int i = 2; i<tokens.size()-2; i++)    
    {
        if(i==2)
        {
            cout<<"t"<<count<<"="<<tokens[i]<<tokens[i+1]<<tokens[i+2]<<endl;
        }
        else
        {
            count++;
            cout<<"t"<<count<<"=t"<<count-1<<tokens[i+1]<<tokens[i+2]<<endl;
        }
        i++;
    }
    
    cout<<tokens[0]<<tokens[1]<<"t"<<count;
        
    
}
