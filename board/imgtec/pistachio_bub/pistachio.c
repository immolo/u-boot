/*
 * Copyright (C) 2015 Imagination Technologies
 * Author: Govindraj Raja <govindraj.raja@imgtec.com>
 *
 * SPDX-License-Identifier:	GPL-2.0+
 */

#include <common.h>
#include <miiphy.h>
#include <netdev.h>
#include <serial.h>

#include <asm/addrspace.h>
#include <asm/io.h>
#include <asm/pistachio.h>
#include <asm/mipsregs.h>

phys_size_t initdram(int board_type)
{
	return CONFIG_SYS_MEM_SIZE;
}

int checkboard(void)
{
	return 0;
}

/*
 * Print CPU information
 */
int print_cpuinfo(void)
{
	printf("MIPS(interAptiv): IMG Pistachio %dMHz.\n", CONFIG_SYS_MHZ);
	return 0;
}

char *addr= "01:23:45:67:89:AB";
uchar enetaddr[6];
int board_eth_init(bd_t *bs)
{
	eth_parse_enetaddr(addr, enetaddr);
	eth_setenv_enetaddr("ethaddr", enetaddr);

	if (designware_initialize(CKSEG1ADDR(PISTACHIO_ETHERNET),
			PHY_INTERFACE_MODE_RMII) >= 0)
		return 1;

	return 0;
}

void _machine_restart(void)
{
}

int board_early_init_f(void)
{
	return 0;
}

int misc_init_r(void)
{
	return 0;
}

struct serial_device *default_serial_console(void)
{
	return &eserial2_device;
}