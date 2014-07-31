#include <iostream>
#include <fstream>
#include <cstdlib>
#include <conio.h>
#include <string>
#include "C:\Users\Tech\Desktop\prg\include\curl\curl.h"
#include "C:\Users\Tech\Desktop\prg\include\curl\curl.h"
using namespace std;
size_t write_data(void *ptr, size_t size, size_t nmemb, FILE *stream)
{
    size_t written;
    written = fwrite(ptr, size, nmemb, stream);
    return written;
}
int main()
{
  int whatdo=0;
  CURL *curl;
    FILE *fp;
    char user[20];
    string type;
    CURLcode res;
    string drive;
    string unc;
    string test;
    char cunc[50];
    char *url = "";
    char outfilename[FILENAME_MAX] = "C:\\bbb.txt";
    curl = curl_easy_init();
  string license="ULICENSED";
    char c=' ';
    string password;
    string adminpass="";
    mainscr:
        system("cls");

    ifstream gunc ("netcfg.cfg");
    {
        gunc>>cunc;
    }
gunc.close();
    ifstream lic ("\\silic.dat");
    {

        getline(lic, license);
    }
    lic.close();

  cout<<"                           S u p e r I m a g e\n\n\n";
  cout<<"   This version of SuperImage is licensed to: "<<license<<".\n\n";
  cout<<"          This version of SuperImage is the Technician Portable Version\n\n";
  cout<<"1.) Burn Windows 98 Disk\n";
  cout<<"2.) Burn Windows 2000 Disk\n";
  cout<<"3.) Burn Windows XP Disk\n";
  cout<<"4.) Burn Windows Vista Disk\n";
  cout<<"5.) Burn Windows 7 Starter Disk\n";
  cout<<"6.) Burn Windows 7 Home Premium Disk\n";
  cout<<"7.) Burn Windows 7 Ultimate Disk\n";
  cout<<"8.) Burn Windows 8 Disk\n";
  cout<<"9.) Burn Windows 8.1 Disk\n";
  cout<<"10.) Download & Burn Custom Image\n";
  cout<<"11.) Admin Menu\n";
  cout<<"Enter Choice. . . ";
  cin>>whatdo;


      system("cls");
      cout<<"\n\n\n\n\n\n\n\n                  Enter SuperImage Agent #. . . ";
      cin>>user;

      ifstream getuser (user);
      {
          getline(getuser, adminpass);
          getline(getuser, type);
      }
      if(adminpass==" ")
      {
          cout<<"\n\n\n\n\n\n\n\n\n\n                   Invalid Agent #";
          Sleep(2500);
          goto mainscr;

      }
      getuser.close();
      cout<<"                  Enter Agent Password. . . ";

do   //Loop until 'Enter' is pressed
         {
         c = getch();
         switch(c)
            {
            case 0:
               {
               getch();
               break;
               }
            case '\b':
               {
               if(password.size() != 0)  //If the password string contains data, erase last character
                  {
                  cout << "\b \b";
                  password.erase(password.size() - 1, 1);
                  }
               break;
               }
            default:
               {
               if(isalnum(c) || ispunct(c))
                  {
                  password += c;
                  cout << "*";
                  }
               break;
               }
            };
         }
      while(c != '\r');
if(password==adminpass)
{
   goto doit;
}
else{
     system("cls");
    cout<<"\n\n\n\n\n\n\n\n\n\n\n                  ! ! ! I N V A L I D   P A S S W O R D ! ! !";
    _beep(200, 3000);

    password="";
    adminpass="";
    goto mainscr;
}
doit:

   password="";
    adminpass="";
system("cls");



if((whatdo==11) && (type!="1"))
    {

        cout<<"\n\n\n\n\n\n\n\n\n         You do not possess the required permission level to access this menu.";
        Sleep(2500);
        goto mainscr;

    }

if((whatdo==11) && (type=="1"))
{
    int adm;
    char agno[20];
    char agpw[100];
    char agty[100];
    cout<<"0.) Exit This Menu\n";
    cout<<"1.) Add New User\n";
    cout<<"2.) Delete User\n";
    cout<<"3.) Enter New Store Name ["<<license<<"]\n";
    cout<<"4.) Change Network Image Location ["<<cunc<<"]\n";
    cout<<"Enter Option: ";
    cin>>adm;

    if(adm==4)
    {

        cout<<"Enter The Network Location to FirstCheck images. . . ";
        cin>>unc;
        ofstream newunc ("netcfg.cfg");
        {
            newunc<<unc;
        }
        newunc.close();
        cout<<"New network location saved!";
        Sleep(2500);
        goto mainscr;

    }

if(adm==0)
{

    goto mainscr;
}
    if(adm==2)
    {

        char del[20];
        cout<<"Enter the Agent # to Delete. . .";
        cin>>del;
        remove(del);
        cout<<"Agent Deleted Successfully!";
        Sleep(2500);
        goto mainscr;
    }

    if(adm==1)
    {

        cout<<"Enter New Agent #. . . ";
        cin>>agno;
        cout<<"Enter New Agent Pw. . . ";
        cin>>agpw;
        cout<<"Enter New Agent Type (0-User .. 1-Admin). . . ";
        cin>>agty;

        ofstream newag (agno);
        {
            newag<<agpw;
            newag<<"\n";
            newag<<agty;
        }
        newag.close();
        cout<<"New Agent Added!";
        Sleep(2500);
        goto mainscr;
    }
}
if(whatdo==10)
{


    if (curl)
    {
        char tempiso[100];
        cout<<"Enter the download name of the image. . . ";
        cin>>tempiso;
        char outfilename[FILENAME_MAX] = "temp.iso";
        fp = fopen(outfilename,"wb");
        curl_easy_setopt(curl, CURLOPT_URL, tempiso);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);
        curl_easy_setopt (curl, CURLOPT_VERBOSE, 1L);
        res = curl_easy_perform(curl);
        curl_easy_cleanup(curl);
    }
        isoburntemp:
        cout<<"Enter the drive to burn to. . . ";
        cin>>drive;
        ofstream burntemp ("burntemp.bat");
        {
            burntemp<<"isoburn /q  "<<drive<<": temp.iso";
        }
        burntemp.close();

}

    ////////

