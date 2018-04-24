#include<iostream>
#include<string>
#include<fstream>
#include<conio.h>
#include<cctype>
#include<windows.h>
#include<time.h>
using namespace std;
void CheckBookingRecord();
void changepoints();
void booking();
void cabstatusfunc();
int time(int);
int time1(int);
ofstream MYFILE;
string NewWorkerName;
string NewWorkerPassword;
string AdminName="admin";
string AdminPassword="admin";
const int Size=10;
string NumberOfCab[Size]={"1","2","3","4","5","6"};
int CABSTATUS[Size]={1,1,1,1,1,1};
int ChargesPerKm=5;
int Counting=4;
int count=0;
int n=5,i,j,k;
int adj[5][5]={{0,10,30,15,25},{10,0,7,10,30},{30,7,0,15,5},{15,10,15,0,2},{25,30,5,2,0}};
int adj1[5][5]={{0,15,35,20,30},{15,0,9,14,37},{33,12,0,18,7},{16,10,17,0,5},{27,32,7,4,0}};
int pickup,drop;
int *PChargesPerKm=&ChargesPerKm;

bool wrong = false;//initializing

int main()
{
    srand(time(0));
    int count=0;
   system("color 1E");//Setting The Color Of Console
   cout<<endl;
   cout<<"\t******************************\n";
   cout<<"\t*         Welcome            *\n";
   cout<<"\t*            To              *\n";
   cout<<"\t*    Cab Booking System      *\n";
   cout<<"\t******************************\n";
   cout<<endl;
   cout<<endl;
   cout<<endl;
   cout<<"\tLoading ";
   Sleep(100);//For Pause
   cout<<".";
   Sleep(100);//For Pause
   cout<<".";
   Sleep(100);//For Pause
   cout<<".";
      Sleep(100);//For Pause
   cout<<".";
   Sleep(100);//For Pause
   cout<<".";
   Sleep(100);//For Pause
   cout<<".";
   Sleep(100);//For Pause
   cout<<".";
      Sleep(100);//For Pause
   cout<<".";
   cout<<"\n\n\tSuccessful\n";

   Sleep(2000);//For Pause
   system("CLS");//To Clear The Screen

   //login menu

    char Wish;
    string Choice;
    do{

        system("CLS");
        cout<<"\t*******************"<<endl;
        cout<<"\tCab Booking System"<<endl;
        cout<<"\t*******************"<<endl;
        cout<<endl;

        cout<<"<1>  For Login Admin"<<endl;
        cout<<endl;

        cout<<"<2> For Login User"<<endl;
        cout<<endl;

        cout<<"<3> For Exit"<<endl;

        cout<<endl;
        cout<<"Select your choice: ";
        cin>>Choice;

    int choice = atoi( Choice.c_str() );

    switch(choice)
    {
        case 1://admin
            {
                  string UserName;//declaration
                  string Password;//declaration
                  bool LoginSuccess= false;

                  do
                  {
                    system("CLS");
                    cout<<"\t********************"<<endl;
                    cout<<"\t*  Admin Login     *"<<endl;
                    cout<<"\t********************"<<endl;
                    cout<<endl;
                    Sleep(500);
                    cout<<"\nUserName: ";
                    cin>>UserName;
                    cout<<"Password: ";
                    cin>>Password;

             if(UserName== AdminName && Password == AdminPassword)
             {
              cout<<"Login Successful \n";
              LoginSuccess= true;
              Sleep(2000);
              system("CLS");
              char Wish;
              do
              {
                system("CLS");
                string Choice;//declaration
                cout<<"\t********************"<<endl;
                cout<<"\t* Administration   *"<<endl;
                cout<<"\t********************"<<endl;
                cout<<endl;
                cout<<"<1> Customer Record"<<endl;
                cout<<endl;
                cout<<"<2> Cab Status"<<endl;
                cout<<endl;
                cout<<"<3> Canceled Booking Record"<<endl;
                cout<<endl;
                cout<<"<4> Change The Rate Of Per Km Charges"<<endl;
                cout<<endl;
                cout<<"<5> New User Account"<<endl;
                cout<<endl;
                cout<<"<6> Change points for pick up and drop"<<endl;
                cout<<endl;
                cout<<"<7> To Log Out"<<endl;
                cout<<"Select choice :";
                cin>>Choice;
                int choice = atoi( Choice.c_str() );

                switch(choice)
                    {
                        case 1://Customer Record
                        {
                            cout<<"check booking record\n";
                            CheckBookingRecord();
                            break;
                        }

                        case 2://Cab status
                        {
                            system("CLS");
                            int size=6;
                            cout<<"CAB STATUS\n";
                            for(int i=0;i<size;i++)
                            {
                                if(CABSTATUS[i] ==1)
                                {
                                    cout<<"Cab "<<NumberOfCab[i]<<" IS FREE\n";
                                }
                                else
                                {
                                    cout<<"Cab "<<NumberOfCab[i]<<" IS NOT FREE\n";
                                }

                            }
                            break;
                        }

                        case 3://Cancelled booking record
                        {
                            system("CLS");
                            ifstream InFile;//creating Object to read from file
                            char ch;//initiailzing
                            InFile.open("CancelBooking.txt");//file open
                            while (!InFile.eof())
                            {
                                InFile.get ( ch ) ;
                                cout << ch ;
                            }
                            InFile.close();//file close
                            cout<<endl;
                            break;
                        }

                        case 4://Change rate per km
                        {
                            char Wish;
                            do{

                                int Charges;
                                cout<<"Current Charge per km is "<<ChargesPerKm<<"Rs\n";
                                cout<<"Enter The Amount That You Want To Increment or Decrement On Km Per Charges :";
                                do
                                {
                                 cin>>Charges;
                                 wrong = cin.fail();//if type is opposite
                                 if(wrong)
                                  cout<<"Error Wrong Input\nEnter again"<<endl;
                                 cin.clear();
                                 cin.ignore(200, '\n');//ignore upto 200 characters
                                }while(wrong);

                                *PChargesPerKm+=Charges;
                                cout<<"\nThe Changes Has Been Done SuccessFully"<<endl;
                                cout<<"\nNew Charge per km is "<<ChargesPerKm<<"Rs\n";
                                cout<<"Do you Want TO Change The Rate Again(Y/N):  ";
                                cin>>Wish;
                               }while(Wish=='Y' || Wish=='y');
                                break;
                        }

                        case 5:
                          {
                           system("CLS");
                           cout<<"\t WELCOME"<<endl;
                           cout<<endl;
                           cout<<"Enter The New User's User Name: ";
                           cin>>NewWorkerName;
                           cout<<endl;
                           cout<<"Enter New User's Password: ";
                           cin>>NewWorkerPassword;
                           cout<<endl;
                           cout<<"The Account Has Been Made Successfully\n";
                           cout<<endl;
                           cout<<"\tThank YOu"<<endl;

                           break;
                          }

                        case 6:
                            {
                                changepoints();
                            }
                        case 7:
                        {
                            system("CLS");
                            cout<<"\tLogout\n";
                            break;
                        }

                        default:
                        {
                            cout<<"You Enter Wrong Choice"<<endl;
                            break;
                        }
                    }

                    if(choice==7)
                     {
                      break;
                     }
                        cout<<"Press any key to continue...... ";
                        Wish=getch();
                      }while(Wish);
                  }
                  else
                  {
                       cout<<"Incorrect User Name And Password\n"
                        <<"Please Try Again";
                        Sleep(1000);
                  }
               }while(!LoginSuccess);
               break;
             }//end of case 1

             case 2://user
                  {
                    string UserName="";
                    string Password="";
                    bool LoginSuccess= false;
                    do{
                    system("CLS");
                    cout<<"\t********************"<<endl;
                    cout<<"\t*    User Login    *"<<endl;
                    cout<<"\t********************"<<endl;

                    cout<<"UserName: ";
                    cin>>UserName;
                    cout<<"Password: ";
                    cin>>Password;

                    if(UserName== "user" && Password == "user" || UserName== NewWorkerName && Password == NewWorkerPassword )
                       {
                            cout<<"Login Successful \n";
                            LoginSuccess= true;
                            Sleep(2000);

                            system("CLS");

                            char Wish;
                            string Choice;
                            do{
                                x:
                                system("CLS");
                                cout<<"\t********************"<<endl;
                                cout<<"\t*        User      *"<<endl;
                                cout<<"\t********************"<<endl;
                                cout<<endl;
                                cout<<endl;
                                cout<<"<1> Booking"<<endl;
                                cout<<endl;
                                cout<<"<2> Cab Status    "<<endl;
                                cout<<endl;
                                cout<<"<3> To LogOut         "<<endl;
                                cout<<endl;

                                cout<<"Select :";
                                cin>>Choice;
                                int choice = atoi( Choice.c_str() );
                                switch(choice)
                                {

                                case 1:
                                {
                                    booking();
                                    break;
                                }

                                case 2://cab status
                                {
                                    system("CLS");
                                    int size=6;
                                    cout<<"CAB STATUS\n";
                                    for(int i=0;i<size;i++)
                                    {
                                        if(CABSTATUS[i] ==1)
                                         {
                                              cout<<"Cab "<<NumberOfCab[i]<<" IS FREE\n";
                                         }
                                         else
                                         {
                                             cout<<"Cab "<<NumberOfCab[i]<<" IS NOT FREE\n";
                                         }

                                    }

                                    break;
                                }

                                case 3:
                                {
                                    system("CLS");
                                    cout<<"\tFor Logout\n";
                                    break;
                                }

                                default:
                                {
                                    cout<<"You Enter Wrong Choice\n";
                                    break;
                                }
                            }//end of switch

                            if(choice==3)
                             {
                              break;
                             }
                            cout<<"Press any key to continue...... ";
                            Wish=getch();
                            }while(Wish);
                }

                            else
                            {
                                cout<<"Incorrect User Name And Password\n"
                                <<"Please Try Again";
                                Sleep(2000);

                            }
                        }while(!LoginSuccess);
                        break;
                  }//end of case 2


                case 3:
                {
                    system("CLS");
                    ifstream InFile;//creating object to read from file
                    char ch;//initializing
                    InFile.open("Exit.txt");//file open
                    while (!InFile.eof())
                    {
                        InFile.get ( ch ) ;
                        cout << ch ;
                    }
                    InFile.close();//file close
                    cout<<endl;
                    Sleep(2000);
                    exit(0);
                 break;
                 }//end of case 3

                default:
                {
                    cout<<"You Enter Wrong Choice"<<endl;
                    break;
                }//end of default
    }//end of Switch

    cout<<"Press any key to continue...... ";
    Wish=getch();
    }while(Wish);

}

