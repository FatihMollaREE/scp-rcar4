/*
* LICENSE
*/

#ifndef RCAR4_MMAP_H
#define RCAR4_MMAP_H

/* The base-address of Module Standby, Software Reset */
#define SOFTWARE_RESET_BASE 0xE6150000


/* Peripherals */
#define MFIS_BASE (0xE6260000) // Fatih: hier muss ich nochmal nachschauen und Matthias fragen, siehe Excel
#define MFISAREICR_BASE (MFIS_BASE + 0x1400)
//#define CPG_BASE (PERIPHERAL_BASE + 0x00150000)

/* Memory */ 
#define SCP_SRAM_BASE (0xE6302000U) // within System-RAM
#define SCP_SRAM_SIZE (0x00001000U)

#define SCP_SRAM_STACK_BASE (SCP_SRAM_BASE + SCP_SRAM_SIZE)
#define SCP_SRAM_STACK_SIZE (0x00001000U)

#define TRUSTED_RAM_BASE (SCP_SRAM_STACK_BASE + SCP_SRAM_STACK_SIZE) // Fatih: warum hier 8kB statt nur 4?
#define NONTRUSTED_RAM_BASE (TRUSTED_RAM_BASE + 8* FWK_KIB)

/* tbd - copied form rcar_mmap.h
#define SCP_SRAM_BASE (0xE6302000U) 
#define SCP_SRAM_SIZE (0x00001000U)
#define SCP_SRAM_STACK_BASE (SCP_SRAM_BASE + SCP_SRAM_SIZE)
#define SCP_SRAM_STACK_SIZE (0x00001000U) unterschied von dem zum anderen stack? ders ja nur 2 * 1024
sram vs ram?  --> ich glaube einfach LMA vs VMA, also da wo das Program zu beginn geladen wird (rom/flash) und wo das zum ausführen hinkommt ram, LMA ist ja im emmc?
LMA - load memory address
VMA - virtuel memory address
-> vllt auch nicht, hört sich eher falsch an
*/

#endif /* RCAR4_MMAP_H */