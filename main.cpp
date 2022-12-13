#include <iostream>
#include <algorithm>

using namespace std;

class Bug {
private:
    int severty;
    string deadline;
    string Status;
    string assignee;
public:
    Bug() {
        severty = 0;
        deadline = "00.00.0000";
        Status = "NOT_RESOLVED";
        assignee = "";

    }
    Bug(int sev, string dead, string Status, string assignee1) {
        severty = sev;
        deadline = dead;
        this->Status = Status;
        assignee = assignee1;
    }
    int Get_severty() {
        return severty;
    }
    string Get_deadline() {
        return deadline;
    }
    string Get_status() {
        return Status;
    }
    string Get_assignee() {
        return assignee;
    }
    void Information() {
        cout << "Severty " << severty << endl;
        cout << "deadline " << deadline << endl;
        cout << "assigne " << assignee << endl;
    }

};

#define Max_elements 10

std::string Company_name;
std::string Need_status = "RESOLVED";

//----------------------------------------------------
class Back_Log {

public:
    Bug Bugs[Max_elements];
    Bug Bug_temp;
    //----------------------------------------------------
    Back_Log()
    {

        int i = 0;
        for (i = 0; i < Max_elements; i++) {
            Bugs[i] = Bug_temp;
        };
    };
    //----------------------------------------------------
    void Print(void) {
        for (int i = 0; i < Max_elements; i++) {
            if ((Company_name == Bugs[i].Get_assignee()) && (Bugs[i].Get_status() == Need_status))
                Bugs[i].Information();
        };
    };
    //----------------------------------------------------
    //void Fill_element(int sev,string dead , string Status, string assignee){
    void Fill_element(void) {
        Bug Temp_Bug1(4, "13.11.2022", "RESOLVED", "FIRST_COMPANY");
        Bug Temp_Bug2(55, "15.11.2022", "NOT_RESOLVED", "SECOND_COMPANY");
        Bug Temp_Bug3(90, "13.11.2022", "RESOLVED", "FIRST_COMPANY");
        Bug Temp_Bug4(5, "15.11.2022", "NOT_RESOLVED", "SECOND_COMPANY");
        Bug Temp_Bug5(150, "13.11.2022", "RESOLVED", "FIRST_COMPANY");
        Bug Temp_Bug6(35, "15.11.2022", "RESOLVED", "SECOND_COMPANY");
        Bug Temp_Bug7(20, "13.11.2022", "RESOLVED", "FIRST_COMPANY");
        Bug Temp_Bug8(15, "15.11.2022", "NOT_RESOLVED", "SECOND_COMPANY");
        Bug Temp_Bug9(70, "13.11.2022", "RESOLVED", "FIRST_COMPANY");
        Bug Temp_Bug10(55, "15.11.2022", "NOT_RESOLVED", "FIRST_COMPANY");

        //    Bugs[number].
        Bugs[0] = Temp_Bug1;
        Bugs[1] = Temp_Bug2;
        Bugs[2] = Temp_Bug3;
        Bugs[3] = Temp_Bug4;
        Bugs[4] = Temp_Bug5;
        Bugs[5] = Temp_Bug6;
        Bugs[6] = Temp_Bug7;
        Bugs[7] = Temp_Bug8;
        Bugs[8] = Temp_Bug9;
        Bugs[9] = Temp_Bug10;

    };
    //----------------------------------------------------
    void Sorting(void) {
        int length = sizeof(Bugs) / sizeof(Bugs[0]);

        for (int i = 0; i < length - 1; i++) {
            for (int j = length - 1; j > i; j--) {
                if (Bugs[j - 1].Get_severty() < Bugs[j].Get_severty()) {
                    std::swap(Bugs[j - 1], Bugs[j]);
                };
            };
        };

    };
};



int main() {

    cout << "\n======= Inicialization Section =================" << endl;
    Back_Log BB;
    BB.Fill_element();
    cout << "\n======= Printing Section =======================" << endl;

    Company_name = "FIRST_COMPANY";

    BB.Print();
    cout << "\n========= Sorting Section ======================" << endl;

    BB.Sorting();
    BB.Print();
    cout << "=================================================="<<endl;
    return 0;
};