/*
 * SevenSeg_Driver.h
 *
 *  Created on: Aug 4, 2020
 *      Author: sharath
 */

#ifndef SEVENSEG_DRIVER_H_
#define SEVENSEG_DRIVER_H_

#include<stdint.h>
#include "GPIO_drivers.h"

/*==========================================================================================
BBB_expansion_header_P8_pins           GPIO number            4-digit 7seg Display pin number
=============================================================================================
P8.7                                   GPIO_66                     11   (SEG A)
P8.8                                   GPIO_67                     7    (SEG B)
P8.9                                   GPIO_69                     4	(SEG C)
P8.10                                  GPIO_68                     3	(DP)
P8.11                                  GPIO_45                     2	(SEG D)
P8.12                                  GPIO_44                     1	(SEG E)
P8.14                                  GPIO_26                     10	(SEG F)
P8.16                                  GPIO_46                     5	(SEG G)
============================================================================================ */


/*==========================================================================================
BBB_expansion_header_P9_pins           GPIO number            4-digit 7seg Dispaly pin number
=============================================================================================
P9.15                                   GPIO_48                     12   (DIGIT 1 )
P9.23                                   GPIO_49                      9	 (DIGIT 2 )
P9.30                                   GPIO_112                     8	 (DIGIT 3 )
P9.27                                   GPIO_115                     6	 (DIGIT 4 )
============================================================================================= */

/* un comment this macro only if you use COMMAN CATHODE display */
#define COMMON_CATHODE



#define GPIO_66_P8_7_SEGA       GPIO_66       /*  display pin 11    */
#define GPIO_67_P8_8_SEGB       GPIO_67       /*  display pin 7     */
#define GPIO_69_P8_9_SEGC       GPIO_69       /*  display pin 4     */
#define GPIO_68_P8_10_DP        GPIO_68       /*  display pin 3     */
#define GPIO_45_P8_11_SEGD      GPIO_45       /*  display pin 2     */
#define GPIO_44_P8_12_SEGE      GPIO_44       /*  display pin 1     */
#define GPIO_26_P8_14_SEGF      GPIO_26       /*  display pin 10    */
#define GPIO_46_P8_16_SEGG      GPIO_46       /*  display pin 5     */

#define GPIO_48_P9_15_DIGIT1     GPIO_48       /*  display pin 12    */
#define GPIO_49_P9_23_DIGIT2     GPIO_49       /*  display pin 9     */
#define GPIO_117_P9_30_DIGIT3    GPIO_112      /*  display pin 8     */
#define GPIO_115_P9_27_DIGIT4    GPIO_115      /*  display pin 6     */



#ifdef COMMON_CATHODE
	#define SEGMENT_ON          HIGH_VALUE
	#define SEGMENT_OFF         LOW_VALUE
#else
	#define SEGMENT_ON          LOW_VALUE
	#define SEGMENT_OFF         HIGH_VALUE
#endif


void dispaly_numbers(uint32_t number);
void Write_number_to_7segdisplay(uint8_t numberToDisplay);


#endif /* SEVENSEG_DRIVER_H_ */
