#include <iostream>
#include <windows.h>
#include <mysql.h>
#include <sstream>
#include <string>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <unistd.h>
#include <cstdlib>
#include <ctime>

using namespace std;

const char* hostname    = "localhost";
const char* username    = "root";
const char* password    = "";
const char* database    = "essentialmode";
unsigned int port       = 3306;
const char* unixsocket  = NULL;
unsigned long clientflag = 0;

void ClearCMDShit(){
    system("CLS");
}

void InsertPeopleInformation(MYSQL* conn) {
    ClearCMDShit();
    int HasNotQueryExecuted = 0;
    int Option;
    int Age;
    stringstream  QueryString;
    string firstName, lastName, BirthDay, CodeMeli, Year, Month, Day, phoneNumber;
    cout << "Lotfan Esm Bimar Ra Vared Konid: ";
    cin >> firstName;
    ClearCMDShit();
    cout << "Lotfan Nam Khanevadegi Bimar Ra Vared Konid: ";
    cin >> lastName;
    ClearCMDShit();
    cout << "Lotfan Code Meli Bimar Ra Vared Konid: ";
    cin >> CodeMeli;
    ClearCMDShit();
    cout << "Lotfan Saal Tavlod Bimar Ra Vared Konid: ";
    cin >> Year;
    ClearCMDShit();
    cout << "Lotfan Maah Tavlod Bimar Ra Vared Konid: ";
    cin >> Month;
    ClearCMDShit();
    cout << "Lotfan Rooz Tavlod Bimar Ra Vared Konid: ";
    cin >> Day;
    ClearCMDShit();
    cout << "Lotfan Shomare Mobile Bimar Ra Vared Konid: ";
    cin >> phoneNumber;
    ClearCMDShit();
    BirthDay = ""+Year+"-"+Month+"-"+Day+"";
    Age = 1400 - stoi(Year);
    string UserAge = to_string(Age);
    ClearCMDShit();
    do {
        ClearCMDShit();
        cout << "---------------Aya Etelaat Vared Shode Sahih Ast?-----------------------------"<<endl<<endl;
        cout << "           Naam:            "<< firstName<<endl;
        cout << "           Nam Khanevadegi: "<< lastName<<endl;
        cout << "           Code Meli:       "<< CodeMeli<<endl;
        cout << "           Tarikh Tavalod:  "<< Year<<"/"<<Month<<"/"<<Day<<endl;
        cout << "           Sen:             "<< Age<<endl;
        cout << "-------------------------------------------------------------------------------"<<endl<<endl;
        cout << "  [1] - Bale, Etelaat Vared Shode Sahih Ast."<<endl;
        cout << "  [2] - Kheyr, Eteelat Vared Shode Sahih Nist Va Bayad Eslah Shavad"<<endl;
        cin >> Option;
    } while (Option !=1 && Option !=2);
        if (Option == 1){
            QueryString << "INSERT INTO bimar (firstName, lastName, CodeMeli, BirthDay, Age, phoneNumber) VALUES ('"+firstName+"', '"+lastName+"', '"+CodeMeli+"', '"+BirthDay+"', '"+UserAge+"', '"+phoneNumber+"')";
            string Query = QueryString.str();
            const char* Element = Query.c_str();
            HasNotQueryExecuted = mysql_query(conn, Element);
            if(!HasNotQueryExecuted){
                ClearCMDShit();
                cout << "Etelaat Vared Shode Ba Movafaghait Zakhire Shod";
                sleep(10);
            }else{
                ClearCMDShit();
                cout << "Code e Meli Vared Shode Tekrari Ast!!!"<< endl;
                cout << "Etelaat Ra Dobare Vared Konid...";
                sleep(10);
                InsertPeopleInformation(conn);
            }
        }else{
            InsertPeopleInformation(conn);
        }
}

