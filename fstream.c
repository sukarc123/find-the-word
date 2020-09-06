#include <iostream>
#include <fstream>
#include <vector>
#include <iterator>
#include <string>
#include <algorithm>
#include <boost/algorithm/string.hpp>
 //A class to read data from a csv file.

class CSVReader
{
    std::string fileName;
    std::string delimeter;
public:
    CSVReader(std::string filename, std::string delm = ",") :
            fileName(filename), delimeter(delm)
    { }
    // Function to fetch data from a CSV File
    std::vector<std::vector<std::string> > getData();
};

std::vector<std::vector<std::string> > CSVReader::getData()
{
    std::ifstream file(fileName);
    std::vector<std::vector<std::string> > dataList;
    std::string line = "";
    // Iterate through each line and split the content using delimeter
    while (getline(file, line))
    {
        std::vector<std::string> vec;
        boost::algorithm::split(vec, line, boost::is_any_of(delimeter));
        dataList.push_back(vec);
    }
    // Close the File
    file.close();
    return dataList;
}
int main()
{
    // Creating an object of CSVWriter
    CSVReader reader("EnglishDictionary.csv");
    // Get the data from CSV File
    std::vector<std::vector<std::string> > dataList = reader.getData();
    // Print the content of row by row on screen
    for(std::vector<std::string> vec : dataList)
    {
        for(std::string data : vec)
        {
            std::cout<<data << " , ";
        }
        std::cout<<std::endl;
    }
    return 0;


    bool CheckWord(char* filename, char* search)
{



    int offset;
    string line;
    ifstream Myfile;
    Myfile.open("EnglishDictionary.csv");

    if(Myfile.is_open())
    {
        while(!Myfile.eof())
        {
            getline(Myfile,line);
            if ((offset = line.find(search, 0)) != string::npos)
            {
             cout << "YES '" << search << " \n\n"<< line  <<endl;
             return true;
            }
            else
            {

                cout << "Not found \n\n";

            }
        }
        Myfile.close();
    }
    else
    cout<<"Unable to open this file."<<endl;

    return false;
}


int main ()
{

    CheckWord("EnglishDictionary.csv", "word");

    return 0;
}
}
