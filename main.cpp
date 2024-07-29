#include<iostream>
#include<string>
using namespace std;

class services {//abstract class
public:
 friend void AppointmentAndScheduling(string, string);
 string static staff_makeup_artist[8];
 string static staff_facial_meni_pedi[5];
 string static staff_hairstylist[5];
 //string selected_staff[5]; when we add time management then we will use
 string static name_services[5];
 int static price_facial_meni_pedi[5];
 int static price_makeupartist[8];
 int static price_hairstyle[5];
 void virtual update() = 0;
 float virtual billing(int discount) = 0;
 void virtual printing() = 0;
 virtual void print_inquiry() {}
};
string services::staff_makeup_artist[8] = { "Kashif","Natasha","Sana","Sara","Sobia","Wajid","Zainab","Zara" };
string services::staff_facial_meni_pedi[5] = { "Aiman","Amna","Beenish","Dania","Hania" };
string services::staff_hairstylist[5] = { "Hadiya","Hira","Ilsa","Iqra","Rida" };
string services::name_services[5] = { "Makeup","Facial","Menicure","Pedicure","Hairstyle" };
int services::price_makeupartist[8] = { 30000,80000,50000,40000,30000,55000,65000,48000 };
int services::price_facial_meni_pedi[5] = { 5000,6000,3000,4500,3200 };
int services::price_hairstyle[5] = { 1500,2000,2500,3000,1800 };

