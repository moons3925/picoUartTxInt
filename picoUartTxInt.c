#include "pico/stdlib.h"
#include "uart_ex.h"

int main() {
    stdio_init_all();
    uart_init(uart0, 115200);

    uart_ex_init();

    // 7bit + パリティだと 8bit を指定するらしい
    uart_set_format(uart0, 8, 1, UART_PARITY_EVEN);

    uart_set_fifo_enabled(uart0, false);  // FiFoなしでやってみる
    gpio_set_function(0, GPIO_FUNC_UART);
    gpio_set_function(1, GPIO_FUNC_UART);

    irq_set_exclusive_handler(UART0_IRQ, on_uart_tx_int);
    irq_set_enabled(UART0_IRQ, true);
    uart_set_irq_enables(uart0, false, true);  // 送信割り込みのみ
    while (true) {
        uart_ex_send_first_byte();
        sleep_ms(1000);
    }
    return 0;
}
