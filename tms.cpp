#include <iostream>
#include <fstream>
#include <string.h>
#include <iomanip>
#include <windows.h>

using namespace std;

void menue();
class manage_menue
{
protected:
    string username;

public:
    manage_menue()
    {
        system("color 0A");
        cout << "\n\n\n\n\nEnter user name:-  ";
        cin >> username;
        system("CLS");
        menue();
    }
    ~manage_menue()
    {
    }
};
class manage_customers
{
protected:
    string name;
    string address;
    int mobile_no;
    string e_mail;

public:
    static int id;
    char all_l[999];
    int rtrn;

    void set_details_customer()
    {
        system("CLS");
        ofstream out("oldcustomer.txt", ios::app);
        {
            cout << "Enter Name of customer:- ";
            cin >> name;
            cout << "Enter Customer's Mobile number:- ";
            cin >> mobile_no;
            cout << "Customer's Id:- ";
            cin >> id;
            cout << "Enter Customer's e-mail:- ";
            cin >> e_mail;
            cout << "Enter Customer's address:- ";
            cin >> address;
        }
        out << endl
            << name << endl
            << id << endl
            << mobile_no << address << endl
            << e_mail << endl;
        out.close();
        cout << endl
             << "Details Saved!!" << endl;
        system("CLS");

        cout << "\n\n\nEnter 1 to go to main menue else to exit from program!!" << endl;
        cin >> rtrn;
        if (rtrn == 1)
        {
            menue();
        }
        else
        {
            exit(0);
        }
    }
    void show_details()
    {
        ifstream in("oldcustomer.txt");

        {
            if (!in)
            {
                cout << "File Error !!" << endl;
            }

            while (!in.eof())
            {
                in.getline(all_l, 999);
                cout << all_l << endl;
            }
            in.close();
        }
        cout << "\n\n\nEnter 1 to go to main menue else to exit from program!!" << endl;
        cin >> rtrn;
        if (rtrn == 1)
        {
            menue();
        }
        else
        {
            exit(0);
        }
    }
};

