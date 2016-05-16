#include <fstream>
#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>
#include <cstdint>

#define MINSUP 0.4

using namespace std;

    //stockage de la base de données
vector<string> monthData, timeData, powerData;
vector<string> mo = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
vector<string> ti = {"Morning", "Noon", "Evening"};
vector<string> po = {"Very low", "Low", "Medium", "High", "Very high"};
    //tableau rempli par l'algo: les mois, temps, conso présents dans le texte courant sont mis à true
vector<vector<bool>> months(12, vector<bool>()), time(3,vector<bool>()), power(5,vector<bool>());
    //variables utiles pour la fermeture
vector<string> G;
vector<vector<string>> fMonths(12, vector<string>(3)), fTime(3, vector<string>(3)), fPower(5, vector<string>(3));
vector<vector<vector<string>>> fMonths1(12, vector<vector<string>>(3, vector<string>(3))), fTime1(3, vector<vector<string>>(5, vector<string>(3))), fPower1(5, vector<vector<string>>(12, vector<string>(3)));
    //variables support
vector<int> sMonths(12, 0), sTime(3, 0), sPower(5, 0);
vector<vector<int>> sMonths1(12, vector<int>(3, 0)), sTime1(3, vector<int>(5, 0)), sPower1(5, vector<int>(12, 0));
    //variables 2nd gen
vector<string> secondGen[3];
vector<string> thirdGen1[12][3], thirdGen2[3][5], thirdGen3[5][12];
vector<string> motsFrequents;
int gen=0;


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
            cnt++;
         }
         else if (cnt == 1){
            timeData.push_back(value);
            cnt++;
         }
         else{
            powerData.push_back(value);
            cnt = 0;
         }
    }monthData.erase(monthData.begin()); timeData.erase(timeData.begin()); powerData.erase(powerData.begin());
}

void fermeture(){
    vector<string> tmp;
    if(gen==0){
        for(int m=0; m<mo.size(); m++){
            if(G.at(0).compare(mo.at(m)) == 0){
                if(fMonths.at(m).empty()){
                    fMonths.at(m).push_back(G.at(0)); fMonths.at(m).push_back(G.at(1));  fMonths.at(m).push_back(G.at(2));
                }
                else{
                    sort(fMonths.at(m).begin(),fMonths.at(m).end());
                    sort(G.begin(),G.end());
                    set_intersection(fMonths.at(m).begin(),fMonths.at(m).end(),G.begin(),G.end(),back_inserter(tmp));
                    fMonths.at(m).clear(); fMonths.at(m)=tmp; tmp.clear();
                } sMonths.at(m)+=1;
            }
        }
        for(int t=0; t<ti.size(); t++){
            if(G.at(1).compare(ti.at(t)) == 0){
                if(fTime.at(t).empty()){
                    fTime.at(t).push_back(G.at(0)); fTime.at(t).push_back(G.at(1));  fTime.at(t).push_back(G.at(2));
                }
                else{
                    sort(fTime.at(t).begin(),fTime.at(t).end());
                    sort(G.begin(),G.end());
                    set_intersection(fTime.at(t).begin(),fTime.at(t).end(),G.begin(),G.end(),back_inserter(tmp));
                    fTime.at(t).clear(); fTime.at(t)=tmp; tmp.clear();
                } sTime.at(t)+=1;
            }
        }
        for(int p=0; p<po.size(); p++){
            if(G.at(2).compare(po.at(p)) == 0){
                if(fPower.at(p).empty()){
                    fPower.at(p).push_back(G.at(0)); fPower.at(p).push_back(G.at(1));  fPower.at(p).push_back(G.at(2));
                }
                else{
                    sort(fPower.at(p).begin(),fPower.at(p).end());
                    sort(G.begin(),G.end());
                    set_intersection(fPower.at(p).begin(),fPower.at(p).end(),G.begin(),G.end(),back_inserter(tmp));
                    fPower.at(p).clear(); fPower.at(p)=tmp; tmp.clear();
                } sPower.at(p)+=1;
            }
        }
    }

    else if(gen==1){
        for(int m=0; m<mo.size(); m++){
            for(int t=0; t<ti.size(); t++){
                for(int p=0; p<po.size(); p++){
                   if(G.at(0).compare(mo.at(m)) == 0 && find(secondGen[0].begin(), secondGen[0].end(), G.at(0)) != secondGen[0].end() && G.at(1).compare(ti.at(t)) == 0 && find(secondGen[1].begin(), secondGen[1].end(), G.at(1)) != secondGen[1].end()){
                        if(fMonths1[m].at(t).empty()){
                            fMonths1[m].at(t).push_back(G.at(0)); fMonths1[m].at(t).push_back(G.at(1));  fMonths1[m].at(t).push_back(G.at(2));
                        }
                        else{
                            sort(fMonths1[m].at(t).begin(),fMonths1[m].at(t).end());
                            sort(G.begin(),G.end());
                            set_intersection(fMonths1[m].at(t).begin(),fMonths1[m].at(t).end(),G.begin(),G.end(),back_inserter(tmp));
                            fMonths1[m].at(t).clear(); fMonths1[m].at(t)=tmp; tmp.clear();
                        } sMonths1[m].at(t)+=1;
                    }
                    else if(G.at(0).compare(mo.at(m)) == 0 && find(secondGen[0].begin(), secondGen[0].end(), G.at(0)) != secondGen[0].end() && G.at(2).compare(po.at(p)) == 0 && find(secondGen[2].begin(), secondGen[2].end(), G.at(2)) != secondGen[2].end()){
                        if(fPower1[p].at(m).empty()){
                            fPower1[p].at(m).push_back(G.at(0)); fPower1[p].at(m).push_back(G.at(1));  fPower1[p].at(m).push_back(G.at(2));
                        }
                        else{
                            sort(fPower1[p].at(m).begin(),fPower1[p].at(m).end());
                            sort(G.begin(),G.end());
                            set_intersection(fPower1[p].at(m).begin(),fPower1[p].at(m).end(),G.begin(),G.end(),back_inserter(tmp));
                            fPower1[p].at(m).clear(); fPower1[p].at(m)=tmp; tmp.clear();
                        } sPower1[p].at(m)+=1;
                    }
                      if(G.at(1).compare(ti.at(t)) == 0 && find(secondGen[1].begin(), secondGen[1].end(), G.at(1)) != secondGen[1].end() && G.at(2).compare(po.at(p)) == 0 && find(secondGen[2].begin(), secondGen[2].end(), G.at(2)) != secondGen[2].end()){
                          if(fTime1[t].at(p).empty()){
                            fTime1[t].at(p).push_back(G.at(0)); fTime1[t].at(p).push_back(G.at(1));  fTime1[t].at(p).push_back(G.at(2));
                          }
                        else{
                            sort(fTime1[t].at(p).begin(),fTime1[t].at(p).end());
                            sort(G.begin(),G.end());
                            set_intersection(fTime1[t].at(p).begin(),fTime1[t].at(p).end(),G.begin(),G.end(),back_inserter(tmp));
                            fTime1[t].at(p).clear(); fTime1[t].at(p)=tmp; tmp.clear();
                        } sTime1[t].at(p)+=1;
                    }
                }
            }
        }
    }

    G.clear();
}