class Customer :public services {
private://encapsulation
 string name;
 int no_of_services;
 string service[5];//save artist name
 string services_names[5];//save service provided and 1 customer can take only 5 services max in a day
 int total_amount;//bill before discount
 float total_amount_discount;//total billing after discount
 int UpdateNum, UpdateNum2;
 string UpdateItem;
 int record[5], p, makeupType;// in record separate billing is stored
 string card;
public:
 static int count;
 friend class Salon;//using friend
 Customer() {};
 Customer(string name, int no_of_services, string service2[5], string services_name[5], int records[5], int total_amount) {
  this->name = name;
  this->no_of_services = no_of_services;
  copy(services_name, services_name + 5, services_names);
  copy(service2, service2 + 5, service);
  copy(records, records + 5, record);
  this->total_amount = total_amount;
  count++;
 }
 string getname() { return name; }
 float gettotalamount() { return total_amount_discount; }
 void update()override {
  do {
   cout << "Select\n1: Customer's Name\n2: Services\n3: Done" << endl;
   cin >> UpdateNum;
   if (UpdateNum == 1) {
    cout << "Re-enter Custonmer's Name: ";
    cin >> name;
   }

   if (UpdateNum == 2) {
    cout << "Enter no of services :" << endl;
    cin >> no_of_services;
    while (no_of_services > 5) {
     cout << "Services cannot be more than 5" << endl;
     cout << "Re-enter number of services" << endl;
     cin >> no_of_services;
    }
    for (int i = 0; i < no_of_services; i++) {
     cout << "Select\n1 : Makeup\n2 : Facial, Menicure or Pedicure\n3 : Hairstyle" << endl;
     cin >> services_names[i];
     int a1 = 0;//for checking
     if (services_names[i] == "1") {
      services_names[i] = "Makeup";
      cout << "Select\n1 : Party Makeup\n2 : Bridal Makeup" << endl;
      cin >> makeupType;
      if (makeupType == 1) {
       services_names[i] = "Party Makeup";
      }
      if (makeupType == 2) {
       services_names[i] = "Bridal Makeup";
      }
      cout << "Select :" << endl;
      for (int j = 0; j < 8; j++) {
       cout << j + 1 << " : " << services::staff_makeup_artist[j] << endl;
      }
      cin >> p;
      p = p - 1;
      for (int j = 0; j < 8; j++) {
       if (p == j) {
        service[i] = services::staff_makeup_artist[j];
        total_amount = services::price_makeupartist[j] + total_amount;
        record[i] = services::price_makeupartist[j];
        cout << service[i] << endl;
       }
      }
     }
     if (services_names[i] == "2") {
      services_names[i] = "Facial,Menicure or Pedicure";
      cout << "Select :" << endl;
      for (int j = 0; j < 5; j++) {
       cout << j + 1 << " : " << services::staff_facial_meni_pedi[j] << endl;
      }
      cin >> p;
      p = p - 1;
      for (int j = 0; j < 5; j++) {
       if (p == j) {
        service[i] = services::staff_facial_meni_pedi[j];
        total_amount = services::price_facial_meni_pedi[j] + total_amount;
        record[i] = services::price_facial_meni_pedi[j];
        cout << service[i] << endl;
       }
      }
     }
     if (services_names[i] == "3") {
      services_names[i] = "Hairstyle";
      cout << "Select :" << endl;
      for (int j = 0; j < 5; j++) {
       cout << j + 1 << " : " << services::staff_hairstylist[j] << endl;
      }
      cin >> p;
      p = p - 1;
      for (int j = 0; j < 5; j++) {
       if (p == j) {
        service[i] = services::staff_hairstylist[j];
        total_amount = services::price_hairstyle[j] + total_amount;
        record[i] = services::price_hairstyle[j];
        cout << service[i] << endl;
       }
      }
     }
    }

   }
  } while (UpdateNum != 3);

 }
 float billing(int discount)override {
  cout << "<---------BILLING-------->" << endl;
  cout << "Name of customer :" << name << endl;
  cout << "Number of services :" << no_of_services << endl;
  for (int i = 0; i < no_of_services; i++) {
   cout << "Service name :" << services_names[i] << endl;
   cout << "Staff booked for the service :" << service[i] << "\t\t";
   cout << "Price :Rs." << record[i] << endl;
  }
  cout << "Total amount = Rs." << total_amount << endl;

  if (discount == 1) {
   card = "Platinum card";
   cout << "Discount Applied 50%" << endl;
   total_amount_discount = total_amount * 0.5;
   cout << "Total amount = Rs." << total_amount_discount << endl;
  }
  else if (discount == 2) {
   card = "Gold card";
   cout << "Discount Applied 25%" << endl;
   total_amount_discount = total_amount * 0.75;
   cout << "Total amount = Rs." << total_amount_discount << endl;
  }
  else if (discount == 3) {
   card = "Silver card";
   cout << "Discount Applied 15%" << endl;
   total_amount_discount = total_amount * 0.85;
   cout << "Total amount = Rs." << total_amount_discount << endl;
  }
  else if (discount == 4) {
   card = "No card";
   cout << "Discount Applied 0%" << endl;
   total_amount_discount = total_amount * 1.0;
   cout << "Total amount = Rs." << total_amount_discount << endl;
  }
  return total_amount_discount;
 }
 void printing()override {
  cout << "CUSTOMER DETAILS" << endl;
  cout << "Name :" << name << endl;
  cout << "Number of services :" << no_of_services << endl;
  for (int i = 0; i < no_of_services; i++) {
   cout << "Service name :" << services_names[i] << endl;
   cout << "Staff booked for the service :" << service[i] << endl;
  }
 }
};
int Customer::count = 0;
class Packages {

};
class Salon {
private:
 float total_amount;
 Customer* arr[200];//using aggregation
public:
 void copyingarray(Customer(*obj)[200]) {
  for (int i = 0; i < Customer::count; i++) {
   arr[i] = &((*obj)[0]) + i;
  }
 }
 float totalbill() {
  total_amount = 0;
  for (int i = 0; i < Customer::count; i++) {
   total_amount = total_amount + arr[i]->gettotalamount();
  }
  return total_amount;
 }
 void operator !() {//operator overloading
  string name2;
  cout << "Enter Customer Name" << endl;
  cin >> name2;
  for (int i = 0; i < Customer::count; i++) {
   if (arr[i]->getname() == name2) {
    arr[i]->printing();
   }
  }
 }

};
class Schedule : public services {
public:
 static string Weekdays[7];
 static string MakeupArtistAvailability[8];
 static string MeniPediAvailability[5];
 static string HaistylistAvailability[5];
 static string MakeupTimeSlots[3];
 static string MeniPediFacialTimesSlots[4];
 static string HairstyleTimeSlots[4];


