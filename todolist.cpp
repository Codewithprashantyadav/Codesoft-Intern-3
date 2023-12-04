#include<bits/stdc++.h>
using namespace std;

#define cls system("cls");

class task_list
{
    public:

    map<int,pair<string,bool>> task_map;
    int size_of_list;
    int task_no;

    task_list()
    {
        size_of_list=0, task_no=0;
    }

    void add_task(string task)
    {
        if(size_of_list==0)
        {
            task_no=0;
        }

        task_no++;
        size_of_list++;

        task_map.insert({task_no,{task,false}});
        cout<<"\n --> Task inserted with id: "<<task_no<<"\n";
    }

    void view_all_tasks()
    {
        if(size_of_list==0)
        {
            cout<<"\n --> LIST IS EMPTY !!";
            return ;
        }

        cout<<"\n ALL THE TASKS PRESENT IN THE LIST: \n\n";
        for(auto it:task_map)
        {
            int key=it.first;
            string task_details=it.second.first;
            string status=it.second.second==false ? "Pending":"Completed";

            cout<<" Id: "<<key<<" | TASK: "<<task_details<<" | Status: "<<status<<"\n";
        }
        cout<<"\n";
    }

    void mark_complete(int task_id)
    {
        if(size_of_list==0)
        {
            cout<<"\n --> LIST IS EMPTY !!\n";
            return ;
        }

        else if(task_map.find(task_id)==task_map.end())
        {
            cout<<"\n --> TASK ID PROVIDED IS INVALID\n";
            return ;
        }

        else if(task_map[task_id].second)
        {
            cout<<"\n --> TASK IS ALREADY MARKED TRUE\n";
            return ;
        }

        task_map[task_id].second=true;

        cout<<"\n --> TASK WITH TASK ID "<<task_id<<" HAS BEEN MARKED COMPLETED\n";
    }

    void remove_task(int task_id)
    {
        if(size_of_list==0)
        {
            cout<<"\n --> LIST IS EMPTY !!";
            return ;
        }

        if(task_map.find(task_id)==task_map.end())
        {
            cout<<"\n --> TASK ID PROVIDED IS INVALID";
            return ;
        }

        task_map.erase(task_id);
        size_of_list--;

        cout<<"\n --> TASK WITH TASK ID "<<task_id<<" HAS BEEN REMOVED FROM LIST\n";
    }
};

void title_display()
{
    cout<<"\n\n************************************************************************************************************************************************";
    cout<<"\n\t\t\t\t\t\t\t\t TO-DO LIST ";
    cout<<"\n************************************************************************************************************************************************\n";
}

void section_disp(int sec)
{
    cout<<"\n\t\t\t\t\t\t\t\tSection - "<<sec;
    cout<<"\n================================================================================================================================================\n";
}

void thanks_message()
{
    cout<<"\n\n================================================================================================================================================";
    cout<<"\n\t\t\t\t\t\t\t         THANK YOU";
    cout<<"\n================================================================================================================================================";
}

int main()
{
    system("color B4");
    task_list obj;
    cls
    while(true)
    {
        
        title_display();
        cout<<endl;

        cout<<"1. ADD new task\n";
        cout<<"2. VIEW all tasks\n";
        cout<<"3. MARK a task as completed\n";
        cout<<"4. REMOVE a task from list\n";
        cout<<"5. EXIT";

        int choice;
        cout<<"\n\n --> ENTER YOUR CHOICE: ";
        cin>>choice;
        char again;

        switch(choice)
        {
            case 1:

                do{
                    cls
                    title_display();
                    section_disp(1);

                    string task_details;
                    cout<<"\n Enter the task details: ";
                    cin.ignore(1,'\n');
                    getline(cin,task_details);

                    obj.add_task(task_details);

                    cout<<"\n <> Do you want to enter more tasks ? (y-yes/n-no) : ";
                    cin>>again;
                    cin.ignore(1,'\n');

                }while(again=='Y' || again=='y');

                break;

            case 2:

                cls
                title_display();
                section_disp(2);

                obj.view_all_tasks();
                cout<<"\n\n ";
                system("pause");
                break;
            
            case 3:

                do{
                    cls
                    title_display();
                    section_disp(3);

                    if(obj.size_of_list==0)
                    {
                        cout<<"\n --> LIST IS EMPTY !!\n\n ";
                        system("pause");
                        break;
                    }

                    obj.view_all_tasks();

                    int task_id;
                    cout<<"\n Enter the task id which you want to mark complete: ";
                    cin>>task_id;

                    obj.mark_complete(task_id);

                    cout<<"\n <> Do you want to mark more tasks ? (y-yes/n-no) : ";
                    cin>>again;

                }while(again=='Y' || again=='y');

                break;
            
            case 4:

                do{
                    cls
                    title_display();
                    section_disp(4);

                    if(obj.size_of_list==0)
                    {
                        cout<<"\n --> LIST IS EMPTY !!\n\n ";
                        system("pause");
                        break;
                    }

                    obj.view_all_tasks();

                    int task_id;
                    cout<<"\n Enter the task id which you want to remove: ";
                    cin>>task_id;

                    obj.remove_task(task_id);

                    cout<<"\n <> Do you want to remove more tasks ? (y-yes/n-no) : ";
                    cin>>again;

                }while(again=='Y' || again=='y');
                
                break;
            
            case 5:
                thanks_message();
                cout<<"\n\n\n\n\n\n\n";
                return 0;
            
            default: 
                cout<<"\n INVALID CHOICE";
                system("pause");
        }

        cls
        
    }


    thanks_message();
    cout<<"\n\n\n\n\n\n\n";
    return 0;
}