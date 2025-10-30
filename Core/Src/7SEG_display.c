/*
 * 7SEG_display.c
 *
 *  Created on: Oct 17, 2025
 *      Author: dinhh
 */

#include "7SEG_display.h"

void set_on_4digits()
{
	status_4digits[0] = LED_ON;
	status_4digits[1] = LED_ON;
	status_4digits[2] = LED_ON;
	status_4digits[3] = LED_ON;
}

void unable_4digit() {
	HAL_GPIO_WritePin(EN_0_GPIO_Port, EN_0_Pin, DISABLE);
	HAL_GPIO_WritePin(EN_1_GPIO_Port, EN_1_Pin, DISABLE);
	HAL_GPIO_WritePin(EN_2_GPIO_Port, EN_2_Pin, DISABLE);
	HAL_GPIO_WritePin(EN_3_GPIO_Port, EN_3_Pin, DISABLE);
}

void display_4digits() {
	if ((status_4digits[led_7seg_index] == LED_ON) &&
		((led_7seg_index == 1 && led_7seg_buffer[0]) || (led_7seg_index == 3 && led_7seg_buffer[2])
					    							 || led_7seg_buffer[led_7seg_index]))
	{
		display_a_digit(led_7seg_index, led_7seg_buffer[led_7seg_index]);
	}
	++led_7seg_index;
	if (led_7seg_index > 3)
	{
		led_7seg_index = 0;
	}
}

void update_led_7seg_buffer()
{
	led_7seg_buffer[0] = (counter_way0 / 10) % 10;
	led_7seg_buffer[1] = counter_way0 % 10;
	led_7seg_buffer[2] = (counter_way1 / 10) % 10;
	led_7seg_buffer[3] = counter_way1 % 10;
}

void display_a_digit(int digit, int num)
{
	unable_4digit();
	display_number(num);
	enable_digit(digit);
}

