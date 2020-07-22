/* Example of hashing in SHA-224 */

#include <iostream>
#include <cryptopp/sha.h>
#include <cryptopp/hex.h>
#include <cryptopp/filters.h>
#include <cryptopp/files.h>
#include <cryptopp/cryptlib.h>

using namespace CryptoPP;

class HASH{
	public:
	static void sha224(std::string clr_msg){
	
		HexEncoder encoder(new FileSink(std::cout));
		std::string digest;
	
		SHA224 sha_224;
		std::cout << "Name > " << sha_224.AlgorithmName() << std::endl;
		std::cout << "Digest size > " << sha_224.DigestSize() << std::endl;
		std::cout << "Block size > " << sha_224.BlockSize() << std::endl << std::endl;
	
		StringSource(clr_msg, true, new HashFilter(sha_224, new StringSink(digest)));
	
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
	
	hash.sha224(clr_msg); // 844518F9598739B808C32858766B1683148273BF6F76FEB861F52DDF
	
	return 0;
}
	
