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
    //variables support
vector<int> sMonths(12, 0), sTime(3, 0), sPower(5, 0);
vector<int> sMonths2[3], sTime2[5], sPower2[12];
    //variables 2nd gen
vector<string> secondGen[3];
vector<string> motsFrequents;


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
    G.clear();
}

void nextGen(){
    for(int m=0; m<sMonths.size(); m++){
        if(sMonths.at(m)>=MINSUP*monthData.size()){
            motsFrequents.push_back(fMonths.at(m).at(0)+" "+fMonths.at(m).at(1)+" "+fMonths.at(m).at(2)); // à remplacer par une boucle tant que fMonths non vide
            secondGen[0].push_back(mo.at(m));
        }
    }
    for(int t=0; t<sTime.size(); t++){
        if(sTime.at(t)>=MINSUP*timeData.size()){
            motsFrequents.push_back(fTime.at(t).at(0)+" "+fTime.at(t).at(1)+" "+fTime.at(t).at(2)); //idem
            secondGen[1].push_back(ti.at(t));
        }
    }
    for(int p=0; p<sPower.size(); p++){
        if(sPower.at(p)>=MINSUP*powerData.size()){
            motsFrequents.push_back(fPower.at(p).at(0)+" "+fPower.at(p).at(1)+" "+fPower.at(p).at(2)); //idem
            secondGen[2].push_back(po.at(p));
        }
    } //lorqu'il y a 1 time ET 1 power OU 1 time ET 1 mois OU 1 mois ET 1 power à true et appartenant à secondGen -> zou on remplit G pareil qu'avant
    //pour la fermeture il faudra mettre une condition dans fermeture() pour voir si c'est la 1è ou 2ègen qu'on va gérer
    // pour la 2è gen on remplira un vecteur de vecteurs de vecteurs
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

void displaySecondGen(){

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
