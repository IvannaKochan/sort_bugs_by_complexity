#include <iostream>
#include <algorithm>

using namespace std;

class Bug {
private:
    int severty;
    string deadline;
    string status;
    string assignee;
public:
    Bug() {
        severty = 0;
        deadline = "00.00.0000";
        status = "NOT_RESOLVED";
        assignee = "";

    }
    Bug(int sev, string dead, string status, string assignee1) {
        severty = sev;
        deadline = dead;
        this->status = status;
        assignee = assignee1;
    }
    int get_severty() {
        return severty;
    }
    string get_deadline() {
        return deadline;
    }
    string get_status() {
        return status;
    }
    string get_assignee() {
        return assignee;
    }
    void print_information_about_b() {
        cout << "severty " << severty << endl;
        cout << "deadline " << deadline << endl;
        cout << "assigne " << assignee << endl;
    }

};

#define max_elements 10

std::string company_name;
std::string need_status = "RESOLVED";

//----------------------------------------------------
class BackLog {

public:
    Bug Bugs[max_elements];
    Bug Bug_temp;
    //----------------------------------------------------
    BackLog(){

        for (int i = 0; i < max_elements; i++) {
            Bugs[i] = Bug_temp;
        };
    };
    //----------------------------------------------------
    void find_and_print_bugs_which_need_status(void){
        for (int i = 0; i < max_elements; i++) {
            if ((company_name == Bugs[i].get_assignee()) && (Bugs[i].get_status() == need_status))
                Bugs[i].print_information_about_b();
        };
    };
    //----------------------------------------------------
    //void Fill_element(int sev,string dead , string status, string assignee){
    void fill_information_about_bugs(void) {
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
    void SortingBugsBySeverty(void) {
        int length = sizeof(Bugs) / sizeof(Bugs[0]);

        for (int i = 0; i < length - 1; i++) {
            for (int j = length - 1; j > i; j--) {
                if (Bugs[j - 1].get_severty() < Bugs[j].get_severty()) {
                    std::swap(Bugs[j - 1], Bugs[j]);
                };
            };
        };

    };
};



int main() {

    cout << "\n======= Inicialization Section =================" << endl;
    BackLog BB;
    BB.fill_information_about_bugs();
    cout << "\n======= Printing Section =======================" << endl;

    company_name = "FIRST_COMPANY";

    BB.find_and_print_bugs_which_need_status();
    cout << "\n========= Sorting Section ======================" << endl;

    BB.SortingBugsBySeverty();
    BB.find_and_print_bugs_which_need_status();
    cout << "=================================================="<<endl;
    return 0;
};