 friend void AppointmentAndScheduling(string, string);
 void virtual update() {}
 float virtual billing(int discount) { return 0; }
 void virtual printing() {}
 void print_inquiry() {
  cout << " <--------SERVICES PROVIDED---------> " << endl << endl;
  for (int i = 0; i < 5; i++) {
   if (i == 4) {
    cout << name_services[i] << ". ";
   }
   else {
    cout << name_services[i] << ", ";
   }

  }
  cout << endl << endl;
  cout << " <--------STAFF MEMBERS----------> " << endl << endl;

  cout << "MAKEUP ARTISTS\t\tFEES\t\t\tOFF DAYS" << endl << endl;
  for (int i = 0; i < 8; i++) {
   cout << staff_makeup_artist[i] << "\t\t\t";
   cout << "Rs." << price_makeupartist[i] << "\t\t";
   cout << MakeupArtistAvailability[i] << endl;
  }
  cout << endl;
  cout << "MENI PEDI &n FACIAL\tFEES\t\t\tOFF DAY" << endl << endl;
  for (int i = 0; i < 5; i++) {
   cout << staff_facial_meni_pedi[i] << "\t\t\t";
   cout << price_facial_meni_pedi[i] << "\t\t\t";
   cout << MeniPediAvailability[i] << endl;
  }
  cout << endl;
  cout << "HAIRSTYLISTS\t\tFEES\t\t\tOFF DAY" << endl << endl;
  for (int i = 0; i < 5; i++) {
   cout << staff_hairstylist[i] << "\t\t\t";
   cout << price_hairstyle[i] << "\t\t\t";
   cout << HaistylistAvailability[i] << endl;
  }
 }


};
string Schedule::Weekdays[7] = { "Monday","Tuesday","Wednesday","Thursday","Friday","Saturday","Sunday" };
string Schedule::MakeupArtistAvailability[8] = { "Monday","Monday","Sunday","Wednesday","Friday","Tuesday","Saturday","Thursday" };
string Schedule::MeniPediAvailability[5] = { "Tuesday","Friday","Thursday","Wednesday","Monday" };
string Schedule::HaistylistAvailability[5] = { "Monday","Thursday","Wednesday","Tuesday","Friday" };
string Schedule::MakeupTimeSlots[3] = { "12 p.m. to 4 p.m.","3 p.m. to 7.30 p.m.","6.30p.m. to 9.30 p.m." };
string Schedule::MeniPediFacialTimesSlots[4] = { "12 p.m. to 2 p.m.","2 p.m. to 4 p.m.","6 p.m. to 8 p.m.","8 p.m. to 10 p.m." };
string Schedule::HairstyleTimeSlots[4] = { "12 p.m. to 2 p.m.","2 p.m. to 4 p.m.","6 p.m. to 8 p.m.","8 p.m. to 10 p.m." };
string MakeupTimeSlotBooked[8][6][3];//8 makeup artists, 5 workingdays and 3 timeslots
string MPFTimeSlotsBooked[5][6][4];
string HairstyleTimeSlotsBooked[5][6][4];

