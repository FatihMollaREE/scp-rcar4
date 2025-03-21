/*
* LICENSE ...
*/

#ifndef FMW_MEMORY_H
#define FMW_MEMORY_H

#include <system_mmap_scp.h>
#include <rcar4_mmap_scp.h>

#define FMW_MEM_MODE ARCH_MEM_MODE_SINGLE_REGION

/*
* RAM memory
*/
#define FMW_MEM0_SIZE SCP_RAM_SIZE
#define FMW_MEM0_BASE SCP_RAM_BASE

#define FMW_STACK_SIZE (2 * 1024)  // einfach von rcar übernommen

#endif /* FMW_MEMORY_H */