void InsertDoctorInformation(MYSQL* conn){
    ClearCMDShit();
    int HasNotQueryExecuted = 0;
    int Option;
    stringstream  QueryString;
    string firstName, lastName, CodeMeli;
    cout << "Lotfan Esm Pezeshk Ra Vared Konid: ";
    cin >> firstName;
    ClearCMDShit();
    cout << "Lotfan Nam Khanevadegi Pezeshk Ra Vared Konid: ";
    cin >> lastName;
    ClearCMDShit();
    cout << "Lotfan Code Meli Pezeshk Ra Vared Konid: ";
    cin >> CodeMeli;
    ClearCMDShit();
    do {
        ClearCMDShit();
        cout << "---------------Aya Etelaat Vared Shode Sahih Ast?-----------------------------"<<endl<<endl;
        cout << "           Naam:            "<< firstName<<endl;
        cout << "           Nam Khanevadegi: "<< lastName<<endl;
        cout << "           Code Meli:       "<< CodeMeli<<endl;
        cout << "-------------------------------------------------------------------------------"<<endl<<endl;
        cout << "  [1] - Bale, Etelaat Vared Shode Sahih Ast."<<endl;
        cout << "  [2] - Kheyr, Eteelat Vared Shode Sahih Nist Va Bayad Eslah Shavad"<<endl;
        cin >> Option;
    } while (Option !=1 && Option !=2);
        if (Option == 1){
            QueryString << "INSERT INTO pezeshk (firstName, lastName, CodeMeli) VALUES ('"+firstName+"', '"+lastName+"', '"+CodeMeli+"')";
            string Query = QueryString.str();
            const char* Element = Query.c_str();
            HasNotQueryExecuted = mysql_query(conn, Element);
            if(!HasNotQueryExecuted){
                ClearCMDShit();
                cout << "Etelaat Vared Shode Ba Movafaghait Zakhire Shod";
                sleep(10);
            }else{
                ClearCMDShit();
                cout << "Code e Meli Vared Shode Tekrari Ast!!!"<<endl;
                cout << "Etelaat Ra Dobare Vared Konid...";
                sleep(10);
                InsertDoctorInformation(conn);
            }
        }else{
            InsertDoctorInformation(conn);
        }
}

void CreateNobat(MYSQL* conn){
    ClearCMDShit();
    time_t rawtime;
    struct tm * timeinfo;
    int HasNotQueryExecuted = 0;
    char buffer[80];
    time (&rawtime);
    timeinfo = localtime(&rawtime);
    strftime(buffer,sizeof(buffer),"%d-%m-%Y %H:%M:%S",timeinfo);
    string str(buffer);
    stringstream  QueryString;
    string CodeMeli;
    string CodeMeliPezeshk;
    string Year = "1400";
    string Second = "00";
    string Month, Day, Hour, Minute;
    string Duration;
    cout << "Lotfan Code Meli Bimar Ra Vared Konid: ";
    cin >> CodeMeli;
    ClearCMDShit();
    cout << "Lotfan Code Meli Pezeshk Ra Vared Konid: ";
    cin >> CodeMeliPezeshk;
    ClearCMDShit();
    cout << "Lotfan Maah Nobat Ra Vared Konid:  ";
    cin >> Month;
    ClearCMDShit();
    cout << "Lotfan Rooz Nobat Ra Vared Konid:  ";
    cin >> Day;
    ClearCMDShit();
    cout << "Lotfan Saat Nobat Ra Vared Konid:  ";
    cin >> Hour;
    ClearCMDShit();
    cout << "Lotfan Daghighe Nobat Ra Vared Konid:  ";
    cin >> Minute;
    ClearCMDShit();
    cout << "Lotfan Moddat Zaman Nobat Ra Vared Konid:  ";
    cin >> Duration;
    string Enter = Year+"-"+Month+"-"+Day+" "+Hour+":"+Minute+":"+Second;
    string Exit = Year+"-"+Month+"-"+Day+" "+Hour+":"+to_string(stoi(Minute)+10)+":"+Second;
    int Option;
    do {
        ClearCMDShit();
        cout << "---------------Aya Etelaat Vared Shode Sahih Ast?-----------------------------"<<endl<<endl;
        cout << "           Code Meli Bimar:   "<< CodeMeli<<endl;
        cout << "           Code Meli Pezeshk: "<< CodeMeliPezeshk<<endl;
        cout << "           Tarikh Vorud:      "<< Year+"-"+Month+"-"+Day+" "+Hour+":"+Minute+":"+Second<<endl;
        cout << "           Tarikh Khoruj:     "<< Year+"-"+Month+"-"+Day+" "+Hour+":"+to_string(stoi(Minute)+stoi(Duration))+":"+Second<<endl;
        cout << "-------------------------------------------------------------------------------"<<endl<<endl;
        cout << "  [1] - Bale, Etelaat Vared Shode Sahih Ast."<<endl;
        cout << "  [2] - Kheyr, Eteelat Vared Shode Sahih Nist Va Bayad Eslah Shavad"<<endl;
        cin >> Option;
    } while (Option !=1 && Option !=2);
        if (Option == 1){
            QueryString << "INSERT INTO nobat (Bimar, Pezeshk, EnterTime, ExitTime) VALUES ('"+CodeMeli+"', '"+CodeMeliPezeshk+"', '"+Enter+"', '"+Exit+"')";
            string Query = QueryString.str();
            const char* Element = Query.c_str();
            HasNotQueryExecuted = mysql_query(conn, Element);
            cout << "Etelaat Ba Movafaghiat Zakhire Shod";
        }else{
            CreateNobat(conn);
        }
}

