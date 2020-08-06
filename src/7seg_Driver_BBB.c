/*
 ============================================================================
 Name        : 7seg_Driver_BBB.c
 Author      : Sharath
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <fcntl.h>
#include <unistd.h>
#include <time.h>
#include "GPIO_drivers.h"
#include "SevenSeg_Driver.h"



int main(void)
{

	int hours,minutes;
	int value=0;
	printf("digital clock application\n");


	        /*first lets export all required gpios */
	        gpio_export(GPIO_66_P8_7_SEGA);
	        gpio_export(GPIO_67_P8_8_SEGB);
	        gpio_export(GPIO_69_P8_9_SEGC);
	        gpio_export(GPIO_68_P8_10_DP);
	        gpio_export(GPIO_45_P8_11_SEGD);
	        gpio_export(GPIO_44_P8_12_SEGE);
	        gpio_export(GPIO_26_P8_14_SEGF);
	        gpio_export(GPIO_46_P8_16_SEGG);

	        gpio_export(GPIO_48_P9_15_DIGIT1);
	        gpio_export(GPIO_49_P9_23_DIGIT2);
	        gpio_export(GPIO_117_P9_30_DIGIT3);
	        gpio_export(GPIO_115_P9_27_DIGIT4);

	        /*first configure the direction for segments */

	        gpio_configure_dir(GPIO_66_P8_7_SEGA,GPIO_DIR_OUT);
	        gpio_configure_dir(GPIO_67_P8_8_SEGB,GPIO_DIR_OUT);
	        gpio_configure_dir(GPIO_69_P8_9_SEGC,GPIO_DIR_OUT);
	        gpio_configure_dir(GPIO_68_P8_10_DP,GPIO_DIR_OUT);
	        gpio_configure_dir(GPIO_45_P8_11_SEGD,GPIO_DIR_OUT);
	        gpio_configure_dir(GPIO_44_P8_12_SEGE,GPIO_DIR_OUT);
	        gpio_configure_dir(GPIO_26_P8_14_SEGF,GPIO_DIR_OUT);
	        gpio_configure_dir(GPIO_46_P8_16_SEGG,GPIO_DIR_OUT);

	        /*configure the direction for digit control */
	        gpio_configure_dir(GPIO_48_P9_15_DIGIT1,GPIO_DIR_OUT);
	        gpio_configure_dir(GPIO_49_P9_23_DIGIT2,GPIO_DIR_OUT);
	        gpio_configure_dir(GPIO_117_P9_30_DIGIT3,GPIO_DIR_OUT);
	        gpio_configure_dir(GPIO_115_P9_27_DIGIT4,GPIO_DIR_OUT);

	        /* make all segments low */
	        gpio_write_value(GPIO_66_P8_7_SEGA,SEGMENT_OFF);
	        gpio_write_value(GPIO_67_P8_8_SEGB,SEGMENT_OFF);
	        gpio_write_value(GPIO_69_P8_9_SEGC,SEGMENT_OFF);
	        gpio_write_value(GPIO_68_P8_10_DP,SEGMENT_OFF);
	        gpio_write_value(GPIO_45_P8_11_SEGD,SEGMENT_OFF);
	        gpio_write_value(GPIO_44_P8_12_SEGE,SEGMENT_OFF);
	        gpio_write_value(GPIO_26_P8_14_SEGF,SEGMENT_OFF);
	        gpio_write_value(GPIO_46_P8_16_SEGG,SEGMENT_OFF);

	        /*MAKE ALL DIGITS OFF */
	        gpio_write_value(GPIO_48_P9_15_DIGIT1,GPIO_HIGH_VALUE);
	        gpio_write_value(GPIO_49_P9_23_DIGIT2,GPIO_HIGH_VALUE);
	        gpio_write_value(GPIO_117_P9_30_DIGIT3,GPIO_HIGH_VALUE);
	        gpio_write_value(GPIO_115_P9_27_DIGIT4,GPIO_HIGH_VALUE);

	        time_t rawtime;
		    struct tm * timeinfo;


	        char buf[6];
	        while(1)
	        {
	        	time ( &rawtime );
			    timeinfo = localtime ( &rawtime );
			   // correct the time according to your timezone
			    hours=timeinfo->tm_hour;
			    minutes=timeinfo->tm_min;
			    hours=(hours+5)%23;
			    minutes=(minutes+52);
			    if(minutes > 59)
			    {
			    	hours=(hours+1)%23;
			    	minutes=(minutes%59);
			    }
			    sprintf(buf,"%02d%02d",hours,minutes);
			    value=atoi(buf);
	        	dispaly_numbers(value);
	        }


	return EXIT_SUCCESS;
}
