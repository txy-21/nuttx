/****************************************************************************
 * arch/arm/include/stm32u5/chip.h
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Licensed to the Apache Software Foundation (ASF) under one or more
 * contributor license agreements.  See the NOTICE file distributed with
 * this work for additional information regarding copyright ownership.  The
 * ASF licenses this file to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance with the
 * License.  You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.  See the
 * License for the specific language governing permissions and limitations
 * under the License.
 *
 ****************************************************************************/

#ifndef __ARCH_ARM_INCLUDE_STM32U5_CHIP_H
#define __ARCH_ARM_INCLUDE_STM32U5_CHIP_H

/****************************************************************************
 * Included Files
 ****************************************************************************/

#include <nuttx/config.h>

/****************************************************************************
 * Pre-processor Prototypes
 ****************************************************************************/

#if defined(CONFIG_STM32U5_STM32U535XX) || defined(CONFIG_STM32U5_STM32U545XX)
#  define STM32_SRAM1_SIZE       (0x00030000)   /* 192Kb SRAM1 */
#  define STM32_SRAM2_SIZE       (0x00010000)   /* 64kB  SRAM2 */
#elif defined(CONFIG_STM32U5_STM32U575XX) || defined(CONFIG_STM32U5_STM32U585XX)
#  define STM32_SRAM1_SIZE       (0x00030000)   /* 192Kb SRAM1 */
#  define STM32_SRAM2_SIZE       (0x00010000)   /* 64kB  SRAM2 */
#  define STM32_SRAM3_SIZE       (0x00080000)   /* 512kB SRAM3 */
#elif defined(CONFIG_STM32U5_STM32U59XX) || defined(CONFIG_STM32U5_STM32U59AXX) || defined(CONFIG_STM32U5_STM32U5A5XX) || defined(CONFIG_STM32U5_STM32U5A9XX)
#  define STM32_SRAM1_SIZE       (0x000C0000)   /* 768Kb SRAM1 */
#  define STM32_SRAM2_SIZE       (0x00010000)   /* 64kB  SRAM2 */
#  define STM32_SRAM3_SIZE       (0x000d0000)   /* 832kB SRAM3 */
#  define STM32_SRAM5_SIZE       (0x000d0000)   /* 832kB SRAM5 */
#else
#  error "Unsupported STM32U5 chip"
#endif

#if defined(CONFIG_STM32U5_STM32U585XX) || defined(CONFIG_STM32U5_STM32U5A5XX)
#  define STM32_NFSMC                    1   /* Have FSMC memory controller */
#  define STM32_NATIM                    2   /* Two advanced timers TIM1 and 8 */
#  define STM32_NGTIM32                  2   /* 32-bit general timers TIM2 and 5 with DMA */
#  define STM32_NGTIM16                  2   /* 16-bit general timers TIM3 and 4 with DMA */
#  define STM32_NGTIMNDMA                3   /* 16-bit general timers TIM15-17 without DMA */
#  define STM32_NBTIM                    2   /* Two basic timers, TIM6-7 */
#  define STM32_NLPTIM                   2   /* Two low-power timers, LPTIM1-2 */
#  define STM32_NRNG                     1   /* Random number generator (RNG) */
#  define STM32_NUART                    2   /* UART 4-5 */
#  define STM32_NUSART                   3   /* USART 1-3 */
#  define STM32_NLPUART                  1   /* LPUART 1 */
#  define STM32_QSPI                     0   /* No QuadSPI1 */
#  define STM32_OCTOSPI                  2   /* OCTOSPI1-2 */
#  define STM32_NSPI                     3   /* SPI1-3 */
#  define STM32_NI2C                     4   /* I2C1-4 */
#  define STM32_NSWPMI                   0   /* No SWPMI1 */
#  define STM32_NUSBOTGFS                1   /* USB OTG FS */
#  define STM32_NUSBFS                   0   /* No USB FS */
#  define STM32_NCAN                     1   /* CAN1 */
#  define STM32_NSAI                     2   /* SAI1-2 */
#  define STM32_NSDMMC                   1   /* SDMMC interface */
#  define STM32_NDMA                     2   /* DMA1-2 */
#  define STM32_NPORTS                   9   /* 9 GPIO ports, GPIOA-I */
#  define STM32_NADC                     1   /* 12-bit ADC1, up to 20 channels */
#  define STM32_NDAC                     2   /* 12-bit DAC1-2 */
#  define STM32_NCRC                     1   /* CRC */
#  define STM32_NCOMP                    2   /* Comparators */
#  define STM32_NOPAMP                   2   /* Operational Amplifiers */
#endif /* CONFIG_STM32U5_STM32U585XX */

#if defined(CONFIG_STM32U5_STM32U5A5ZJT)
#  define STM32_NUSBOTGHS                1   /* USB OTG HS */
#endif

/* NVIC priority levels *****************************************************/

/* 16 Programmable interrupt levels */

#define NVIC_SYSH_PRIORITY_MIN     0xf0 /* All bits set in minimum priority */
#define NVIC_SYSH_PRIORITY_DEFAULT 0x80 /* Midpoint is the default */
#define NVIC_SYSH_PRIORITY_MAX     0x00 /* Zero is maximum priority */
#define NVIC_SYSH_PRIORITY_STEP    0x10 /* Four bits of interrupt priority used */

#endif /* __ARCH_ARM_INCLUDE_STM32U5_CHIP_H */