void display_number(int num)
{
	switch (num) {
		case 0:
			HAL_GPIO_WritePin(SEG_0_GPIO_Port, SEG_0_Pin, LED_ON);
			HAL_GPIO_WritePin(SEG_1_GPIO_Port, SEG_1_Pin, LED_ON);
			HAL_GPIO_WritePin(SEG_2_GPIO_Port, SEG_2_Pin, LED_ON);
			HAL_GPIO_WritePin(SEG_3_GPIO_Port, SEG_3_Pin, LED_ON);
			HAL_GPIO_WritePin(SEG_4_GPIO_Port, SEG_4_Pin, LED_ON);
			HAL_GPIO_WritePin(SEG_5_GPIO_Port, SEG_5_Pin, LED_ON);
			HAL_GPIO_WritePin(SEG_6_GPIO_Port, SEG_6_Pin, LED_OFF);
			HAL_GPIO_WritePin(SEG_7_GPIO_Port, SEG_7_Pin, LED_OFF);
			break;
		case 1:
			HAL_GPIO_WritePin(SEG_0_GPIO_Port, SEG_0_Pin, LED_OFF);
			HAL_GPIO_WritePin(SEG_1_GPIO_Port, SEG_1_Pin, LED_ON);
			HAL_GPIO_WritePin(SEG_2_GPIO_Port, SEG_2_Pin, LED_ON);
			HAL_GPIO_WritePin(SEG_3_GPIO_Port, SEG_3_Pin, LED_OFF);
			HAL_GPIO_WritePin(SEG_4_GPIO_Port, SEG_4_Pin, LED_OFF);
			HAL_GPIO_WritePin(SEG_5_GPIO_Port, SEG_5_Pin, LED_OFF);
			HAL_GPIO_WritePin(SEG_6_GPIO_Port, SEG_6_Pin, LED_OFF);
			HAL_GPIO_WritePin(SEG_7_GPIO_Port, SEG_7_Pin, LED_OFF);
			break;
		case 2:
			HAL_GPIO_WritePin(SEG_0_GPIO_Port, SEG_0_Pin, LED_ON);
			HAL_GPIO_WritePin(SEG_1_GPIO_Port, SEG_1_Pin, LED_ON);
			HAL_GPIO_WritePin(SEG_2_GPIO_Port, SEG_2_Pin, LED_OFF);
			HAL_GPIO_WritePin(SEG_3_GPIO_Port, SEG_3_Pin, LED_ON);
			HAL_GPIO_WritePin(SEG_4_GPIO_Port, SEG_4_Pin, LED_ON);
			HAL_GPIO_WritePin(SEG_5_GPIO_Port, SEG_5_Pin, LED_OFF);
			HAL_GPIO_WritePin(SEG_6_GPIO_Port, SEG_6_Pin, LED_ON);
			HAL_GPIO_WritePin(SEG_7_GPIO_Port, SEG_7_Pin, LED_OFF);
			break;
		case 3:
			HAL_GPIO_WritePin(SEG_0_GPIO_Port, SEG_0_Pin, LED_ON);
			HAL_GPIO_WritePin(SEG_1_GPIO_Port, SEG_1_Pin, LED_ON);
			HAL_GPIO_WritePin(SEG_2_GPIO_Port, SEG_2_Pin, LED_ON);
			HAL_GPIO_WritePin(SEG_3_GPIO_Port, SEG_3_Pin, LED_ON);
			HAL_GPIO_WritePin(SEG_4_GPIO_Port, SEG_4_Pin, LED_OFF);
			HAL_GPIO_WritePin(SEG_5_GPIO_Port, SEG_5_Pin, LED_OFF);
			HAL_GPIO_WritePin(SEG_6_GPIO_Port, SEG_6_Pin, LED_ON);
			HAL_GPIO_WritePin(SEG_7_GPIO_Port, SEG_7_Pin, LED_OFF);
			break;
		case 4:
			HAL_GPIO_WritePin(SEG_0_GPIO_Port, SEG_0_Pin, LED_OFF);
			HAL_GPIO_WritePin(SEG_1_GPIO_Port, SEG_1_Pin, LED_ON);
			HAL_GPIO_WritePin(SEG_2_GPIO_Port, SEG_2_Pin, LED_ON);
			HAL_GPIO_WritePin(SEG_3_GPIO_Port, SEG_3_Pin, LED_OFF);
			HAL_GPIO_WritePin(SEG_4_GPIO_Port, SEG_4_Pin, LED_OFF);
			HAL_GPIO_WritePin(SEG_5_GPIO_Port, SEG_5_Pin, LED_ON);
			HAL_GPIO_WritePin(SEG_6_GPIO_Port, SEG_6_Pin, LED_ON);
			HAL_GPIO_WritePin(SEG_7_GPIO_Port, SEG_7_Pin, LED_OFF);
			break;
		case 5:
			HAL_GPIO_WritePin(SEG_0_GPIO_Port, SEG_0_Pin, LED_ON);
			HAL_GPIO_WritePin(SEG_1_GPIO_Port, SEG_1_Pin, LED_OFF);
			HAL_GPIO_WritePin(SEG_2_GPIO_Port, SEG_2_Pin, LED_ON);
			HAL_GPIO_WritePin(SEG_3_GPIO_Port, SEG_3_Pin, LED_ON);
			HAL_GPIO_WritePin(SEG_4_GPIO_Port, SEG_4_Pin, LED_OFF);
			HAL_GPIO_WritePin(SEG_5_GPIO_Port, SEG_5_Pin, LED_ON);
			HAL_GPIO_WritePin(SEG_6_GPIO_Port, SEG_6_Pin, LED_ON);
			HAL_GPIO_WritePin(SEG_7_GPIO_Port, SEG_7_Pin, LED_OFF);
			break;
		case 6:
			HAL_GPIO_WritePin(SEG_0_GPIO_Port, SEG_0_Pin, LED_ON);
			HAL_GPIO_WritePin(SEG_1_GPIO_Port, SEG_1_Pin, LED_OFF);
			HAL_GPIO_WritePin(SEG_2_GPIO_Port, SEG_2_Pin, LED_ON);
			HAL_GPIO_WritePin(SEG_3_GPIO_Port, SEG_3_Pin, LED_ON);
			HAL_GPIO_WritePin(SEG_4_GPIO_Port, SEG_4_Pin, LED_ON);
			HAL_GPIO_WritePin(SEG_5_GPIO_Port, SEG_5_Pin, LED_ON);
			HAL_GPIO_WritePin(SEG_6_GPIO_Port, SEG_6_Pin, LED_ON);
			HAL_GPIO_WritePin(SEG_7_GPIO_Port, SEG_7_Pin, LED_OFF);
			break;
		case 7:
			HAL_GPIO_WritePin(SEG_0_GPIO_Port, SEG_0_Pin, LED_ON);
			HAL_GPIO_WritePin(SEG_1_GPIO_Port, SEG_1_Pin, LED_ON);
			HAL_GPIO_WritePin(SEG_2_GPIO_Port, SEG_2_Pin, LED_ON);
			HAL_GPIO_WritePin(SEG_3_GPIO_Port, SEG_3_Pin, LED_OFF);
			HAL_GPIO_WritePin(SEG_4_GPIO_Port, SEG_4_Pin, LED_OFF);
			HAL_GPIO_WritePin(SEG_5_GPIO_Port, SEG_5_Pin, LED_OFF);
			HAL_GPIO_WritePin(SEG_6_GPIO_Port, SEG_6_Pin, LED_OFF);
			HAL_GPIO_WritePin(SEG_7_GPIO_Port, SEG_7_Pin, LED_OFF);
			break;
		case 8:
			HAL_GPIO_WritePin(SEG_0_GPIO_Port, SEG_0_Pin, LED_ON);
			HAL_GPIO_WritePin(SEG_1_GPIO_Port, SEG_1_Pin, LED_ON);
			HAL_GPIO_WritePin(SEG_2_GPIO_Port, SEG_2_Pin, LED_ON);
			HAL_GPIO_WritePin(SEG_3_GPIO_Port, SEG_3_Pin, LED_ON);
			HAL_GPIO_WritePin(SEG_4_GPIO_Port, SEG_4_Pin, LED_ON);
			HAL_GPIO_WritePin(SEG_5_GPIO_Port, SEG_5_Pin, LED_ON);
			HAL_GPIO_WritePin(SEG_6_GPIO_Port, SEG_6_Pin, LED_ON);
			HAL_GPIO_WritePin(SEG_7_GPIO_Port, SEG_7_Pin, LED_OFF);
			break;
		case 9:
			HAL_GPIO_WritePin(SEG_0_GPIO_Port, SEG_0_Pin, LED_ON);
			HAL_GPIO_WritePin(SEG_1_GPIO_Port, SEG_1_Pin, LED_ON);
			HAL_GPIO_WritePin(SEG_2_GPIO_Port, SEG_2_Pin, LED_ON);
			HAL_GPIO_WritePin(SEG_3_GPIO_Port, SEG_3_Pin, LED_ON);
			HAL_GPIO_WritePin(SEG_4_GPIO_Port, SEG_4_Pin, LED_OFF);
			HAL_GPIO_WritePin(SEG_5_GPIO_Port, SEG_5_Pin, LED_ON);
			HAL_GPIO_WritePin(SEG_6_GPIO_Port, SEG_6_Pin, LED_ON);
			HAL_GPIO_WritePin(SEG_7_GPIO_Port, SEG_7_Pin, LED_OFF);
			break;
		default:
			HAL_GPIO_WritePin(SEG_0_GPIO_Port, SEG_0_Pin, LED_OFF);
			HAL_GPIO_WritePin(SEG_1_GPIO_Port, SEG_1_Pin, LED_OFF);
			HAL_GPIO_WritePin(SEG_2_GPIO_Port, SEG_2_Pin, LED_OFF);
			HAL_GPIO_WritePin(SEG_3_GPIO_Port, SEG_3_Pin, LED_OFF);
			HAL_GPIO_WritePin(SEG_4_GPIO_Port, SEG_4_Pin, LED_OFF);
			HAL_GPIO_WritePin(SEG_5_GPIO_Port, SEG_5_Pin, LED_OFF);
			HAL_GPIO_WritePin(SEG_6_GPIO_Port, SEG_6_Pin, LED_OFF);
			HAL_GPIO_WritePin(SEG_7_GPIO_Port, SEG_7_Pin, LED_OFF);
			break;
	}
}