void nextGen(){
    if(gen==0){
        string s1, s2, s3;
        for(int m=0; m<sMonths.size(); m++){
            if(sMonths.at(m)>=0.4*monthData.size()){
                for(int i=0; i<fMonths.at(m).size(); i++){
                    s1+=" "+fMonths.at(m).at(i);
                }
                motsFrequents.push_back(s1);
                secondGen[0].push_back(mo.at(m));
            }
        }
        for(int t=0; t<sTime.size(); t++){
            if(sTime.at(t)>=MINSUP*timeData.size()){
                for(int i=0; i<fTime.at(t).size(); i++){
                    s2+=" "+fTime.at(t).at(i);
                }
                motsFrequents.push_back(s2);
                secondGen[1].push_back(ti.at(t));
            }
        }
        for(int p=0; p<sPower.size(); p++){
            if(sPower.at(p)>=MINSUP*powerData.size()){
                for(int i=0; i<fPower.at(p).size(); i++){
                    s3+=" "+fPower.at(p).at(i);
                }
                motsFrequents.push_back(s3);
                secondGen[2].push_back(po.at(p));
            }
        } gen++;
    }
    else if(gen==1){
        string s1, s2, s3;
        for(int m=0; m<sMonths1.size(); m++){
            for(int n=0; n<sMonths1.at(m).size(); n++){
                if(sMonths1.at(m).at(n)>=0.4*monthData.size()){
                    for(int i=0; i<fMonths1.at(m).at(n).size(); i++){
                        s1+=" "+fMonths1.at(m).at(n).at(i);
                    }
                    motsFrequents.push_back(s1);
                    thirdGen1[m][n].push_back(mo.at(m)+", "+ti.at(n));
                }
            }
        }
        for(int m=0; m<sTime1.size(); m++){
            for(int n=0; n<sTime1.at(m).size(); n++){
                if(sTime1.at(m).at(n)>=0.4*timeData.size()){
                    for(int i=0; i<fTime1.at(m).at(n).size(); i++){
                        s2+=" "+fTime1.at(m).at(n).at(i);
                    }
                    motsFrequents.push_back(s2);
                    thirdGen2[m][n].push_back(ti.at(m)+", "+po.at(n));
                }
            }
        }
        for(int m=0; m<sPower1.size(); m++){
            for(int n=0; n<sPower1.at(m).size(); n++){
                if(sPower1.at(m).at(n)>=0.4*powerData.size()){
                    for(int i=0; i<fPower1.at(m).at(n).size(); i++){
                        s3+=" "+fPower1.at(m).at(n).at(i);
                    }
                    motsFrequents.push_back(s3);
                    thirdGen3[m][n].push_back(po.at(m)+", "+mo.at(n));
                }
            }
        } gen++;
    }
}

