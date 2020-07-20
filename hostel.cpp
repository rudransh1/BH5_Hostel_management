  //C++ OOP PROJECT
  //BH-5 HOSTEL MANAGEMENT SYSTEM : Rudransh Gupta
  #include<iostream>
  #include<conio.h>
  #include<fstream>
  #include<stdio.h>
  #include<stdlib.h>


  using namespace std;

  //START OF CLASS



class bh5_hostel
{

    int room_no;
    char name[30];
    char address[50];
    char phone[10];

    public:

    void hostel_menu();		//to dispay the main menu of student hostel
    void add();			//to book a room in student hostel
    void display(); 		//to display the student record
    void rooms();			//to display alloted rooms in student hostel
    void edit();			//to edit the student record
    int check(int);			//to check room status
    void modify(int);		//to modify the record
    void delete_rec(int);	//to delete the record
    void bill(int);               //for the bill of a record
};
      //END OF CLASS DEFINITION







void bh5_hostel::hostel_menu()
{

    int choice;
    while(choice!=5)
    {

        system("cls");
        cout<<"\n\t\t\t\t*************************";
        cout<<"\n\t\t\t\t BH-5 HOSTEL MANAGEMENT SYSTEM";
        cout<<"\n\t\t\t\t      * Hostel MENU *";
        cout<<"\n\t\t\t\t*************************";
        cout<<"\n\n\n\t\t\t1.Book A Room";
        cout<<"\n\t\t\t2.Student Records";
        cout<<"\n\t\t\t3.Rooms Allotted";
        cout<<"\n\t\t\t4.Edit Record";
        cout<<"\n\t\t\t5.Exit";
        cout<<"\n\n\t\t\tEnter Your Choice: ";
        cin>>choice;

        switch(choice)
        {

            case 1:	add();
            break;

            case 2: display();
            break;

            case 3: rooms();
            break;

            case 4:	edit();
            break;

            case 5: break;

            default:
            {

                cout<<"\n\n\t\t\tWrong choice.....!!!";
                cout<<"\n\t\t\tPress any key to   continue....!!";
                getch();

            }

        }

      }

  }


  //END OF MENU FUNCTION


  //FUNCTION FOR BOOKING OF ROOM IN student HOSTEL


  void bh5_hostel::add()
  {

      system("cls");
      int r,flag;
      ofstream fout("Record.txt",ios::app);

      cout<<"\n Enter student Detalis";
      cout<<"\n ----------------------";
      cout<<"\n\n Room no: ";
      cout<<"\n Total no. of Rooms - 50";
      cout<<"\n Single bed Rooms from 1 - 30";
      cout<<"\n Double bed Rooms from 31 - 45";
      cout<<"\n Meeting  Rooms from 46 - 50";
      cout <<"\n Enter The Room no. you want to stay in :- "<<endl;
      cin>>r;

      flag=check(r);

      if(flag)
      cout<<"\n Sorry..!!!Room is already booked";

      else
      {

      room_no=r;
      cout<<" Name: ";
      cin>>name;
      cout<<" Address: ";
      cin>>address;
      cout<<" Phone No: ";
      cin>>phone;

      fout.write((char*)this,sizeof(bh5_hostel));
      cout<<"\n Room is booked...!!!";

      }

      cout<<"\n Press any key to continue.....!!";

      getch();
      fout.close();

  }


  //END OF BOOKING FUNCTION


  //FUNCTION FOR DISPLAYING A PURTICULAR student`S RECORD





void bh5_hostel::display()
{

    system("cls");

    ifstream fin("Record.txt",ios::in);
    int r,flag;

    cout<<"\n Enter room no. for a particular student`s details :- "<<endl;
    cin>>r;

    while(!fin.eof())
    {

        fin.read((char*)this,sizeof(bh5_hostel));
        if(room_no==r)
        {

            system("cls");
            cout<<"\n student Details";
            cout<<"\n ----------------";
            cout<<"\n\n Room no: "<<room_no;
            cout<<"\n Name: "<<name;
            cout<<"\n Address: "<<address;
            cout<<"\n Phone no: "<<phone;
            flag=1;
            break;

        }

    }

    if(flag==0)
    cout<<"\n Sorry Room no. not found or vacant....!!";
    cout<<"\n\n Press any key to continue....!!";

    getch();
    fin.close();
}


  //END OF DISPLAY FUNCTION

  //FUNCTION TO DISPLAY ALL ROOMS OCCUPIED


  void bh5_hostel::rooms()
  {

      system("cls");

      ifstream fin("Record.txt",ios::in);
      cout<<"\n\t\t\t    List Of Rooms Allotted";
      cout<<"\n\t\t\t    ----------------------";
      cout<<"\n\n Room No.\tName\t\tAddress\t\t\t\tPhone No.\n";

      while(!fin.eof())
      {

      fin.read((char*)this,sizeof(bh5_hostel));
      cout<<"\n\n "<<room_no<<"\t\t"<<name;
      cout<<"\t\t"<<address<<"\t\t"<<phone;

      }

      cout<<"\n\n\n\t\t\tPress any key to continue.....!!";
      getch();
      fin.close();

  }


  //FUNCTION FOR EDITING RECORDS AND FOR BILL


  void bh5_hostel::edit()
  {

    system("cls");

      int choice,r;
      cout<<"\n EDIT MENU";
      cout<<"\n ---------";
      cout<<"\n\n 1.Modify student Record";
      cout<<"\n 2.Delete student Record";
      cout<<"\n 3. Bill Of student";
      cout<<"\n Enter your choice: ";

      cin>>choice;
        system("cls");

      cout<<"\n Enter room no: " ;
      cin>>r;

      switch(choice)
      {

          case 1:	modify(r);
          break;

          case 2:	delete_rec(r);
          break;

          case 3: bill(r);
          break;

          default: cout<<"\n Wrong Choice.....!!";

      }
      cout<<"\n Press any key to continue....!!!";

      getch();
  }
