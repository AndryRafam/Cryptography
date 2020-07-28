// RSA (OAEP/SHA)

#include <iostream>
#include <string>
#include <exception>
#include <cryptopp/rsa.h>
#include <cryptopp/filters.h>
#include <cryptopp/files.h>
#include <cryptopp/osrng.h>
#include <cryptopp/cryptlib.h>
#include <cryptopp/hex.h>

using namespace CryptoPP;

class Rsa{
	public:
	static void rsa(std::string clr_text){
		
		try{
		
			HexEncoder encoder(new FileSink(std::cout));
		
			// Generate keys 4096 bits
			AutoSeededRandomPool rng;
			InvertibleRSAFunction parameters;
			parameters.GenerateRandomWithKeySize(rng,4096);
		
			RSA::PrivateKey privateKey(parameters);
			RSA::PublicKey publicKey(parameters);
		
			std::string cipher;
		
			// Encryption
			RSAES_OAEP_SHA_Encryptor e(publicKey);
			
			StringSource(clr_text, true, new PK_EncryptorFilter(rng,e,new StringSink(cipher)));
		
			std::cout << "[ RSA Encrypt ] > ";
			StringSource(cipher, true, new Redirector(encoder));
			std::cout << std::endl << std::endl;
		}
		catch(Exception& e){
			std::cerr << "Caugh Exception..." << std::endl;
			std::cerr << e.what() << std::endl;
		}
		return;
	}
};

int main(int argc, char **argv){
	std::string plain = "Hello Github. This is RSA encryption test.";
	std::cout << std::endl;
	std::cout << "[ Clear MSG ] > " << plain << std::endl << std::endl;	
	Rsa::rsa(plain);
	
	return 0;
}

