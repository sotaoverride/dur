/**
 * Copyright (c) 2020 Raspberry Pi (Trading) Ltd.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "pico/stdlib.h"
#include <stdio.h>
#include "hardware/pwm.h"

int main() {
	stdio_init_all();
	// Define pin connections and settings
	const int ForwardPin = 1;   // Pin for forward motor control
	const int BackwardPin = 0;  // Pin for backward motor control
	const long ActionTime = 200; // Duration for motor action (milliseconds)
	const int MaxSpeed = 110;    // Maximum speed (0-255)
	bool DirectionFlag = true;   // Direction flag for motor control
	gpio_set_function(0, GPIO_FUNC_PWM);
	gpio_set_function(1, GPIO_FUNC_PWM);
	uint slice_num = pwm_gpio_to_slice_num(0);
	pwm_set_clkdiv(slice_num, 100);
	// Set period of 4 cycles (0 to 3 inclusive)
	pwm_set_wrap(slice_num, 12500);
	// Set channel A output high for one cycle before dropping
	pwm_set_chan_level(slice_num, PWM_CHAN_A, 125000/2);
	// Set initial B output high for three cycles before dropping
	//pwm_set_chan_level(slice_num, PWM_CHAN_B, 3);
	// Set the PWM running
	pwm_set_enabled(slice_num, true);
	/// \end::setup_pwm[]

	// Note we could also use pwm_set_gpio_level(gpio, x) which looks up the
	// correct slice and channel for a given GPIO.

}