class manage_cabs
{
protected:
    char cab_type;
    float Kilometers;
    float cab_cost;

public:
    float last_cab_cost = 0.0;
    string rtrn;
    int gtm;
    void cab_details()
    {
        cout << "\n\nWelcome to the fastest,safest and most economic cab booking portal!!" << endl;
        cout << "\n\nFor standard cab rate= Rs15/km & For premium cab rate= Rs25/km" << endl;
        cout << "\n\nFor standard cab press 'S' & For premium cab press 'P'" << endl;

        cout << "\n\nEnter the type of cab :- ";
        cin >> cab_type;

        string hirecab;
        cout << "\n\nEnter the Distance in kilometers:- ";
        cin >> Kilometers;
        if (cab_type == 'S')
        {
            cab_cost = 15 * Kilometers;
            cout << "\n\nYour Journey cost will be " << cab_cost << " for a standard cab" << endl;
            cout << "\n\nType ok to hire this cab and anything else to return cab choices." << endl;
            cin >> hirecab;
            system("CLS");
            if (hirecab == "ok")
            {
                last_cab_cost = cab_cost;
                cout << "\n\nYou have succesfully booked your cab" << endl;
                cout << "\n\nGO TO MAIN MENUE enter 1 else any other key to exit" << endl;
                cin >> gtm;
                if (gtm == 1)
                {
                    menue();
                }
                else
                {
                    exit(0);
                }
            }
            else
            {
                cab_details();
            }
        }
        else if (cab_type == 'P')
        {
            cab_cost = 25 * Kilometers;
            cout << "\n\nYour Journey cost will be " << cab_cost << " for a premium cab" << endl;
            cout << "\n\nType ok to hire this cab and anything else to return cab choices." << endl;
            cin >> hirecab;
            system("CLS");
            if (hirecab == "ok")
            {
                last_cab_cost = cab_cost;
                cout << "\n\nYou have succesfully booked your cab" << endl;
                cout << "\n\nGO TO MAIN MENUE press 1 else any other key to exit!!" << endl;
                cin >> gtm;
                if (gtm == 1)
                {
                    menue();
                }
                else
                {
                    exit(0);
                }
                menue();
            }
            else
            {
                cab_details();
            }
        }
        else
        {
            cout << "Invalid cab-type entered!!" << endl;
            menue();
        }

        system("CLS");
    }
};
class manage_hotel_booking
{
protected:
    int hotel_choice;
    int package_choice;
    float hotel_cost;

public:
    string rtrn;
    int gm;
    void hotels()
    {
        string hotel_name[] = {"HOTEL TAJ", "HAYAT", "GALA GALAXY"};
        for (int i = 0; i < 3; i++)
        {
            cout << (i + 1) << ". hotel" << hotel_name[i] << endl;
        }
        cout << endl
             << "\n\nWe are currently collaborated with above hotels!!" << endl;

        cout << "\n\nPress any key to go back or enter a number of above hotels" << endl;
        cin >> hotel_choice;
        system("CLS");
        if (hotel_choice == 1)
        {
            cout << endl
                 << "<-------------welcome to Hotel TAJ------------>" << endl;

            cout << "Packages Offered by Hotel Taj" << endl;
            cout << endl
                 << "\n1.Standard Pack" << endl;
            cout << "\nAll Basic facilities you need just for Rs 9000 per night stay!!" << endl;

            cout << "\n2.Premium Pack" << endl;
            cout << "\nEnjoy premium facilities for just Rs 15000 per night stay!!" << endl;

            cout << "\n3.Luxury Pack" << endl;
            cout << "\nEnjoy the luxurious facilities  just for Rs 20000 per night stay" << endl;

            cout << "\nPress another key to go back or enter package number you want " << endl;
            cin >> package_choice;
            if (package_choice == 1)
            {
                hotel_cost=9000;
                cout << "\nThank you For standard pack" << endl;
                cout << "\nGo to main menue and take your booking reciept" << endl;
            }
            else if (package_choice == 2)
            {
                hotel_cost=15000;
                cout << "\nThank you For choosing premium pack" << endl;
                cout << "\nGo to main menue and take your booking reciept" << endl;
            }
            else if (package_choice == 3)
            {
                hotel_cost=20000;
                cout << "\nThank you For choosing luxury pack" << endl;
                cout << "\nGo to main menue and take your booking reciept" << endl;
            }
            else
            {
                cout << "Invalid input!!" << endl;
                system("CLS");
            }

            cout << "\n\nEnter 1 for main menue else any other key to exit!!";
            cin >> gm;
            if (gm == 1)
            {
                menue();
            }
            else
            {
                exit(0);
            }
        }
        else if (hotel_choice == 2)
        {
            cout << endl
                 << "<-------------welcome to Hotel GALA GALAXY------------>" << endl;

            cout << "\nPackages Offered by Hotel Gala Galaxy" << endl;
            cout << endl
                 << "\n1.Standard Pack" << endl;
            cout << "\nAll Basic facilities you need just for Rs 7000 per night stay!!" << endl;

            cout << "\n2.Premium Pack" << endl;
            cout << "Enjoy premium facilities for just Rs 13000 per night stay!!" << endl;

            cout << "\n3.Luxury Pack" << endl;
            cout << "\nEnjoy the luxurious facilities  just for Rs 17000 per night stay" << endl;

            cout << "\n\nPress another key to go back or enter package number you want " << endl;
            cin >> package_choice;
            if (package_choice == 1)
            {
                hotel_cost=7000;
                cout << "\nThank you For standard pack" << endl;
                cout << "\nGo to main menue and take your booking reciept" << endl;
            }
            else if (package_choice == 2)
            {hotel_cost=13000;
                cout << "\nThank you For choosing premium pack" << endl;
                cout << "\nGo to main menue and take your booking reciept" << endl;
            }
            else if (package_choice == 3)
            {hotel_cost=17000;
                cout << "\nThank you For choosing luxury pack" << endl;
                cout << "\nGo to main menue and take your booking reciept" << endl;
            }
            else
            {
                cout << "\nInvalid Input!!" << endl;
                system("CLS");
            }
            cout << "\nEnter 1 for main menue else any other key to exit!!";
            cin >> gm;
            if (gm == 1)
            {
                menue();
            }
            else
            {
                exit(0);
            }
        }

        else if (hotel_choice == 3)
        {
            cout << endl
                 << "<-------------welcome to Hotel Hayat------------>" << endl;

            cout << "\nPackages Offered by Hotel Gala Galaxy" << endl;
            cout << endl
                 << "\n1.Standard Pack" << endl;
            cout << "\nAll Basic facilities you need just for Rs 6000 per night stay!!" << endl;

            cout << "\n2.Premium Pack" << endl;
            cout << "\nEnjoy premium facilities for just Rs 11000 per night stay!!" << endl;

            cout << "n\3.Luxury Pack" << endl;
            cout << "\nEnjoy the luxurious facilities  just for Rs 15000 per night stay" << endl;

            cout << "\n\nPress another key to go back or enter package number you want " << endl;
            cin >> package_choice;
            if (package_choice == 1)
            {hotel_cost=6000;
                cout << "\nThank you For standard pack" << endl;
                cout << "\nGo to main menue and take your booking reciept" << endl;
            }
            else if (package_choice == 2)
            {hotel_cost=11000;
                cout << "\nThank you For choosing premium pack" << endl;
                cout << "\nGo to main menue and take your booking reciept" << endl;
            }
            else if (package_choice == 3)
            {hotel_cost=15000;
                cout << "\nThank you For choosing luxury pack" << endl;
                cout << "\nGo to main menue and take your booking reciept" << endl;
            }

            else
            {
                cout << "Invalid Input!!" << endl;
                system("CLS");
            }
            cout << "\n\nenter 1 to go to main menue:-  ";
            cin >> gm;
            if (gm == 1)
            {
                menue();
            }
            else
            {
                exit(0);
            }
        }

        else
        {
            cout << "\n\nEnter 1 for main menue , 2 for hotel menue and any other key to exit the program!!" << endl;
            cin >> gm;
            if (gm == 1)
            {
                menue();
            }
            else if (gm == 2)
            {
                hotels();
            }
            else
            {
                exit(0);
            }
        }
    }
};

