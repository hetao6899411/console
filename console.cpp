#include<iostream>
#include<string>
#include<cstdlib>
using namespace std;
string null;
string username, password;
bool passok = false;
string varnames[114];
string varvalues[114];
int next_var_i = 0;
void prnHelp()
{
    cout<<"System settings:"<<endl;
    cout<<"|    help ------- Get helps."<<endl;
    cout<<"|    clear ------- Clear screen."<<endl;
    cout<<"|    editname ------ Edit your username."<<endl;
    cout<<"|    editpass ------ Edit your password."<<endl;
    cout<<"|    exit ------ Exit program."<<endl;
    cout<<"|    lock ------ Lock user."<<endl;
    cout<<"Main command:"<<endl;
    cout<<"|    var ------ Set variable.Must has variable-nane and variable-value.Max can set 114 variables.Varname and value must are a string."<<endl;
    cout<<"|    getvalue ------- Get variable value."<<endl;
    cout<<"|    calc ------- Start Calc."<<endl;
    cout<<"|    konglong ------- Start the KongDangJieLong Game."<<endl;
    cout<<"|    redheart ------- Start the Redheart Fights Game."<<endl;
    cout<<"|    minesw ------- Start the Minesweeper Game."<<endl;
    cout<<"|    cards ------- Start the Cards Game."<<endl;
    cout<<"|    zhizhu ------- Start the ZhiZhu Cards Game."<<endl;
    cout<<"|    draw -------- Start the DrawTools."<<endl;
}
int check_var_is_unique(string chk_varname)
{
    //遍历
    for(int i=0;i<next_var_i;i++)
    {
        if(varnames[i] == chk_varname)
        {
            return i;
        }
    }
    return -1;
}
string str_lower(string s)
{
    int s_len = s.size();
    for(int i=0;i<s_len;i++)
    {
        if(s[i] >= 'A' && s[i] <= 'Z')
        {
            //变成小写
            s[i] += 32;
        }
    }
    return s;
}
int main()
{
    cout<<"Username: ";
    getline(cin, username);

    if(username == "")
    {
        cout<<"Fatal error: UserName can not null."<<endl;
        cout<<"Please press enter-key to exit."<<endl;
        getline(cin, null);
        return 0;
    }

    cout<<"Password: ";
    getline(cin, password);
    cout<<"Seted username and password."<<endl;
    cout<<"Please press enter-key to continue."<<endl;
    getline(cin, null);

    system("cls");
    //开始运行
    if(passok)
    {
        cout<<"Input help to get helps."<<endl;
        cout<<"Using head #, that is a rem."<<endl;
    }
    while(true)
    {
        //确认密码状态
        if(!passok)
        {
            string input_password;
            cout<<"Input your password: ";
            getline(cin, input_password);
            if(input_password == password)
            {
                cout<<"ID passed.Hello, "<<username<<"!"<<endl;
                passok = true;
                cout<<"Press enter-key to continue."<<endl;
                getline(cin, null);
                system("cls");
                cout<<"Input help to get helps."<<endl;
                cout<<"Using head #, that is a rem."<<endl;
            }
            else
            {
                cout<<"Password error.Press enter-key to exit."<<endl;
                getline(cin, null);
                return 0;
            }
        }

        string cmd;
        cout<<">>> ";
        getline(cin, cmd);

        cmd = str_lower(cmd);

        if(cmd == "help")
        {
            prnHelp();
        }
        else if(cmd == "clear")
        {
            system("cls");
            cout<<"Input help to get helps."<<endl;
            cout<<"Using head #, that is a rem."<<endl;
        }
        else if(cmd == "editname")
        {
            cout<<"Warning: After edited username, you need input password."<<endl;
            string newname;
            cout<<"New username: ";
            getline(cin, newname);

            if(newname == "")
            {
                cout<<"Error: UserName can not null."<<endl;
                continue;
            }

            username = newname;
            cout<<"Seted new username."<<endl;
            passok = false;
        }
        else if(cmd == "editpass")
        {
            cout<<"Warning: After edited password, you need input your new password."<<endl;
            //输入旧密码
            cout<<"Please input old password: ";
            string input_old_password;
            getline(cin, input_old_password);
            if(input_old_password != password)
            {
                cout<<"Password wrong.Command invalid."<<endl;
                continue;
            }
            //密码正确，设置新密码
            string new_password;
            cout<<"OK!Please input new password: ";
            getline(cin, new_password);
            password = new_password;
            cout<<"Seted password.Press enter key to continue."<<endl;
            getline(cin, null);
            passok = false;
            system("cls");
        }
        else if(cmd == "exit")
        {
            return 0;
        }
        else if(cmd == "lock")
        {
            //锁定
            system("cls");
            passok = false;
        }
        else if(cmd == "var")
        {
            cout<<"Varname: ";
            string input_varname;
            getline(cin, input_varname);

            if(input_varname == "")
            {
                cout<<"Variable-Error: Can not set the varname is null."<<endl;
                continue;
            }

            int chk_func_retvalue = check_var_is_unique(input_varname);
            if(chk_func_retvalue != -1)
            {
                cout<<"The variable was create.We will update the variable-value after you inputed the new-variable-value."<<endl;
            }

            cout<<"Value: ";
            string input_varvalue;
            getline(cin, input_varvalue);

            //录入
            if(next_var_i >= 114)
            {
                //无法设置变量
                cout<<"Sorry, the variable list was full."<<endl;
                continue;
            }

            if(chk_func_retvalue == -1)
            {
                varnames[next_var_i] = input_varname;
                varvalues[next_var_i] = input_varvalue;
                next_var_i++;
                cout<<"Seted a variable."<<endl;
            }
            else
            {
                //修改值
                varvalues[chk_func_retvalue] = input_varvalue;
                cout<<"Updated value."<<endl;
            }
        }
        else if(cmd == "getvalue")
        {
            cout<<"Varname: ";
            string user_find_varname;
            getline(cin, user_find_varname);

            //开始查找
            bool found = false;
            for(int i=0;i<next_var_i;i++)
            {
                if(varnames[i] == user_find_varname)
                {
                    cout<<"The value is: "<<varvalues[i]<<endl;
                    found = true;
                    break;
                }
            }

            if(found)
            {
                continue;
            }
            cout<<"Has not this variable."<<endl;
        }
        else if(cmd == "calc")
        {
            system("calc.exe");
        }
        else if(cmd == "konglong")
        {
            system("konglong.exe");
        }
        else if(cmd == "redheart")
        {
            system("redheart.exe");
        }
        else if(cmd == "minesw")
        {
            system("minesw.exe");
        }
        else if(cmd == "cards")
        {
            system("cards.exe");
        }
        else if(cmd == "zhizhu")
        {
            system("zhizhu.exe");
        }
        else if(cmd == "draw")
        {
            system("draw.exe");
        }
        else
        {
            if(cmd == "" || cmd[0] == '#')
            {
                continue;
            }
            cout<<"Command invalid."<<endl;
        }
    }
    return 0;
}