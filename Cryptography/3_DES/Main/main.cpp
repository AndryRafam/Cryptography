/* Andry RAFAM ANDRIANJAFY - 3_DES encryption program.
 * 
 * Compiler version: gcc/g++ 9.3.0 */
 
#include <iostream>
#include "../Tools/header.h"

int main(){
	
	DES des;
	std::string test = "AABB09182736CCDD"; // 16 Bytes (64 bits) long
	/*std::cout <<*/ des.Triple_DES_Encrypt(test); /*<< std::endl;*/
    
    return 0;
}
