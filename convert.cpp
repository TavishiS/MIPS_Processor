# include <iostream>
# include <fstream>
using namespace std;

void convertToHex(string fname)
{
    ifstream readFile(fname);

    if(!readFile)
    {
        cerr<<"Error opening given file"<<endl;
        return;
    }

    ofstream writeFile("memory_dump_hex", ios::out);

    if(!writeFile)
    {
        cerr<<"Error creating hex file"<<endl;
        return;
    }

    string line;

    while(getline(readFile, line))
    {
        writeFile<<line<<endl;
        for(int i=0;i<3;i++)
        {
            writeFile<<"00000000"<<endl;
        }
    }

    readFile.close();
    writeFile.close();
}

int main()
{
    cout<<"Enter file name"<<endl;
    string fname;
    cin>>fname;
    convertToHex(fname);
    cout<<"Check out the memory_dump_hex file!!"<<endl;
    return 0;
}