void RemoveNobat(MYSQL* conn){
    ClearCMDShit();
    stringstream  QueryString;
    int HasNotQueryExecuted = 0;
    string firstName, lastName, CodeMeli;
    cout << "Lotfan Code Meli Bimar Ra Vared Konid: ";
    cin >> CodeMeli;
    QueryString << "DELETE FROM nobat WHERE Bimar = '"+CodeMeli+"'";
    string Query = QueryString.str();
    const char* Element = Query.c_str();
    HasNotQueryExecuted = mysql_query(conn, Element);
    cout << endl<<"Nobat Baraye CodeMeli: ["+CodeMeli+"] Laghv Shod"<<endl;
}

void NobatThread(MYSQL* conn){
    ClearCMDShit();
    cout << "----------------Lotfan Entekhab Konid-----------------------"<<endl<<endl;
    cout << "            [1] - Sabt Nobat"<<endl;
    cout << "            [2] - Laghv Nobat"<<endl<<endl;
    cout << "-------------------------------------------------------------"<<endl;
    int Option;
    cin >> Option;
    switch (Option) {
        case 1:
            CreateNobat(conn);
            break;
        case 2:
            RemoveNobat(conn);
            break;
        default:
            NobatThread(conn);
            break;
    }
}

void SearchByNationalCode(MYSQL* conn){
    ClearCMDShit();
    int HasNotQueryExecuted = 0;
    int Counter = 0;
    int Option;
    string CodeMeli;
    stringstream QueryString;
    ClearCMDShit();
    cout << "Lotfan Code Meli Shakhs Ra Vared Konid: ";
    cin >> CodeMeli;
    do {
        ClearCMDShit();
        cout << "----------------Lotfan Entekhab Konid-----------------------"<<endl<<endl;
        cout << "            [1] - Jostejooye Etelaat Pezeshk"<<endl;
        cout << "            [2] - Jostejooye Etelaat Bimar"<<endl<<endl;
        cout << "-------------------------------------------------------------"<<endl;
        cin >> Option;
    } while (Option !=1 && Option !=2);
        if (Option == 1){
            QueryString << "SELECT * FROM pezeshk WHERE CodeMeli = '"+CodeMeli+"'";
        }else{
            QueryString << "SELECT * FROM bimar WHERE CodeMeli = '"+CodeMeli+"'";
        }
    string Query = QueryString.str();
    const char* Element = Query.c_str();
    HasNotQueryExecuted = mysql_query(conn, Element);
    ClearCMDShit();
    MYSQL_ROW row;
    MYSQL_RES* res;
    res = mysql_store_result(conn);
    int count = mysql_num_fields(res);
    cout << "\t[Number]\t[Name]\t[lastName]\t[NationalCode]\t[BirthDay]\t[Age]\t[Mobile]"<<endl;
    while(row = mysql_fetch_row(res)){
        for(int i=0;i<count;i++){
            cout<<"\t"<<row[i];
            Counter = Counter + 1;
        }
        cout<<endl;
    }
    if(Counter<2)
    {
        ClearCMDShit();
        cout <<endl<< "Hich Shakhsi Ba In Moshakhasat Peyda Nashod!!"<<endl;
        cout <<endl<< "Lotfan Etelaat Ra Dobare Vared Konid..."<<endl;
        sleep(5);
        SearchByNationalCode(conn);
    }
}

