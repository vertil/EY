
#include <iostream>
#include <fstream>
#include <vector>

#include <filesystem>
#include <sys/stat.h>
#include "randDate.h"
#include "func.h"

int main(int argc, char** argv)
{
    std::vector<std::string> files;
    files.resize(100);

    for (int i = 0; i < files.size(); i++) {
        files[i] = std::to_string(i)+".txt";
    }
    //std::filesystem::path a = argv[1];
    if(!std::filesystem::exists("./files100")){
        std::filesystem::create_directory("./files100");
    }
    std::string fileString;
    fileString.resize(80);
    
    std::ofstream file;
    
    randDate sss;
    //generating 100 files
    /*for (int i = 0; i < files.size(); i++) {      
        
        file.open("./files100/" + files[i]);
                
        for(int j = 0; j < 100000; j++) {
            fileString = sss.getRandDate() + " || ";
            for (int a = 0; a < 10; a++) {
                fileString.push_back(sss.randLat());
            }
            fileString += " || ";
            for (int b = 0; b < 10; b++) {
                fileString.push_back(sss.randRus());
            }
            fileString += " || " + std::to_string(rand()%100000000+1)+" || " + std::to_string(sss.randD())+ " || " +"\n";
            
            file << fileString;
            
        }
        file.close();
 
    }*/
    
    std::cout<<"files generated"<<std::endl;
    std::cout << "What next? " << std::endl;
    std::cout << "Enter 1 - for combine files, 2 - ipmort files to database, 3 - realize database procedure" << std::endl;
    int choise = 0;
    std::string toDel;
    std::cin >> choise;
    //file to write
    //fileR to read
    //fileB to All.txt
    std::ifstream fileR;
    int numofDel=0;
    std::vector<std::string> buffVec;
    //buffVec.resize(100000);
    char buffc[80];
    while (1) {
        if (choise == 1) {
            std::ofstream fileB;//for read
            fileB.open("./files100/All.txt");
            std::cout << "Enter combintion of symbols to delete" << std::endl;
            std::cin >> toDel;
            for (int i = 0; i < 100; i++) {

                fileR.open("./files100/" + files[i]);
                for (int j = 0; j < 100000; j++) {
                    fileR.getline(buffc, 80);
                    fileString = buffc;
                    fileB << fileString << '\n';//add to all.txt
                    //----start edit string
                    std::string::size_type s = fileString.find(toDel);
                    if (s != std::string::npos) {
                        buffVec.push_back(fileString);
                    }
                    //------

                    fileString.clear();

                }
                file.open("./files100/" + files[i]);
                for (int j = 0; j < 100000; j++) {
                    file << buffVec[j] << "\n";
                }
                file.close();
                buffVec.clear();
                fileR.close();
            }
            std::cout << "Number od edited lines - " << numofDel << std::endl;
        }
        if (choise == 2) {

        }
    }










}
