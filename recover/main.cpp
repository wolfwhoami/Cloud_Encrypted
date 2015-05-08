#include <fstream>
#include <iostream>
#include <sstream>
#include "bcipher.h"
#include "hexa.h"

int main(int argc, char* argv[]){
	if(argc != 4){
		std::cout<<"Invalid number of arguments"<<std::endl;
		return -1;
	}
	std::string fkeyfile,file,filename;
	std::string input = argv[1];
	std::stringstream ss(input);
	ss >> file;
	ss.str("");

	input = argv[2];
	std::stringstream ss1(input);
	ss1 >> filename;
	ss.str("");

	input = argv[3];
	std::stringstream ss2(input);
	ss2 >> fkeyfile;

        std::string content ="Created by Xuefeng Time: 2015-05-01 14:20";

        Hexa h;
	//Recover phase
	BCipher a;
	std::cout<<"Recover Phase"<<std::endl;
        std:: string signature = a.signature(content);
        std::cout<<"====================================================================="<<std::endl;
        a.generateRSAkeys();
        std::cout<<"====================================================================="<<std::endl;

	a.decrypt(fkeyfile,filename,file,"file_recovered.txt",content, signature);
        h.hex_to_string_decoder1("file_recovered.txt");
	std::cout<<"Recover Phase complete"<<std::endl;

	return 0;
}