void AppointmentAndScheduling(string Service, string StaffName) {
 int choice=0, choice2=0,var=0,var2=0;
 if (Service == "Party Makeup" || Service == "Bridal Makeup") {
  for (int i = 0; i < 8; i++) {
   if (StaffName == services::staff_makeup_artist[i]) {
    cout << "Select" << endl;
    for (int k = 0; k < 7; k++) {
     if (Schedule::Weekdays[k] != Schedule::MakeupArtistAvailability[i]) {
      cout << k + 1 << ": " << Schedule::Weekdays[k] << endl;
     }
     if (Schedule::Weekdays[k] == Schedule::MakeupArtistAvailability[i]) {
      cout << k + 1 << ": " << Schedule::Weekdays[k] << " ------> NOT AVAILABLE!!!" << endl;
      var = k;
     }
    }
    cout << "Select:\n";
    cin >> choice;
    while (choice == var+1) {
     cout << "Please select a valid option!" << endl;
     cin >> choice;
    }
    
    cout << "TimeSlots Available: " << endl;
    for (int l = 0; l < 3; l++) {
     if (MakeupTimeSlotBooked[i][choice - 1][l] != Schedule::MakeupTimeSlots[0]&& MakeupTimeSlotBooked[i][choice - 1][l] != Schedule::MakeupTimeSlots[1] && MakeupTimeSlotBooked[i][choice - 1][l] != Schedule::MakeupTimeSlots[2] ) {
      cout << l + 1 << ": " << Schedule::MakeupTimeSlots[l] << endl;
     }
     else {
      cout << l + 1 << ": " << Schedule::MakeupTimeSlots[l] << " ------> ALREADY BOOKED!!!" << endl;
      var2 = l;
     }
    }
    cout << "Select:\n";
    cin >> choice2;
    while (choice2 == var2 + 1) {
     cout << "Please select a valid option!" << endl;
     cin >> choice2;
    }
    MakeupTimeSlotBooked[i][choice - 1][choice2 - 1] = Schedule::MakeupTimeSlots[choice2 - 1];
    cout << "Makeup Artist: " << StaffName << "\tDay: " << Schedule::Weekdays[choice - 1] << "\t" << "Time: " << MakeupTimeSlotBooked[i][choice - 1][choice2 - 1] << endl;
   }
  }
 }
 if (Service == "Facial,Menicure or Pedicure") {
  for (int i = 0; i < 5; i++) {
   if (StaffName == services::staff_facial_meni_pedi[i]) {
    cout << "Select" << endl;
    for (int k = 0; k < 7; k++) {
     if (Schedule::Weekdays[k] != Schedule::MeniPediAvailability[i]) {
      cout << k + 1 << ": " << Schedule::Weekdays[k] << endl;
     }
     if (Schedule::Weekdays[k] == Schedule::MeniPediAvailability[i]) {
      cout << k + 1 << ": " << Schedule::Weekdays[k] << " ------> NOT AVAILABLE!!!" << endl;
      var = k;
     }
    }
    cout << "Select:\n";
    cin >> choice;
    while (choice == var + 1) {
     cout << "Please select a valid option!" << endl;
     cin >> choice;
    }
    cout << "TimeSlots Available: " << endl;
    for (int l = 0; l < 4; l++) {
     if (MPFTimeSlotsBooked[i][choice - 1][l] != Schedule::MeniPediFacialTimesSlots[0] && MPFTimeSlotsBooked[i][choice - 1][l] != Schedule::MeniPediFacialTimesSlots[1] && MPFTimeSlotsBooked[i][choice - 1][l] != Schedule::MeniPediFacialTimesSlots[2]) {
      cout << l + 1 << ": " << Schedule::MeniPediFacialTimesSlots[l] << endl;
     }
     else {
      cout << l + 1 << ": " << Schedule::MeniPediFacialTimesSlots[l] << " ------> ALREADY BOOKED!!!" << endl;
      var2 = l;
     }
    }
    cout << "Select:\n";
    cin >> choice2;
    while (choice2 == var2 + 1) {
     cout << "Please select a valid option!" << endl;
     cin >> choice2;
    }
    MPFTimeSlotsBooked[i][choice - 1][choice2 - 1] = Schedule::MeniPediFacialTimesSlots[choice2 - 1];
    cout << "Meni, Pedi and Facial Staff: " << StaffName << "\tDay: " << Schedule::Weekdays[choice - 1] << "\t" << "Time: " << MPFTimeSlotsBooked[i][choice - 1][choice2 - 1] << endl;
   }
  }
 }
 if (Service == "Hairstyle") {
  for (int i = 0; i < 5; i++) {
   if (StaffName == services::staff_hairstylist[i]) {
    cout << "Select" << endl;
    for (int k = 0; k < 7; k++) {
     if (Schedule::Weekdays[k] != Schedule::HaistylistAvailability[i]) {
      cout << k + 1 << ": " << Schedule::Weekdays[k] << endl;
     }
     if (Schedule::Weekdays[k] == Schedule::HaistylistAvailability[i]) {
      cout << k + 1 << ": " << Schedule::Weekdays[k] << " ------> NOT AVAILABLE!!!" << endl;
      var = k;
     }
    }
    cout << "Select:\n";
    cin >> choice;
    while (choice == var + 1) {
     cout << "Please select a valid option!" << endl;
     cin >> choice;
    }
    cout << "TimeSlots Available: " << endl;
    for (int l = 0; l < 4; l++) {
     if (HairstyleTimeSlotsBooked[i][choice - 1][l] != Schedule::HairstyleTimeSlots[0] && HairstyleTimeSlotsBooked[i][choice - 1][l] != Schedule::HairstyleTimeSlots[1] && HairstyleTimeSlotsBooked[i][choice - 1][l] != Schedule::HairstyleTimeSlots[2]) {
      cout << l + 1 << ": " << Schedule::HairstyleTimeSlots[l] << endl;
     }
     else {
      cout << l + 1 << ": " << Schedule::HairstyleTimeSlots[l] << " ------> ALREADY BOOKED!!!" << endl;
      var2 = l;
     }
    }
    cout << "Select:\n";
    cin >> choice2;
    while (choice2 == var2 + 1) {
     cout << "Please select a valid option!" << endl;
     cin >> choice2;
    }
    HairstyleTimeSlotsBooked[i][choice - 1][choice2 - 1] = Schedule::HairstyleTimeSlots[choice2 - 1];
    cout << "HairStylist: " << StaffName << "\tDay: " << Schedule::Weekdays[choice - 1] << "\t" << "Time: " << HairstyleTimeSlotsBooked[i][choice - 1][choice2 - 1] << endl;
   }
  }
 }
}
int main() {
 Customer obj[200];//max 200 customers in a day
 int a;
 int k = -1;
 do {
  cout << "Select\n1 : Inquiry\n2 : Appointment \n3 : total amount and admin details\n4 : Pre-booked Appointments \n5 : Execution" << endl;
  cin >> a;
  if (a == 1) {
   services* s = new Schedule();
   s->print_inquiry();
  }
  else if (a == 2) {
   k++;
   string name;
   int no_of_services;
   string service[5];
   int total_amount = 0;
   int record_makeupartist[8];//saving amount earned by each staff
   int record_hairstyle[5];
   int record_facial_meni_pedi[5];
   int p;
   int makeupType;
   string services_names[5];
   cout << "Enter Customer's name :" << endl;
   cin >> name;
   cout << "Enter no of services :" << endl;
   cin >> no_of_services;
   while (no_of_services > 5) {
    cout << "Services cannot be more than 5" << endl;
    cout << "Re-enter number of services" << endl;
    cin >> no_of_services;
   }
   int record[5];
   for (int i = 0; i < no_of_services; i++) {
    cout << "Select\n1 : Makeup\n2 : Facial, Menicure or Pedicure\n3 : Hairstyle" << endl;
    cin >> services_names[i];
    int a1 = 0;
    if (services_names[i] == "1") {
     services_names[i] = "Makeup";
     cout << "Select\n1 : Party Makeup\n2 : Bridal Makeup" << endl;
     cin >> makeupType;
     if (makeupType == 1) {
      services_names[i] = "Party Makeup";
     }
     if (makeupType == 2) {
      services_names[i] = "Bridal Makeup";
     }
     cout << "Select :" << endl;
     for (int j = 0; j < 8; j++) {
      cout << j + 1 << " : " << services::staff_makeup_artist[j] << endl;
     }
     cin >> p;
     p = p - 1;
     for (int j = 0; j < 8; j++) {
      if (p == j) {
       service[i] = services::staff_makeup_artist[j];
       total_amount = services::price_makeupartist[j] + total_amount;
       record[i] = services::price_makeupartist[j];
       cout << service[i] << endl;

      }
     }
    }
    if (services_names[i] == "2") {
     services_names[i] = "Facial,Menicure or Pedicure";
     cout << "Select :" << endl;
     for (int j = 0; j < 5; j++) {
      cout << j + 1 << " : " << services::staff_facial_meni_pedi[j] << endl;
     }
     cin >> p;
     p = p - 1;
     for (int j = 0; j < 5; j++) {
      if (p == j) {
       service[i] = services::staff_facial_meni_pedi[j];
       total_amount = services::price_facial_meni_pedi[j] + total_amount;
       record[i] = services::price_facial_meni_pedi[j];
       cout << service[i] << endl;
      }
     }
    }
    if (services_names[i] == "3") {
     services_names[i] = "Hairstyle";
     cout << "Select :" << endl;
     for (int j = 0; j < 5; j++) {
      cout << j + 1 << " : " << services::staff_hairstylist[j] << endl;
     }
     cin >> p;
     p = p - 1;
     for (int j = 0; j < 5; j++) {
      if (p == j) {
       service[i] = services::staff_hairstylist[j];
       total_amount = services::price_hairstyle[j] + total_amount;
       record[i] = services::price_hairstyle[j];
       cout << service[i] << endl;
      }
     }
    }
    AppointmentAndScheduling(services_names[i], service[i]);
   }

   Customer temp(name, no_of_services, service, services_names, record, total_amount);
   int check;
   do {
    cout << "Select \n1 :Update\n2 :Billing\n3 :Back " << endl;
    cin >> check;
    if (check == 1) {
     temp.update();
    }
    else if (check == 2) {
     int discount;
     cout << "Select\n1 :Platinum Card Membership\n2 :Gold Card Memebership\n3 :Silver Card Membercardship\n4 :No Membership" << endl;
     cin >> discount;
     temp.billing(discount);
    }

   } while (check != 3);
   obj[k] = temp;//For saving data of customer data is being copied in an array;
  }
  else if (a == 3) {
   string password;//Login system
   cout << "Enter Password" << endl;
   cin >> password;
   if (password == "WANsalon@123") {
    while (1) {
     Salon obj2;
     obj2.copyingarray(&obj);
     int abc;
     cout << "Select 1:total billing\nSelect 2:customer Information\nSelect 3:Back" << endl;
     cin >> abc;
     if (abc == 1) {
      cout << "Total Amount : " << obj2.totalbill() << endl;
     }
     else if (abc == 2) {
      !obj2;
     }
     else if (abc == 3) {
      break;
     }
    }
   }
   else {
    cout << "Login Failed" << endl;
   }

  }
 } while (a != 5);
}