void SearchByFirstName(MYSQL* conn){
    ClearCMDShit();
    int HasNotQueryExecuted = 0;
    int Counter = 0;
    int Option;
    string firstName;
    stringstream QueryString;
    ClearCMDShit();
    cout << "Lotfan Naam Fard Ra Vared Konid: ";
    cin >> firstName;
    do {
        ClearCMDShit();
        cout << "----------------Lotfan Entekhab Konid-----------------------"<<endl<<endl;
        cout << "            [1] - Jostejooye Etelaat Pezeshk"<<endl;
        cout << "            [2] - Jostejooye Etelaat Bimar"<<endl<<endl;
        cout << "-------------------------------------------------------------"<<endl;
        cin >> Option;
    } while (Option !=1 && Option !=2);
        if (Option == 1){
            QueryString << "SELECT * FROM pezeshk WHERE firstName = '"+firstName+"'";
        }else{
            QueryString << "SELECT * FROM bimar WHERE firstName = '"+firstName+"'";
        }
    string Query = QueryString.str();
    const char* Element = Query.c_str();
    HasNotQueryExecuted = mysql_query(conn, Element);
    ClearCMDShit();
    MYSQL_ROW row;
    MYSQL_RES* res;
    res = mysql_store_result(conn);
    int count = mysql_num_fields(res);
    cout << "\t[Number]\t[Name]\t[lastName]\t[NationalCode]\t[BirthDay]\t[Age]\t[Mobile]"<<endl;
    while(row = mysql_fetch_row(res)){
        for(int i=0;i<count;i++){
            cout<<"\t"<<row[i];
            Counter = Counter + 1;
        }
        cout<<endl;
    }
    if(Counter<2)
    {
        ClearCMDShit();
        cout <<endl<< "Hich Shakhsi Ba In Moshakhasat Peyda Nashod!!"<<endl;
        sleep(5);
        SearchByFirstName(conn);
    }
}

void SearchByLastName(MYSQL* conn){
    ClearCMDShit();
    int HasNotQueryExecuted = 0;
    int Counter = 0;
    int Option;
    string lastName;
    stringstream QueryString;
    ClearCMDShit();
    cout << "Lotfan Naam Fard Ra Vared Konid: ";
    cin >> lastName;
    do {
        ClearCMDShit();
        cout << "----------------Lotfan Entekhab Konid-----------------------"<<endl<<endl;
        cout << "            [1] - Jostejooye Etelaat Pezeshk"<<endl;
        cout << "            [2] - Jostejooye Etelaat Bimar"<<endl<<endl;
        cout << "-------------------------------------------------------------"<<endl;
        cin >> Option;
    } while (Option !=1 && Option !=2);
        if (Option == 1){
            QueryString << "SELECT * FROM pezeshk WHERE lastName = '"+lastName+"'";
        }else{
            QueryString << "SELECT * FROM bimar WHERE lastName = '"+lastName+"'";
        }
    string Query = QueryString.str();
    const char* Element = Query.c_str();
    HasNotQueryExecuted = mysql_query(conn, Element);
    ClearCMDShit();
    MYSQL_ROW row;
    MYSQL_RES* res;
    res = mysql_store_result(conn);
    int count = mysql_num_fields(res);
    cout << "\t[Number]\t[Name]\t[lastName]\t[NationalCode]\t[BirthDay]\t[Age]\t[Mobile]"<<endl;
    while(row = mysql_fetch_row(res)){
        for(int i=0;i<count;i++){
            cout<<"\t"<<row[i];
            Counter = Counter + 1;
        }
        cout<<endl;
    }
    if(Counter<2)
    {
        ClearCMDShit();
        cout <<endl<< "Hich Shakhsi Ba In Moshakhasat Peyda Nashod!!"<<endl;
        sleep(5);
        SearchByFirstName(conn);
    }
}