if(whatdo==1)
{

ifstream test98 ("win98.iso");
{
    getline(test98, test);
}
test98.close();
if(test!="")
{
        cout<<"Enter the drive to burn to. . . ";
        cin>>drive;
        ofstream burn98 ("burn98.bat");
        {
            burn98<<"isoburn /q "<<drive<<": win98.iso";
        }
        burn98.close();
        system("burn98.bat");
        goto mainscr;
}

ofstream nunc ("nunc.tmp");
{
    nunc<<cunc<<"win98.iso";
}
nunc.close();
ifstream tmp ("nunc.tmp");
{
    tmp>>cunc;
}
tmp.close();
ifstream test98unc (cunc);
{
    getline(test98unc, test);
}
test98unc.close();
if(test!="")
{
        cout<<"Enter the drive to burn to. . . ";
        cin>>drive;
        ofstream burn98 ("burn98.bat");
        {
            burn98<<"isoburn /q "<<drive<<": "<<cunc;
        }
        burn98.close();
        system("burn98.bat");
        goto mainscr;
}


    if (curl)
    {
        char outfilename[FILENAME_MAX] = "win98.iso";
        fp = fopen(outfilename,"wb");
        curl_easy_setopt(curl, CURLOPT_URL,"www.tygrahmann.com/TCC/Images/OS/Win98.iso");
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);
        curl_easy_setopt (curl, CURLOPT_VERBOSE, 1L);
        res = curl_easy_perform(curl);
        curl_easy_cleanup(curl);
    }
        cout<<"Enter the drive to burn to. . . ";
        cin>>drive;
        ofstream burn98 ("burn98.bat");
        {
            burn98<<"isoburn /q "<<drive<<": win98.iso";
        }
        burn98.close();
        system("burn98.bat");
        goto mainscr;

}
if(whatdo==2)
{


ifstream test2k ("win2k.iso");
{
    getline(test2k, test);
}
test2k.close();
if(test!="")
{
        cout<<"Enter the drive to burn to. . . ";
        cin>>drive;
        ofstream burn2k ("burn2k.bat");
        {
            burn2k<<"isoburn /q "<<drive<<": win2k.iso";
        }
        burn2k.close();
        system("burn2k.bat");
        goto mainscr;
}

ofstream nunc ("nunc.tmp");
{
    nunc<<cunc<<"win2k.iso";
}
nunc.close();
ifstream tmp ("nunc.tmp");
{
    tmp>>cunc;
}
tmp.close();
ifstream test2kunc (cunc);
{
    getline(test2kunc, test);
}
test2kunc.close();
if(test!="")
{
        cout<<"Enter the drive to burn to. . . ";
        cin>>drive;
        ofstream burn2k ("burn2k.bat");
        {
            burn2k<<"isoburn /q "<<drive<<": "<<cunc;
        }
        burn2k.close();
        system("burn2k.bat");
        goto mainscr;
}

    if (curl)
    {
        char outfilename[FILENAME_MAX] = "win2k.iso";
        fp = fopen(outfilename,"wb");
        curl_easy_setopt(curl, CURLOPT_URL,"www.tygrahmann.com/TCC/Images/OS/Win2000.iso");
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);
        curl_easy_setopt (curl, CURLOPT_VERBOSE, 1L);
        res = curl_easy_perform(curl);
        curl_easy_cleanup(curl);
    }
}
if(whatdo==3)
{

ifstream testXP ("winXP.iso");
{
    getline(testXP, test);
}
testXP.close();
if(test!="")
{
        cout<<"Enter the drive to burn to. . . ";
        cin>>drive;
        ofstream burnXP ("burnXP.bat");
        {
            burnXP<<"isoburn /q "<<drive<<": winXP.iso";
        }
        burnXP.close();
        system("burnXP.bat");
        goto mainscr;
}

ofstream nunc ("nunc.tmp");
{
    nunc<<cunc<<"winXP.iso";
}
nunc.close();
ifstream tmp ("nunc.tmp");
{
    tmp>>cunc;
}
tmp.close();
ifstream testXPunc (cunc);
{
    getline(testXPunc, test);
}
testXPunc.close();
if(test!="")
{
        cout<<"Enter the drive to burn to. . . ";
        cin>>drive;
        ofstream burnXP ("burnXP.bat");
        {
            burnXP<<"isoburn /q "<<drive<<": "<<cunc;
        }
        burnXP.close();
        system("burnXP.bat");
        goto mainscr;
}

    if (curl)
    {
        char outfilename[FILENAME_MAX] = "winxp.iso";
        fp = fopen(outfilename,"wb");
        curl_easy_setopt(curl, CURLOPT_URL,"www.tygrahmann.com/TCC/Images/OS/WinXP.iso");
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);
        curl_easy_setopt (curl, CURLOPT_VERBOSE, 1L);
        res = curl_easy_perform(curl);
        curl_easy_cleanup(curl);
    }
}
if(whatdo==4)
{


ifstream testVista ("winVista.iso");
{
    getline(testVista, test);
}
testVista.close();
if(test!="")
{
        cout<<"Enter the drive to burn to. . . ";
        cin>>drive;
        ofstream burnVista ("burnVista.bat");
        {
            burnVista<<"isoburn /q "<<drive<<": winVista.iso";
        }
        burnVista.close();
        system("burnVista.bat");
        goto mainscr;
}

ofstream nunc ("nunc.tmp");
{
    nunc<<cunc<<"winVista.iso";
}
nunc.close();
ifstream tmp ("nunc.tmp");
{
    tmp>>cunc;
}
tmp.close();
ifstream testVistaunc (cunc);
{
    getline(testVistaunc, test);
}
testVistaunc.close();
if(test!="")
{
        cout<<"Enter the drive to burn to. . . ";
        cin>>drive;
        ofstream burnVista ("burnVista.bat");
        {
            burnVista<<"isoburn /q "<<drive<<": "<<cunc;
        }
        burnVista.close();
        system("burnVista.bat");
        goto mainscr;
}


    if (curl)
    {
        char outfilename[FILENAME_MAX] = "winVista.iso";
        fp = fopen(outfilename,"wb");
        curl_easy_setopt(curl, CURLOPT_URL,"www.tygrahmann.com/TCC/Images/OS/WinVista.iso");
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);
        curl_easy_setopt (curl, CURLOPT_VERBOSE, 1L);
        res = curl_easy_perform(curl);
        curl_easy_cleanup(curl);
    }
        cout<<"Enter the drive to burn to. . . ";
        cin>>drive;
        ofstream burnVista ("burnVista.bat");
        {
            burnVista<<"isoburn /q "<<drive<<": winVista.iso";
        }
        burnVista.close();
        system("burnVista.bat");
        goto mainscr;

}
if(whatdo==5)
{


ifstream test7start ("win7start.iso");
{
    getline(test7start, test);
}
test7start.close();
if(test!="")
{
        cout<<"Enter the drive to burn to. . . ";
        cin>>drive;
        ofstream burn7start ("burn7start.bat");
        {
            burn7start<<"isoburn /q "<<drive<<": win7start.iso";
        }
        burn7start.close();
        system("burn7start.bat");
        goto mainscr;
}

ofstream nunc ("nunc.tmp");
{
    nunc<<cunc<<"win7start.iso";
}
nunc.close();
ifstream tmp ("nunc.tmp");
{
    tmp>>cunc;
}
tmp.close();
ifstream test7startunc (cunc);
{
    getline(test7startunc, test);
}
test7startunc.close();
if(test!="")
{
        cout<<"Enter the drive to burn to. . . ";
        cin>>drive;
        ofstream burn7start ("burn7start.bat");
        {
            burn7start<<"isoburn /q "<<drive<<": "<<cunc;
        }
        burn7start.close();
        system("burn7start.bat");
        goto mainscr;
}


    if (curl)
    {
        char outfilename[FILENAME_MAX] = "win7start.iso";
        fp = fopen(outfilename,"wb");
        curl_easy_setopt(curl, CURLOPT_URL,"www.tygrahmann.com/TCC/Images/OS/Win7start.iso");
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);
        curl_easy_setopt (curl, CURLOPT_VERBOSE, 1L);
        res = curl_easy_perform(curl);
        curl_easy_cleanup(curl);
    }
        cout<<"Enter the drive to burn to. . . ";
        cin>>drive;
        ofstream burn7start ("burn7start.bat");
        {
            burn7start<<"isoburn /q "<<drive<<": win7start.iso";
        }
        burn7start.close();
        system("burn7start.bat");
        goto mainscr;

}
if(whatdo==6)
{


ifstream test7HP ("win7HP.iso");
{
    getline(test7HP, test);
}
test7HP.close();
if(test!="")
{
        cout<<"Enter the drive to burn to. . . ";
        cin>>drive;
        ofstream burn7HP ("burn7HP.bat");
        {
            burn7HP<<"isoburn /q "<<drive<<": win7HP.iso";
        }
        burn7HP.close();
        system("burn7HP.bat");
        goto mainscr;
}

ofstream nunc ("nunc.tmp");
{
    nunc<<cunc<<"win7HP.iso";
}
nunc.close();
ifstream tmp ("nunc.tmp");
{
    tmp>>cunc;
}
tmp.close();
ifstream test7HPunc (cunc);
{
    getline(test7HPunc, test);
}
test7HPunc.close();
if(test!="")
{
        cout<<"Enter the drive to burn to. . . ";
        cin>>drive;
        ofstream burn7HP ("burn7HP.bat");
        {
            burn7HP<<"isoburn /q "<<drive<<": "<<cunc;
        }
        burn7HP.close();
        system("burn7HP.bat");
        goto mainscr;
}


    if (curl)
    {
        char outfilename[FILENAME_MAX] = "win7HP.iso";
        fp = fopen(outfilename,"wb");
        curl_easy_setopt(curl, CURLOPT_URL,"www.tygrahmann.com/TCC/Images/OS/Win7HP.iso");
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);
        curl_easy_setopt (curl, CURLOPT_VERBOSE, 1L);
        res = curl_easy_perform(curl);
        curl_easy_cleanup(curl);
    }
        cout<<"Enter the drive to burn to. . . ";
        cin>>drive;
        ofstream burn7HP ("burn7HP.bat");
        {
            burn7HP<<"isoburn /q "<<drive<<": win7HP.iso";
        }
        burn7HP.close();
        system("burn7HP.bat");
        goto mainscr;

}
if(whatdo==7)
{


ifstream test7ult ("win7ult.iso");
{
    getline(test7ult, test);
}
test7ult.close();
if(test!="")
{
        cout<<"Enter the drive to burn to. . . ";
        cin>>drive;
        ofstream burn7ult ("burn7ult.bat");
        {
            burn7ult<<"isoburn /q "<<drive<<": win7ult.iso";
        }
        burn7ult.close();
        system("burn7ult.bat");
        goto mainscr;
}

ofstream nunc ("nunc.tmp");
{
    nunc<<cunc<<"win7ult.iso";
}
nunc.close();
ifstream tmp ("nunc.tmp");
{
    tmp>>cunc;
}
tmp.close();
ifstream test7ultunc (cunc);
{
    getline(test7ultunc, test);
}
test7ultunc.close();
if(test!="")
{
        cout<<"Enter the drive to burn to. . . ";
        cin>>drive;
        ofstream burn7ult ("burn7ult.bat");
        {
            burn7ult<<"isoburn /q "<<drive<<": "<<cunc;
        }
        burn7ult.close();
        system("burn7ult.bat");
        goto mainscr;
}


    if (curl)
    {
        char outfilename[FILENAME_MAX] = "win7ult.iso";
        fp = fopen(outfilename,"wb");
        curl_easy_setopt(curl, CURLOPT_URL,"www.tygrahmann.com/TCC/Images/OS/Win7ult.iso");
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);
        curl_easy_setopt (curl, CURLOPT_VERBOSE, 1L);
        res = curl_easy_perform(curl);
        curl_easy_cleanup(curl);
    }
        cout<<"Enter the drive to burn to. . . ";
        cin>>drive;
        ofstream burn7ult ("burn7ult.bat");
        {
            burn7ult<<"isoburn /q "<<drive<<": win7ult.iso";
        }
        burn7ult.close();
        system("burn7ult.bat");
        goto mainscr;

}
if(whatdo==8)
{

ifstream test8 ("win8.iso");
{
    getline(test8, test);
}
test8.close();
if(test!="")
{
        cout<<"Enter the drive to burn to. . . ";
        cin>>drive;
        ofstream burn8 ("burn8.bat");
        {
            burn8<<"isoburn /q "<<drive<<": win8.iso";
        }
        burn8.close();
        system("burn8.bat");
        goto mainscr;
}

ofstream nunc ("nunc.tmp");
{
    nunc<<cunc<<"win8.iso";
}
nunc.close();
ifstream tmp ("nunc.tmp");
{
    tmp>>cunc;
}
tmp.close();
ifstream test8unc (cunc);
{
    getline(test8unc, test);
}
test8unc.close();
if(test!="")
{
        cout<<"Enter the drive to burn to. . . ";
        cin>>drive;
        ofstream burn8 ("burn8.bat");
        {
            burn8<<"isoburn /q "<<drive<<": "<<cunc;
        }
        burn8.close();
        system("burn8.bat");
        goto mainscr;
}


    if (curl)
    {
        char outfilename[FILENAME_MAX] = "win8.iso";
        fp = fopen(outfilename,"wb");
        curl_easy_setopt(curl, CURLOPT_URL,"www.tygrahmann.com/TCC/Images/OS/Win8.iso");
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);
        curl_easy_setopt (curl, CURLOPT_VERBOSE, 1L);
        res = curl_easy_perform(curl);
        curl_easy_cleanup(curl);
    }
        cout<<"Enter the drive to burn to. . . ";
        cin>>drive;
        ofstream burn8 ("burn8.bat");
        {
            burn8<<"isoburn /q "<<drive<<": win8.iso";
        }
        burn8.close();
        system("burn8.bat");
        goto mainscr;

}
if(whatdo==9)
{



ifstream test81 ("win81.iso");
{
    getline(test81, test);
}
test81.close();
if(test!="")
{
        cout<<"Enter the drive to burn to. . . ";
        cin>>drive;
        ofstream burn81 ("burn81.bat");
        {
            burn81<<"isoburn /q "<<drive<<": win81.iso";
        }
        burn81.close();
        system("burn81.bat");
        goto mainscr;
}

ofstream nunc ("nunc.tmp");
{
    nunc<<cunc<<"win81.iso";
}
nunc.close();
ifstream tmp ("nunc.tmp");
{
    tmp>>cunc;
}
tmp.close();
ifstream test81unc (cunc);
{
    getline(test81unc, test);
}
test81unc.close();
if(test!="")
{
        cout<<"Enter the drive to burn to. . . ";
        cin>>drive;
        ofstream burn81 ("burn81.bat");
        {
            burn81<<"isoburn /q "<<drive<<": "<<cunc;
        }
        burn81.close();
        system("burn81.bat");
        goto mainscr;
}


    if (curl)
    {
        char outfilename[FILENAME_MAX] = "win81.iso";
        fp = fopen(outfilename,"wb");
        curl_easy_setopt(curl, CURLOPT_URL,"www.tygrahmann.com/TCC/Images/OS/Win81.iso");
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);
        curl_easy_setopt (curl, CURLOPT_VERBOSE, 1L);
        res = curl_easy_perform(curl);
        curl_easy_cleanup(curl);
    }
        cout<<"Enter the drive to burn to. . . ";
        cin>>drive;
        ofstream burn81 ("burn81.bat");
        {
            burn81<<"isoburn /q "<<drive<<": win81.iso";
        }
        burn81.close();
        system("burn81.bat");
        goto mainscr;

}
}
