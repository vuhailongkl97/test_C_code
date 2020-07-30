#include <openssl/md5.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>


int32_t swap_int32( int32_t val )
{
    val = ((val << 8) & 0xFF00FF00) | ((val >> 8) & 0xFF00FF ); 
    return (val << 16) | ((val >> 16) & 0xFFFF);
}
int main()
{
    unsigned char result[MD5_DIGEST_LENGTH];
    const unsigned char* str;
  
	MD5_CTX context;
    str = (unsigned char*)"hello";
    unsigned int long_size = 100;
    MD5Init(&context);
    MD5Update(&context, "123456", 6);
	MD5Final(result, &context);
	
	for(int i = 0; i< MD5_DIGEST_LENGTH; i++)
		printf("%2x ", (result[i]));
}
