/*
    ChibiOS - Copyright (C) 2006..2018 Giovanni Di Sirio

    Licensed under the Apache License, Version 2.0 (the "License");
    you may not use this file except in compliance with the License.
    You may obtain a copy of the License at

        http://www.apache.org/licenses/LICENSE-2.0

    Unless required by applicable law or agreed to in writing, software
    distributed under the License is distributed on an "AS IS" BASIS,
    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
    See the License for the specific language governing permissions and
    limitations under the License.
*/

#include "global.h"
#include "usbconsole.h"
#include "usbcfg.h"
#include "chprintf.h"
#include "digital_inputs.h"
#include "adc.h"
#include "efilib.h"

BaseSequentialStream *chp = (BaseSequentialStream *)&EFI_CONSOLE_USB_DEVICE;

/*
 * This is a periodic thread that does absolutely nothing except flashing
 * a LED.
 */
static THD_WORKING_AREA(waThread1, 128);
static THD_FUNCTION(Thread1, arg) {

  (void)arg;
  chRegSetThreadName("blinker");
  while (true) {
    palSetLine(LINE_LED1);
    chThdSleepMilliseconds(50);
    palSetLine(LINE_LED2);
    chThdSleepMilliseconds(50);
    palSetLine(LINE_LED3);
    chThdSleepMilliseconds(200);
    palClearLine(LINE_LED1);
    chThdSleepMilliseconds(50);
    palClearLine(LINE_LED2);
    chThdSleepMilliseconds(50);
    palClearLine(LINE_LED3);
    chThdSleepMilliseconds(200);
  }
}

static THD_WORKING_AREA(consoleThread, 256);
static void ConsoleThread(void*) {
    while (true) {
//        for (int i = 0;i<ADC_GRP_NUM_CHANNELS;i++) {
//            int value = getAdcValue(i);
//            itoa10(buf, value);
//            chprintf(chp, buf);
//            chprintf(chp, " ");
//        }

        for (int s = 0;s<16;s++) {
            setScenarioIndex(s);

            chprintf(chp, "%d: %1.3f mV\r\n", s, getAdcValue(0));
        }


        chprintf(chp, "Hello\r\n");
        chThdSleepMilliseconds(200);
    }
}

/*
 * Application entry point.
 */
int main(void) {

  /*
   * System initializations.
   * - HAL initialization, this also initializes the configured device drivers
   *   and performs the board-specific initializations.
   * - Kernel initialization, the main() function becomes a thread and the
   *   RTOS is active.
   */
  halInit();
  chSysInit();

  initAnalogInputs();
  initDigitalInputs();
  usb_serial_start();

  setOutputIndex(0);

  /*
   * Creates the example thread.
   */
  chThdCreateStatic(waThread1, sizeof(waThread1), NORMALPRIO + 1, Thread1, NULL);

  chThdCreateStatic(consoleThread, sizeof(consoleThread), NORMALPRIO, ConsoleThread, nullptr);


  /*
   * Normal main() thread activity, in this demo it does nothing except
   * sleeping in a loop and check the button state.
   */
  while (true) {
    if (palReadLine(LINE_BUTTON)) {
    }
    chThdSleepMilliseconds(500);
  }
}
