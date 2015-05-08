#include <fstream>
#include <iostream>
#include <sstream>
#include "bcipher.h"
#include "hexa.h"
#include <cryptopp/files.h>
#include "cryptopp/osrng.h"
#include "cryptopp/modes.h"
#include "cryptopp/aes.h"
#include "cryptopp/filters.h"
#include "cryptopp/rsa.h"
#include "cryptopp/pssr.h"
#include <cryptopp/base64.h>

using namespace CryptoPP;
int main(int argc, char* argv[]){
	if(argc != 4){
		std::cout<<"Invalid number of arguments"<<std::endl;
		return -1;
	}
	std::string keyfile,file,filename ,cipher1;
	std::string input = argv[1];
	std::stringstream ss(input);
	ss >> keyfile;
	ss.str("");

	input = argv[2];
	std::stringstream ss1(input);
	ss1 >> file;
	ss1.str("");

	input = argv[3];
	std::stringstream ss2(input);
	ss2 >> filename;

	Hexa h;
	std::cout<<"Setting Up Environment" <<std::endl;
	h.string_to_hex_encoder(file);
	h.string_to_hex_encoder(filename);
	std::cout<<"Environment Set"<<std::endl;

        BCipher a;
        a.generateRSAkeys();
        std::cout<<"Done." <<std::endl;
                	
	// PreProcess phase
	std::cout<<"Encrypt Phase"<<std::endl;
	a.encrypt(keyfile,file,"efile.txt");
        a.sha256_pre(filename,"efilename.txt");
        h.hex_to_string_decoder1(file);
	h.hex_to_string_decoder1(filename);
	std::cout<<"Encrypt Phase complete"<<std::endl;

	return 0;
}