void enable_digit(int digit)
{
	switch (digit) {
		case 0:
			HAL_GPIO_WritePin(EN_0_GPIO_Port, EN_0_Pin, ENABLE);
			HAL_GPIO_WritePin(EN_1_GPIO_Port, EN_1_Pin, DISABLE);
			HAL_GPIO_WritePin(EN_2_GPIO_Port, EN_2_Pin, DISABLE);
			HAL_GPIO_WritePin(EN_3_GPIO_Port, EN_3_Pin, DISABLE);
			break;
		case 1:
			HAL_GPIO_WritePin(EN_0_GPIO_Port, EN_0_Pin, DISABLE);
			HAL_GPIO_WritePin(EN_1_GPIO_Port, EN_1_Pin, ENABLE);
			HAL_GPIO_WritePin(EN_2_GPIO_Port, EN_2_Pin, DISABLE);
			HAL_GPIO_WritePin(EN_3_GPIO_Port, EN_3_Pin, DISABLE);
			break;
		case 2:
			HAL_GPIO_WritePin(EN_0_GPIO_Port, EN_0_Pin, DISABLE);
			HAL_GPIO_WritePin(EN_1_GPIO_Port, EN_1_Pin, DISABLE);
			HAL_GPIO_WritePin(EN_2_GPIO_Port, EN_2_Pin, ENABLE);
			HAL_GPIO_WritePin(EN_3_GPIO_Port, EN_3_Pin, DISABLE);
			break;
		case 3:
			HAL_GPIO_WritePin(EN_0_GPIO_Port, EN_0_Pin, DISABLE);
			HAL_GPIO_WritePin(EN_1_GPIO_Port, EN_1_Pin, DISABLE);
			HAL_GPIO_WritePin(EN_2_GPIO_Port, EN_2_Pin, DISABLE);
			HAL_GPIO_WritePin(EN_3_GPIO_Port, EN_3_Pin, ENABLE);
			break;
		default:
			break;
	}
}

























