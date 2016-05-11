#include <fstream>
#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

    //stockage de la base de données
vector<string> monthData, timeData, powerData;
    //tableau rempli par l'algo: les mois, temps, conso présents dans le texte courant sont mis à true
vector<vector<bool>> months(12, vector<bool>()), time(3,vector<bool>()), power(5,vector<bool>());
    //variables utiles pour la fermeture
vector<string> G;
vector<vector<string>> fMonths(12, vector<string>(3)), fTime(3, vector<string>(3)), fPower(5, vector<string>(3));

void prepareData(){
    int cnt = 0;
    //ifstream file ("C:/Users/Eva Ly Kok/Desktop/Serie_de_donneesC++Friendly.csv");
    ifstream file ("C:/Users/Eva Ly Kok/Desktop/C++Friendly_Cropped.csv");
    string value;
    while (file.good())
    {
         getline(file, value, ';');
         if(cnt == 0){
            monthData.push_back(string(value, 1, value.length()));
            //cout << endl << "month : " << monthData.at(monthData.size()-1);
            cnt++;
         }
         else if (cnt == 1){
            timeData.push_back(value);
            //cout << endl << "time : " << timeData.at(timeData.size()-1);
            cnt++;
         }
         else{
            powerData.push_back(value);
            //cout << endl << "power : " << powerData.at(powerData.size()-1);
            cnt = 0;
         }
    }monthData.erase(monthData.begin()); timeData.erase(timeData.begin()); powerData.erase(powerData.begin());
}

