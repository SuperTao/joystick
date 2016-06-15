
#include <stdio.h>
#include <myerror.h>

struct js_event {
	unsigned int   time;      /* event timestamp in milliseconds */
	unsigned short value;     /* value */
	unsigned char  type;      /* event type */
	unsigned char  number;    /* axis/button number */
};


int main(void)
{
	FILE *filp = NULL ; 

	struct js_event  evt ; 
	
	filp = fopen("/dev/input/js0" , "r");
    if (NULL == filp)
    {
        printf("open joystic fail\n");
        goto err;
    }

	while(1)
	{
		fread(&evt , sizeof(evt) , 1 , filp);
		printf("val:%d  type:%d  number:%d  \n" , evt.value , evt.type , evt.number);
	}

	return 0 ;
err:	
	return -1 ; 
}
