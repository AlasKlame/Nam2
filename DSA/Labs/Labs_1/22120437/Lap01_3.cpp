#include<iostream>
#include<fstream>
#include<vector>
using namespace std;

struct Examinee{
    string id;
    float math, physics, chemistry, biology,literature ,history, geography, civic_education, natural_science, social_science, foreign_language;
};

Examinee readExaminee(string lineInfo){
    Examinee examinee;
    int i = 0;
    string temp = "";
    while(lineInfo[i] != ','){
        temp += lineInfo[i];
        i++;
    }
    examinee.id = temp;
    temp = "";
    i++;
    while(lineInfo[i] != ','){
        temp += lineInfo[i];
        i++;
    }
    
    temp = "";
    i++;
    while(lineInfo[i] != ','){
        temp += lineInfo[i];
        i++;
    }
    if(temp == ""){
        examinee.math = 0;
    }
    else{
        examinee.math = stof(temp);
    }
    temp = "";
    i++;
    while(lineInfo[i] != ','){
        temp += lineInfo[i];
        i++;
    }
    if(temp == ""){
        examinee.physics = 0;
    }
    else{
        examinee.physics = stof(temp);
    }

    temp = "";
    i++;
    while(lineInfo[i] != ','){
        temp += lineInfo[i];
        i++;
    }
    if(temp == ""){
        examinee.chemistry = 0;
    }
    else{
        examinee.chemistry = stof(temp);
    }
    temp = "";
    i++;
    while(lineInfo[i] != ','){
        temp += lineInfo[i];
        i++;
    }
    if(temp == ""){
        examinee.biology = 0;
    }
    else{
        examinee.biology = stof(temp);
    }
    temp = "";
    i++;
    while(lineInfo[i] != ','){
        temp += lineInfo[i];
        i++;
    };
    if(temp == ""){
        examinee.literature = 0;
    }
    else{
        examinee.literature = stof(temp);
    }
    temp = "";
    i++;
    while(lineInfo[i] != ','){
        temp += lineInfo[i];
        i++;
    }
    if(temp == ""){
        examinee.history = 0;
    }
    else{
        examinee.history = stof(temp);
    }
    temp = "";
    i++;
    while(lineInfo[i] != ','){
        temp += lineInfo[i];
        i++;
    }
    if(temp == ""){
        examinee.geography = 0;
    }
    else{
        examinee.geography = stof(temp);
    }

    temp = "";
    i++;
    while(lineInfo[i] != ','){
        temp += lineInfo[i];
        i++;
    }
    if(temp == ""){
        examinee.civic_education = 0;
    }
    else{
        examinee.civic_education = stof(temp);
    }
    temp = "";
    i++;
    while(lineInfo[i] != ','){
        temp += lineInfo[i];
        i++;
    }
    if(temp == ""){
        examinee.natural_science = 0;
    }
    else{
        examinee.natural_science = stof(temp);
    }
    temp = "";
    i++;
    while(lineInfo[i] != ','){
        temp += lineInfo[i];
        i++;
    }
    
    if(temp == ""){
        examinee.social_science = 0;
    }
    else{
        examinee.social_science = stof(temp);
    }
    temp = "";
    i++;
    while(lineInfo[i] != ','){
        temp += lineInfo[i];
        i++;
    }
    if(temp == ""){
        examinee.foreign_language = 0;
    }
    else{
        examinee.foreign_language = stof(temp);
    }
    return examinee;
}

vector<Examinee> readExamineeList(string file_name){
    ifstream file;
    file.open(file_name);
    vector<Examinee> examineeList;
    string line;
    int lineIndex = 0;
    while(getline(file, line)){
        if (lineIndex == 0){
            lineIndex++;
            continue;
        }
        examineeList.push_back(readExaminee(line));
        lineIndex++;
    }
    file.close();
    return examineeList;
}

void writeTotal(vector<Examinee> examineeList, string out_file_name){
    ofstream file;
    file.open(out_file_name);
    for(int i = 0; i < examineeList.size(); i++){
        file << examineeList[i].id << " " << examineeList[i].math + examineeList[i].physics + examineeList[i].chemistry + examineeList[i].biology + examineeList[i].history + examineeList[i].geography + examineeList[i].civic_education + examineeList[i].natural_science + examineeList[i].social_science + examineeList[i].foreign_language + examineeList[i].literature << endl;
    }
    file.close();
}

vector<string> splitTokens(string line, const string& delimeter) {
    vector<string> tokens;

    size_t index = 0;

    while ((index = line.find(delimeter)) != std::string::npos) {
        tokens.push_back(line.substr(0, index));

        line.erase(0, index + delimeter.length());
    }

    tokens.push_back(line);

    return tokens;
}

int main(){
    ifstream infile("data.txt");
    ofstream outfile("output.txt");
    string line;

    writeTotal(readExamineeList("data.txt"), "output.txt");
    
    cout << "writeTotal" <<"\n";

    
    

    return 0;

    
}