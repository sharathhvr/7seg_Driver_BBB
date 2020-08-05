/*
 * GPIO_drivers.h
 *
 *  Created on: Aug 4, 2020
 *      Author: sharath
 */

#ifndef GPIO_DRIVERS_H_
#define GPIO_DRIVERS_H_

#define SYS_GPIO_PATH       "/sys/class/gpio"

int gpio_export(uint32_t gpio_num);
int gpio_configure_dir(uint32_t gpio_num, uint8_t dir_value);
int gpio_write_value(uint32_t gpio_num, uint8_t out_value);

#endif /* GPIO_DRIVERS_H_ */
