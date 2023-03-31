#include "hello_world/evaluate_test.cc"
#include "micro_speech/main.cc"
#include "person_detection/main.cc"
#include <iostream>
#include <cstring>

using namespace std;

int main(void) {

    char project_id[1];

    while(1){
 
        cout << "Select project_id to load:\n [0] hello_world\n [1] micro_speech\n [2] person_detection\n ";
        cin >> project_id;
        cout << "\nproject_id: " << project_id << endl;

        if (strcmp(project_id, "0") == 0){
            main_hello_world();
        }
        else if (strcmp(project_id, "1") == 0){
            main_micro_speech();
        }
        else if (strcmp(project_id, "2") == 0){
            main_person_detection();
        }
        else
            ;
    }
    return 0;
}