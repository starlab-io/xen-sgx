/*
 *  Copyright (C) 2015, Shannon Zhao <shannon.zhao@linaro.org>
 *
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 */

#ifndef _ASM_ARM_ACPI_H
#define _ASM_ARM_ACPI_H

#include <xen/init.h>
#include <asm/page.h>

#define COMPILER_DEPENDENT_INT64   long long
#define COMPILER_DEPENDENT_UINT64  unsigned long long
#define ACPI_MAP_MEM_ATTR          PAGE_HYPERVISOR

/* Tables marked as reserved in efi table */
typedef enum {
    TBL_FADT,
    TBL_MADT,
    TBL_STAO,
    TBL_XSDT,
    TBL_RSDP,
    TBL_EFIT,
    TBL_MMAP,
    TBL_MMAX,
} EFI_MEM_RES;

#ifdef CONFIG_ACPI
extern bool_t acpi_disabled;
/* Basic configuration for ACPI */
static inline void disable_acpi(void)
{
    acpi_disabled = 1;
}

static inline void enable_acpi(void)
{
    acpi_disabled = 0;
}
#else
#define acpi_disabled (1)
#define disable_acpi()
#define enable_acpi()
#endif

#endif /*_ASM_ARM_ACPI_H*/