int manage_customers::id;

class billing : public manage_cabs, public manage_hotel_booking, public manage_customers
{
public:
    float expense;

    void print_bill()
    {

        ofstream out("receipt2.txt");
        {
            out << "<--------GAMPA TRAVELL AGENCY--------->" << endl;
            out << "<---------------Recipt---------------->" << endl;
            out << "_______________________________________" << endl;

            out << "Customer ID: " << manage_customers::id << endl
                << endl;

            out << "Description of your TOTAL:-" << endl;
            out << "Hotel cost:\t\t" << fixed << setprecision(2) << hotel_cost << endl;
            out << "Travel(cab) cost:\t\t" << fixed << setprecision(2) << last_cab_cost << endl;

            out << "________________________________________" << endl;
            out << "Total Travell charges:\t\t" << fixed << setprecision(2) << hotel_cost + last_cab_cost;
            out << "_________________________________________" << endl;
            out << "<---------THANK YOU FOR CHOOSING US----------->" << endl;
            out.close();
        }
    }

    void show_bill()
    {
        ifstream inf("receipt2.txt");
        {
            if (!inf)
            {
                cout << "File Error!" << endl;
            }
            while (!(inf.eof()))
            {
                inf.getline(manage_customers::all_l, 999);
                cout << all_l << endl;
            }
        }
        inf.close();
    }
};

void menue()
{
    int menu_choice;
    int subchoices;
    cout << "\t\t\t\t<----------------GAMPA TRAVELLS---------------->" << endl;
    cout << "\t\t\t\t<++++++++++++++++++MAIN MENUE++++++++++++++++++>" << endl;
    cout << endl;
    cout << "\t\t\t\tPress following key to direct on desired submenue:--" << endl;
    cout<<"\t\t\t ***********FOR PROCEEDING IN PLAESE ENTER VALID DETAILS OF CUSTOMERS***********"<<endl;
    cout << "\t\t\t\tCustomer management-->1" << endl;
    cout << "\t\t\t\tcab management-->2" << endl;
    cout << "\t\t\t\tHotel booking management-->3" << endl;
    cout << "\t\t\t\tcharges & Bills-->4" << endl;
    cout << "\t\t\t\tEXIT-->5" << endl;
    cout << "\t\t\t\t+________________________________________________+" << endl;
    cout << "Enter choice" << endl;
    cin >> menu_choice;

    manage_customers cust;
    manage_cabs cab;
    manage_hotel_booking hb;
    billing b;

    if (menu_choice == 1)
    {
        cout << "<------Customers------>" << endl;
        cout << "1. Enter New Customer" << endl;
        cout << "2. See old customers" << endl;

        cout << "\n\nEnter Choice:-  ";
        cin >> subchoices;

        if (subchoices == 1)
        {
            cust.set_details_customer();
        }
        else if (subchoices == 2)
        {
            cust.show_details();
        }
        else
        {
            cout << "Invalid Input ! Redirecting to Previous menue \n please wait!" << endl;
            Sleep(10);
            system("CLS");
            menue();
        }
    }

    else if (menu_choice == 2)
    {

        cab.cab_details();
    }
    else if (menu_choice == 3)
    {
        hb.hotels();
    }
    else if (menu_choice == 4)
    {
        cout << "\nFor Printing recipt of charges-->1" << endl;
        cout << "\nEnter Choice:-  ";

        cout << "\nFor Displaying recipt of charges-->2" << endl;

        cout << "\nEnter Choice:-  ";
        cin >> subchoices;

        if (subchoices == 1)
        {
            b.print_bill();
            menue();
        }
        else if (subchoices == 2)
        {
            b.show_bill();
            menue();
        }
    }
    else if (menu_choice == 5)
    {

        exit(0);
    }
}

int main()
{

    manage_menue m1;
    return 0;
}