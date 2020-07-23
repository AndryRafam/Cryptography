/* Example of hashing in SHA-512 */

#include <iostream>
#include <cryptopp/cryptlib.h>
#include <cryptopp/sha.h>
#include <cryptopp/hex.h>
#include <cryptopp/files.h>
#include <cryptopp/filters.h>

using namespace CryptoPP;

class HASH{
	public:
	static void sha512(std::string clr_msg){
	
		HexEncoder encoder(new FileSink(std::cout));
		std::string digest;
		
		SHA512 sha_512;
		std::cout << "Name > " << sha_512.AlgorithmName() << std::endl;
		std::cout << "Digest size > " << sha_512.DigestSize() << std::endl;
		std::cout << "Block size > " << sha_512.BlockSize() << std::endl << std::endl;
		
		StringSource(clr_msg, true, new HashFilter(sha_512, new StringSink(digest)));
		
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
	
	hash.sha512(clr_msg); // E854EAF691D151A10F757CF7CA5731960446C6A1817676AA3013A9BF81C8BA25D993656112F113CD6A8704D4BC56D3F05AB6BC1FF3C231BBCAA3BB7184145F6E
	
	return 0;
}

