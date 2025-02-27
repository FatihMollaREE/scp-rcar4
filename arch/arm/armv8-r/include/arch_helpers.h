/*
 * 
 * LICENSE
 *
 * 
 */

#ifndef ARCH_HELPERS_H
#define ARCH_HELPERS_H


#include <fwk_noreturn.h>

#include <stdbool.h>
#include <stdint.h>
#include <string.h>


extern unsigned int critical_section_nest_level;

inline static void enable_irq(){
    /* FATIH: hier muss ich interrupts enablen, muss noch nachschauen wie genau, cr-52 datasheet oder manual oder sonst wo nachschauen, vergleich mit ROTS dummy? aber da iwie nix gefunden*/
    
    __asm__ volatile (
        "MRS R0, CPSR\n"        // CPSR-Register in R0 speichern
        "BIC R0, R0, #0xC0\n"   // IRQ (I-Bit) und FIQ (F-Bit) löschen (Interrupts aktivieren)
        "MSR CPSR_c, R0\n"      // Zurückschreiben ins CPSR-Register
        ::: "r0", "memory"
    );
    
}

inline static void arch_interrupts_enable(unsigned int not_used)
{
    /* Decrement critical_section_nest_level only if in critical section */
    if (critical_section_nest_level > 0) {
        critical_section_nest_level--;
    }

    /* Enable interrupts globally if now outside critical section FATIH: critical_section_nest_level == 0*/
    if (critical_section_nest_level == 0) {
        enable_irq();
    }
}


inline static void disable_irq(){
    /* FATIH: kp ob die intr so passen */
    
    __asm__ volatile (
        "MRS R0, CPSR\n"        // CPSR-Register in R0 speichern
        "ORR R0, R0, #0xC0\n"   // IRQ (I-Bit) und FIQ (F-Bit) setzen (Interrupts deaktivieren)
        "MSR CPSR_c, R0\n"      // Zurückschreiben ins CPSR-Register
        ::: "r0", "memory"
    );

}

inline static unsigned int arch_interrupts_disable(void)
{
    disable_irq();
    critical_section_nest_level++;

    return 0;
}


inline static void arch_suspend(void)
{
    return;
}

#endif /* ARCH_HELPERS_H */
