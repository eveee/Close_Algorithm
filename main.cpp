#include <fstream>
#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>
#include <cstdint>

using namespace std;

    //stockage de la base de données
vector<string> monthData, timeData, powerData;
    //tableau rempli par l'algo: les mois, temps, conso présents dans le texte courant sont mis à true
vector<vector<bool>> months(12, vector<bool>()), time(3,vector<bool>()), power(5,vector<bool>());
    //variables utiles pour la fermeture
vector<string> G;
vector<vector<string>> fMonths(12, vector<string>(3)), fTime(3, vector<string>(3)), fPower(5, vector<string>(3));
vector<int> sMonths(12, 0), sTime(3, 0), sPower(5, 0);

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

void fermeture(){
    int m=0; int t=0; int p=0; vector<string> tmp;
    if(G.at(0).compare("January") == 0){
        if(fMonths.at(m).empty()){
            fMonths.at(m).push_back(G.at(0)); fMonths.at(m).push_back(G.at(1));  fMonths.at(m).push_back(G.at(2));
        }
        else{
            sort(fMonths.at(m).begin(),fMonths.at(m).end());
            sort(G.begin(),G.end());
            set_intersection(fMonths.at(m).begin(),fMonths.at(m).end(),G.begin(),G.end(),back_inserter(tmp));
            fMonths.at(m).clear(); fMonths.at(m)=tmp; tmp.clear();
            if(fMonths.at(m).empty())
                fMonths.at(m).push_back("January");
        } sMonths.at(m)+=1;
    }
    else if(G.at(0).compare("February") == 0){
        m=1;
        if(fMonths.at(m).empty()){
            fMonths.at(m).push_back(G.at(0)); fMonths.at(m).push_back(G.at(1));  fMonths.at(m).push_back(G.at(2));
        }
        else{
            sort(fMonths.at(m).begin(),fMonths.at(m).end());
            sort(G.begin(),G.end());
            set_intersection(fMonths.at(m).begin(),fMonths.at(m).end(),G.begin(),G.end(),back_inserter(tmp));
            fMonths.at(m).clear(); fMonths.at(m)=tmp; tmp.clear();
            if(fMonths.at(m).empty())
                fMonths.at(m).push_back("February");
        } sMonths.at(m)+=1;
    }
    else if(G.at(0).compare("March") == 0){
        m=2;
        if(fMonths.at(m).empty()){
            fMonths.at(m).push_back(G.at(0)); fMonths.at(m).push_back(G.at(1));  fMonths.at(m).push_back(G.at(2));
        }
        else{
            sort(fMonths.at(m).begin(),fMonths.at(m).end());
            sort(G.begin(),G.end());
            set_intersection(fMonths.at(m).begin(),fMonths.at(m).end(),G.begin(),G.end(),back_inserter(tmp));
            fMonths.at(m).clear(); fMonths.at(m)=tmp; tmp.clear();
            if(fMonths.at(m).empty())
                fMonths.at(m).push_back("March");
        } sMonths.at(m)+=1;
    }
    else if(G.at(0).compare("April") == 0){
        m=3;
        if(fMonths.at(m).empty()){
            fMonths.at(m).push_back(G.at(0)); fMonths.at(m).push_back(G.at(1));  fMonths.at(m).push_back(G.at(2));
        }
        else{
            sort(fMonths.at(m).begin(),fMonths.at(m).end());
            sort(G.begin(),G.end());
            set_intersection(fMonths.at(m).begin(),fMonths.at(m).end(),G.begin(),G.end(),back_inserter(tmp));
            fMonths.at(m).clear(); fMonths.at(m)=tmp; tmp.clear();
            if(fMonths.at(m).empty())
                fMonths.at(m).push_back("April");
        } sMonths.at(m)+=1;
    }
    else if(G.at(0).compare("May") == 0){
        m=4;
        if(fMonths.at(m).empty()){
            fMonths.at(m).push_back(G.at(0)); fMonths.at(m).push_back(G.at(1));  fMonths.at(m).push_back(G.at(2));
        }
        else{
            sort(fMonths.at(m).begin(),fMonths.at(m).end());
            sort(G.begin(),G.end());
            set_intersection(fMonths.at(m).begin(),fMonths.at(m).end(),G.begin(),G.end(),back_inserter(tmp));
            fMonths.at(m).clear(); fMonths.at(m)=tmp; tmp.clear();
            if(fMonths.at(m).empty())
                fMonths.at(m).push_back("May");
        } sMonths.at(m)+=1;
    }
    else if(G.at(0).compare("June") == 0){
        m=5;
        if(fMonths.at(m).empty()){
            fMonths.at(m).push_back(G.at(0)); fMonths.at(m).push_back(G.at(1));  fMonths.at(m).push_back(G.at(2));
        }
        else{
            sort(fMonths.at(m).begin(),fMonths.at(m).end());
            sort(G.begin(),G.end());
            set_intersection(fMonths.at(m).begin(),fMonths.at(m).end(),G.begin(),G.end(),back_inserter(tmp));
            fMonths.at(m).clear(); fMonths.at(m)=tmp; tmp.clear();
            if(fMonths.at(m).empty())
                fMonths.at(m).push_back("June");
        } sMonths.at(m)+=1;
    }
    else if(G.at(0).compare("July") == 0){
        m=6;
        if(fMonths.at(m).empty()){
            fMonths.at(m).push_back(G.at(0)); fMonths.at(m).push_back(G.at(1));  fMonths.at(m).push_back(G.at(2));
        }
        else{
            sort(fMonths.at(m).begin(),fMonths.at(m).end());
            sort(G.begin(),G.end());
            set_intersection(fMonths.at(m).begin(),fMonths.at(m).end(),G.begin(),G.end(),back_inserter(tmp));
            fMonths.at(m).clear(); fMonths.at(m)=tmp; tmp.clear();
            if(fMonths.at(m).empty())
                fMonths.at(m).push_back("July");
        } sMonths.at(m)+=1;
    }
    else if(G.at(0).compare("August") == 0){
        m=7;
        if(fMonths.at(m).empty()){
            fMonths.at(m).push_back(G.at(0)); fMonths.at(m).push_back(G.at(1));  fMonths.at(m).push_back(G.at(2));
        }
        else{
            sort(fMonths.at(m).begin(),fMonths.at(m).end());
            sort(G.begin(),G.end());
            set_intersection(fMonths.at(m).begin(),fMonths.at(m).end(),G.begin(),G.end(),back_inserter(tmp));
            fMonths.at(m).clear(); fMonths.at(m)=tmp; tmp.clear();
            if(fMonths.at(m).empty())
                fMonths.at(m).push_back("August");
        } sMonths.at(m)+=1;
    }
    else if(G.at(0).compare("September") == 0){
        m=8;
        if(fMonths.at(m).empty()){
            fMonths.at(m).push_back(G.at(0)); fMonths.at(m).push_back(G.at(1));  fMonths.at(m).push_back(G.at(2));
        }
        else{
            sort(fMonths.at(m).begin(),fMonths.at(m).end());
            sort(G.begin(),G.end());
            set_intersection(fMonths.at(m).begin(),fMonths.at(m).end(),G.begin(),G.end(),back_inserter(tmp));
            fMonths.at(m).clear(); fMonths.at(m)=tmp; tmp.clear();
            if(fMonths.at(m).empty())
                fMonths.at(m).push_back("September");
        } sMonths.at(m)+=1;
    }
    else if(G.at(0).compare("October") == 0){
        m=9;
        if(fMonths.at(m).empty()){
            fMonths.at(m).push_back(G.at(0)); fMonths.at(m).push_back(G.at(1));  fMonths.at(m).push_back(G.at(2));
        }
        else{
            sort(fMonths.at(m).begin(),fMonths.at(m).end());
            sort(G.begin(),G.end());
            set_intersection(fMonths.at(m).begin(),fMonths.at(m).end(),G.begin(),G.end(),back_inserter(tmp));
            fMonths.at(m).clear(); fMonths.at(m)=tmp; tmp.clear();
            if(fMonths.at(m).empty())
                fMonths.at(m).push_back("October");
        } sMonths.at(m)+=1;
    }
    else if(G.at(0).compare("November") == 0){
        m=10;
        if(fMonths.at(m).empty()){
            fMonths.at(m).push_back(G.at(0)); fMonths.at(m).push_back(G.at(1));  fMonths.at(m).push_back(G.at(2));
        }
        else{
            sort(fMonths.at(m).begin(),fMonths.at(m).end());
            sort(G.begin(),G.end());
            set_intersection(fMonths.at(m).begin(),fMonths.at(m).end(),G.begin(),G.end(),back_inserter(tmp));
            fMonths.at(m).clear(); fMonths.at(m)=tmp; tmp.clear();
            if(fMonths.at(m).empty())
                fMonths.at(m).push_back("November");
        } sMonths.at(m)+=1;
    }
    else if(G.at(0).compare("December") == 0){
        m=11;
        if(fMonths.at(m).empty()){
            fMonths.at(m).push_back(G.at(0)); fMonths.at(m).push_back(G.at(1));  fMonths.at(m).push_back(G.at(2));
        }
        else{
            sort(fMonths.at(m).begin(),fMonths.at(m).end());
            sort(G.begin(),G.end());
            set_intersection(fMonths.at(m).begin(),fMonths.at(m).end(),G.begin(),G.end(),back_inserter(tmp));
            fMonths.at(m).clear(); fMonths.at(m)=tmp; tmp.clear();
            if(fMonths.at(m).empty())
                fMonths.at(m).push_back("December");
        } sMonths.at(m)+=1;
    }

    if(G.at(1).compare("Morning") == 0){
        if(fTime.at(t).empty()){
            fTime.at(t).push_back(G.at(0)); fTime.at(t).push_back(G.at(1));  fTime.at(t).push_back(G.at(2));
        }
        else{
            sort(fTime.at(t).begin(),fTime.at(t).end());
            sort(G.begin(),G.end());
            set_intersection(fTime.at(t).begin(),fTime.at(t).end(),G.begin(),G.end(),back_inserter(tmp));
            fTime.at(t).clear(); fTime.at(t)=tmp; tmp.clear();
            if(fTime.at(t).empty())
                fTime.at(t).push_back("Morning");
        } sTime.at(t)+=1;
    }
    else if(G.at(1).compare("Noon") == 0){
        t=1;
        if(fTime.at(t).empty()){
            fTime.at(t).push_back(G.at(0)); fTime.at(t).push_back(G.at(1));  fTime.at(t).push_back(G.at(2));
        }
        else{
            sort(fTime.at(t).begin(),fTime.at(t).end());
            sort(G.begin(),G.end());
            set_intersection(fTime.at(t).begin(),fTime.at(t).end(),G.begin(),G.end(),back_inserter(tmp));
            fTime.at(t).clear(); fTime.at(t)=tmp; tmp.clear();
            if(fTime.at(t).empty())
                fTime.at(t).push_back("Noon");
        } sTime.at(t)+=1;
    }
    else if(G.at(1).compare("Evening") == 0){
        t=2;
        if(fTime.at(t).empty()){
            fTime.at(t).push_back(G.at(0)); fTime.at(t).push_back(G.at(1));  fTime.at(t).push_back(G.at(2));
        }
        else{
            sort(fTime.at(t).begin(),fTime.at(t).end());
            sort(G.begin(),G.end());
            set_intersection(fTime.at(t).begin(),fTime.at(t).end(),G.begin(),G.end(),back_inserter(tmp));
            fTime.at(t).clear(); fTime.at(t)=tmp; tmp.clear();
            if(fTime.at(t).empty())
                fTime.at(t).push_back("Evening");
        } sTime.at(t)+=1;
    }

    if(G.at(2).compare("Very low") == 0){
        if(fPower.at(p).empty()){
            fPower.at(p).push_back(G.at(0)); fPower.at(p).push_back(G.at(1));  fPower.at(p).push_back(G.at(2));
        }
        else{
            sort(fPower.at(p).begin(),fPower.at(p).end());
            sort(G.begin(),G.end());
            set_intersection(fPower.at(p).begin(),fPower.at(p).end(),G.begin(),G.end(),back_inserter(tmp));
            fPower.at(p).clear(); fPower.at(p)=tmp; tmp.clear();
            if(fPower.at(p).empty())
                fPower.at(p).push_back("Very low");
        } sPower.at(p)+=1;
    }
    else if(G.at(2).compare("Low") == 0){
        p=1;
        if(fPower.at(p).empty()){
            fPower.at(p).push_back(G.at(0)); fPower.at(p).push_back(G.at(1));  fPower.at(p).push_back(G.at(2));
        }
        else{
            sort(fPower.at(p).begin(),fPower.at(p).end());
            sort(G.begin(),G.end());
            set_intersection(fPower.at(p).begin(),fPower.at(p).end(),G.begin(),G.end(),back_inserter(tmp));
            fPower.at(p).clear(); fPower.at(p)=tmp; tmp.clear();
            if(fTime.at(t).empty())
                fTime.at(t).push_back("Low");
        } sPower.at(p)+=1;
    }
    else if(G.at(2).compare("Medium") == 0){
        p=2;
        if(fPower.at(p).empty()){
            fPower.at(p).push_back(G.at(0)); fPower.at(p).push_back(G.at(1));  fPower.at(p).push_back(G.at(2));
        }
        else{
            sort(fPower.at(p).begin(),fPower.at(p).end());
            sort(G.begin(),G.end());
            set_intersection(fPower.at(p).begin(),fPower.at(p).end(),G.begin(),G.end(),back_inserter(tmp));
            fPower.at(p).clear(); fPower.at(p)=tmp; tmp.clear();
            if(fTime.at(t).empty())
                fTime.at(t).push_back("Medium");
        } sPower.at(p)+=1;
    }
    else if(G.at(2).compare("High") == 0){
        p=3;
        if(fPower.at(p).empty()){
            fPower.at(p).push_back(G.at(0)); fPower.at(p).push_back(G.at(1));  fPower.at(p).push_back(G.at(2));
        }
        else{
            sort(fPower.at(p).begin(),fPower.at(p).end());
            sort(G.begin(),G.end());
            set_intersection(fPower.at(p).begin(),fPower.at(p).end(),G.begin(),G.end(),back_inserter(tmp));
            fPower.at(p).clear(); fPower.at(p)=tmp; tmp.clear();
            if(fTime.at(t).empty())
                fTime.at(t).push_back("High");
        } sPower.at(p)+=1;
    }
    else if(G.at(2).compare("Very high") == 0){
        p=4;
        if(fPower.at(p).empty()){
            fPower.at(p).push_back(G.at(0)); fPower.at(p).push_back(G.at(1));  fPower.at(p).push_back(G.at(2));
        }
        else{
            sort(fPower.at(p).begin(),fPower.at(p).end());
            sort(G.begin(),G.end());
            set_intersection(fPower.at(p).begin(),fPower.at(p).end(),G.begin(),G.end(),back_inserter(tmp));
            fPower.at(p).clear(); fPower.at(p)=tmp; tmp.clear();
            if(fTime.at(t).empty())
                fTime.at(t).push_back("Very high");
        } sPower.at(p)+=1;
    }

    G.clear();
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

        fermeture();
    }
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

