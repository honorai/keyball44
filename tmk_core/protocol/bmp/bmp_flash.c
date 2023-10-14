// Copyright 2023 sekigon-gonnoc
/* SPDX-License-Identifier: GPL-2.0-or-later */

#include "wait.h"

#include "bmp_flash.h"
#include "apidef.h"

void flash_write_dword(uint32_t addr, uint32_t *data) {
    int retry = 3;
    int res   = 0;
    while (1) {
        res = BMPAPI->flash.write_dword(addr, data);
        if (res == 0 || --retry == 0) {
            break;
        }
        wait_ms(10);
    }
}

void flash_write_page(uint32_t page, uint32_t *data) {
    int retry = 3;
    int res   = 0;
    while (1) {
        BMPAPI->flash.write_page(page, data);
        if (res == 0 || --retry == 0) {
            break;
        }
        wait_ms(10);
    }
}

void flash_read(uint32_t addr, uint8_t *data, uint32_t len) {
    BMPAPI->flash.read(addr, data, len);
}

void flash_erase_page(uint32_t page) {
    int retry = 3;
    int res   = 0;
    while (1) {
        BMPAPI->flash.erase_page(page);
        if (res == 0 || --retry == 0) {
            break;
        }
        wait_ms(10);
    }
}