#include "mbed.h"

DigitalOut led1(LED1);
DigitalOut led2(LED2);
Thread thread;

void led2_thread() {
    while (true) {
        led2 = !led2;
        wait(1);
    }
}

// main() runs in its own thread in the OS
int main() {
    printf("----------------------------------------\r\n");
    thread.start(led2_thread);

    while (true) {
        led1 = !led1;
        wait(0.5);
        printf("test\r\n");
    }
}