void displayFermeture(){
    cout << endl << endl;
    for(int i=0; i<fMonths.size(); i++){
        cout << endl << "fermeture mois " << i << " : ";
        for(int j=0; j<fMonths.at(i).size(); j++){
             cout << fMonths.at(i).at(j) << " ";
        }
    }
    for(int i=0; i<fTime.size(); i++){
        cout << endl << "fermeture periode " << i << " : ";
        for(int j=0; j<fTime.at(i).size(); j++){
             cout << fTime.at(i).at(j) << " ";
        }
    }
    for(int i=0; i<fPower.size(); i++){
        cout << endl << "fermeture conso " << i << " : ";
        for(int j=0; j<fPower.at(i).size(); j++){
             cout << fPower.at(i).at(j) << " ";
        }
    }
}

void displaySupport(){
    cout << endl << endl;
    for(int i=0; i<sMonths.size(); i++){
        cout << endl << "support mois " << i << " : " << sMonths.at(i);
    }
    for(int i=0; i<sTime.size(); i++){
        cout << endl << "support periode " << i << " : " << sTime.at(i);
    }
    for(int i=0; i<sPower.size(); i++){
        cout << endl << "support conso " << i << " : " << sPower.at(i);
    }
}

void display(){
    displayMonths();
    displayTime();
    displayPower();
    displayFermeture();
    displaySupport();
}

int main(){
    prepareData();
    remplissage();
    display();

}
