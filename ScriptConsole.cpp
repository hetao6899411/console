#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
string null;
string compile_file_name, file_path, username;
FILE* opencode;
string lines[114];
int lines_i = 0;
string varnames[114], varvalues[114];
int vars_i = 0;
int main()
{
    cout<<"Caution: We are not support the commands in System Settings(Exit can use).Run only the commands in Main Command.Can run 114 lines."<<endl;
    cout<<"Compile filename(Must In Desktop): ";
    getline(cin, compile_file_name);
    cout<<"Computer Username: ";
    getline(cin, username);
    file_path = "C:/Users/" + username + "/Desktop/" + compile_file_name;
    opencode = freopen(file_path.c_str(), "r", stdin);
    if(opencode == NULL)
    {
        cout<<"Fatal Error: File not found."<<endl;
        return 0;
    }
    //运行脚本文件
    cout<<"Compiling..."<<endl;
    cout<<"Reading..."<<endl;
    while(getline(cin, lines[lines_i]))
    {
        if(lines_i >= 114)
        {
            cout<<"Fatal Error: Reading Error: Lines over 114."<<endl;
            return 0;
        }
        lines_i++;
    }
    //正式编译
    cout<<"Running..."<<endl;
    int next_is_arg = 0;
    string just_cmd;
    for(int i=0;i<lines_i;i++)
    {
        if(next_is_arg > 0)
        {
            if(just_cmd == "var")
            {
                if(vars_i >= 114)
                {
                    cout<<"Traceback: Line "<<i+1<<": Variable list was full."<<endl;
                    return 0;
                }
                if(next_is_arg == 1)
                {
                    if(lines[i] == "")
                    {
                        cout<<"Traceback: Line "<<i+1<<": Variable name can not null."<<endl;
                        return 0;
                    }
                    varnames[vars_i] = lines[i];
                    next_is_arg++;
                }
                else if(next_is_arg == 2)
                {
                    varvalues[vars_i] = lines[i];
                    vars_i++;
                    next_is_arg = 0;
                }
            }
            else if(just_cmd == "getvalue")
            {
                bool found = false;
                for(int j=0;j<vars_i;j++)
                {
                    if(varnames[j] == lines[i])
                    {
                        cout<<varvalues[j]<<endl;
                        next_is_arg = 0;
                        found = true;
                        break;
                    }
                }
                if(!found)
                {
                    cout<<"Traceback: Line "<<i+1<<": Variable "<<lines[i]<<" not found."<<endl;
                    return 0;
                }
            }
            continue;
        }
        if(lines[i] == "exit")
        {
            break;
        }
        else if(lines[i] == "var")
        {
            next_is_arg = 1;
            just_cmd = "var";
        }
        else if(lines[i] == "getvalue")
        {
            next_is_arg = 1;
            just_cmd = "getvalue";
        }
        else if(lines[i] == "calc")
        {
            system("Desktop\\ScriptConsole\\calc.exe");
        }
        else if(lines[i] == "konglong")
        {
            system("Desktop\\ScriptConsole\\konglong.exe");
        }
        else if(lines[i] == "redheart")
        {
            system("Desktop\\ScriptConsole\\redheart.exe");
        }
        else if(lines[i] == "minesw")
        {
            system("Desktop\\ScriptConsole\\minesw.exe");
        }
        else if(lines[i] == "cards")
        {
            system("Desktop\\ScriptConsole\\cards.exe");
        }
        else if(lines[i] == "zhizhu")
        {
            system("Desktop\\ScriptConsole\\zhizhu.exe");
        }
        else
        {
            if(lines[i] == "" || lines[i][0] == '#')
            {
                continue;
            }
            cout<<"Traceback: In line "<<i+1<<": Command not found."<<endl;
            return 0;
        }
    }
    cout<<"Did program."<<endl;
    return 0;
}