/* Example of hashing using SHA-1 */

#include <iostream>
#include <cryptopp/sha.h>
#include <cryptopp/cryptlib.h>
#include <cryptopp/filters.h>
#include <cryptopp/hex.h>
#include <cryptopp/files.h>

using namespace CryptoPP;

class HASH{
	public:
	static void sha1(std::string clr_msg){
	
		HexEncoder encoder(new FileSink(std::cout));
		std::string digest;
	
		SHA1 sha_1;
		std::cout << "Name > " << sha_1.AlgorithmName() << std::endl;
		std::cout << "Digest size > " << sha_1.DigestSize() << std::endl;
		std::cout << "Block size > " << sha_1.BlockSize() << std::endl << std::endl;
		
		StringSource(clr_msg, true, new HashFilter(sha_1, new StringSink(digest)));
	
		std::cout << "[ Digest ] > ";
		StringSource(digest, true, new Redirector(encoder));
		std::cout << std::endl << std::endl;
	
		return;
	}
};

int main(int argc, char **argv){
	HASH hash;
	
	std::string clr_msg;
	std::cout << std::endl;
	
	clr_msg = "Hello Github. This is a test.";
	std::cout << "[ Message ] > " << clr_msg;
	std::cout << std::endl << std::endl;
	
	hash.sha1(clr_msg); // F3CDCE0C7A90DB46B8538E7D72BBDE08FF903DC6
		
	return 0;
}
	
 