void SearchByAge(MYSQL* conn){
    ClearCMDShit();
    int HasNotQueryExecuted = 0;
    int Counter = 0;
    cout << "Lotfan Saal Tavalod Fard Ra Vared Konid: ";
    string Age;
    cin >> Age;
    stringstream QueryString;
    QueryString << "SELECT * FROM bimar WHERE Age = '"+Age+"'";
    string Query = QueryString.str();
    const char* Element = Query.c_str();
    HasNotQueryExecuted = mysql_query(conn, Element);
    ClearCMDShit();
    MYSQL_ROW row;
    MYSQL_RES* res;
    res = mysql_store_result(conn);
    int count = mysql_num_fields(res);
    cout << "\t[Number]\t[Name]\t[lastName]\t[NationalCode]\t[BirthDay]\t[Age]\t[Mobile]"<<endl;
    while(row = mysql_fetch_row(res)){
        for(int i=0;i<count;i++){
            cout<<"\t"<<row[i];
            Counter = Counter + 1;
        }
        cout<<endl;
    }
    if(Counter<2)
    {
        ClearCMDShit();
        cout <<endl<< "Hich Shakhsi Ba In Moshakhasat Peyda Nashod!!"<<endl;
        sleep(5);
        SearchByFirstName(conn);
    }
}

void SearchByVizitNumber(MYSQL* conn){
    ClearCMDShit();
    cout << "Lotfan Shomare Vizit Ra Vared Konid: ";
    string vizNumberr;
    cin >> vizNumberr;
    stringstream QueryString;
    QueryString << "SELECT * FROM vizit WHERE id = '"+vizNumberr+"'";
    int HasNotQueryExecuted = 0;
    int Counter = 0;
    string Query = QueryString.str();
    const char* Element = Query.c_str();
    HasNotQueryExecuted = mysql_query(conn, Element);
    ClearCMDShit();
    MYSQL_ROW row;
    MYSQL_RES* res;
    res = mysql_store_result(conn);
    int count = mysql_num_fields(res);
    cout << "\t[Number]\t[Bimar]\t[Pezeshk]\t[Vorud]\t[Khoruj]"<<endl;
    while(row = mysql_fetch_row(res)){
        for(int i=0;i<count;i++){
            cout<<"\t"<<row[i];
            Counter = Counter + 1;
        }
        cout<<endl;
    }
    if(Counter<2)
    {
        ClearCMDShit();
        cout <<endl<< "Hich Shakhsi Ba In Moshakhasat Peyda Nashod!!"<<endl;
        sleep(5);
        SearchByVizitNumber(conn);
    }
}

