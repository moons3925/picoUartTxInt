#ifndef __UARTEX_H
#define __UARTEX_H

#include "pico/stdlib.h"

typedef struct {
    uint8_t buf[1024];
    int index;
    int length;
} uart_t;

void on_uart_tx_int();
void uart_ex_send_first_byte();
void uart_ex_init();
bool uart_ex_is_txim(uart_inst_t *);
void uart_ex_non_blocking_putc(uart_inst_t *, uint8_t);

#endif /* __UARTEX_H */
