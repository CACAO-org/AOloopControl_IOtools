/**
 * @file    AOloopControl_IOtools_RTLOGsave.c
 * @brief   Save realtime buffers
 * 
 * @author  O. Guyon
 *
 * 
 */



#define _GNU_SOURCE



#include <string.h>
#include <stdint.h>
#include <math.h>
#include "statistic/statistic.h"
#include "CommandLineInterface/CLIcore.h"
#include "00CORE/00CORE.h"
#include "AOloopControl/AOloopControl.h"
#include "AOloopControl_IOtools/AOloopControl_IOtools.h"
#include "COREMOD_memory/COREMOD_memory.h"








extern AOLOOPCONTROL_CONF *AOconf; // declared in AOloopControl.c






int_fast8_t AOloopControl_IOtools_RTLOGsave(long loop, const char *streamname, const char *dirname)
{
	// data buffers
	char imnameb0[500];
    char imnameb1[500];
	long IDinb0, IDinb1;
	
	// info buffers
	char imnamebinfo0[500];
    char imnamebinfo1[500];
	long IDinbinfo0, IDinbinfo1;
	

    if(sprintf(imnameb0, "aol%ld_%s_logbuff0", loop, streamname) < 1)
        printERROR(__FILE__, __func__, __LINE__, "sprintf wrote <1 char");

    if(sprintf(imnameb1, "aol%ld_%s_logbuff1", loop, streamname) < 1)
        printERROR(__FILE__, __func__, __LINE__, "sprintf wrote <1 char");

    if(sprintf(imnamebinfo0, "aol%ld_%s_logbuffinfo0", loop, streamname) < 1)
        printERROR(__FILE__, __func__, __LINE__, "sprintf wrote <1 char");

    if(sprintf(imnamebinfo1, "aol%ld_%s_logbuffinfo1", loop, streamname) < 1)
        printERROR(__FILE__, __func__, __LINE__, "sprintf wrote <1 char");

   printf("DATA buffers:  %s  %s\n", imnameb0, imnameb1);
   printf("INFO buffers:  %s  %s\n", imnamebinfo0, imnamebinfo1);
   
    IDinb0 = read_sharedmem_image(imnameb0);
    IDinb1 = read_sharedmem_image(imnameb1);
    IDinbinfo0 = read_sharedmem_image(imnamebinfo0);
    IDinbinfo1 = read_sharedmem_image(imnamebinfo1);

	list_image_ID();

/*    cnt0_old = data.image[IDinb0].md[0].cnt0;
    cnt1_old = data.image[IDinb1].md[0].cnt0;

    xsize = data.image[IDinb0].md[0].size[0];
    ysize = data.image[IDinb0].md[0].size[1];
    xysize = xsize*ysize;
    zsize = data.image[IDinb0].md[0].size[2];
    atype = data.image[IDinb0].md[0].atype;
  */ 
    return(0);
}
