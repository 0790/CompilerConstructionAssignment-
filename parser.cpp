#include<iostream>
#include<bits/stdc++.h>
using namespace std ;


int main(){
    ofstream output;
    output.open("output/parser_o_7.txt",ios::out);

    //map consisting non terminals and terminals along with a serial number
    map<int,string> s;

    s[0]="<start>"; //  non-terminals
    s[1]="<code>";
    s[2]="S";
    s[3]="I";
    s[4]="II";
    s[5]="F";
    s[6]="IF";
    s[7]="FF";
    s[8]="Ar";
    s[9]="I1";
    s[10]="I2";
    s[11]="Iobj";
    s[12]="I44arr";
    s[13]="I46arr";
    s[14]="I48arr";
    s[15]="P1";
    s[16]="P2";
    s[17]="P3";
    s[18]="P4";
    s[19]="V";
    s[20]="A";
    s[21]="B";
    s[22]="C";
    s[23]="A'";
    s[24]="X1";
    s[25]="B1";
    s[26]="C1";
    s[27]="F'";
    s[28]="F2";
    s[29]="V'";
    s[30]="V1";
    s[31]="Ar1";
    s[32]="eps"; //   terminals  //CHECK IF EPS MAKES SENSE 
    s[33]="$";
    s[34]="id";
    s[35]="let";
    s[36]="const";
    s[37]="for";
    s[38]="function";
    s[39]="return";
    s[40]="=";
    s[41]=";";
    s[42]="[";
    s[43]="]";
    s[44]="{";
    s[45]="}";
    s[46]="(";
    s[47]=")";
    s[48]="floating point";
    s[49]="integer";
    s[50]="string literal";
    s[51]=",";
    s[52]=":";
    // s[53]="=";
    s[54]="<";
    s[55]="<=";
    s[56]=">";
    s[57]=">=";
    s[58]="==";
    s[59]="||";
    s[60]="&&";
    // s[61]="++";
    // s[62]="--";
    s[63]="if";
    s[64]="else";
    s[65]="*";
    s[66]="+";
    s[67]="/";
    s[68]="-";
    s[69]="%";

    //making inverse map of s
    map<string,int> s1;

    for(auto x:s){
        s1[x.second]=x.first;
    }

    //map consisting resultant lexeme token numbers and terminal serial number from s 
    map<string,int> w;

    w["$"]=1000;      //$  //check
    w["30"]=34;     //id
    w["31"]=35;     //let
    w["33"]=36;     //const
    w["34"]=37;     //for
    w["39"]=38;     //function
    w["40"]=39;     //return 
    w["15"]=40;     //=
    w["12"]=41;     //;
    w["10"]=42;     //[
    w["11"]=43;     //]
    w["6"]=44;      //{
    w["7"]=45;      //}
    w["8"]=46;      //(
    w["9"]=47;      //)
    w["44"]=48;     //floating point
    w["46"]=49;     //integer
    w["48"]=50;     //string literal
    w["13"]=51;     //,
    w["18"]=52;     //:
    // w["15"]=53;  //=
    w["21"]=54;     //<
    w["22"]=55;     //<=
    w["19"]=56;     //>
    w["20"]=57;     //>=
    w["16"]=58;     //==
    w["29"]=59;     //||
    w["27"]=60;     //&&
    // w[""]="++";
    // w[62]="--";
    w["37"]=63;     //if
    w["38"]=64;     //else
    w["3"]=65;      //*
    w["1"]=66;      //+
    w["4"]=67;      ///
    w["2"]=68;      //-
    w["5"]=69;      //%

    //Constructing the parse table 

    map<pair<int,int>,vector<int>> par;                     // modelling the parse table and inserting the entries
    vector<int> t; 
    t.clear();
    //1
    t.push_back(s1["<code>"]);
    //check accept <start>->eps
    par[make_pair(s1["<start>"],s1["id"])]=t;
    par[make_pair(s1["<start>"],s1["let"])]=t;
    par[make_pair(s1["<start>"],s1["const"])]=t;
    par[make_pair(s1["<start>"],s1["for"])]=t;
    par[make_pair(s1["<start>"],s1["function"])]=t;
    par[make_pair(s1["<start>"],s1["return"])]=t;
    par[make_pair(s1["<start>"],s1["{"])]=t;
    par[make_pair(s1["<start>"],s1["integer"])]=t;
    par[make_pair(s1["<start>"],s1["floating point"])]=t;
    par[make_pair(s1["<start>"],s1["string literal"])]=t;
    par[make_pair(s1["<start>"],s1["if"])]=t;
    t.clear();
    //2
    t.push_back(s1["eps"]);
    par[make_pair(s1["<code>"],s1["$"])]=t;
    par[make_pair(s1["<code>"],s1["}"])]=t;
    t.clear();
    //3
    t.push_back(s1["S"]);
    t.push_back(s1["<code>"]);
    par[make_pair(s1["<code>"],s1["id"])]=t;
    par[make_pair(s1["<code>"],s1["let"])]=t;
    par[make_pair(s1["<code>"],s1["const"])]=t;
    par[make_pair(s1["<code>"],s1["for"])]=t;
    par[make_pair(s1["<code>"],s1["function"])]=t;
    par[make_pair(s1["<code>"],s1["return"])]=t;
    par[make_pair(s1["<code>"],s1["{"])]=t;
    par[make_pair(s1["<code>"],s1["integer"])]=t;
    par[make_pair(s1["<code>"],s1["floating point"])]=t;
    par[make_pair(s1["<code>"],s1["string literal"])]=t;
    par[make_pair(s1["<code>"],s1["if"])]=t;
    t.clear();
    //4
    t.push_back(s1["id"]);
    t.push_back(s1["I"]);
    par[make_pair(s1["S"],s1["id"])]=t;
    t.clear();
    //5
    t.push_back(s1["let"]);
    t.push_back(s1["II"]);
    par[make_pair(s1["S"],s1["let"])]=t;
    t.clear();
    //6
    t.push_back(s1["const"]);
    t.push_back(s1["II"]);
    par[make_pair(s1["S"],s1["const"])]=t;
    t.clear();
    //7
    t.push_back(s1["for"]);
    t.push_back(s1["F"]);
    par[make_pair(s1["S"],s1["for"])]=t;
    t.clear();
    //8
    t.push_back(s1["IF"]);
    par[make_pair(s1["S"],s1["if"])]=t;
    par[make_pair(s1["S"],s1["{"])]=t;
    t.clear();
    //9
    t.push_back(s1["function"]);
    t.push_back(s1["FF"]);
    par[make_pair(s1["S"],s1["function"])]=t;
    t.clear();
    //10
    t.push_back(s1["Ar"]);
    par[make_pair(s1["S"],s1["integer"])]=t;
    par[make_pair(s1["S"],s1["floating point"])]=t;
    par[make_pair(s1["S"],s1["string literal"])]=t;
    t.clear();
    //11
    t.push_back(s1["return"]);
    t.push_back(s1["Ar"]);
    par[make_pair(s1["S"],s1["return"])]=t;
    t.clear();
    //12
    t.push_back(s1["="]);
    t.push_back(s1["I1"]);
    par[make_pair(s1["I"],s1["="])]=t;
    t.clear();
    //13
    t.push_back(s1["["]);
    t.push_back(s1["I2"]);
    par[make_pair(s1["I1"],s1["["])]=t;
    t.clear();
    //14
    t.push_back(s1["{"]);
    t.push_back(s1["Iobj"]);
    par[make_pair(s1["I1"],s1["{"])]=t;
    t.clear();
    //15
    t.push_back(s1["id"]);
    t.push_back(s1["("]);
    t.push_back(s1["V'"]);
    par[make_pair(s1["I1"],s1["id"])]=t;
    t.clear();
    //16
    t.push_back(s1["Ar"]);
    par[make_pair(s1["I1"],s1["integer"])]=t;
    par[make_pair(s1["I1"],s1["floating point"])]=t;
    par[make_pair(s1["I1"],s1["string literal"])]=t;
    t.clear();
    //17
    t.push_back(s1["I46arr"]);
    par[make_pair(s1["I2"],s1["floating point"])]=t;
    t.clear();
    //18
    t.push_back(s1["I44arr"]);
    par[make_pair(s1["I2"],s1["integer"])]=t;
    t.clear();
    //19
    t.push_back(s1["I48arr"]);
    par[make_pair(s1["I2"],s1["string literal"])]=t;
    t.clear();
    //20
    t.push_back(s1["integer"]);
    t.push_back(s1["P1"]);
    par[make_pair(s1["I44arr"],s1["integer"])]=t;
    t.clear();
    //21
    t.push_back(s1[","]);
    t.push_back(s1["I44arr"]);
    par[make_pair(s1["P1"],s1[","])]=t;
    t.clear();
    //22
    t.push_back(s1["]"]);
    t.push_back(s1[";"]);
    par[make_pair(s1["P1"],s1["]"])]=t;
    t.clear();
    //23
    t.push_back(s1["floating point"]);
    t.push_back(s1["P2"]);
    par[make_pair(s1["I46arr"],s1["floating point"])]=t;
    t.clear();
    //24
    t.push_back(s1[","]);
    t.push_back(s1["I46arr"]);
    par[make_pair(s1["P2"],s1[","])]=t;
    t.clear();
    //25
    t.push_back(s1["]"]);
    t.push_back(s1[";"]);
    par[make_pair(s1["P2"],s1["]"])]=t;
    t.clear();
    //26
    t.push_back(s1["string literal"]);
    t.push_back(s1["P3"]);
    par[make_pair(s1["I48arr"],s1["string literal"])]=t;
    t.clear();
    //27
    t.push_back(s1[","]);
    t.push_back(s1["I48arr"]);
    par[make_pair(s1["P3"],s1[","])]=t;
    t.clear();
    //28
    t.push_back(s1["]"]);
    t.push_back(s1[";"]);
    par[make_pair(s1["P3"],s1["]"])]=t;
    t.clear();
    //29
    t.push_back(s1["id"]);
    t.push_back(s1[":"]);
    t.push_back(s1["V"]);
    t.push_back(s1["P4"]);
    par[make_pair(s1["Iobj"],s1["id"])]=t;
    t.clear();
    //30
    t.push_back(s1[","]);
    t.push_back(s1["Iobj"]);
    par[make_pair(s1["P4"],s1[","])]=t;
    t.clear();
    //31
    t.push_back(s1["}"]);
    t.push_back(s1[";"]);
    par[make_pair(s1["P4"],s1["}"])]=t;
    t.clear();
    //32
    t.push_back(s1["integer"]);
    par[make_pair(s1["V"],s1["integer"])]=t;
    t.clear();
    //33
    t.push_back(s1["floating point"]);
    par[make_pair(s1["V"],s1["floating point"])]=t;
    t.clear();
    //34
    t.push_back(s1["string literal"]);
    par[make_pair(s1["V"],s1["string literal"])]=t;
    t.clear();
    //35
    t.push_back(s1["id"]);
    par[make_pair(s1["V"],s1["id"])]=t;
    t.clear();
    //36
    t.push_back(s1["id"]);
    t.push_back(s1["I"]);
    par[make_pair(s1["II"],s1["id"])]=t;
    t.clear();
    //37
    t.push_back(s1["("]);
    t.push_back(s1["A"]);
    t.push_back(s1[";"]);
    t.push_back(s1["B"]);
    t.push_back(s1[";"]);
    t.push_back(s1["C"]);
    t.push_back(s1[")"]);
    t.push_back(s1["{"]);
    t.push_back(s1["<code>"]);
    t.push_back(s1["}"]);
    par[make_pair(s1["F"],s1["("])]=t;
    t.clear();
    //38
    t.push_back(s1["let"]);
    t.push_back(s1["A'"]);
    par[make_pair(s1["A"],s1["let"])]=t;
    t.clear();
    //39
    t.push_back(s1["eps"]);
    par[make_pair(s1["A"],s1[";"])]=t;
    t.clear();
    //40
    t.push_back(s1["id"]);
    t.push_back(s1["="]);
    t.push_back(s1["V"]);
    t.push_back(s1["x1"]);
    par[make_pair(s1["A'"],s1["id"])]=t;
    t.clear();
    //41
    t.push_back(s1[","]);
    t.push_back(s1["A'"]);
    par[make_pair(s1["X1"],s1[","])]=t;
    t.clear();
    //42
    t.push_back(s1["eps"]);
    par[make_pair(s1["X1"],s1[";"])]=t;
    t.clear();
    //43
    t.push_back(s1["V"]);
    t.push_back(s1["B1"]);
    par[make_pair(s1["B"],s1["integer"])]=t;
    par[make_pair(s1["B"],s1["floating point"])]=t;
    par[make_pair(s1["B"],s1["string literal"])]=t;
    par[make_pair(s1["B"],s1["id"])]=t;
    t.clear();
    //44
    t.push_back(s1["<="]);
    t.push_back(s1["V"]);
    par[make_pair(s1["B1"],s1["<="])]=t;
    t.clear();
    //45
    t.push_back(s1["<"]);
    t.push_back(s1["V"]);
    par[make_pair(s1["B1"],s1["<"])]=t;
    t.clear();
    //46
    t.push_back(s1[">="]);
    t.push_back(s1["V"]);
    par[make_pair(s1["B1"],s1[">="])]=t;
    t.clear();
    //47
    t.push_back(s1[">"]);
    t.push_back(s1["V"]);
    par[make_pair(s1["B1"],s1[">"])]=t;
    t.clear();
    //48
    t.push_back(s1["=="]);
    t.push_back(s1["V"]);
    par[make_pair(s1["B1"],s1["=="])]=t;
    t.clear();
    //49
    t.push_back(s1["||"]);
    t.push_back(s1["V"]);
    par[make_pair(s1["B1"],s1["||"])]=t;
    t.clear();
    //50
    t.push_back(s1["&&"]);
    t.push_back(s1["V"]);
    par[make_pair(s1["B1"],s1["&&"])]=t;
    t.clear();
    //51
    t.push_back(s1["id"]);
    t.push_back(s1["="]);
    t.push_back(s1["id"]);
    t.push_back(s1["C1"]);
    par[make_pair(s1["C"],s1["id"])]=t;
    t.clear();
    //52
    t.push_back(s1["+"]);
    t.push_back(s1["integer"]);
    par[make_pair(s1["C1"],s1["+"])]=t;
    t.clear();
    //53
    t.push_back(s1["-"]);
    t.push_back(s1["integer"]);
    par[make_pair(s1["C1"],s1["-"])]=t;
    t.clear();
    //54
    t.push_back(s1["if"]);
    t.push_back(s1["("]);
    t.push_back(s1["B"]);
    t.push_back(s1[")"]);
    t.push_back(s1["{"]);
    t.push_back(s1["<code>"]);
    t.push_back(s1["}"]);
    t.push_back(s1["else"]);
    t.push_back(s1["IF"]);
    par[make_pair(s1["IF"],s1["if"])]=t;
    t.clear();
    //55
    //SKIP ONLY IF CASE
    //56
    t.push_back(s1["id"]);
    t.push_back(s1["("]);
    t.push_back(s1["F'"]);
    par[make_pair(s1["FF"],s1["id"])]=t;
    t.clear();
    //57
    t.push_back(s1["id"]);
    t.push_back(s1[")"]);
    t.push_back(s1["F2"]);
    par[make_pair(s1["F'"],s1["id"])]=t;
    t.clear();
    //58
    t.push_back(s1["eps"]);
    par[make_pair(s1["F2"],s1["$"])]=t;
    par[make_pair(s1["F2"],s1["id"])]=t;
    par[make_pair(s1["F2"],s1["let"])]=t;
    par[make_pair(s1["F2"],s1["const"])]=t;
    par[make_pair(s1["F2"],s1["for"])]=t;
    par[make_pair(s1["F2"],s1["function"])]=t;
    par[make_pair(s1["F2"],s1["return"])]=t;
    par[make_pair(s1["F2"],s1["}"])]=t;
    par[make_pair(s1["F2"],s1["integer"])]=t;
    par[make_pair(s1["F2"],s1["floating point"])]=t;
    par[make_pair(s1["F2"],s1["string literal"])]=t;
    par[make_pair(s1["F2"],s1["if"])]=t;
    t.clear();
    //59
    t.push_back(s1["{"]);
    t.push_back(s1["<code>"]);
    t.push_back(s1["}"]);
    par[make_pair(s1["F2"],s1["{"])]=t;
    t.clear();
    //60
    t.push_back(s1["V"]);
    t.push_back(s1["v1"]);
    par[make_pair(s1["V'"],s1["id"])]=t;
    par[make_pair(s1["V'"],s1["integer"])]=t;
    par[make_pair(s1["V'"],s1["floating point"])]=t;
    par[make_pair(s1["V'"],s1["string literal"])]=t;
    t.clear();
    //61
    t.push_back(s1[","]);
    t.push_back(s1["V'"]);
    par[make_pair(s1["V1"],s1[","])]=t;
    t.clear();
    //62
    t.push_back(s1[")"]);
    par[make_pair(s1["V1"],s1[")"])]=t;
    t.clear();
    //63
    t.push_back(s1["V"]);
    t.push_back(s1["Ar1"]);
    par[make_pair(s1["Ar"],s1["id"])]=t;
    par[make_pair(s1["Ar"],s1["integer"])]=t;
    par[make_pair(s1["Ar"],s1["floating point"])]=t;
    par[make_pair(s1["Ar"],s1["string literal"])]=t;
    t.clear();
    //64
    t.push_back(s1["*"]);
    t.push_back(s1["Ar"]);
    par[make_pair(s1["Ar1"],s1["*"])]=t;
    t.clear();
    //65
    t.push_back(s1["+"]);
    t.push_back(s1["Ar"]);
    par[make_pair(s1["Ar1"],s1["+"])]=t;
    t.clear();
    //66
    t.push_back(s1["/"]);
    t.push_back(s1["Ar"]);
    par[make_pair(s1["Ar1"],s1["/"])]=t;
    t.clear();
    //67
    t.push_back(s1["%"]);
    t.push_back(s1["Ar"]);
    par[make_pair(s1["Ar1"],s1["%"])]=t;
    t.clear();
    //68
    t.push_back(s1["-"]);
    t.push_back(s1["Ar"]);
    par[make_pair(s1["Ar1"],s1["-"])]=t;
    t.clear();
    //69
    t.push_back(s1[";"]);
    par[make_pair(s1["Ar1"],s1[";"])]=t;
    t.clear();


    //SYNCH STATES
    t.clear();
    t.push_back(101); //synch state number  //check
    par[make_pair(s1["S"],s1["$"])] = t;
    par[make_pair(s1["S"],s1["}"])] = t;

    par[make_pair(s1["I"],s1["$"])]=t;
    par[make_pair(s1["I"],s1["id"])]=t;
    par[make_pair(s1["I"],s1["let"])]=t;
    par[make_pair(s1["I"],s1["const"])]=t;
    par[make_pair(s1["I"],s1["for"])]=t;
    par[make_pair(s1["I"],s1["function"])]=t;
    par[make_pair(s1["I"],s1["return"])]=t;
    par[make_pair(s1["I"],s1["{"])]=t;
    par[make_pair(s1["I"],s1["}"])]=t;
    par[make_pair(s1["I"],s1["integer"])]=t;
    par[make_pair(s1["I"],s1["floating point"])]=t;
    par[make_pair(s1["I"],s1["string literal"])]=t;
    par[make_pair(s1["I"],s1["if"])]=t;

    par[make_pair(s1["II"],s1["$"])]=t;
    par[make_pair(s1["II"],s1["let"])]=t;
    par[make_pair(s1["II"],s1["const"])]=t;
    par[make_pair(s1["II"],s1["for"])]=t;
    par[make_pair(s1["II"],s1["function"])]=t;
    par[make_pair(s1["II"],s1["return"])]=t;
    par[make_pair(s1["II"],s1["{"])]=t;
    par[make_pair(s1["II"],s1["}"])]=t;
    par[make_pair(s1["II"],s1["integer"])]=t;
    par[make_pair(s1["II"],s1["floating point"])]=t;
    par[make_pair(s1["II"],s1["string literal"])]=t;
    par[make_pair(s1["II"],s1["if"])]=t;

    par[make_pair(s1["F"],s1["$"])]=t;
    par[make_pair(s1["F"],s1["id"])]=t;
    par[make_pair(s1["F"],s1["let"])]=t;
    par[make_pair(s1["F"],s1["const"])]=t;
    par[make_pair(s1["F"],s1["for"])]=t;
    par[make_pair(s1["F"],s1["function"])]=t;
    par[make_pair(s1["F"],s1["return"])]=t;
    par[make_pair(s1["F"],s1["{"])]=t;
    par[make_pair(s1["F"],s1["}"])]=t;
    par[make_pair(s1["F"],s1["integer"])]=t;
    par[make_pair(s1["F"],s1["string literal"])]=t;
    par[make_pair(s1["F"],s1["if"])]=t;

    par[make_pair(s1["IF"],s1["$"])]=t;
    par[make_pair(s1["IF"],s1["id"])]=t;
    par[make_pair(s1["IF"],s1["let"])]=t;
    par[make_pair(s1["IF"],s1["const"])]=t;
    par[make_pair(s1["IF"],s1["for"])]=t;
    par[make_pair(s1["IF"],s1["function"])]=t;
    par[make_pair(s1["IF"],s1["return"])]=t;
    par[make_pair(s1["IF"],s1["}"])]=t;
    par[make_pair(s1["IF"],s1["{"])]=t;
    par[make_pair(s1["IF"],s1["integer"])]=t;
    par[make_pair(s1["IF"],s1["floating point"])]=t;
    par[make_pair(s1["IF"],s1["string literal"])]=t;

    par[make_pair(s1["FF"],s1["$"])]=t;
    par[make_pair(s1["FF"],s1["let"])]=t;
    par[make_pair(s1["FF"],s1["const"])]=t;
    par[make_pair(s1["FF"],s1["for"])]=t;
    par[make_pair(s1["FF"],s1["function"])]=t;
    par[make_pair(s1["FF"],s1["return"])]=t;
    par[make_pair(s1["FF"],s1["{"])]=t;
    par[make_pair(s1["FF"],s1["}"])]=t;
    par[make_pair(s1["FF"],s1["integer"])]=t;
    par[make_pair(s1["FF"],s1["floating point"])]=t;
    par[make_pair(s1["FF"],s1["string literal"])]=t;
    par[make_pair(s1["FF"],s1["if"])]=t;

    par[make_pair(s1["Ar"],s1["$"])]=t;
    par[make_pair(s1["Ar"],s1["let"])]=t;
    par[make_pair(s1["Ar"],s1["const"])]=t;
    par[make_pair(s1["Ar"],s1["for"])]=t;
    par[make_pair(s1["Ar"],s1["function"])]=t;
    par[make_pair(s1["Ar"],s1["return"])]=t;
    par[make_pair(s1["Ar"],s1["{"])]=t;
    par[make_pair(s1["Ar"],s1["}"])]=t;
    par[make_pair(s1["Ar"],s1["if"])]=t;

    par[make_pair(s1["I1"],s1["$"])]=t;
    par[make_pair(s1["I1"],s1["let"])]=t;
    par[make_pair(s1["I1"],s1["const"])]=t;
    par[make_pair(s1["I1"],s1["for"])]=t;
    par[make_pair(s1["I1"],s1["function"])]=t;
    par[make_pair(s1["I1"],s1["return"])]=t;
    par[make_pair(s1["I1"],s1["}"])]=t;
    par[make_pair(s1["I1"],s1["if"])]=t;

    par[make_pair(s1["I2"],s1["$"])]=t;
    par[make_pair(s1["I2"],s1["id"])]=t;
    par[make_pair(s1["I2"],s1["let"])]=t;
    par[make_pair(s1["I2"],s1["const"])]=t;
    par[make_pair(s1["I2"],s1["for"])]=t;
    par[make_pair(s1["I2"],s1["function"])]=t;
    par[make_pair(s1["I2"],s1["return"])]=t;
    par[make_pair(s1["I2"],s1["{"])]=t;
    par[make_pair(s1["I2"],s1["}"])]=t;
    par[make_pair(s1["I2"],s1["if"])]=t;

    par[make_pair(s1["Iobj"],s1["$"])]=t;
    par[make_pair(s1["Iobj"],s1["let"])]=t;
    par[make_pair(s1["Iobj"],s1["const"])]=t;
    par[make_pair(s1["Iobj"],s1["for"])]=t;
    par[make_pair(s1["Iobj"],s1["function"])]=t;
    par[make_pair(s1["Iobj"],s1["return"])]=t;
    par[make_pair(s1["Iobj"],s1["{"])]=t;
    par[make_pair(s1["Iobj"],s1["}"])]=t;
    par[make_pair(s1["Iobj"],s1["integer"])]=t;
    par[make_pair(s1["Iobj"],s1["floating point"])]=t;
    par[make_pair(s1["Iobj"],s1["string literal"])]=t;
    par[make_pair(s1["Iobj"],s1["if"])]=t;

    par[make_pair(s1["I44arr"],s1["$"])]=t;
    par[make_pair(s1["I44arr"],s1["id"])]=t;
    par[make_pair(s1["I44arr"],s1["let"])]=t;
    par[make_pair(s1["I44arr"],s1["const"])]=t;
    par[make_pair(s1["I44arr"],s1["for"])]=t;
    par[make_pair(s1["I44arr"],s1["function"])]=t;
    par[make_pair(s1["I44arr"],s1["return"])]=t;
    par[make_pair(s1["I44arr"],s1["{"])]=t;
    par[make_pair(s1["I44arr"],s1["}"])]=t;
    par[make_pair(s1["I44arr"],s1["floating point"])]=t;
    par[make_pair(s1["I44arr"],s1["string literal"])]=t;
    par[make_pair(s1["I44arr"],s1["if"])]=t;

    par[make_pair(s1["I46arr"],s1["$"])]=t;
    par[make_pair(s1["I46arr"],s1["id"])]=t;
    par[make_pair(s1["I46arr"],s1["let"])]=t;
    par[make_pair(s1["I46arr"],s1["const"])]=t;
    par[make_pair(s1["I46arr"],s1["for"])]=t;
    par[make_pair(s1["I46arr"],s1["function"])]=t;
    par[make_pair(s1["I46arr"],s1["return"])]=t;
    par[make_pair(s1["I46arr"],s1["{"])]=t;
    par[make_pair(s1["I46arr"],s1["}"])]=t;
    par[make_pair(s1["I46arr"],s1["integer"])]=t;
    par[make_pair(s1["I46arr"],s1["string literal"])]=t;
    par[make_pair(s1["I46arr"],s1["if"])]=t;

    par[make_pair(s1["I48arr"],s1["$"])]=t;
    par[make_pair(s1["I48arr"],s1["id"])]=t;
    par[make_pair(s1["I48arr"],s1["let"])]=t;
    par[make_pair(s1["I48arr"],s1["const"])]=t;
    par[make_pair(s1["I48arr"],s1["for"])]=t;
    par[make_pair(s1["I48arr"],s1["function"])]=t;
    par[make_pair(s1["I48arr"],s1["return"])]=t;
    par[make_pair(s1["I48arr"],s1["{"])]=t;
    par[make_pair(s1["I48arr"],s1["}"])]=t;
    par[make_pair(s1["I48arr"],s1["integer"])]=t;
    par[make_pair(s1["I48arr"],s1["floating point"])]=t;
    par[make_pair(s1["I48arr"],s1["if"])]=t;

    par[make_pair(s1["P1"],s1["$"])]=t;
    par[make_pair(s1["P1"],s1["id"])]=t;
    par[make_pair(s1["P1"],s1["let"])]=t;
    par[make_pair(s1["P1"],s1["const"])]=t;
    par[make_pair(s1["P1"],s1["for"])]=t;
    par[make_pair(s1["P1"],s1["function"])]=t;
    par[make_pair(s1["P1"],s1["return"])]=t;
    par[make_pair(s1["P1"],s1["{"])]=t;
    par[make_pair(s1["P1"],s1["}"])]=t;
    par[make_pair(s1["P1"],s1["integer"])]=t;
    par[make_pair(s1["P1"],s1["floating point"])]=t;
    par[make_pair(s1["P1"],s1["string literal"])]=t;
    par[make_pair(s1["P1"],s1["if"])]=t;

    par[make_pair(s1["P2"],s1["$"])]=t;
    par[make_pair(s1["P2"],s1["id"])]=t;
    par[make_pair(s1["P2"],s1["let"])]=t;
    par[make_pair(s1["P2"],s1["const"])]=t;
    par[make_pair(s1["P2"],s1["for"])]=t;
    par[make_pair(s1["P2"],s1["function"])]=t;
    par[make_pair(s1["P2"],s1["return"])]=t;
    par[make_pair(s1["P2"],s1["{"])]=t;
    par[make_pair(s1["P2"],s1["}"])]=t;
    par[make_pair(s1["P2"],s1["integer"])]=t;
    par[make_pair(s1["P2"],s1["floating point"])]=t;
    par[make_pair(s1["P2"],s1["string literal"])]=t;
    par[make_pair(s1["P2"],s1["if"])]=t;

    par[make_pair(s1["P3"],s1["$"])]=t;
    par[make_pair(s1["P3"],s1["id"])]=t;
    par[make_pair(s1["P3"],s1["let"])]=t;
    par[make_pair(s1["P3"],s1["const"])]=t;
    par[make_pair(s1["P3"],s1["for"])]=t;
    par[make_pair(s1["P3"],s1["function"])]=t;
    par[make_pair(s1["P3"],s1["return"])]=t;
    par[make_pair(s1["P3"],s1["{"])]=t;
    par[make_pair(s1["P3"],s1["}"])]=t;
    par[make_pair(s1["P3"],s1["integer"])]=t;
    par[make_pair(s1["P3"],s1["floating point"])]=t;
    par[make_pair(s1["P3"],s1["string literal"])]=t;
    par[make_pair(s1["P3"],s1["if"])]=t;

    par[make_pair(s1["P4"],s1["$"])]=t;
    par[make_pair(s1["P4"],s1["id"])]=t;
    par[make_pair(s1["P4"],s1["let"])]=t;
    par[make_pair(s1["P4"],s1["const"])]=t;
    par[make_pair(s1["P4"],s1["for"])]=t;
    par[make_pair(s1["P4"],s1["function"])]=t;
    par[make_pair(s1["P4"],s1["return"])]=t;
    par[make_pair(s1["P4"],s1["]"])]=t;
    par[make_pair(s1["P4"],s1["{"])]=t;
    par[make_pair(s1["P4"],s1["integer"])]=t;
    par[make_pair(s1["P4"],s1["floating point"])]=t;
    par[make_pair(s1["P4"],s1["string literal"])]=t;
    par[make_pair(s1["P4"],s1["if"])]=t;    

    par[make_pair(s1["V"],s1[";"])]=t;
    par[make_pair(s1["V"],s1["}"])]=t;
    par[make_pair(s1["V"],s1[")"])]=t;
    par[make_pair(s1["V"],s1[","])]=t;
    par[make_pair(s1["V"],s1["<"])]=t;
    par[make_pair(s1["V"],s1["<="])]=t;
    par[make_pair(s1["V"],s1[">"])]=t;
    par[make_pair(s1["V"],s1[">="])]=t;
    par[make_pair(s1["V"],s1["=="])]=t;
    par[make_pair(s1["V"],s1["||"])]=t;
    par[make_pair(s1["V"],s1["&&"])]=t;
    par[make_pair(s1["V"],s1["*"])]=t;
    par[make_pair(s1["V"],s1["+"])]=t;
    par[make_pair(s1["V"],s1["/"])]=t;
    par[make_pair(s1["V"],s1["-"])]=t;
    par[make_pair(s1["V"],s1["%"])]=t;

    par[make_pair(s1["B"],s1[";"])]=t;
    par[make_pair(s1["B"],s1[")"])]=t;

    par[make_pair(s1["C"],s1[")"])]=t;

    par[make_pair(s1["A'"],s1[";"])]=t;

    par[make_pair(s1["B1"],s1[";"])]=t;
    par[make_pair(s1["B1"],s1[")"])]=t;
 
    par[make_pair(s1["C1"],s1[")"])]=t;

    par[make_pair(s1["F'"],s1["$"])]=t;
    par[make_pair(s1["F'"],s1["let"])]=t;
    par[make_pair(s1["F'"],s1["const"])]=t;
    par[make_pair(s1["F'"],s1["for"])]=t;
    par[make_pair(s1["F'"],s1["function"])]=t;
    par[make_pair(s1["F'"],s1["return"])]=t;
    par[make_pair(s1["F'"],s1["{"])]=t;
    par[make_pair(s1["F'"],s1["}"])]=t;
    par[make_pair(s1["F'"],s1["integer"])]=t;
    par[make_pair(s1["F'"],s1["floating point"])]=t;
    par[make_pair(s1["F'"],s1["string literal"])]=t;
    par[make_pair(s1["F'"],s1["if"])]=t;

    par[make_pair(s1["V'"],s1["$"])]=t;
    par[make_pair(s1["V'"],s1["let"])]=t;
    par[make_pair(s1["V'"],s1["const"])]=t;
    par[make_pair(s1["V'"],s1["for"])]=t;
    par[make_pair(s1["V'"],s1["function"])]=t;
    par[make_pair(s1["V'"],s1["return"])]=t;
    par[make_pair(s1["V'"],s1["{"])]=t;
    par[make_pair(s1["V'"],s1["}"])]=t;
    par[make_pair(s1["V'"],s1["if"])]=t;

    par[make_pair(s1["V1"],s1["$"])]=t;
    par[make_pair(s1["V1"],s1["id"])]=t;
    par[make_pair(s1["V1"],s1["let"])]=t;
    par[make_pair(s1["V1"],s1["const"])]=t;
    par[make_pair(s1["V1"],s1["for"])]=t;
    par[make_pair(s1["V1"],s1["function"])]=t;
    par[make_pair(s1["V1"],s1["return"])]=t;
    par[make_pair(s1["V1"],s1["{"])]=t;
    par[make_pair(s1["V1"],s1["}"])]=t;
    par[make_pair(s1["V1"],s1["integer"])]=t;
    par[make_pair(s1["V1"],s1["floating point"])]=t;
    par[make_pair(s1["V1"],s1["string literal"])]=t;
    par[make_pair(s1["V1"],s1["if"])]=t;

    par[make_pair(s1["Ar"],s1["$"])]=t;
    par[make_pair(s1["Ar"],s1["let"])]=t;
    par[make_pair(s1["Ar"],s1["const"])]=t;
    par[make_pair(s1["Ar"],s1["for"])]=t;
    par[make_pair(s1["Ar"],s1["function"])]=t;
    par[make_pair(s1["Ar"],s1["return"])]=t;
    par[make_pair(s1["Ar"],s1["{"])]=t;
    par[make_pair(s1["Ar"],s1["}"])]=t;
    par[make_pair(s1["Ar"],s1["if"])]=t;

    par[make_pair(s1["Ar1"],s1["$"])]=t;
    par[make_pair(s1["Ar1"],s1["id"])]=t;
    par[make_pair(s1["Ar1"],s1["let"])]=t;
    par[make_pair(s1["Ar1"],s1["const"])]=t;
    par[make_pair(s1["Ar1"],s1["for"])]=t;
    par[make_pair(s1["Ar1"],s1["function"])]=t;
    par[make_pair(s1["Ar1"],s1["return"])]=t;
    par[make_pair(s1["Ar1"],s1["{"])]=t;
    par[make_pair(s1["Ar1"],s1["}"])]=t;
    par[make_pair(s1["Ar1"],s1["integer"])]=t;
    par[make_pair(s1["Ar1"],s1["floating point"])]=t;
    par[make_pair(s1["Ar1"],s1["string literal"])]=t;
    par[make_pair(s1["Ar1"],s1["if"])]=t;

  t.clear();  //ACCEPT
  t.push_back(2312) ;//accept
  par[make_pair(s1["<start>"],s1["$"])]=t;


    //SKIP
    t.clear();
    t.push_back(100);                 // skip state
    for(int i = 0; i <= 31; i++)      // for all NTs
    {
        for(int j = 32; j <= 69; j++) // for all terminals
        {
            if(par.find(make_pair(i,j)) == par.end()) // if NT, T pair does not exist
            {
                par[make_pair(i,j)] = t;              // make pair with skip state
            }
        }
    }

    stack<int> stk;              // stack for parsing
    stk.push(33);
    stk.push(0);

    vector<int> input;          // vector to store input lexemes
    vector<int> linenum;        // vector to store line numbers 

    fstream newfile;                          // opening input file
    newfile.open("output/lexer_o_7.txt",ios::in);
    string tp;
    while(getline(newfile, tp))
    {
    	string tm = "";
    	tm += tp[6];
    	if(tp[7] != ',')
    	{	tm += tp[7];
    		if(tp[8] != ',')
    			tm += tp[8];
    	}	
        // cout<<tm<<endl;
      string num,temp;
      stringstream ss(tp);
      while(ss>>temp){
        // cout<<temp<<" ";
        num=temp;
      }
    //   cout<<num;
    //   cout<<endl;
      linenum.push_back(stoi(num));
      input.push_back(w[tm]);
    }
    input.push_back(33);             // inserting $ at the end of the input
    linenum.push_back(9999);

    vector<int> matched;

    while(input.size() > 0)                             // parsing the input
    {
       if((stk.size() == 1) && (input.size() > 1))
        {

          output<<endl<<"\nInput :\n";
          for(int i = 0; i < input.size(); i++)        // print the remaining part of input left
          {
              output<<s[input[i]]<<" ";
          }

          stack<int> forPrint(stk);                   // print the current content of the stack
            output<<endl<<"Stack :\n";
          while (!forPrint.empty()) 
          {  output<<s[forPrint.top()]<<" ";
              forPrint.pop();
          }

          output<<endl<<"Matched :\n";

          for(int i = 0; i < matched.size(); i++)     // print the terms that hve been matched till then 
          {
              output<<s[matched[i]]<<" ";
          }

          output<<"\nError in Line Number : "<<*linenum.begin()<<", Recovery not possible";  // Error message
          break;	
        }

       output<<endl<<"\nInput :\n";                // print the remaining part of input left
       for(int i = 0; i < input.size(); i++)
       {
       		output<<s[input[i]]<<" ";
       }

       stack<int> forPrint(stk);
        output<<endl<<"Stack :\n";
       while (!forPrint.empty())                 // print the current content of the stack
       {  output<<s[forPrint.top()]<<" ";
      	  forPrint.pop();
       }

       output<<endl<<"Matched :\n";               // print the terms that hve been matched till then 

       for(int i = 0; i < matched.size(); i++)
       {
       		output<<s[matched[i]]<<" ";
       }

       if(input[0] == stk.top())                 // if input and stack top match, remove the terminal from both
	     {
       	 matched.push_back(input[0]);
       	 input.erase(input.begin());
          linenum.erase(linenum.begin());
       	 stk.pop();
       }

       else if(par.find(make_pair(stk.top(),input[0])) == par.end())                                 // Error if top of stack does not match with the first of input and both are terminals
       {
       		output<<"\nError in Line Number : "<<*linenum.begin()<<"Pop Terminal : "<<s[stk.top()];
          stk.pop();
       }

       else if(par[make_pair(stk.top(),input[0])][0] == 100)                                        // skip the input lexeme for skip state
       {

         output<<endl<<"Error in Line Number : "<<*linenum.begin()<<" Skip Lexeme : "<<s[*input.begin()]<<endl;
          input.erase(input.begin());
          linenum.erase(linenum.begin());
       }

       else if(par[make_pair(stk.top(),input[0])][0] == 101)                                       // pop the top of stack for synch state 
       {
         output<<endl<<"Error in Line Number : "<<*linenum.begin()<<" Pop Non-Terminal : "<<s[stk.top()]<<endl;
         stk.pop();
       }
       
       else if(par[make_pair(stk.top(),input[0])][0] == 2312)                                       // pop the top of stack for synch state 
       {
         output<<endl<<"ACCEPTED"<<endl;
         stk.pop();
       }


       else                                            // replace top of stack with its correspondng RHS of production
       {
       	 int nt = stk.top();
       	 stk.pop();
       	 int t = input[0];
       	 vector<int> tmp = par[make_pair(nt,t)];
       	 reverse(tmp.begin(), tmp.end());
       	 if(tmp[0] == 30)
       	 	continue;
       	 for(int i = 0; i < tmp.size(); i++)
       	 	stk.push(tmp[i]);	
       }
       
	   

   }

    output<<endl;   
}