void SearchByNobatNumber(MYSQL* conn){
    ClearCMDShit();
    cout << "Lotfan Shomare Nobat Ra Vared Konid: ";
    string vizNumberr;
    cin >> vizNumberr;
    stringstream QueryString;
    QueryString << "SELECT * FROM nobat WHERE id = '"+vizNumberr+"'";
    int HasNotQueryExecuted = 0;
    int Counter = 0;
    string Query = QueryString.str();
    const char* Element = Query.c_str();
    HasNotQueryExecuted = mysql_query(conn, Element);
    ClearCMDShit();
    MYSQL_ROW row;
    MYSQL_RES* res;
    res = mysql_store_result(conn);
    int count = mysql_num_fields(res);
    cout << "\t[Number]\t[Bimar]\t[Pezeshk]\t[Vorud]\t[Khoruj]"<<endl;
    while(row = mysql_fetch_row(res)){
        for(int i=0;i<count;i++){
            cout<<"\t"<<row[i];
            Counter = Counter + 1;
        }
        cout<<endl;
    }
    if(Counter<2)
    {
        ClearCMDShit();
        cout <<endl<< "Hich Shakhsi Ba In Moshakhasat Peyda Nashod!!"<<endl;
        sleep(5);
        SearchByVizitNumber(conn);
    }
}

void VizitThread(MYSQL* conn){
    ClearCMDShit();
    time_t rawtime;
    struct tm * timeinfo;
    int HasNotQueryExecuted = 0;
    char buffer[80];
    time (&rawtime);
    timeinfo = localtime(&rawtime);
    strftime(buffer,sizeof(buffer),"%d-%m-%Y %H:%M:%S",timeinfo);
    string str(buffer);
    stringstream  QueryString;
    string CodeMeli;
    string CodeMeliPezeshk;
    string Duration;
    cout << "Lotfan Code Meli Bimar Ra Vared Konid: ";
    cin >> CodeMeli;
    ClearCMDShit();
    cout << "Lotfan Code Meli Pezeshk Ra Vared Konid: ";
    cin >> CodeMeliPezeshk;
    ClearCMDShit();
    cout << "Lotfan Moddat Zaman Nobat Ra Vared Konid:  ";
    cin >> Duration;
    int Option;
    do {
        ClearCMDShit();
        cout << "---------------Aya Etelaat Vared Shode Sahih Ast?-----------------------------"<<endl<<endl;
        cout << "           Code Meli Bimar:   "<< CodeMeli<<endl;
        cout << "           Code Meli Pezeshk: "<< CodeMeliPezeshk<<endl;
        cout << "           Tarikh Vorud:      "<< str<<endl;
        cout << "           Tarikh Khoruj:     "<< str<<endl;
        cout << "-------------------------------------------------------------------------------"<<endl<<endl;
        cout << "  [1] - Bale, Etelaat Vared Shode Sahih Ast."<<endl;
        cout << "  [2] - Kheyr, Eteelat Vared Shode Sahih Nist Va Bayad Eslah Shavad"<<endl;
        cin >> Option;
    } while (Option !=1 && Option !=2);
        if (Option == 1){
            QueryString << "INSERT INTO vizit (Bimar, Pezeshk, EnterTime, ExitTime) VALUES ('"+CodeMeli+"', '"+CodeMeliPezeshk+"', '"+str+"', '"+str+"')";
            string Query = QueryString.str();
            const char* Element = Query.c_str();
            HasNotQueryExecuted = mysql_query(conn, Element);
            cout << "Etelaat Ba Movafaghiat Zakhire Shod";
        }else{
            CreateNobat(conn);
        }
}

void SearchFromDatabase(MYSQL* conn){
    ClearCMDShit();
    cout << "----------------Lotfan Nahve Jostejoo Ra Entekhab Konid-----------------------"<<endl<<endl;
    cout << "            [1] - Jostejoo Bar Asas Code Meli"<<endl;
    cout << "            [2] - Jostejoo Bar Asas Naam"<<endl;
    cout << "            [3] - Jostejoo Bar Asas Naam Khanavedgi"<<endl;
    cout << "            [4] - Jostejoo Bar Asas Sen"<<endl;
    cout << "            [5] - Jostejoo Bar Asas Shomare Vizit"<<endl;
    cout << "            [6] - Jostejoo Bar Asas Shomare Nobat"<<endl<<endl;
    cout << "-------------------------------------------------------------"<<endl;
    int Option;
    cin >> Option;
    switch (Option) {
        case 1:
            SearchByNationalCode(conn);
            break;
        case 2:
            SearchByFirstName(conn);
            break;
        case 3:
            SearchByLastName(conn);
            break;
        case 4:
            SearchByAge(conn);
            break;
        case 5:
            SearchByVizitNumber(conn);
            break;
        case 6:
            SearchByNobatNumber(conn);
            break;
        default:
            SearchFromDatabase(conn);
            break;
    }
}

