#include <stdio.h>
#include <sys/time.h>
#include <string.h>

struct tr143diagstats_t
{
    struct timeval sysTimeTCPOpenRequest;
    struct timeval sysTimeTCPOpenResponse;
    struct timeval sysTimeROM;
    struct timeval sysTimeBOM;
    struct timeval sysTimeEOM;
    unsigned int TestBytesReceived;
    unsigned int TotalBytesReceived;
    unsigned int TotalBytesSent;
    int BOMOutOctet;
    int EOMOutOctet;
    char DiagnosticsState[64];

};

int main(void)
{
	struct tr143diagstats_t gTR143UldDiagInfo;
	memset(&gTR143UldDiagInfo, 0 , sizeof(gTR143UldDiagInfo));
	FILE *fp = fopen("/tmp/ulDiagResult", "r");
	if (NULL == fp)
	{
		perror("open result error ");
		return -1;
	}

	int rc = fread(&gTR143UldDiagInfo, sizeof(gTR143UldDiagInfo), 1, fp);

	if( rc <=0)
	{
		perror("error fread ");
		return -1;
	}

	printf("infor systimeopen %ld\n", gTR143UldDiagInfo.sysTimeTCPOpenRequest.tv_sec);
	printf("infor systimeresponse %ld\n", gTR143UldDiagInfo.sysTimeTCPOpenResponse.tv_sec);
	printf("infor sysTimeROM %ld\n", gTR143UldDiagInfo.sysTimeROM.tv_sec);
	printf("infor systimeBOM %ld\n", gTR143UldDiagInfo.sysTimeBOM.tv_sec);
	printf("infor systimeEOM %ld\n", gTR143UldDiagInfo.sysTimeEOM.tv_sec);
	printf("infor test byte received %ld\n", gTR143UldDiagInfo.TestBytesReceived);
	printf("infor total byte received %ld\n", gTR143UldDiagInfo.TotalBytesReceived);
	printf("infor total byte sent %ld\n", gTR143UldDiagInfo.BOMOutOctet);
	printf("infor total byte sent %ld\n", gTR143UldDiagInfo.EOMOutOctet);
	printf("infor total byte sent %ld\n", gTR143UldDiagInfo.TotalBytesSent);
	printf("infor diagnosticstate %s\n", gTR143UldDiagInfo.DiagnosticsState);
	return 0;
}