void remplissage(){
    vector<string>::iterator itMonth=monthData.begin();
    vector<string>::iterator itTime=timeData.begin();
    vector<string>::iterator itPower=powerData.begin();
    for(; itMonth!=monthData.end() && itTime!=timeData.end() && itPower!=powerData.end(); itMonth++, itTime++, itPower++){
       int m=0; int t=0; int p=0;
       if(((string)(*itMonth)).compare("January") == 0){
            months.at(m).push_back(true);
            G.push_back("January");
            for(int j=m+1; j<months.size(); j++){
                months.at(j).push_back(false);
            }
        }
        else if(((string)(*itMonth)).compare("February") == 0){
            m = 1;
            months.at(m).push_back(true);
            G.push_back("February");
            for(int j=0; j<m; j++){
                months.at(j).push_back(false);
            }
            for(int j=m+1; j<months.size(); j++){
                months.at(j).push_back(false);
            }
        }
        else if(((string)(*itMonth)).compare("March") == 0){
            m = 2;
            months.at(m).push_back(true);
            G.push_back("March");
            for(int j=0; j<m; j++){
                months.at(j).push_back(false);
            }
            for(int j=m+1; j<months.size(); j++){
                months.at(j).push_back(false);
            }
        }
        else if(((string)(*itMonth)).compare("April") == 0){
            m = 3;
            months.at(m).push_back(true);
            G.push_back("April");
            for(int j=0; j<m; j++){
                months.at(j).push_back(false);
            }
            for(int j=m+1; j<months.size(); j++){
                months.at(j).push_back(false);
            }
        }
        else if(((string)(*itMonth)).compare("May") == 0){
            m = 4;
            months.at(m).push_back(true);
            G.push_back("May");
            for(int j=0; j<m; j++){
                months.at(j).push_back(false);
            }
            for(int j=m+1; j<months.size(); j++){
                months.at(j).push_back(false);
            }
        }
        else if(((string)(*itMonth)).compare("June") == 0){
            m = 5;
            months.at(m).push_back(true);
            G.push_back("June");
            for(int j=0; j<m; j++){
                months.at(j).push_back(false);
            }
            for(int j=m+1; j<months.size(); j++){
                months.at(j).push_back(false);
            }
        }
        else if(((string)(*itMonth)).compare("July") == 0){
            m = 6;
            months.at(m).push_back(true);
            G.push_back("July");
            for(int j=0; j<m; j++){
                months.at(j).push_back(false);
            }
            for(int j=m+1; j<months.size(); j++){
                months.at(j).push_back(false);
            }
        }
        else if(((string)(*itMonth)).compare("August") == 0){
            m = 7;
            months.at(m).push_back(true);
            G.push_back("August");
            for(int j=0; j<m; j++){
                months.at(j).push_back(false);
            }
            for(int j=m+1; j<months.size(); j++){
                months.at(j).push_back(false);
            }
        }
        else if(((string)(*itMonth)).compare("September") == 0){
           m = 8;
           months.at(m).push_back(true);
           G.push_back("September");
           for(int j=0; j<m; j++){
               months.at(j).push_back(false);
           }
           for(int j=m+1; j<months.size(); j++){
               months.at(j).push_back(false);
           }
        }
        else if(((string)(*itMonth)).compare("October") == 0){
            m = 9;
            months.at(m).push_back(true);
            G.push_back("October");
            for(int j=0; j<m; j++){
                months.at(j).push_back(false);
            }
            for(int j=m+1; j<months.size(); j++){
                months.at(j).push_back(false);
            }
        }
        else if(((string)(*itMonth)).compare("November") == 0){
            m = 10;
            months.at(m).push_back(true);
            G.push_back("November");
            for(int j=0; j<m; j++){
                months.at(j).push_back(false);
            }
            for(int j=m+1; j<months.size(); j++){
                months.at(j).push_back(false);
            }
        }
        else {
            m = 11;
            months.at(m).push_back(true);
            G.push_back("December");
            for(int j=0; j<m; j++){
                months.at(j).push_back(false);
            }
            for(int j=m+1; j<months.size(); j++){
                months.at(j).push_back(false);
            }
        }

        if(((string)(*itTime)).compare("Morning") == 0){
            time.at(t).push_back(true);
            G.push_back("Morning");
            for(int j=t+1; j<time.size(); j++){
                time.at(j).push_back(false);
            }
        }
        else if(((string)(*itTime)).compare("Noon") == 0){
            t = 1;
            time.at(t).push_back(true);
            G.push_back("Noon");
            for(int j=0; j<t; j++){
                time.at(j).push_back(false);
            }
            for(int j=t+1; j<time.size(); j++){
                time.at(j).push_back(false);
            }
        }
        else {
            t = 2;
            time.at(t).push_back(true);
            G.push_back("Evening");
            for(int j=0; j<t; j++){
                time.at(j).push_back(false);
            }
            for(int j=t+1; j<time.size(); j++){
                time.at(j).push_back(false);
            }
        }

        if(((string)(*itPower)).compare("Very low") == 0){
            power.at(p).push_back(true);
            G.push_back("Very low");
            for(int j=p+1; j<power.size(); j++){
                power.at(j).push_back(false);
            }
        }
        else if(((string)(*itPower)).compare("Low") == 0){
            p = 1;
            power.at(p).push_back(true);
            G.push_back("Low");
            for(int j=0; j<p; j++){
                power.at(j).push_back(false);
            }
            for(int j=p+1; j<power.size(); j++){
                power.at(j).push_back(false);
            }
        }
        else if(((string)(*itPower)).compare("Medium") == 0){
            p = 2;
            power.at(p).push_back(true);
            G.push_back("Medium");
            for(int j=0; j<p; j++){
                power.at(j).push_back(false);
            }
            for(int j=p+1; j<power.size(); j++){
                power.at(j).push_back(false);
            }
        }
        else if(((string)(*itPower)).compare("High") == 0){
            p = 3;
            power.at(p).push_back(true);
            G.push_back("High");
            for(int j=0; j<p; j++){
                power.at(j).push_back(false);
            }
            for(int j=p+1; j<power.size(); j++){
                power.at(j).push_back(false);
            }
        }
        else {
            p = 4;
            power.at(p).push_back(true);
            G.push_back("Very high");
            for(int j=0; j<p; j++){
                power.at(j).push_back(false);
            }
            for(int j=p+1; j<power.size(); j++){
                power.at(j).push_back(false);
            }
        }
    }
}

void fermeture(){
    if(G.at(0).compare("Janvier") == 0){
        if(fMonths.empty())
            fMonths.at(0).push_back(G.at(0)+G.at(1)+G.at(2));
        else{
            vector<string> tmp;
            set_intersection(fMonths.at(0).begin(),fMonths.at(0).end(),G.begin(),G.end(),tmp.begin());
            fMonths.at(0).clear(); fMonths.at(0) = tmp; tmp.clear();
        }
    }

    G.clear();
}

void displayMonths(){
    for(int i=0; i<months.size(); i++){
        if (i<10)
            cout << endl << "month  " << i << "|  ";
        else
            cout << endl << "month " << i << "|  ";
        for(int j=0; j<months.at(i).size(); j++){
            cout << months.at(i).at(j) << "  |  ";
        }
    }
}

void displayTime(){
    for(int i=0; i<time.size(); i++){
        cout << endl << "time   " << i << "|  ";
        for(int j=0; j<time.at(i).size(); j++){
            cout << time.at(i).at(j) << "  |  ";
        }
    }
}

void displayPower(){
    for(int i=0; i<power.size(); i++){
        cout << endl << "power  " << i << "|  ";
        for(int j=0; j<power.at(i).size(); j++){
            cout << power.at(i).at(j) << "  |  ";
        }
    }
}

void display(){
    displayMonths();
    displayTime();
    displayPower();
}

int main(){
    prepareData();
    remplissage();
    display();

}