void RemoveBimar(MYSQL* conn){
    ClearCMDShit();
    stringstream  QueryString;
    int HasNotQueryExecuted = 0;
    string firstName, lastName, CodeMeli;
    cout << "Lotfan Code Meli Bimar Ra Vared Konid: ";
    cin >> CodeMeli;
    QueryString << "DELETE FROM bimar WHERE CodeMeli = '"+CodeMeli+"'";
    string Query = QueryString.str();
    const char* Element = Query.c_str();
    HasNotQueryExecuted = mysql_query(conn, Element);
    cout << endl<<"Bimar Ba CodeMeli: ["+CodeMeli+"] Hazf Shod"<<endl;
}

void RemoveDoctor(MYSQL* conn){
    ClearCMDShit();
    stringstream  QueryString;
    int HasNotQueryExecuted = 0;
    string firstName, lastName, CodeMeli;
    cout << "Lotfan Code Meli Pezeshk Ra Vared Konid: ";
    cin >> CodeMeli;
    QueryString << "DELETE FROM pezeshk WHERE CodeMeli = '"+CodeMeli+"'";
    string Query = QueryString.str();
    const char* Element = Query.c_str();
    HasNotQueryExecuted = mysql_query(conn, Element);
    cout << endl<<"Pezeshk Ba CodeMeli: ["+CodeMeli+"] Hazf Shod"<<endl;
}

void RemoveVizit(MYSQL* conn){
    ClearCMDShit();
    stringstream  QueryString;
    int HasNotQueryExecuted = 0;
    string firstName, lastName, CodeMeli;
    cout << "Lotfan Shomare Vizit Ra Vared Konid: ";
    cin >> CodeMeli;
    QueryString << "DELETE FROM vizit WHERE id = '"+CodeMeli+"'";
    string Query = QueryString.str();
    const char* Element = Query.c_str();
    HasNotQueryExecuted = mysql_query(conn, Element);
    cout << endl<<"Vizit Ba Shomare: ["+CodeMeli+"] Hazf Shod"<<endl;
}

void ManageInformations(MYSQL* conn){
    ClearCMDShit();
    cout << "----------------Lotfan Entekhab Konid-----------------------"<<endl<<endl;
    cout << "            [1] - Hazf Bimar"<<endl;
    cout << "            [2] - Hazf Pezeshk"<<endl;
    cout << "            [3] - Hazf Vizit"<<endl;
    cout << "-------------------------------------------------------------"<<endl;
    int Option;
    cin >> Option;
    switch (Option) {
        case 0:
            ClearCMDShit();
            ManageInformations(conn);
            break;
        case 1:
            RemoveBimar(conn);
            break;
        case 2:
            RemoveDoctor(conn);
            break;
        case 3:
            RemoveVizit(conn);
            break;
        default:
            ClearCMDShit();
            cout<<"Error: Adad Vared Shode Sahih Nist, Yek Adad Az 1 ta 6 Entekhab Konid"<<endl<<endl;
            ManageInformations(conn);
            break;
    }
}

