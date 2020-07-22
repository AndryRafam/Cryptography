/* Example of hashing in SHA-256 */

#include <iostream>
#include <cryptopp/sha.h>
#include <cryptopp/cryptlib.h>
#include <cryptopp/hex.h>
#include <cryptopp/files.h>
#include <cryptopp/filters.h>

using namespace CryptoPP;

class HASH{
	public:
	static void sha256(std::string clr_msg){
		
		HexEncoder encoder(new FileSink(std::cout));
		std::string digest;
		
		SHA256 sha_256;
		std::cout << "Name > " << sha_256.AlgorithmName() << std::endl;
		std::cout << "Digest size > " << sha_256.DigestSize() << std::endl;
		std::cout << "Block size > " << sha_256.BlockSize() << std::endl << std::endl;
		
		StringSource(clr_msg, true, new HashFilter(sha_256, new StringSink(digest)));
		
		std::cout << "[ Digest ] > ";
		StringSource(digest, true, new Redirector(encoder));
		std::cout << std::endl << std::endl;
		
		return;
	}
};

int main(int argc, char **argv){
	HASH hash;
	std::cout << std::endl;
	std::string clr_msg = "Hello Github. This is a test.";
	std::cout << "[ Message ] > " << clr_msg << std::endl << std::endl;
	
	hash.sha256(clr_msg); // F2D73F5D18B2F895496520349F518A484ACB0F982734F61332239686C30AFCA0
	
	return 0;
}
