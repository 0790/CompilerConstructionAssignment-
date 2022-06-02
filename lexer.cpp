/*
    Team 69:
    Eva Tiwari 2018B5A70816H
    Anirudh A 2018B4A70936H
    Deepti Kumar 2018B5A70790H
    Shreya Srirampur 2018B4A70886H
*/
#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;
/*
    Token List:
    1   +
    2   -
    3   *
    4   /
    5   %
    6   {
    7   }
    8   (
    9   )
    10  [
    11  ]
    12  ;
    13  ,
    14  ?
    15  =
    16  ==
    17  ===
    18  :
    19  >
    20  >=	
    21  <
    22  <=
    23  !
    24  !=
    25  !==
    26  &
    27  &&
    28  |
    29  ||
    30  id
    31  let
    32  val
    33  const
    34  for
    35  in
    36  of
    37  if
    38  else
    39  function
    40  return
    44  floating point
    46  integer
    48  string literal
*/

//Variable to store line number 
int line=1;
//map to store the tokens for the keywords
map <string,int> tokens;
//string array of reserved words
vector<string> keyword = {"let", "val", "const", "for", "in", "of", "if", "else","function", "return"};
//
int lb;
//lexer implemented using two buffers
void tokenizer(vector<char> b1, vector<char> b2, ifstream &code,ofstream &Output, int size){
    int state=0; //keep track of state number
    int flag=0;
    int x=1; //keeps track of buffer in use, 1 by default, else 2
    char c; //to track current character
    string number=""; //to store ints and floats
    string word=""; //to store strings in the code
    string temp=""; //temporary storage, for ids and keywords
    int filepointer=lb;
    while(flag==0){
        if(x==1) c=b1[filepointer];
		if(x==2) c=b2[filepointer];
		if(c=='\0') flag=1;
        //To ignore comments in the input code
		if(state == 4){
			if(c == '/'){
			    while(c != '\n'){
                    if(filepointer<size-1) filepointer++;
                    else{
                        if(x==1){
                            filepointer=0;
                            x=2;
                        }
                        else{
                            b1=b2;
                            b2.clear();
                            b2.resize(size,'\0');
                            code.read(b2.data(),size);
                            x==2;
                            filepointer=0;
                        }
                    }
                    if(x==1)
                        c=b1[filepointer];
                    if(x==2)
                        c=b2[filepointer];
			  }
			  state=0;
		    }
		}
        //DFA begins
        switch(state){
            case 0: //initial state in the DFA, in the beginning of every single lexeme
                if((c<='z' && c>='a')||(c<='Z' && c>='A')){ //move to the state which examines id, keywords etc.
                    temp+=c; //
                    state=30;
                    break;
                }
                switch(c){ //to evaluate symbols and numeric values in the code.
                    case ' ': break; //ignore spaces
                    case '\t': break; //ignores tabs
                    case '\n': line++; break; //changes line number
                    case '+': state=1; number+=c; break;
                    case '-': state=2; number+=c; break;
                    case '*': state=3; break;
                    case '/': state=4; break;
                    case '%': state=5; break;
                    case '{': state=6; break;
                    case '}': state=7; break;
                    case '(': state=8; break;
                    case ')': state=9; break;
                    case '[': state=10; break;
                    case ']': state=11; break;
                    case ';': state=12; break;
                    case ',': state=13; break;
                    case '?': state=14; break;
                    case '=': state=15; break;
                    case ':': state=18; break;
                    case '>': state=19; break;
                    case '<': state=21; break;
                    case '!': state=23; break;
                    case '&': state=26; break;
                    case '|': state=28; break;
                    case '0': state=41; break; //checks for int 0 or a decimal number beginning with 0
                    case '1': case '2': case '3': case '4': case '5': case '6': case '7': case '8': case '9': state=45; number+=c; break; 
                    case '"': state=47; break;
                    default: state=100; break;
                }
                break;
            //cases 1 - 14 and 18 to evaluate single character lexemes
            case 1: Output<<"Token 1, string +, line number "<<line<<endl; 
                    if(filepointer>0) filepointer--;
                    else{
                        filepointer=size-1;
                        if(x==1) x=2;
                        else x=1;
                    }
                    state=0;
                    break;
            case 2: Output<<"Token 2, string -, line number "<<line<<endl; 
                    if(filepointer>0) filepointer--;
                    else{
                        filepointer=size-1;
                        if(x==1) x=2;
                        else x=1;
                    }
                    state=0;
                    break;
            case 3: Output<<"Token 3, string *, line number "<<line<<endl; 
                    if(filepointer>0) filepointer--;
                    else{
                        filepointer=size-1;
                        if(x==1) x=2;
                        else x=1;
                    }
                    state=0;
                    break;
            case 4: Output<<"Token 4, string /, line number "<<line<<endl; 
                    if(filepointer>0) filepointer--;
                    else{
                        filepointer=size-1;
                        if(x==1) x=2;
                        else x=1;
                    }
                    state=0;
                    break;
            case 5: Output<<"Token 5, string %, line number "<<line<<endl; 
                    if(filepointer>0) filepointer--;
                    else{
                        filepointer=size-1;
                        if(x==1) x=2;
                        else x=1;
                    }
                    state=0;
                    break;
            case 6: Output<<"Token 6, string {, line number "<<line<<endl; 
                    if(filepointer>0) filepointer--;
                    else{
                        filepointer=size-1;
                        if(x==1) x=2;
                        else x=1;
                    }
                    state=0;
                    break;
            case 7: Output<<"Token 7, string }, line number "<<line<<endl; 
                    if(filepointer>0) filepointer--;
                    else{
                        filepointer=size-1;
                        if(x==1) x=2;
                        else x=1;
                    }
                    state=0;
                    break;
            case 8: Output<<"Token 8, string (, line number "<<line<<endl; 
                    if(filepointer>0) filepointer--;
                    else{
                        filepointer=size-1;
                        if(x==1) x=2;
                        else x=1;
                    }
                    state=0;
                    break;
            case 9: Output<<"Token 9, string ), line number "<<line<<endl; 
                    if(filepointer>0) filepointer--;
                    else{
                        filepointer=size-1;
                        if(x==1) x=2;
                        else x=1;
                    }
                    state=0;
                    break;
            case 10: Output<<"Token 10, string [, line number "<<line<<endl; 
                    if(filepointer>0) filepointer--;
                    else{
                        filepointer=size-1;
                        if(x==1) x=2;
                        else x=1;
                    }
                    state=0;
                    break;
            case 11: Output<<"Token 11, string ], line number "<<line<<endl; 
                    if(filepointer>0) filepointer--;
                    else{
                        filepointer=size-1;
                        if(x==1) x=2;
                        else x=1;
                    }
                    state=0;
                    break;
            case 12: Output<<"Token 12, string ;, line number "<<line<<endl; 
                    if(filepointer>0) filepointer--;
                    else{
                        filepointer=size-1;
                        if(x==1) x=2;
                        else x=1;
                    }
                    state=0;
                    break;
            case 13: Output<<"Token 13, string ,, line number "<<line<<endl; 
                    if(filepointer>0) filepointer--;
                    else{
                        filepointer=size-1;
                        if(x==1) x=2;
                        else x=1;
                    }
                    state=0;
                    break;
            case 14: Output<<"Token 14, string ?, line number "<<line<<endl; 
                    if(filepointer>0) filepointer--;
                    else{
                        filepointer=size-1;
                        if(x==1) x=2;
                        else x=1;
                    }
                    state=0;
                    break;
            case 18: Output<<"Token 18, string :, line number "<<line<<endl; 
                    if(filepointer>0) filepointer--;
                    else{
                        filepointer=size-1;
                        if(x==1) x=2;
                        else x=1;
                    }
                    state=0;
                    break;
            //tokenizes = or if another = entails, goes to next state.
            case 15: if(c=='=') {state=16; break;}
                    Output<<"Token 15, string =, line number "<<line<<endl;
                    if(filepointer>0) filepointer--;
                    else{
                        filepointer=size-1;
                        if(x==1) x=2;
                        else x=1;
                    }
                    state=0;
                    break;
            //tokenizes == or if another = follows, goes to next state.
            case 16: if(c=='=') {state=17; break;}
                    Output<<"Token 16, string ==, line number "<<line<<endl;
                    if(filepointer>0) filepointer--;
                    else{
                        filepointer=size-1;
                        if(x==1) x=2;
                        else x=1;
                    }
                    state=0;
                    break;
            //tokenizes ===
            case 17: Output<<"Token 17, string ===, line number "<<line<<endl;
                    if(filepointer>0) filepointer--;
                    else{
                        filepointer=size-1;
                        if(x==1) x=2;
                        else x=1;
                    }
                    state=0;
                    break;
            //tokenizes >, if an = follows, goes to next state
            case 19: if(c=='=') {state=20; break;}
                    Output<<"Token 19, string >, line number "<<line<<endl;
                    if(filepointer>0) filepointer--;
                    else{
                        filepointer=size-1;
                        if(x==1) x=2;
                        else x=1;
                    }
                    state=0;
                    break;
            //tokenizes >=
            case 20: Output<<"Token 20, string >=, line number "<<line<<endl;
                    if(filepointer>0) filepointer--;
                    else{
                        filepointer=size-1;
                        if(x==1) x=2;
                        else x=1;
                    }
                    state=0;
                    break;
            //tokenizes <, if an = follows, moves to next state
            case 21: if(c=='=') {state=22; break;}
                    Output<<"Token 21, string <, line number "<<line<<endl;
                    if(filepointer>0) filepointer--;
                    else{
                        filepointer=size-1;
                        if(x==1) x=2;
                        else x=1;
                    }
                    state=0;
                    break;
            //tokenizes <=
            case 22: Output<<"Token 22, string <=, line number "<<line<<endl;
                    if(filepointer>0) filepointer--;
                    else{
                        filepointer=size-1;
                        if(x==1) x=2;
                        else x=1;
                    }
                    state=0;
                    break;
            //tokenizes if !, else moves to next state
            case 23: if(c=='=') {state=24; break;}
                    Output<<"Token 23, string !, line number "<<line<<endl;
                    if(filepointer>0) filepointer--;
                    else{
                        filepointer=size-1;
                        if(x==1) x=2;
                        else x=1;
                    }
                    state=0;
                    break;
            //tokenizes if !=, else moves to next state
            case 24: if(c=='=') {state=25; break;}
                    Output<<"Token 24, string !=, line number "<<line<<endl;
                    if(filepointer>0) filepointer--;
                    else{
                        filepointer=size-1;
                        if(x==1) x=2;
                        else x=1;
                    }
                    state=0;
                    break;
            //tokenizes !==
            case 25: Output<<"Token 25, string !==, line number "<<line<<endl;
                    if(filepointer>0) filepointer--;
                    else{
                        filepointer=size-1;
                        if(x==1) x=2;
                        else x=1;
                    }
                    state=0;
                    break;
            //tokenizes &, else moves to next state
            case 26: if(c=='&') {state=27; break;}
                    Output<<"Token 26, string &, line number "<<line<<endl;
                    if(filepointer>0) filepointer--;
                    else{
                        filepointer=size-1;
                        if(x==1) x=2;
                        else x=1;
                    }
                    state=0;
                    break;
            //tokenizes &&
            case 27: Output<<"Token 27, string &&, line number "<<line<<endl;
                    if(filepointer>0) filepointer--;
                    else{
                        filepointer=size-1;
                        if(x==1) x=2;
                        else x=1;
                    }
                    state=0;
                    break;
            //tokenizes |, else moves to the next state
            case 28: if(c=='|') {state=29; break;}
                    Output<<"Token 28, string |, line number "<<line<<endl;
                    if(filepointer>0) filepointer--;
                    else{
                        filepointer=size-1;
                        if(x==1) x=2;
                        else x=1;
                    }
                    state=0;
                    break;
            //tokenizes ||
            case 29: Output<<"Token 29, string ||, line number "<<line<<endl;
                    if(filepointer>0) filepointer--;
                    else{
                        filepointer=size-1;
                        if(x==1) x=2;
                        else x=1;
                    }
                    state=0;
                    break;
            //if a character is followed by another char or an underscore, it remains in this state.
            //if it is followed by something else, it moves on to 31.
            //the regular expression for this is [a-zA-Z][_a-zA-Z]*
            case 30: if((c=='_')||(c<='z' && c>='a')||(c<='Z' && c>='A')){
                        state=30;
                        temp+=c;
                    }
				 	else state=31;
					break;
            //checks if the string is a keyword, else it tags it as an id
            //it does that by looking into the hashtable (map) created to achieve O(1) lookup
			case 31: if(tokens.count(temp)){
                        Output<<"Token "<<tokens[temp]<<", string "<<temp<<",line number "<<line<<endl;
                        if(filepointer>1) filepointer-=2;
                        else{
                            if(filepointer==1) filepointer=size-1;
                            else filepointer=size-2;
                            if(x==1) x=2;
                            else x=1;
                        }
                    }
                    else{
                        Output<<"Token 30, string "<<temp<<", line number "<<line<<endl;
                        if(filepointer>1) filepointer-=2;
                        else{
                            if(filepointer==1) filepointer=size-1;
                            else filepointer=size-2;
                            if(x==1) x=2;
                            else x=1;
                        }
                    }
				 	state=0;
				 	temp="";
				 	break;
            //checks if 0 is followed by a decimal point, if yes, goes to state 42.
            //else it is simply identified as 0 integer alone.
            case 41: if(c=='.'){
                        state=42;
                        number+=c;
                    }
                    else state=46;
                    break;
            //checks if the decimal point is followed by more digits to confirm floating point number.
            //else it is an error.
            case 42:  if(c>='0' && c<='9'){
                        state=43;
                        number+=c;
                    }
                    else state=100;
                    break;
            //checks if the digit (not including zero) is followed by any other digits.
            //if yes, remains in this state else sent to state 44
            case 43: if(c>='0' && c<='9'){
                        state=43;
                        number+=c;
                    }
                    else state=44;
                    break;
            //tokenizes as floating point number
            case 44: Output<<"Token 44, string "<<number<<", line number "<<line<<endl;
                    if(filepointer>1) filepointer--;
                    else{
                        if(filepointer==1) filepointer=size-1;
                        else filepointer=size-2;
                        if(x==1) x=2;
                        else x=1;
                    }
                    state=0;
                    number="";
                    break;
            //if digit is followed by another digit, remains in this state.
            //if followed by . , it goes to state 42 where it is checked for floating point number
            //else it goes to state 46
            case 45: if(c>='0' && c<='9'){
                        state=45;
                        number+=c;
                    }
                    else if(c=='.'){
                        state=42;
                        number+=c;
                    }
                    else state=46;
                    break;
            //tokenizes as integer
            case 46:if(number[0] == '+' || number[0] == '-'){
                    number.erase(0,1) ;
                    } 
                    Output<<"Token 46, string "<<number<<", line number "<<line<<endl;
                    if(filepointer>1) filepointer--;
                    else{
                        if(filepointer==1) filepointer=size-1;
                        else filepointer=size-2;
                        if(x==1) x=2;
                        else x=1;
                    }
                    state=0;
                    number="";
                    break;
            //handles strings inside the code
            case 47: if(c=='"'){state=48; break;}
                    word+=c;
                    state=47;
                    break;
            //tokenizes as string
            case 48: Output<<"Token 48, string "<<word<<", line number "<<line<<endl;
                    if(filepointer>0) filepointer--;
                    else{
                        filepointer=size-1;
                        if(x==1) x=2;
                        else x=1;
                    }
                    state=0;
                    word="";
                    break;
            //handles the case where the lexeme does not belong to the language
            case 100: Output<<"Error: Lexical error in line number "<<line<<endl; state=0; filepointer-=1; break;
        }
        //checks if the string in the input code has been terminated or not
        if(flag==1){
            if(state==47) Output<<"Error: String literal not terminated in line number "<<line<<endl;
            break;
        }
        if(filepointer<size-1) filepointer++;
        //eof case
        else{
            if(x==1){
                filepointer=0;
                x=2;
            }
            else{
                b1=b2;
                b2.clear();
                b2.resize(size,'\0');
                code.read(b2.data(),size);
                x==2;
                filepointer=0;
            }
        }
    }
    
}

int main(){
    lb=0;
    int size=5;
    for(int i=0;i<keyword.size();i++){
        tokens[keyword[i]]=31+i;
    }
    //create buffers
    vector<char> b1(size), b2(size);
    //open file
    ifstream code;
    // output file
    ofstream Output;
    code.open("test_cases/sample7.txt");
    Output.open("output/lexer_o_7.txt");
    //parse file
    code.read(b1.data(),size);
    code.read(b2.data(),size);
    tokenizer(b1,b2,code,Output,size);
    //close file
    code.close();
    Output.close();
    return 0;
}


//  if (hour < 18) {
//   greeting = "Good day";
// }


//  for (let i = 0; i < 5; i=i+1) {
//   text =text+5;
// }


// function myFunction(a, b) {
//   return a * b;
// }


// function myFunction(a, b) {
//   return a * b;
// }
// const x = function (a, b) {return a * b};
// let z = x(4, 3); 