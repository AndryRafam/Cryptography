/* Example of hashing in SHA-384 */

#include <iostream>
#include <cryptopp/cryptlib.h>
#include <cryptopp/sha.h>
#include <cryptopp/hex.h>
#include <cryptopp/files.h>
#include <cryptopp/filters.h>

using namespace CryptoPP;

class HASH{
	public:
	static void sha384(std::string clr_msg){
	
		HexEncoder encoder(new FileSink(std::cout));
		std::string digest;
		
		SHA384 sha_384;
		std::cout << "Name > " << sha_384.AlgorithmName() << std::endl;
		std::cout << "Digest size > " << sha_384.DigestSize() << std::endl;
		std::cout << "Block size > " << sha_384.BlockSize() << std::endl << std::endl;
		
		StringSource(clr_msg, true, new HashFilter(sha_384, new StringSink(digest)));
		
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
	
	hash.sha384(clr_msg); // 221121B97C6956ECE4EC12ECF53895475B337FEA54325B73B35236A54ABAC4813775E58BA1D89A0184FF98B732A79907
	
	return 0;
}
		