//checking for the availability of the room

  int bh5_hostel::check(int r)
  {

      int flag=0;

      ifstream fin("Record.dat",ios::in);

      while(!fin.eof())
      {

          fin.read((char*)this,sizeof(bh5_hostel));
          if(room_no==r)
          {

              flag=1;
              break;

          }

      }

      fin.close();
      return(flag);

  }


  //FUNCTION TO MODIFY studentS RECORD


void bh5_hostel::modify(int r)
{

    long pos,flag=0;

    fstream file("Record.dat",ios::in|ios::out|ios::binary);

    while(!file.eof())
    {

        pos=file.tellg();
        file.read((char*)this,sizeof(bh5_hostel));

        if(room_no==r)
        {

            cout<<"\n Enter New Details";
            cout<<"\n -----------------";
            cout<<"\n Name: ";
            cin>>name;
            cout<<" Address: ";
            cin>>address;
            cout<<" Phone no: ";
            cin>>phone;
            file.seekg(pos);
            file.write((char*)this,sizeof(bh5_hostel));
            cout<<"\n Record is modified....!!";
            flag=1;
            break;

        }

    }

    if(flag==0)
    cout<<"\n Sorry Room no. not found or vacant...!!";
    file.close();
}


  //END OF MODIFY FUNCTION


  //FUNCTION FOR DELETING RECORD


void bh5_hostel::delete_rec(int r)
{

    int flag=0;
    char ch;
    ifstream fin("Record.txt",ios::in);
    ofstream fout("temp.dat",ios::out);

    while(!fin.eof())
    {

        fin.read((char*)this,sizeof(bh5_hostel));
        if(room_no==r)

        {

            cout<<"\n Name: "<<name;
            cout<<"\n Address: "<<address;
            cout<<"\n Phone No: "<<phone;
            cout<<"\n\n Do you want to delete this record(y/n): ";
            cin>>ch;

            if(ch=='n')
              fout.write((char*)this,sizeof(bh5_hostel));
            flag=1;

        }

        else
          fout.write((char*)this,sizeof(bh5_hostel));

    }

    fin.close();
    fout.close();

    if(flag==0)
    cout<<"\n Sorry room no. not found or vacant...!!";

    else
    {

      remove("Record.txt");
      rename("temp.dat","Record.txt");

    }
}


  //END OF DELETE FUNCTION


  //FUNCTION FOR student`S BILL
void bh5_hostel::bill(int r)
{

    bh5_hostel h1;
    ifstream f1;
     f1.open("record.txt",ios::in|ios::binary);

    if(!f1)
     cout<<"cannot open";

     else
     {
        int temp=0;
        f1.read((char*)&h1,sizeof (bh5_hostel));
        while(f1)

        {

            f1.read((char*)&h1,sizeof(bh5_hostel));

            

            if (h1.room_no == r)
            {
                temp=1;
                if(h1.room_no>=1&&h1.room_no<=30)
                cout<<"your bill = 500";
                else if (h1.room_no>=35&&h1.room_no<=45)
                cout<<"your bill = 1000" ;
                else
                cout<<"your bill = 2000";
                break;
            }
        }

        if(temp==0)
        { 
          cout<<"room no. not found";
        }
    }

    f1.close();
    getch();

}


  //START OF THE MAIN()

  int main()
  {

      bh5_hostel h;

      system("cls");

      cout<<"\n\t\t\t****************************";
      cout<<"\n\t\t\t* BH-5 student HOSTEL *";
      cout<<"\n\t\t\t****************************";
      cout<<"\n\n\n\n\n\n\n\t\t\t\t\tPress any key to continue....!!";

      getch();

      h.hostel_menu();
      return 0;
  }

  //END OF MAIN()
