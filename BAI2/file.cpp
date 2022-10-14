#include <iostream>
#include <fstream>

using namespace std;

bool check_existed_file(string filename) 
{   
    bool ok = false;
    ifstream ifs(filename);
    if (ifs.is_open) ok = true;
    ifs.close();
    return ok;
}

void create_new_file(string filename) 
{
    bool ok = check_existed_file(filename);
    if (!ok) 
    {
        ofstream ofs;
        ofs.open(filename, std::ios::out);
        if (ofs) cout << "Created file successfully!\n";
        else cout << "Cannot creat file!\n";
        ofs.close();
    }
    else 
        cout << "file existed! \n";
}

bool write_new_file(string filename, string buff) 
{
    ofstream ofs;
    ofs.open(filename, std::ios::out);
    if (ofs) 
    {
        ofs << buff;
        cout << "Done!\n";
    }
    else cout << "Cannot open file!\n";
    ofs.close();
}

void write_append_file(string filename, string buff) 
{
    ofstream ofs;
    ofs.open(filename, std::ios::out | std::ios::app);
    if (ofs) 
    {
        ofs << buff;
        cout << "Done!\n";
    }
    else cout << "Cannot open file!\n";
    ofs.close();
}

void rename_file(string old_name, string new_name) 
{
    if (rename(old_name.c_str(), new_name.c_str()) != 0) 
        perror("Error to rename file");
    else cout << "Renamed file successfully!\n";
}

void delete_file(string filename) 
{
    if (remove(filename.c_str()) != 0) 
        perror("Error to delete file");
    else cout << "Deleted file successfully!\n";
}

void copy_file(string filename_org, string filename_copy) 
{
    if (check_existed_file(filename_copy)) 
    {
        cout << "filename copy existed!\n";
        return;
    }
    ifstream ifs{filename_org};
    ofstream ofs{filename_copy};
    string line;
    if (ifs && ofs) {
  
        while (getline(ifs, line)) {
            ofs << line << "\n";
        }
        cout << "Copied successfully! \n";
    }
    else {
        perror("Error");
    }
    ifs.close();
    ofs.close();
}

void move_file(string filename_from, string filename_to) 
{
    if (check_existed_file(filename_to)) {
        cout << "filename_to existed!\n";
        return;
    }
    copy_file(filename_from,filename_to);
    delete_file(filename_from);
    cout << "Done!\n";
}


int main() 
{
    string filename = "abc.txt";
    string buff = "Nguyen Dinh Phat \nNguyen Quang Huy";
    string buff2 = "\nLe Van Truong";

    create_file(filename);

    write_new_file(filename, buff);

    // write_append_file(filename, buff2);

    // rename_file("abc.txt", "xyz.txt");

    // delete_file("xyz.txt");

    // copy_file("abc.txt", "/home/phatnd/HomeLazy/BAI2/dir_copy/xyz.txt");
    
    // move_file("abc.txt", "/home/phatnd/HomeLazy/BAI2/dir_copy/xyz.txt");

    return 0;
}