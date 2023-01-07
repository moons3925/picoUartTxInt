#include "uart_ex.h"

uart_t ut;

void on_uart_tx_int() {
    if (uart_is_writable(uart0) && uart_ex_is_txim(uart0)) {
        ut.index++;
        uart_ex_non_blocking_putc(uart0, ut.buf[ut.index]);
        if (ut.index == ut.length) {
            hw_clear_bits(&uart_get_hw(uart0)->imsc,
                          1 << UART_UARTIMSC_TXIM_LSB);
            ut.index = 0;
        }
    }
}

void uart_ex_send_first_byte() {
    if (uart_is_writable(uart0)) {
        uart_ex_non_blocking_putc(uart0, ut.buf[0]);
        hw_set_bits(&uart_get_hw(uart0)->imsc, 1 << UART_UARTIMSC_TXIM_LSB);
    }
}

void uart_ex_init() {
    const char *str = "1234567890\r\n";
    ut.index = 0;
    ut.length = 12;
    for (int i = 0; i < 12; i++) {
        ut.buf[i] = str[i];
    }
}

bool uart_ex_is_txim(uart_inst_t *uart) {
    return uart_get_hw(uart)->imsc & UART_UARTIMSC_TXIM_BITS;
}

void uart_ex_non_blocking_putc(uart_inst_t *uart, uint8_t data) {
    while (!uart_is_writable(uart)) {  // ここは待たなければならない
        tight_loop_contents();
    }
    uart_get_hw(uart)->dr = data;
}