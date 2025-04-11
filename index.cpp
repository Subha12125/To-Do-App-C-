#include<bits/stdc++.h>
using namespace std;

class Task{
    public:
        string description;
        bool completed;

        // constructor
        Task(string desc, bool comp = false) : description(desc), completed(comp) {
            //
        }
        void markCompleted(){
            completed = true;
        }
        string toString() const{
            return description + (completed ? " [Completed]" : " [ ]");
        }

};

class ToDoLApp{
    private: vector<Task> tasks;
    string filename = "text.txt";

    public:
        // Method to add tasks
        void addTask(const string &description){
            tasks.emplace_back(description);
            cout << "Task added successfully";
        }

        // Method for view task
        void display(){
            for(int i=0; i< tasks.size() ; i++){
                cout << i+1 <<"."<<tasks[i].toString()<<endl;
            }
        }

        //Method mark as completed
        void markasCompleted(int index){
            if(index >= 0 && index < tasks.size()){
                tasks[index].markCompleted();
            }
            else{
                cout<<"Please enter a valid index"<< endl;
            }
        }

        //Save Task in file
        void saveTask(){
            ofstream outFile(filename);
            for(auto task : tasks){
                outFile<< task.description << "|" << task.completed<< endl;
            }
            outFile.close();
        }

        // Updating File
        void updateFile(){
            ifstream inFile(filename);
            string line;
            while(getline(inFile, line)){
                size_t pos = line.find("|");
                if(pos != string::npos){
                    string desc = line.substr(0,pos);
                    bool completed = (line.substr(pos+1) == "1");
                    Task task(desc);
                    if(completed){
                        task.markCompleted();
                    }
                    tasks.push_back(task);
                }
            }
            inFile.close();
        }
};

int main(){
    ToDoLApp todoapp;
    int choice;
    string taskDescription;
    do{
        cout << "\nTo-Do List Menu:\n";
        cout << "1. Add Task\n";
        cout << "2. Mark Task Completed\n";
        cout << "3. View Tasks\n";
        cout << "4. Save and Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); // To ignore the newline character after the choice

        switch (choice)
        {
        case 1:
            cout<<"Enter Your task description:";
            getline(cin,taskDescription);
            todoapp.addTask(taskDescription);
            break;
        case 2:
            int index;
            cout<<"Enter the task number to mark as completed"<<endl;
            cin >> index;
            todoapp.markasCompleted(index-1);
            break;
        case 3:
            cout<<"Your To-Do List is :"<<endl;
            todoapp.display();
            break;
        case 4:
            todoapp.saveTask();
            cout<<"Task save and Exit"<<endl;
            break;
        default:
            cout<<"Sorry there is an Error try again ";
            break;
        }

    } while(choice != 4);
    return 0;
}