void remplissage(){
    vector<string>::iterator itMonth=monthData.begin();
    vector<string>::iterator itTime=timeData.begin();
    vector<string>::iterator itPower=powerData.begin();
    for(; itMonth!=monthData.end() && itTime!=timeData.end() && itPower!=powerData.end(); itMonth++, itTime++, itPower++){
       for(int m=0; m<mo.size(); m++){
            if(m!=0){
                if(((string)(*itMonth)).compare(mo.at(m)) == 0){
                    months.at(m).push_back(true);
                    G.push_back(mo.at(m));
                    for(int j=0; j<m; j++){
                        months.at(j).push_back(false);
                    }
                    for(int j=m+1; j<months.size(); j++){
                        months.at(j).push_back(false);
                    }
                }
            }
            else{
                if(((string)(*itMonth)).compare(mo.at(m)) == 0){
                    months.at(m).push_back(true);
                    G.push_back(mo.at(m));
                    for(int j=m+1; j<months.size(); j++){
                        months.at(j).push_back(false);
                    }
                }
            }
       }
       for(int t=0; t<ti.size(); t++){
            if(t!=0){
                if(((string)(*itTime)).compare(ti.at(t)) == 0){
                    time.at(t).push_back(true);
                    G.push_back(ti.at(t));
                    for(int j=0; j<t; j++){
                        time.at(j).push_back(false);
                    }
                    for(int j=t+1; j<time.size(); j++){
                        time.at(j).push_back(false);
                    }
                }
            }
            else{
                if(((string)(*itTime)).compare(ti.at(t)) == 0){
                    time.at(t).push_back(true);
                    G.push_back(ti.at(t));
                    for(int j=t+1; j<time.size(); j++){
                        time.at(j).push_back(false);
                    }
                }
            }
       }
       for(int p=0; p<po.size(); p++){
            if(p!=0){
                if(((string)(*itPower)).compare(po.at(p)) == 0){
                    power.at(p).push_back(true);
                    G.push_back(po.at(p));
                    for(int j=0; j<p; j++){
                        power.at(j).push_back(false);
                    }
                    for(int j=p+1; j<power.size(); j++){
                        power.at(j).push_back(false);
                    }
                }
            }
            else{
                if(((string)(*itPower)).compare(po.at(p)) == 0){
                    power.at(p).push_back(true);
                    G.push_back(po.at(p));
                    for(int j=p+1; j<power.size(); j++){
                        power.at(j).push_back(false);
                    }
                }
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
    if(gen==0){
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
    if(gen==1){
        for(int i=0; i<fMonths1.size(); i++){
            for(int j=0; j<fMonths1.at(i).size(); j++){
                cout << endl << "fermeture month " << i << " - time " << j << " : ";
                for(int k=0; k<fMonths1.at(i).at(j).size(); k++){
                     cout << fMonths1.at(i).at(j).at(k) << " ";
                }
            }
        }
        for(int i=0; i<fPower1.size(); i++){
            for(int j=0; j<fPower1[i].size(); j++){
                cout << endl << "fermeture power " << i << " - month " << j << " : ";
                for(int k=0; k<fPower1[i].at(j).size(); k++){
                     cout << fPower1[i].at(j).at(k) << " ";
                }
            }
        }
        for(int i=0; i<fTime1.size(); i++){
            for(int j=0; j<fTime1[i].size(); j++){
                cout << endl << "fermeture time " << i << " - power " << j << " : ";
                for(int k=0; k<fTime1[i].at(j).size(); k++){
                     cout << fTime1[i].at(j).at(k) << " ";
                }
            }
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

void displayNextGen(){
    if(gen==1){
        cout << endl << endl << "2nd generation : {";
        for(int i=0; i<secondGen[0].size(); i++){
            cout << "{" << secondGen[0].at(i) << "}, ";
        }
        for(int i=0; i<secondGen[1].size(); i++){
            cout << "{" << secondGen[1].at(i) << "}, ";
        }
        for(int i=0; i<secondGen[2].size(); i++){
            cout << "{" << secondGen[2].at(i) << "}, ";
        }
        cout << "}";
    }
    else if (gen==2){
        cout << endl << endl << "3rd generation : {";
        for(int d=0; d<mo.size(); d++){
            for(int e=0; e<ti.size(); e++){
                for(int i=0; i<thirdGen1[d][e].size(); i++){
                    cout << "{" << thirdGen1[d][e].at(i) << "}, ";
                }
            }
        }
        for(int d=0; d<ti.size(); d++){
            for(int e=0; e<po.size(); e++){
                for(int i=0; i<thirdGen2[d][e].size(); i++){
                    cout << "{" << thirdGen2[d][e].at(i) << "}, ";
                }
            }
        }
        for(int d=0; d<po.size(); d++){
            for(int e=0; e<mo.size(); e++){
                for(int i=0; i<thirdGen3[d][e].size(); i++){
                    cout << "{" << thirdGen3[d][e].at(i) << "}, ";
                }
            }
        }
        cout << "}";
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
    nextGen();
    displayNextGen();
    remplissage();
    displayFermeture();
    nextGen();
    displayNextGen();
    cout << endl << "Mots frequents :";
    for(int i=0; i<motsFrequents.size(); i++){
        cout<<endl<<motsFrequents.at(i);
    }
}