MainMenuThread(MYSQL* conn){
    cout << "----------------Lotfan Entekhab Konid-----------------------"<<endl<<endl;
    cout << "            [1] - Sabt Bimar Jadid"<<endl;
    cout << "            [2] - Sabt Pezeshk"<<endl;
    cout << "            [3] - Nobat Dehi"<<endl;
    cout << "            [4] - Sabt Vizit"<<endl;
    cout << "            [5] - Virayesh Etelaat"<<endl;
    cout << "            [6] - Jostojooye Pishrafte"<<endl<<endl;
    cout << "-------------------------------------------------------------"<<endl;
    int Option;
    cin >> Option;
    switch (Option) {
        case 0:
            ClearCMDShit();
            MainMenuThread(conn);
            break;
        case 1:
            InsertPeopleInformation(conn);
            break;
        case 2:
            InsertDoctorInformation(conn);
            break;
        case 3:
            NobatThread(conn);
            break;
        case 4:
            VizitThread(conn);
            break;
        case 5:
            ManageInformations(conn);
            break;
        case 6:
            SearchFromDatabase(conn);
            break;
        default:
            ClearCMDShit();
            cout<<"Error: Adad Vared Shode Sahih Nist, Yek Adad Az 1 ta 6 Entekhab Konid"<<endl<<endl;
            MainMenuThread(conn);
            break;
    }
}

MYSQL* ConnectDatabase(){
    MYSQL* conn;
    conn = mysql_init(0);
    conn = mysql_real_connect(conn, hostname, username, password, database, port, unixsocket, clientflag);
    if(conn){
        return conn;
    }
    else{
        cout<<"Moshkeli Dar Ertebat Ba Database Vojud Darad, Lotfan Be Poshtibani Etelaa Dahid. "<<endl;
        sleep(10);
        exit(1);
    }
}

void BimarSQL(MYSQL* conn) {
    int HasNotQueryExecuted = 0;
    stringstream  QueryString;
    QueryString << "CREATE TABLE IF NOT EXISTS bimar(id INT auto_increment, firstName VARCHAR(255), lastName VARCHAR(255), CodeMeli VARCHAR(255) NOT NULL, BirthDay VARCHAR(255), Age VARCHAR(255), phoneNumber VARCHAR(255), primary key (CodeMeli), KEY id (id))";
    string Query = QueryString.str();
    const char* Element = Query.c_str();
    HasNotQueryExecuted = mysql_query(conn, Element);
}

void PezeshkSQL(MYSQL* conn) {
    int HasNotQueryExecuted = 0;
    stringstream  QueryString;
    QueryString << "CREATE TABLE IF NOT EXISTS pezeshk (id INT auto_increment, firstName VARCHAR(255), lastName VARCHAR(255), CodeMeli VARCHAR(255) NOT NULL, primary key (CodeMeli), KEY id (id))";
    string Query = QueryString.str();
    const char* Element = Query.c_str();
    HasNotQueryExecuted = mysql_query(conn, Element);
}

void NobatSQL(MYSQL* conn) {
    int HasNotQueryExecuted = 0;
    stringstream  QueryString;
    QueryString << "CREATE TABLE IF NOT EXISTS nobat (id INT auto_increment, Bimar VARCHAR(255), Pezeshk VARCHAR(255), EnterTime VARCHAR(255), primary key (id))";
    string Query = QueryString.str();
    const char* Element = Query.c_str();
    HasNotQueryExecuted = mysql_query(conn, Element);
}

void VizitSQL(MYSQL* conn) {
    int HasNotQueryExecuted = 0;
    stringstream  QueryString;
    QueryString << "CREATE TABLE IF NOT EXISTS vizit (id INT auto_increment, Bimar VARCHAR(255), Pezeshk VARCHAR(255), EnterTime VARCHAR(255), ExitTime VARCHAR(255), primary key (id))";
    string Query = QueryString.str();
    const char* Element = Query.c_str();
    HasNotQueryExecuted = mysql_query(conn, Element);
}

int main() {
	MYSQL* conn = ConnectDatabase();
    BimarSQL(conn);
    PezeshkSQL(conn);
    NobatSQL(conn);
    VizitSQL(conn);
    while (true){
        ClearCMDShit();
        MainMenuThread(conn);
    }
	return 0;
}