void CheckBookingRecord()
{
    system("CLS");
    ifstream InFile;//creating Object to read from file
    char ch;//initializing
    InFile.open("Customer Record.txt");//file open
    while (!InFile.eof())
    {
        InFile.get ( ch ) ;
        cout << ch ;
    }
    InFile.close();//file close
    cout<<endl;
}

void changepoints()
{
    cout<<"enter the Distance between the points in the form of a matrix\n";
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            cin>>adj[i][j];
        }
    }

    cout<<"The matrix of distances is \n";
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            cout<<adj[i][j]<<"\t";
        }
        cout<<"\n";
    }
}

void fwa()
{
    for(int k=0; k<n; k++)
    {
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(adj[i][j] <= (adj[i][k] + adj[k][j]))
                {
                    adj[i][j] = adj[i][j];
                }
                else
                {
                    adj[i][j] = (adj[i][k] + adj[k][j]);
                }
            }
        }
    }
}

void fwa1()
{
    for(int k=0; k<n; k++)
    {
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(adj1[i][j] <= (adj1[i][k] + adj1[k][j]))
                {
                    adj1[i][j] = adj1[i][j];
                }
                else
                {
                    adj1[i][j] = (adj1[i][k] + adj1[k][j]);
                }
            }
        }
    }
}
void booking()
{
    fwa();
    fwa1();
    string Name;
    char pick,drp;
    int dist,dist1;
    float charges,charges1;
    int ch,chh;
    int tim,tim1;



    if(CABSTATUS[1]==0 && CABSTATUS[2]==0 && CABSTATUS[3]==0 && CABSTATUS[4]==0 && CABSTATUS[5]==0 )
    {
        cout<<"All The cabs Are Book"<<endl;
        cout<<"We Can Not Book Cab for You"<<endl;
    }

    else
    {

    for(int i=0;i<=6;i++)
    {
        if(CABSTATUS[i]==1)
        {
        count=i;
        break;
        }
    }

    system("CLS");
    ofstream MyFile;//Creating Object Due To Which we Write On File
    ofstream MYFile;//Creating Object Due To Which we Write On File
    ofstream MYFILE;
    MYFILE.open("CabStatus.txt",ios::app);
    MyFile.open("Customer Record.txt",ios::app);//File Open
    MYFile.open("CancelBooking.txt",ios::app);//File Open


    cout<<"1]Normal Cab\t2]Shared Cab\nEnter your choice\n";
    cin>>ch;

    if(ch==1){
        cout<<"Following are the locations\n";
    cout<<"A\tB\tC\tD\tE\n";
    cout<<"Enter pickup location: ";
    cin>>pick;
    cout<<"\nEnter drop location: ";
    cin>>drp;


    switch(pick)
    {
        case 'A':
            {
              pickup=0;
              break;
            }
        case 'B':
            {
              pickup=1;
              break;
            }
        case 'C':
            {
              pickup=2;
              break;
            }
        case 'D':
            {
              pickup=3;
              break;
            }
        case 'E':
            {
              pickup=4;
              break;
            }
            case 'a':
            {
              drop=0;
              break;
            }
        case 'b':
            {
              drop=1;
              break;
            }
        case 'c':
            {
              drop=2;
              break;
            }
        case 'd':
            {
              drop=3;
              break;
            }
        case 'e':
            {
              drop=4;
              break;
            }
        default:
            cout<<"Wrong choice";
    }

    switch(drp)
    {
        case 'A':
            {
              drop=0;
              break;
            }
        case 'B':
            {
              drop=1;
              break;
            }
        case 'C':
            {
              drop=2;
              break;
            }
        case 'D':
            {
              drop=3;
              break;
            }
        case 'E':
            {
              drop=4;
              break;
            }

            case 'a':
            {
              drop=0;
              break;
            }
        case 'b':
            {
              drop=1;
              break;
            }
        case 'c':
            {
              drop=2;
              break;
            }
        case 'd':
            {
              drop=3;
              break;
            }
        case 'e':
            {
              drop=4;
              break;
            }
        default:
            cout<<"Wrong choice";
    }

    dist=adj[pickup][drop];
    if(dist==0)
        cout<<"Please select a different pickup and drop location\n";
    else
    {
        cout<<"\nGuidelines for filling the form\n";
        cout<<"After Entering Your Name Put FullStop After Ending The Name.\n";
        cout<<"Your Must Put Fullstop at The End If You Didn't So Program \n";
        cout<<"Will Not Go Further.\n\n";
        cout << "What is your Name : ";
        getline(cin,Name,'.');
        tim=(time(dist));
        charges=(dist+(tim/3))*ChargesPerKm;
        cout <<"\nPick : "<<pick;
        cout <<"\nDrop: "<<drp;
        cout <<"\nDistance: "<<dist;
        cout<<"\nEstimated Time Taken:"<<tim;
        cout <<"\nCharges: Rs"<< charges<<"\n";
        cout<<endl;

         char PaidCharges;
         cout<<"Do you want to pay the Charges(Y/N) :- ";
         PaidCharges=getch();
         if(PaidCharges =='Y'||PaidCharges =='y')
         {
            cout<<"Cab "<<NumberOfCab[count]<<" is Booked For You\n";

           //cout<<"Your Booking Has Been Done\n";
           MyFile <<"\n\t\tCustomer Record\n";//writing on file
           MyFile << "\nName : "<<Name;//writing on file
           MyFile <<"\nPick : "<<pick;//writing on file
           MyFile <<"\nDrop: "<<drop;//writing on file
           MyFile <<"\nDistance: "<<dist;//writing on file
           MyFile <<"\nCharges: Rs"<< charges;//writing on file
           MyFile.close();//File Close
           CABSTATUS[count]=0;
           Sleep(1000);
         }

         else
         {
          cout<<"Your booking has been Canceled\n";
          MYFile <<"\n\t\tBooking Canceled\n";//writing on file
          MYFile << "\nName : "<< Name;//writing on file
          MYFile <<"\nPick : "<<pick;//writing on file
          MYFile <<"\nDrop: "<<drop;//writing on file
          MYFile <<"\nDistance: "<<dist;//writing on file
          MYFile <<"\nCharges: Rs"<< charges;//writing on file

          count--;
          MYFile.close();//File Close

         }
         MYFILE.close();
         Sleep(2000);
    }
    }

    if(ch==2)
    {
        cout<<"Shared cab\n";
        cout<<"Following are the locations\n";
        cout<<"A\tB\tC\tD\tE\n";
        cout<<"Enter pickup location: ";
        cin>>pick;
        cout<<"\nEnter drop location: ";
        cin>>drp;


        switch(pick)
        {
            case 'A':
                {
                  pickup=0;
                  break;
                }
            case 'B':
                {
                  pickup=1;
                  break;
                }
            case 'C':
                {
                  pickup=2;
                  break;
                }
            case 'D':
                {
                  pickup=3;
                  break;
                }
            case 'E':
                {
                  pickup=4;
                  break;
                }
                case 'a':
                {
                  drop=0;
                  break;
                }
            case 'b':
                {
                  drop=1;
                  break;
                }
            case 'c':
                {
                  drop=2;
                  break;
                }
            case 'd':
                {
                  drop=3;
                  break;
                }
            case 'e':
                {
                  drop=4;
                  break;
                }
            default:
                cout<<"Wrong choice";
        }

        switch(drp)
        {
            case 'A':
                {
                  drop=0;
                  break;
                }
            case 'B':
                {
                  drop=1;
                  break;
                }
            case 'C':
                {
                  drop=2;
                  break;
                }
            case 'D':
                {
                  drop=3;
                  break;
                }
            case 'E':
                {
                  drop=4;
                  break;
                }

                case 'a':
                {
                  drop=0;
                  break;
                }
            case 'b':
                {
                  drop=1;
                  break;
                }
            case 'c':
                {
                  drop=2;
                  break;
                }
            case 'd':
                {
                  drop=3;
                  break;
                }
            case 'e':
                {
                  drop=4;
                  break;
                }
            default:
                cout<<"Wrong choice";
        }

        dist=adj[pickup][drop];
        dist1=adj1[pickup][drop];
        if(dist==0)
            cout<<"Please select a different pickup and drop location\n";
        else
        {
            cout<<"\nGuidelines for filling the form\n";
            cout<<"After Entering Your Name Put FullStop After Ending The NAme.\n";
            cout<<"Your Must Put Fullstop at The End If You Didn't So Program \n";
            cout<<"Will Not Go Further.\n\n";
            cout << "What is your Name : ";
            getline(cin,Name,'.');
            tim=(time(dist));
            tim1=(time1(dist1));
            charges=(dist+(tim/3))*ChargesPerKm;
            charges1=(dist1+(tim1/3))*ChargesPerKm;
            cout <<"\nPick : "<<pick;
            cout <<"\nDrop: "<<drp;
            cout<<"\nChoice 1:";
            cout <<"\nDistance: "<<dist;
            cout<<"\nEstimated Time Taken:"<<tim;
            cout <<"\nCharges: Rs"<< charges<<"\n";
            cout<<endl;
            cout<<"Choice 2:";
            cout <<"\nDistance: "<<dist1;
            cout<<"\nEstimated Time Taken:"<<tim1;
            cout <<"\nCharges: Rs"<< charges1<<"\n";
            cout<<endl;
            cout<<"Enter your choice\n";
            cin>>chh;

            if(chh==2)
            {
                dist=dist1;
                charges=charges1;
            }
             char PaidCharges;
             cout<<"Do you want to pay the Charges(Y/N) :- ";
             PaidCharges=getch();
             if(PaidCharges =='Y'||PaidCharges =='y')
             {
                cout<<"Cab "<<NumberOfCab[count]<<" is Booked For You\n";

               //cout<<"Your Booking Has Been Done\n";
               MyFile <<"\n\t\tCustomer Record\n";//writing on file
               MyFile << "\nName : "<< Name;//writing on file
               MyFile <<"\nPick : "<<pick;//writing on file
               MyFile <<"\nDrop: "<<drop;//writing on file
               MyFile <<"\nDistance: "<<dist;//writing on file
               MyFile <<"\nCharges: Rs"<< charges;//writing on file
               MyFile.close();//File Close
               CABSTATUS[count]=0;
               Sleep(1000);
             }

             else
             {
              cout<<"Your booking has been Canceled\n";
              MYFile <<"\n\t\tBooking Canceled\n";//writing on file
              MYFile << "\nName : "<< Name;//writing on file
              MYFile <<"\nPick : "<<pick;//writing on file
              MYFile <<"\nDrop: "<<drop;//writing on file
              MYFile <<"\nDistance: "<<dist;//writing on file
              MYFile <<"\nCharges: Rs"<< charges;//writing on file

              count--;
              MYFile.close();//File Close

             }
             MYFILE.close();
             Sleep(2000);
        }
    }


    }
}

int time(int x)
{
    int y;
    if(x<5)
    {
        y=(rand()%10)+1;//1 to 11
        return y;
    }

    else if(x>=5&&x<20)
    {
        y=(rand()%20)+10;//10 to 30
        return y;
    }

    else if(x>=20&&x<30)
    {
        y=(rand()%20)+20;//20 to 40
        return y;
    }

    else if(x>=30&&x<=40)
    {
        y=(rand()%20)+30;//30 to 50
        return y;
    }

    else
    {
        y=(rand()%10)+50;//50 to 60
        return y;
    }
}

int time1(int x)
{
    int y;
    if(x<10)
    {
        y=(rand()%5)+1;//1 to 6
        return y;
    }

    else if(x>=10&&x<20)
    {
        y=(rand()%5)+10;//10 to 15
        return y;
    }

    else if(x>=20&&x<30)
    {
        y=(rand()%10)+20;//20 to 30
        return y;
    }

    else
    {
        y=(rand()%5)+30;//30 to 35
        return y;
    }
}


